#include <gtest/gtest.h>
#include <container.h>
#include <airplane.h>
#include <train.h>

TEST(TContainerTest, AddTest)
{
    TContainer c;
    c.Add(new TAirplane);
    c.Add(new TTrain);
    EXPECT_EQ(c.Size(), 2);
    c.Clear();
    EXPECT_EQ(c.Size(), 0);
    for (int i = 0; i < 5; ++i) {
        EXPECT_NO_THROW(c.Add(new TAirplane));
    }
    EXPECT_THROW(c.Add(new TAirplane), std::overflow_error);
}

TEST(TContainerTest, ReadAndPrint)
{
    TContainer c;
    std::istringstream in("1 10 10 10 10 2 10 10 10");
    c.Read(in);
    EXPECT_EQ(c.Size(), 2);
    std::ostringstream out;
    c.Print(out);
    std::string result = out.str();
    EXPECT_EQ(result, "Container with 2 elements:\n0: Airplane specs:\nSpeed: 10\nDistance: 10\nRange: 10\nCapacity: 10\n1: Train specs:\nSpeed: 10\nDistance: 10\nWagons: 10\n");
}