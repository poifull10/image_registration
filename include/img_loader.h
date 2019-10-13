#pragma once
#include <image_registration.h>
#include <string>
#include <memory>


namespace imr{

    class ImgLoader
    {
        
        public:
            ImgLoader(const std::string& fname) : img(fname.c_str()) {}
            const Img & get() const { return img; }
            
            void write(const std::string& fname){
                this->img.save(fname.c_str());
            }
        private:
            Img img;
    };
}