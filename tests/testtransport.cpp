#include <gtest/gtest.h>
#include <transport.h>
#include <airplane.h>
#include <train.h>
#include <boat.h>

TEST(TAirplaneTest, ReadAndPrint)
{
    TAirplane a;
    std::istringstream in("10 10 10 10");
    a.Read(in);
    std::ostringstream out;
    a.Print(out);
    std::string result = out.str();
    EXPECT_EQ(result, "Airplane specs:\nSpeed: 10\nDistance: 10\nRange: 10\nCapacity: 10\n");
}

TEST(TTrainTest, ReadAndPrint)
{
    TTrain t;
    std::istringstream in("10 10 10");
    t.Read(in);
    std::ostringstream out;
    t.Print(out);
    std::string result = out.str();
    EXPECT_EQ(result, "Train specs:\nSpeed: 10\nDistance: 10\nWagons: 10\n");
}

TEST(TBoatTest, ReadAndPrint)
{
    TBoat b;
    std::istringstream in("10 10 10 10");
    b.Read(in);
    std::ostringstream out;
    b.Print(out);
    std::string result = out.str();
    EXPECT_EQ(result, "Boat specs:\nSpeed: 10\nDistance: 10\nCapacity: 10\nMasts count: 10\n");
}

TEST(TTransportTest, ReadAndPrint)
{
    std::istringstream in("2 10 10 10");
    auto* transport = Transport::Read(in);
    std::ostringstream out;
    transport->Print(out);
    delete transport;
    std::string result = out.str();
    EXPECT_EQ(result, "Train specs:\nSpeed: 10\nDistance: 10\nWagons: 10\n");
}

TEST(TTransportTest, IdealTime)
{
    std::istringstream in("2 10 10 10");
    auto* transport = Transport::Read(in);
    EXPECT_EQ(transport->IdealTime(), 1.0);
    delete transport;
}
