#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

struct Student {
    std::string studentID;
    std::string name;
    std::string sport;
    int jerseyNumber;
    int age;
};
int main() {
    std::vector<Student> roster;

    char choice;

    do {
        std::cout << "\n=== Student Sports Roster ===\n";
        std::cout << "[C] Create\n";
        std::cout << "[R] Read\n";
        std::cout << "[U] Update\n";
        std::cout << "[D] Delete\n";
        std::cout << "[E] Exit\n";
        std::cout << "Enter choice: ";
        std::cin >> choice;
        choice = toupper(choice);

        switch (choice) {
            case 'C': std::cout << "Create placeholder\n"; break;
            case 'R': std::cout << "Read placeholder\n"; break;
            case 'U': std::cout << "Update placeholder\n"; break;
            case 'D': std::cout << "Delete placeholder\n"; break;
            case 'E': std::cout << "Exiting...\n"; break;
            default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 'E');

    return 0;
}