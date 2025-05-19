#pragma once
#include "transport.h"

class TContainer {
public:
    TContainer();
    ~TContainer();

    void Clear();
    void Add(ITransport* transport);
    void Read(std::istream& is);
    void Print(std::ostream& os) const;
    void PrintAirplanes(std::ostream& os) const;
    int Size() const;
    ITransport* operator[](int id);

private:
    enum {MAX_SIZE = 5};
    int len;
    ITransport* arr[MAX_SIZE];
};
