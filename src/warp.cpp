#include <warp.h>
using namespace imr;

const Vector2f Warper::warp_x(const Vector2f& x)
{
    VectorXf x_tilda(3);
    x_tilda << x(0), x(1), 1;
    MatrixXf mat = to_mat();
    mat = mat * x_tilda;
    Vector2f ret;
    ret << mat(0), mat(1);
    return ret;
}

const Vector2f Warper::warp_x_inv(const Vector2f& x)
{
    Vector2f ret;
    float _x = x(0), _y = x(1);
    float _lower = (1+p(0))*(1+p(3)) - p(1)*p(2);
    ret <<  ((1+p(3)) * _x - p(2) * _y - (1+p(3))*p(4)+p(2)*p(5))/_lower,
            (p(1)*_x - (1+p(0))*_y - p(1)*p(4) + (1+p(0))*p(5))/(-_lower);
    return ret;
}

const MatrixXf Warper::to_mat() 
{
    MatrixXf m(2, 3);
    m << 1+p(0), p(2), p(4), p(1), 1+p(3), p(5);
    return m;
}

const float Warper::bilinear_interpolation(const Img& img, const Vector2f& v)
{
    float x = v(0);
    float y = v(1);
    int floor_x = std::floor(v(0));
    int floor_y = std::floor(v(1));
    float pix00, pix01, pix10, pix11;
    if (floor_x < 0 || floor_y < 0) return 0;
    if (floor_x + 1 >= img.width() ||
        floor_y + 1 >= img.height() ) return 0;

    pix00 = img(floor_x, floor_y);
    pix10 = img(floor_x + 1, floor_y);
    pix01 = img(floor_x, floor_y + 1);
    pix11 = img(floor_x + 1, floor_y + 1);    
    
    return (floor_x + 1 - x)*((floor_y + 1 - y) * pix00 + (y - floor_y) * pix01) + 
            (x - floor_x) * ((floor_y+1-y) * pix10 + (y - floor_y) * pix11);
        
}