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