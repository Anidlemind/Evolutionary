#include "../include/container.h"
#include "airplane.h"
#include "idealtime.h"

void TContainer::PrintAirplanes(std::ostream& os) const {
    os << "All airplanes from container:\n";
    for (size_t i = 0; i < len; ++i) {
        if (arr[i]->GetType() == ITransport::AIRPLANE) {
            os << i << ": ";
            arr[i]->Print(os);
            os << "Ideal Time: " << IdealTime(arr[i]) << '\n';
        }
    }
}