#include "train.h"

void TTrain::Read(std::istream& is) {
    is >> speed >> distance >> weight >> wagons;
}

void TTrain::Print(std::ostream& os) const {
    os << "Train specs:\n" << "Speed: " << speed << "\nDistance: " << distance << "\nWeight: " << weight << "\nWagons: " << wagons << "\n";
}
