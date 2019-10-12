#pragma once
#define cimg_display 0
#include <CImg.h>
#include <string>
#include <memory>

using namespace cimg_library;

namespace imr{
    using Img = CImg<uint8_t>;
    using ImgPtr = std::shared_ptr<Img>;

    class ImgLoader
    {
        
        public:
            ImgLoader(const std::string& fname) : 
                img(std::shared_ptr<Img>(
                    new Img(fname.c_str()))) {}
            const ImgPtr & get() const { return img; }
            
            void write(const std::string& fname){
                this->img->save(fname.c_str());
            }
        private:
            ImgPtr img;
    };
}