#include "lucas_kanade.h"
#include <Eigen/LU>
#include "grad.h"
#include <iostream>

using namespace imr;


const Warper LucasKanadeMethod::solve(float tolerance) {
    bool is_converged = false;
    int i = 0;
    while (i<10){//! is_converged) {
        auto warped_image = warper.warp(I);
        float error = 0;
        auto grad_x = grad(I, GradDir::X);
        auto grad_y = grad(I, GradDir::Y);
        
        VectorXf accum = VectorXf::Zero(6);
        
        MatrixXf hessian = MatrixXf::Zero(6, 6);
        cimg_forXY(warped_image, x, y) {
            Vector2f nabla;
            nabla << grad_x(x, y), grad_y(x, y);
            Vector2f v;
            v << x, y;
            auto jacob = calc_jacobian(v);
            auto sweep = nabla.transpose() * jacob;    
            auto diff = T(x, y) - warped_image(x, y);
            accum += sweep.transpose() * diff;
            hessian += sweep.transpose() * sweep;
        }

        //calc hessian
        auto h_inv = hessian.inverse();
        auto delta_p = h_inv * accum;

        warper.update(delta_p);
        std::cout << i << " : " << std::endl;
        std::cout << warper.get_p() << std::endl;
        i++;
    }
    return warper;
}