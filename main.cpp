#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
#include <cctype>
#include <iomanip>

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

        if (!s.studentID.empty()) {
        roster.push_back(s);  // Add the student to the roster vector only if valid
        }
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
// =======================
// CREATE FUNCTION (CASE C)
// This function adds a new student record to the roster
// =======================
void createRecord(std::vector<Student>& roster) {
    Student s;
    
    while (true) {
        std::cout << "Enter Student ID: ";
        std::cin >> s.studentID;
        if (s.studentID.length() == 6) break;
        std::cout << "Invalid! ID must be exactly 6 digits.\n";
    }
    
    std::cin.ignore();
    std::cout << "Enter Name: ";
    std::getline(std::cin, s.name);
    if (!s.name.empty() && islower(s.name[0])) {
        s.name[0] = toupper(s.name[0]);
    }
    
    while (true) {
        std::cout << "Enter Sport (Volleyball, Basketball, Badminton): ";
        std::getline(std::cin, s.sport);
        if (!s.sport.empty() && islower(s.sport[0])) s.sport[0] = toupper(s.sport[0]);
        if (s.sport == "Volleyball" || s.sport == "Basketball" || s.sport == "Badminton") break;
        std::cout << "Invalid Sport! Please choose from the allowed list.\n";
    }
    
    while (true) {
    std::cout << "Enter New Jersey Number: ";
    if (std::cin >> s.jerseyNumber) {
        if (s.jerseyNumber >= 0 && s.jerseyNumber <= 99) break;
        std::cout << "Invalid! Must be between 0 and 99.\n";
    } else {
        std::cout << "Invalid! Please enter a number.\n";
        std::cin.clear(); // clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input
    }
}
    
    while (true) {
    std::cout << "Enter New Age: ";
    if (std::cin >> s.age) {
        if (s.age >= 10 && s.age <= 99) break;
        std::cout << "Invalid!\n";
    } else {
        std::cout << "Invalid! Please enter a number.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
}
    
    roster.push_back(s);
    std::cout << "Record added successfully!\n";
}

// =======================
// READ FUNCTION (CASE R)
// This function displays all student records in a formatted table
// =======================
void readRecords(const std::vector<Student>& roster) {
    if (roster.empty()) {
        std::cout << "No records found.\n";
        return;
    }

    std::cout << "\n" << std::left 
              << std::setw(10) << "ID" 
              << std::setw(20) << "Name" 
              << std::setw(15) << "Sport" 
              << std::setw(10) << "Jersey" 
              << std::setw(5)  << "Age" << "\n";
    std::cout << std::string(70, '-') << "\n";

    for (const auto& s : roster) {
        std::cout << std::left 
                  << std::setw(10) << s.studentID 
                  << std::setw(20) << s.name 
                  << std::setw(15) << s.sport 
                  << std::setw(10) << s.jerseyNumber 
                  << std::setw(5)  << s.age << "\n";
    }
}
// =======================
// UPDATE FUNCTION (CASE U)
// This function allows editing of an existing student record
// =======================
void updateStudent(std::vector<Student>& roster) {

    int index;

    // Display all students so user can choose which one to update
    if (roster.empty()) {
        std::cout << "No records found.\n";
        return;
    }

    std::cout << "\n" << std::left 
              << std::setw(10) << "Index"
              << std::setw(10) << "ID" 
              << std::setw(20) << "Name" 
              << std::setw(15) << "Sport" 
              << std::setw(10) << "Jersey" 
              << std::setw(5)  << "Age" << "\n";
    std::cout << std::string(70, '-') << "\n";

    for (int i = 0; i < roster.size(); i++) {
    std::cout << std::left 
              << std::setw(10) << i
              << std::setw(10) << roster[i].studentID 
              << std::setw(20) << roster[i].name 
              << std::setw(15) << roster[i].sport 
              << std::setw(10) << roster[i].jerseyNumber 
              << std::setw(5)  << roster[i].age << "\n";
}

    std::cout << "Enter index to update: ";
    std::cin >> index;

    if (index < 0 || index >= roster.size()) {
        std::cout << "Invalid index.\n";
        return;
    }

    Student &s = roster[index]; // reference so changes directly affect original data

    std::cout << "Updating student: " << s.name << "\n";
    
    while (true) {
        std::cout << "Enter New Student ID: ";
        std::cin >> s.studentID;
        if (s.studentID.length() == 6) break;
        std::cout << "Invalid! ID must be exactly 6 digits.\n";
    }
    
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "Enter New Name: ";
    std::getline(std::cin, s.name);
    if (!s.name.empty() && islower(s.name[0])) {
        s.name[0] = toupper(s.name[0]);
    }
    
    while (true) {
        std::cout << "Enter New Sport (Volleyball, Basketball, Badminton): ";
        std::getline(std::cin, s.sport);
        if (!s.sport.empty() && islower(s.sport[0])) s.sport[0] = toupper(s.sport[0]);
        if (s.sport == "Volleyball" || s.sport == "Basketball" || s.sport == "Badminton") break;
        std::cout << "Invalid Sport! Please choose from the allowed list.\n";
    }
    
    while (true) {
    std::cout << "Enter New Jersey Number: ";
    if (std::cin >> s.jerseyNumber) {
        if (s.jerseyNumber >= 0 && s.jerseyNumber <= 99) break;
        std::cout << "Invalid! Must be between 0 and 99.\n";
    } else {
        std::cout << "Invalid! Please enter a number.\n";
        std::cin.clear(); // clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input
    }
}   
    
    while (true) {
    std::cout << "Enter New Age: ";
    if (std::cin >> s.age) {
        if (s.age >= 0 && s.age <= 99) break;
        std::cout << "Invalid! Must be between 0 and 99.\n";
    } else {
        std::cout << "Invalid! Please enter a number.\n";
        std::cin.clear(); // clear error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // flush bad input
    }
}   
    std::cout << "Record updated successfully.\n";
}

// =======================
// DELETE FUNCTION (CASE D)
// This function removes a selected student from the roster
// =======================
void deleteStudent(std::vector<Student>& roster) {

    if (roster.empty()) {
        std::cout << "Roster is empty.\n";
        return;
    }

    int index;

    // Display all students so user can choose which one to delete
    std::cout << "\n" << std::left 
              << std::setw(10) << "Index"
              << std::setw(10) << "ID" 
              << std::setw(20) << "Name" 
              << std::setw(15) << "Sport" 
              << std::setw(10) << "Jersey" 
              << std::setw(5)  << "Age" << "\n";
    std::cout << std::string(70, '-') << "\n";

    for (int i = 0; i < roster.size(); i++) {
    std::cout << std::left 
              << std::setw(10) << i
              << std::setw(10) << roster[i].studentID 
              << std::setw(20) << roster[i].name 
              << std::setw(15) << roster[i].sport 
              << std::setw(10) << roster[i].jerseyNumber 
              << std::setw(5)  << roster[i].age << "\n";
}

    std::cout << "Enter index to delete: ";
    std::cin >> index;

    if (index < 0 || index >= roster.size()) {
        std::cout << "Invalid index.\n";
        return;
    }

    roster.erase(roster.begin() + index); // remove selected student from vector
    std::cout << "Record deleted.\n";
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
        choice = toupper(choice);  // Convert to uppercase to handle case insensitive input

        switch (choice) {
            case 'C': createRecord(roster); break;
            case 'R': readRecords(roster); break;
            case 'U': updateStudent(roster);break;
            case 'D': deleteStudent(roster);break;
            case 'E': saveToFile(roster); std::cout << "Exiting...\n";break;
            default: std::cout << "Invalid choice.\n";
        }

    } while (choice != 'E');  // Repeat loop until user selects Exit

    return 0;  // Exit the program with success status
}