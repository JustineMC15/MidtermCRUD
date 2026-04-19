#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

// Student structure to hold student information
struct Student {
    std::string studentID;
    std::string name;
    std::string sport;
    int jerseyNumber;
    int age;
};
void loadFromFile(std::vector<Student>& roster) {  // Function to load student data from file
    std::ifstream file("roster.txt");  // Open the roster.txt file for reading using input file stream

    if (!file.is_open()) {  // Check if file failed to open
        std::cout << "No existing data found. Starting fresh.\n";  // Display message if file doesn't exist
        return;  // Exit the function early
    }

    std::string line;
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string studentID, name, sport, jerseyNumberStr, ageStr; // Parses data

        std::getline(ss, studentID, ',');
        std::getline(ss, name, ',');
        std::getline(ss, sport, ',');
        std::getline(ss, jerseyNumberStr, ',');
        std::getline(ss, ageStr, ',');

        Student s;
        s.studentID = studentID;
        s.name = name;
        s.sport = sport;
        s.jerseyNumber = std::stoi(jerseyNumberStr);  // Convert string to integer and assign jersey number
        s.age = std::stoi(ageStr);  // Convert string to integer and assign age

        roster.push_back(s);  // Add the student to the roster vector
    }

    file.close();  // Close the file
    std::cout << "Data loaded successfully.\n";  // Display success message
}
void saveToFile(std::vector<Student>& roster) {  // Function to save student data to file
    std::ofstream file("roster.txt");  // Open the roster.txt file for writing

    if (!file.is_open()) {  // Check if file failed to open
        std::cout << "Error saving data.\n";  // Display error message if file can't be created
        return;  // Exit the function early
    }

    for (int i = 0; i < roster.size(); i++) {
        file << roster[i].studentID << ","
             << roster[i].name << ","
             << roster[i].sport << ","
             << roster[i].jerseyNumber << ","
             << roster[i].age << "\n";
    }

    file.close();  // Close the file
    std::cout << "Data saved successfully.\n";  // Display success message
}
// Main function that displays a menu for CRUD operations
int main() {
    std::vector<Student> roster;  // Create a vector to store all students
    loadFromFile(roster);  // Load existing student data from file

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
        choice = toupper(choice);  // Case senstive

        switch (choice) {
            case 'C': std::cout << "Create placeholder\n"; break;
            case 'R': std::cout << "Read placeholder\n"; break;
            case 'U': std::cout << "Update placeholder\n"; break;
            case 'D': std::cout << "Delete placeholder\n"; break;
            case 'E': saveToFile(roster); std::cout << "Exiting...\n";break;
            default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 'E');  // Repeat loop until user selects Exit

    return 0;  // Exit the program with success status
}