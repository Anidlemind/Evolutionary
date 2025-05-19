#include <multimethod.h>

void SubMultiMethod(ITransport* left, ITransport* right, std::ostream& os) {
    os << left->GetTypeStr() << " and " << right->GetTypeStr() << '\n';
}

void MultiMethod(TContainer& container, std::ostream& os) {
    for (int i = 0; i < container.Size(); ++i) {
        for (int j = i+1; j < container.Size(); ++j) {
            SubMultiMethod(container[i], container[j], os);
            container[i]->Print(os);
            container[j]->Print(os);
        }
    }
}