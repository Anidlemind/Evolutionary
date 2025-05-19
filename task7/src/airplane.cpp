#include "airplane.h"

void TAirplane::Read(std::istream& is) {
    is >> speed >> distance >> weight >> range >> capacity;
}

void TAirplane::Print(std::ostream& os) const {
    os << "Airplane specs:\n" << "Speed: " << speed << "\nDistance: " << distance << "\nWeight: " << weight << "\nRange: " << range << "\nCapacity: " << capacity << "\n";
}

ITransport::Type TAirplane::GetType() const {
    return ITransport::AIRPLANE;
}

std::string TAirplane::GetTypeStr() const {
    return "Airplane";
}
