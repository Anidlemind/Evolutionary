#include "truck.h"

void TTruck::Read(std::istream& is) {
    is >> speed >> distance >> weight >> height >> capacity;
}

void TTruck::Print(std::ostream& os) const {
    os << "Airplane specs:\n" << "Speed: " << speed << "\nDistance: " << distance << "\nWeight: " << weight << "\nHeight: " << height << "\nCapacity: " << capacity << "\n";
}

ITransport::Type TTruck::GetType() const {
    return ITransport::TRUCK;
}

std::string TTruck::GetTypeStr() const {
    return "Truck";
}
