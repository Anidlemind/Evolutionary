#include "boat.h"

void TBoat::Read(std::istream& is) {
    is >> speed >> distance >> capacity >> masts;
}

void TBoat::Print(std::ostream& os) const {
    os << "Boat specs:\n" << "Speed: " << speed << "\nDistance: " << distance << "\nCapacity: " << capacity << "\nMasts count: " << masts << "\n";
}
