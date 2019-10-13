#pragma once
#include <image_registration.h>

namespace imr {
    enum class GradDir : int {
        X, Y
    };
    const Img grad(const Img& img, GradDir dir){
        CImg<float> _img(img.width(), img.height());
        
        if (GradDir::X == dir)
        {
            auto height = _img.height();
            auto width = _img.width();
            for (int h=0; h<height; h++) {
                for (int w=0; w<width-1; w++) {
                    _img(w, h) = img(w+1, h) - img(w, h);
                }
            }
        }
        else if (GradDir::Y == dir){
            auto height = _img.height();
            auto width = _img.width();
            for (int w=0; w<width; w++){
                for (int h=0; h<height; h++) {
                    _img(w, h) = img(w, h+1) - img(w, h);
                }
            }
        }


        return _img;
    }
}