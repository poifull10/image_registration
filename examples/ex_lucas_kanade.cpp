#include "img_loader.h"
#include "warp.h"
#include "lucas_kanade.h"

int main(int argc, char** argv) { 
    imr::ImgLoader i(std::string("../tests/sample/lena.png"));
    imr::ImgLoader t(std::string("../tests/sample/warped.png"));

    imr::LucasKanadeMethod lkm(t.get(), i.get());
    auto warp = lkm.solve();
    auto img = warp.warp(i.get());
    img.save("estimated.png");
}