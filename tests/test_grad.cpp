#include <grad.h>
#include <img_loader.h>
#include <gtest/gtest.h>
#include <iostream>

TEST(Grad, test_grad){
    imr::ImgLoader loader("../tests/sample/lena.png");
    auto img = imr::grad(loader.get(), imr::GradDir::Y);
    img += 125;
    imr::Img output(img.width(), img.height());
    cimg_forXY(img, x, y){
        output(x, y) = static_cast<uint8_t>(img(x, y));
    }
    
    output.save("../tests/sample/grad.png");
}