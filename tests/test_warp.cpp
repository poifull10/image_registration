#include <img_loader.h>
#include <warp.h>
#include <gtest/gtest.h>
#include <iostream>

class WarperTester : public ::testing::Test, public imr::Warper
{
};

TEST_F(WarperTester, test_to_mat){
    p << 1, 2, 3, 4, 5, 6;
    MatrixXf m(2, 3);
    m << 2, 3, 5, 2, 5, 6;
    for (int r=0; r<2; r++)
        for (int c=0; c<3; c++) 
            EXPECT_NEAR(m(r, c), this->to_mat()(r, c), 1e-10);
}


TEST_F(WarperTester, test_warp_x){
    Vector2f x;
    x << 2, 3;
    Vector2f expected;
    expected << 2, 3;
    for (int i=0; i<2; i++)
        EXPECT_NEAR(expected(i), warp_x(x)(i), 1e-10);

    p << 1, 2, 3, 4, 5, 6;
    expected << 2*2+3*3+5, 2*2+5*3+6;
    for (int i=0; i<2; i++)
        EXPECT_NEAR(expected(i), warp_x(x)(i), 1e-10);
}

TEST_F(WarperTester, test_warp_x_inv){
    Vector2f x;
    x << 2, 3;
    p << 1, 2, 3, 4, 5, 6;
    auto actual = warp_x_inv(warp_x(x));
    for (int i=0; i<2; i++)
        EXPECT_NEAR(x(i), actual(i), 1e-10);
}

TEST_F(WarperTester, test_bilinear_interpolation){
    imr::Img img(2, 2);
    img(0, 0) = 1;
    img(1, 0) = 2;
    img(0, 1) = 3;
    img(1, 1) = 4;
    Eigen::Vector2f x;
    x << -0.1, 2;
    auto actual = bilinear_interpolation(img, x);
    float expected = 0;
    EXPECT_NEAR(expected, actual, 1e-10);

    x << 0.4, -0.2;
    actual = bilinear_interpolation(img, x);
    expected = 0;
    EXPECT_NEAR(expected, actual, 1e-10);

    x << 1.1, 0.2;
    actual = bilinear_interpolation(img, x);
    expected = 0;
    EXPECT_NEAR(expected, actual, 1e-10);

    x << 0.2, 1.2;
    actual = bilinear_interpolation(img, x);
    expected = 0;
    EXPECT_NEAR(expected, actual, 1e-10);

    x << 0.5, 0.5;
    actual = bilinear_interpolation(img, x);
    expected = 2.5;
    EXPECT_NEAR(expected, actual, 1e-10);
}

TEST_F(WarperTester, test_warp){
    imr::ImgLoader img_loader(std::string("../tests/sample/lena.png"));
    p(0) = 0.03;
    p(1) = 0.03;
    p(2) = 0.03;
    p(3) = -0.03;
    p(4) = 0;
    p(5) = 0;
    auto img = warp(img_loader.get());
    img.save("../tests/sample/warped.png");
}