#pragma once
#include "../include/transport.h"

class TAirplane : public ITransport {
public:
    void Read(std::istream& is) override;
    void Print(std::ostream& os) const override;
    ITransport::Type GetType() const override;
private:
    int range;
    int capacity;
};