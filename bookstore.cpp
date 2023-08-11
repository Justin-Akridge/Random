#include <iostream>
#include <map>
class Book {
public:
    void set_isbn() {
        std::string isbn;
        std::cout << "Enter the isbn number: ";
        std::cin >> isbn;
        book_data[isbn]++;
        set_password();
    }

    void set_password() {
        std::cout << "Enter a password for account: ";
        std::cin >> password;
    }

    int get_isbn(int password) {
        for (auto it = bookdata.
        if (book_data[password]) {
            return book_data[password]->first;
        }
    }

private:
    std::string isbn;
    std::map<int , std::map<std::string, int>> book_data;
    int password;
};

int main() {
    Book book1;
    book1.set_isbn();    
    std::cout << book1.book_data[0] << std::endl;
}
