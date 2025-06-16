/*
 * File: medizinische
 * Author: Kilian | ItwenzyI
 * Created: 16.06.2025
 * Description: Stell dir vor, du entwickelst eine kleine Funktion für ein medizinisches Assistenzprogramm.
 * In diesem Programm sollen Tagesnotizen eines Arztes gespeichert und bei Bedarf ausgelesen werden können.
 */
//

#include <iostream>
#include <fstream>
#include <filesystem>
#include <vector>

void addNote() {
    std::string date, time, name, note;
    std::cout << "Enter date: (YYYY-MM-DD)";
    std::cin >> date;
    std::cout << "Enter time: ";
    std::cin >> time;
    std::cin.ignore();
    std::cout << "Enter name: ";
    std::getline(std::cin, name);
    std::cout << "Enter note: ";
    std::getline(std::cin, note);
    std::ofstream file("data/med_not/daily_notes.txt", std::ios::app);
    file << "[" << date << " " << time << "] " << name << ": " << note << std::endl;
}

void printNotes() {
    std::ifstream file("data/med_not/daily_notes.txt");
    std::vector<std::string> notes;
    std::string line;
    int i = 1;
    while (std::getline(file, line)) {
        notes.push_back(line);
        std::cout << i++ << ". " << line << "\n" << std::endl;
    }
    file.close();
    std::cout << std::endl;
}

int main() {

    std::filesystem::create_directories("data");
    std::filesystem::create_directories("data/med_not");
    if (!std::filesystem::exists("data/med_not/daily_notes.txt")) {
        std::ofstream out("data/med_not/daily_notes.txt");
        out.close();
    }
    int choice;
    do {
        std::cout << "Med. Menu:" << std::endl;
        std::cout << "1. Add note\n";
        std::cout << "2. Print note\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        switch (choice) {
            case 1: {
                addNote();
                break;
            }
            case 2: {
                printNotes();
                break;
            }
            case 3: {
                std::cout << "Exiting...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice" << std::endl;
                break;
            }
        }
    }while (choice != 3);

    return 0;
}
