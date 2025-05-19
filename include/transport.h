#pragma once
#include <memory>
#include <fstream>

class ITransport {
public:
    virtual ~ITransport() = default;
    virtual void Read(std::istream&) = 0;
    virtual void Print(std::ostream&) const = 0;
protected:
    int speed;
    int distance;
};

namespace Transport {

ITransport* Read(std::istream& is);

}