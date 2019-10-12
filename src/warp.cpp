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

void Warper::warp(const ImgPtr& img) 
{
    ;
}


const MatrixXf Warper::to_mat() 
{
    MatrixXf m(2, 3);
    m << 1+p(0), p(2), p(4), p(1), 1+p(3), p(5);
    return m;
}