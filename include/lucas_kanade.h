#pragma once
#include "image_registration.h"
#include "warp.h"

namespace imr {
    class LucasKanadeMethod
    {
    public:
        LucasKanadeMethod(  const Img& T, 
                            const Img& I) : 
            T(T), I(I), warper() {}
        const Warper solve(float tolerance=1e-3);
    protected:
        Img T;
        Img I;
        Warper warper;
        const MatrixXf calc_jacobian(Vector2f v) {
            MatrixXf ret(2, 6);
            float x = v(0);
            float y = v(1);
            ret << x, 0, y, 0, 1, 0, 
                   0, x, 0, y, 0, 1;
            return ret;
        }

    };
}