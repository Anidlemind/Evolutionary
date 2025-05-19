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

        std::cout << "=== SUCCESS ===\n";
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}