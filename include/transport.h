#pragma once
#include <memory>
#include <fstream>

class ITransport {
public:
    enum Type { AIRPLANE, TRAIN, BOAT };

    virtual ~ITransport() = default;
    virtual void Read(std::istream&) = 0;
    virtual void Print(std::ostream&) const = 0;
    virtual Type GetType() const = 0;
    virtual std::string GetTypeStr() const = 0;

    void MultiMethod(ITransport* other, std::ostream& os) {
        os << this->GetTypeStr() << " and " << other->GetTypeStr() << "\n";
    }

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