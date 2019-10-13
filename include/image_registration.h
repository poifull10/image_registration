#pragma once

#define cimg_display 0
#include <CImg.h>
#include <memory>

using namespace cimg_library;

namespace imr {
    using Img = CImg<uint8_t>;
    using ImgPtr = std::shared_ptr<CImg<uint8_t>>;
}