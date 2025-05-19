#include "../include/container.h"
#include "idealtime.h"

TContainer::TContainer() : len(0) {}

TContainer::~TContainer() {
    Clear();
}

void TContainer::Clear() {
    for (int i = len - 1; i >= 0; --i) {
        delete arr[i];
    }
    len = 0;
}

void TContainer::Add(ITransport* transport) {
    if (len < MAX_SIZE) {
        arr[len] = transport;
        ++len;
    } else {
        throw std::overflow_error("Container limit reached");
    }
}

void TContainer::Read(std::istream& is) {
    while (!is.eof()) {
        if ((arr[len] = Transport::Read(is)) != 0) {
            ++len;
        }
    }
}

void TContainer::Print(std::ostream& os) const {
    os << "Container with " << len << " elements:\n";
    for (size_t i = 0; i < len; ++i) {
        os << i << ": ";
        arr[i]->Print(os);
        os << "Ideal Time: " << IdealTime(arr[i]) << "\n";
    }
}

int TContainer::Size() const {
    return len;
}

ITransport* TContainer::operator[](int id) {
    return arr[id];
}
