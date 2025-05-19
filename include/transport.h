#pragma once
#include <memory>
#include <fstream>

class ITransport {
public:
    virtual ~ITransport() = default;
    virtual void Read(std::istream&) = 0;
    virtual void Print(std::ostream&) const = 0;

    double IdealTime() const {
        return static_cast<double>(distance) / speed;
    }
protected:
    int speed;
    int distance;
    double weight;
};

namespace Transport {

ITransport* Read(std::istream& is);

}