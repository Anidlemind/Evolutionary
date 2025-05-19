#include "train.h"

void TTrain::Read(std::istream& is) {
    is >> speed >> distance >> wagons;
}

void TTrain::Print(std::ostream& os) const {
    os << "Train specs:\n" << "Speed: " << speed << "\nDistance: " << distance << "\nWagons: " << wagons << "\n";
}
