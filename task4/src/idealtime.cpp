#include "../include/idealtime.h"

double IdealTime(ITransport* transport) {
    return static_cast<double>(transport->GetDistance()) / transport->GetSpeed();
}