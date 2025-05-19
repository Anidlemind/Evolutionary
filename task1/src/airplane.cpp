#include "airplane.h"

void TAirplane::Read(std::istream& is) {
    is >> speed >> distance >> range >> capacity;
}

void TAirplane::Print(std::ostream& os) const {
    os << "Airplane specs:\n" << "Speed: " << speed << "\nDistance: " << distance << "\nRange: " << range << "\nCapacity: " << capacity << "\n";
}
