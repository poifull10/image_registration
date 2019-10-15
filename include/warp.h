#pragma once

#include <image_registration.h>
#include <Eigen/Core>
#include <vector>

using namespace Eigen; 

namespace imr {

    class Warper {
        public:
        Warper () : p(VectorXf::Zero(6)) { }
        const Vector2f warp_x(const Vector2f& x);
        const Vector2f warp_x_inv(const Vector2f& x);
        const Img warp(const Img& img) {
            Img _img(img.width(), img.height());
            cimg_forXY(_img, x, y){
                Vector2f v;
                v << x, y;
                Vector2f x_in_img = warp_x_inv(v);
                _img(x, y) = static_cast<uint8_t>(bilinear_interpolation(img, x_in_img));
            }
            return _img;
        }

        void update(const VectorXf& delta){
            p += delta;
        }

        const VectorXf get_p() const {return p;}

        protected:
            VectorXf p;
            const MatrixXf to_mat();
            const float bilinear_interpolation(const Img& img, const Vector2f& v);
    };
}