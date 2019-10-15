#pragma once
#include <image_registration.h>
#include <string>
#include <memory>


namespace imr{

    class ImgLoader
    {
        
        public:
            ImgLoader(const std::string& fname) {
                //auto _img = Img(fname.c_str());
                img = Img(fname.c_str()); //Img(_img.width(), _img.height());
                // cimg_forXY(img, x, y){
                //     img(x, y) = 0.33 * _img(x, y, 0) + 
                //                 0.33 * _img(x, y, 1) +
                //                 0.33 * _img(x, y, 2);
                // }
            }
            const Img & get() const { return img; }
            
            void write(const std::string& fname){
                this->img.save(fname.c_str());
            }
        private:
            Img img;
    };
}