#include <gtest/gtest.h>
#include <container.h>
#include <multimethod.h>
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
    std::istringstream in("1 10 10 10 10 10 2 10 10 10 10");
    c.Read(in);
    EXPECT_EQ(c.Size(), 2);
    std::ostringstream out;
    c.Print(out);
    std::string result = out.str();
    EXPECT_EQ(result, "Container with 2 elements:\n0: Airplane specs:\nSpeed: 10\nDistance: 10\nWeight: 10\nRange: 10\nCapacity: 10\nIdeal Time: 1\n1: Train specs:\nSpeed: 10\nDistance: 10\nWeight: 10\nWagons: 10\nIdeal Time: 1\n");
}

TEST(TContainerTest, PrintAirplanesTest)
{
    TContainer c;
    std::istringstream in("1 10 10 10 10 10 2 10 10 10 10 1 20 20 20 20 20");
    c.Read(in);
    std::ostringstream out;
    c.PrintAirplanes(out);
    std::string result = out.str();
    EXPECT_EQ(result, "All airplanes from container:\n0: Airplane specs:\nSpeed: 10\nDistance: 10\nWeight: 10\nRange: 10\nCapacity: 10\nIdeal Time: 1\n2: Airplane specs:\nSpeed: 20\nDistance: 20\nWeight: 20\nRange: 20\nCapacity: 20\nIdeal Time: 1\n");
}

TEST(TContainerTest, MultiMethodTest)
{
    TContainer c;
    std::istringstream in("1 10 10 10 10 10 2 10 10 10 10 3 20 20 20 20 20 4 30 30 30 30 30");
    c.Read(in);
    std::ostringstream out;
    MultiMethod(c, out);
    std::string result = out.str();
    EXPECT_NE(result.find("Airplane and Train"), std::string::npos);
    EXPECT_NE(result.find("Airplane and Boat"), std::string::npos);
    EXPECT_NE(result.find("Airplane and Truck"), std::string::npos);
    EXPECT_NE(result.find("Train and Boat"), std::string::npos);
    EXPECT_NE(result.find("Train and Truck"), std::string::npos);
    EXPECT_NE(result.find("Boat and Truck"), std::string::npos);
}
