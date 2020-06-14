#include "../Laba1/Program.h"
#include <gtest/gtest.h>
using namespace std;
using namespace testing;

int main(int argc, char** argv) {
    InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
// Тест открытия файла input
TEST(LAB1_test, test_fileInpName) {
    ifstream ifst("input.txt");
    EXPECT_TRUE(ifst.is_open());
}
// Тест открытия файла output
TEST(LAB1_test, test_fileOutName) {
    ofstream ofst("output.txt");
    EXPECT_TRUE(ofst.is_open());
}
// Тест инициализации контейнера
TEST(LAB1_test, test_Init) {
    ifstream ifst("input.txt");
    container c;
    container_Init(c);
    EXPECT_EQ(c.len, 0);
}
// Тест очистки контейнера
TEST(LAB1_test, test_Clear) {
    ifstream ifst("input.txt");
    container c;
    container_Init(c);
    c.len = 10;
    container_Clear(c);
    EXPECT_EQ(c.len, 0);
}