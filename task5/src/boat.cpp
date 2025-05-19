#include "boat.h"

void TBoat::Read(std::istream& is) {
    is >> speed >> distance >> weight >> capacity >> masts;
}

void TBoat::Print(std::ostream& os) const {
    os << "Boat specs:\n" << "Speed: " << speed << "\nDistance: " << distance << "\nWeight: " << weight <<"\nCapacity: " << capacity << "\nMasts count: " << masts << "\n";
}

ITransport::Type TBoat::GetType() const {
    return ITransport::BOAT;
}
