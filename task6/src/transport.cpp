#include "../include/transport.h"
#include "airplane.h"
#include "train.h"
#include "boat.h"

namespace Transport {

ITransport* Read(std::istream& is) {
    int type;
    if (!(is >> type)) return nullptr;

    ITransport* transport;
    switch (type) {
        case 1:
            transport = new TAirplane;
            break;
        case 2:
            transport = new TTrain;
            break;
        case 3:
            transport = new TBoat;
            break;
        default:
            throw std::invalid_argument("Unsupported transport type");
    }

    transport->Read(is);
    return transport;
}

}
