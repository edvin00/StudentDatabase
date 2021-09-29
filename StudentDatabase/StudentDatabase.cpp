#include <iostream>
#include <stdint.h>
#include <string>

class StudentDatabase {

private:
       
    const std::string menuItems[4] = {"Add student", "Query student", "Remove student", "Quit"};

    struct StudentEntry {
        std::string name, surname;
    };

    unsigned int numberOfStudents = 0;
      
    //TODO
    void addStudent() {
    
    }

    //TODO
    void queryStudent() {

    }

    //TODO
    void removeStudent() {

    }

public:

    StudentDatabase() {
        
    }

    void displayMenu() {
        int counter, input;
        counter = 1;

        std::cout << "Menu:" << std::endl;
        for (auto item : menuItems) {
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