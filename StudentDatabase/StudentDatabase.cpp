#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>
#include <fstream>

class StudentDatabase {

private:

    struct SubjectEntry;
    struct StudentEntry;

    const std::string startMenuItems[4] = { "Add student", "Query student", "Remove student", "Quit" };

    struct StudentEntry {
        std::string name, surname, indexNumber;
        std::vector<SubjectEntry> passedSubjectsVector;
        StudentEntry(std::string name, std::string surname, std::string indexNumber) : name{ name }, surname{ surname }, indexNumber{ indexNumber } {};
    };

    struct SubjectEntry {
        std::string subjectCode, subjectName;
        std::vector<SubjectEntry> requiredSubjectsVector;
    };    

    std::vector<StudentEntry> studentEntryVector;
       
    unsigned int numberOfStudents = 0;
      
    void addStudent() {
        std::string name, surname, indexNumber;

        std::cout << "Name Surname IndexNumber: ";
        std::cin >> name >> surname >> indexNumber;

        auto newStudent = StudentEntry(name, surname, indexNumber);
        studentEntryVector.push_back(newStudent);
        numberOfStudents++;
    }

    //TODO
    void queryStudent() {

    }

    //TODO
    void removeStudent() {

    }

public:

    StudentDatabase() {
        
        //load subject list from file

        std::string line;
        std::ifstream subjectsFile;
        subjectsFile.open("listOfSubjects.txt");
        if (!subjectsFile.is_open()) {
            std::cout << "Error reading subjects file! Program aborted." << std::endl;
            return;
        }
        while (std::getline(subjectsFile, line)) {

        }
        subjectsFile.close();

    }

    void displayMenu() {
        int counter, input;
        counter = 1;

        std::cout << "Menu:" << std::endl;
        for (auto item : startMenuItems) {
            std::cout << "\t" << counter++ << ". " << item << std::endl;
        }
        std::cout << std::endl << "Choice: ";
        std::cin >> input;

        switch (input) {
        case 1: addStudent();
                break;
        case 2: queryStudent();
                break;
        case 3: removeStudent();
                break;
        case 4: return;
                break;
        }
    }
};

int main()
{
    auto DB = StudentDatabase();
    DB.displayMenu();
}