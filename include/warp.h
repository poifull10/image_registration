#pragma once

#include "img_loader.h"
#include <Eigen/Core>
#include <vector>

using namespace Eigen; 

namespace imr {

    class Warper {
        public:
        Warper () : p(VectorXf::Zero(6)) { }
        const Vector2f warp_x(const Vector2f& x);
        const Vector2f warp_x_inv(const Vector2f& x);
        void warp(const ImgPtr& img);

        protected:
            VectorXf p;
            const MatrixXf to_mat();
    };
}