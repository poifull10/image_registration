#include <gtest/gtest.h>
#include <img_loader.h>
#include <string>
#include <fstream>

TEST(ImgLoader, test_load_save){
    imr::ImgLoader load(std::string("../tests/sample/lena.png"));
    auto output = std::string("../tests/sample/output.png");
    load.write(output);
    std::ifstream ifs(output);
    ASSERT_TRUE(ifs.is_open());
}
