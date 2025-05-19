#include "../include/container.h"

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
        os << "Ideal Time: " << arr[i]->IdealTime() << '\n';
    }
}

int TContainer::Size() const {
    return len;
}

ITransport* TContainer::Get(int id) const {
    if (id > MAX_SIZE) {
        throw std::range_error("Id is bigger than maximum size of the container");
    }
    if (id > len) {
        throw std::out_of_range("Id is bigger than current size of the container");
    }
    return arr[id];
}

void TContainer::MultiMethod(std::ostream& os) const {
    for (int i = 0; i < len; ++i) {
        for (int j = i+1; j < len; ++j) {
            arr[i]->MultiMethod(arr[j], os);
            arr[i]->Print(os);
            arr[j]->Print(os);
        }
    }
}
