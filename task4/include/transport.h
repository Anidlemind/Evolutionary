#pragma once
#include <memory>
#include <fstream>

class ITransport {
public:
    virtual ~ITransport() = default;
    virtual void Read(std::istream&) = 0;
    virtual void Print(std::ostream&) const = 0;

    int GetSpeed() const {
        return speed;
    }

    int GetDistance() const {
        return distance;
    }

protected:
    int speed;
    int distance;
    double weight;
};

namespace Transport {

ITransport* Read(std::istream& is);

}