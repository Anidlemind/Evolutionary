#include <iostream>
#include <sstream>
#include "container.h"

int main() {
    try {
        TContainer container;
        std::string s = "";
        std::string total;

        while (s != "0") {
            total += s + ' ';
            std::cin >> s;
        }

        std::istringstream is(total);
        container.Read(is);

        std::cout << "=== CONTAINER INSIDES ===\n";
        container.Print(std::cout);

        if (container.Size() > 0) {
            std::cout << "=== CONTAINER'S IDEAL TIMES ===\n";
            for (int i = 0; i < container.Size(); ++i) {
                std::cout << i << ": Ideal time is: " << container.Get(i)->IdealTime() << '\n';
            }
        }

        std::cout << "=== SUCCESS ===\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}