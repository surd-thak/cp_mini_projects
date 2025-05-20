#include <gtest/gtest.h>
#include <iostream>
#include "myVector.hpp"

TEST(MyVectorTest, defaultConstructor) {
    myVector<int> v1;
    EXPECT_EQ(v1.size(), (size_t)0);  
    EXPECT_EQ(v1.empty(), true);  
}

TEST(MyVectorTest, parametrizedConstructor) { 
    myVector<int> v1(5);
    EXPECT_EQ(v1.size(), (size_t)5);  
    EXPECT_EQ(v1.empty(), false);  
    myVector<int> v2(3, -1);
    EXPECT_EQ(v2.size(), 3);  
    for(int i = 0; i < 3; i++) EXPECT_EQ(v2[i], -1); 
}



int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    myVector<int> v1(5);
    std::cout << v1.size() << "\n";
    return RUN_ALL_TESTS();
}
