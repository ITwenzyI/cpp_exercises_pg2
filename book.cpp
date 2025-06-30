/*
 * File: book
 * Author: Kilian | ItwenzyI
 * Created: 30.06.2025
 * Description: 
 */
//

#include <string>
#include <iostream>

class Book {
private:
    const std::string title_;
    const int pages_;

public:
    Book(const std::string& title, int pages) : title_(title), pages_(pages) {

    }
    ~Book() = default;

    std::string getTitle() const {
        return title_;
    }

    int getPages() const {
        return pages_;
    }

    void printInfo() const {
        std::cout << title_ << " " << pages_ << std::endl;
    }


};

int main() {
    const Book book1("Titel", 21);
    std::cout << book1.getTitle() << std::endl;
    std::cout << book1.getPages() << std::endl;
    book1.printInfo();
    return 0;
}
