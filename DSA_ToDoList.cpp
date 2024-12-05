#include <iostream>
#include <vector>
#include <string>

int main() {
    std::vector<std::string> favoriteDishes = {"Giniling", "Menudo", "Adobo"};
    std::string userResponse;

    std::cout << "Available dishes to take out:\n";
    for (const auto& dish : favoriteDishes) {
        std::cout << "- " << dish << "\n";
    }

    for (size_t i = 0; i < favoriteDishes.size(); ++i) {
        std::cout << "Would you like to take out " << favoriteDishes[i] << "? (yes/no): ";
        std::cin >> userResponse;

        if (userResponse == "yes" || userResponse == "Yes") {
            std::cout << "You chose to take out " << favoriteDishes[i] << "\n";
            std::cout << "Go back to dorm and eat in dorm.\n";
            return 0; 
        }
    }

    std::cout << "No favorite dishes available. Try another restaurant.\n";
    return 0;
}