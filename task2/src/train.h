#pragma once
#include "../include/transport.h"

class TTrain : public ITransport {
public:
    void Read(std::istream& is) override;
    void Print(std::ostream& os) const override;
private:
    int wagons;
};