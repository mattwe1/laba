#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include <string>
#include <ctime>

// Логирование операций
void logOperation(const std::string& operation) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << operation << std::endl;
    }
}

// Класс Author
class Author {
private:
    int id;
    std::string name;
    int birthYear;

public:
    Author(const std::string& name, int birthYear) : name(name), birthYear(birthYear) {}

    void saveToDatabase(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            txn.exec0("INSERT INTO authors (name, birth_year) VALUES (" + txn.quote(name) + ", " + txn.quote(birthYear) + ")");
            txn.commit();
            logOperation("Added author: " + name);
            std::cout << "Author added successfully.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    static void listAuthors(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT * FROM authors");
            for (const auto& row : res) {
                std::cout << "ID: " << row["id"].as<int>() << ", Name: " << row["name"].c_str() << ", Birth Year: " << row["birth_year"].as<int>() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

// Класс Book
class Book {
private:
    int id;
    std::string title;
    int authorId;
    int publicationYear;
    std::string genre;

public:
    Book(const std::string& title, int authorId, int publicationYear, const std::string& genre)
        : title(title), authorId(authorId), publicationYear(publicationYear), genre(genre) {}

    void saveToDatabase(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            txn.exec0("INSERT INTO books (title, author_id, publication_year, genre) VALUES (" +
                      txn.quote(title) + ", " + txn.quote(authorId) + ", " +
                      txn.quote(publicationYear) + ", " + txn.quote(genre) + ")");
            txn.commit();
            logOperation("Added book: " + title);
            std::cout << "Book added successfully.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    static void listBooks(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT * FROM books");
            for (const auto& row : res) {
                std::cout << "ID: " << row["id"].as<int>()
                          << ", Title: " << row["title"].c_str()
                          << ", Author ID: " << row["author_id"].as<int>()
                          << ", Year: " << row["publication_year"].as<int>()
                          << ", Genre: " << row["genre"].c_str() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

// Класс User
class User {
private:
    int id;
    std::string name;
    std::string registrationDate;

public:
#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include <string>
#include <ctime>

// Логирование операций
void logOperation(const std::string& operation) {
    std::ofstream logFile("log.txt", std::ios::app);
    if (logFile.is_open()) {
        logFile << operation << std::endl;
    }
}

// Класс Author
class Author {
private:
    int id;
    std::string name;
    int birthYear;

public:
    Author(const std::string& name, int birthYear) : name(name), birthYear(birthYear) {}

    void saveToDatabase(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            txn.exec0("INSERT INTO authors (name, birth_year) VALUES (" + txn.quote(name) + ", " + txn.quote(birthYear) + ")");
            txn.commit();
            logOperation("Added author: " + name);
            std::cout << "Author added successfully.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    static void listAuthors(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT * FROM authors");
            for (const auto& row : res) {
                std::cout << "ID: " << row["id"].as<int>() << ", Name: " << row["name"].c_str() << ", Birth Year: " << row["birth_year"].as<int>() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

// Класс Book
class Book {
private:
    int id;
    std::string title;
    int authorId;
    int publicationYear;
    std::string genre;

public:
    Book(const std::string& title, int authorId, int publicationYear, const std::string& genre)
        : title(title), authorId(authorId), publicationYear(publicationYear), genre(genre) {}

    void saveToDatabase(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            txn.exec0("INSERT INTO books (title, author_id, publication_year, genre) VALUES (" +
                      txn.quote(title) + ", " + txn.quote(authorId) + ", " +
                      txn.quote(publicationYear) + ", " + txn.quote(genre) + ")");
            txn.commit();
            logOperation("Added book: " + title);
            std::cout << "Book added successfully.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    static void listBooks(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT * FROM books");
            for (const auto& row : res) {
                std::cout << "ID: " << row["id"].as<int>()
                          << ", Title: " << row["title"].c_str()
                          << ", Author ID: " << row["author_id"].as<int>()
                          << ", Year: " << row["publication_year"].as<int>()
                          << ", Genre: " << row["genre"].c_str() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

// Класс User
class User {
private:
    int id;
    std::string name;
    std::string registrationDate;

public:
    User(const std::string& name, const std::string& registrationDate) : name(name), registrationDate(registrationDate) {}

    void saveToDatabase(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            txn.exec0("INSERT INTO users (name, registration_date) VALUES (" + txn.quote(name) + ", " + txn.quote(registrationDate) + ")");
            txn.commit();
            logOperation("Added user: " + name);
            std::cout << "User added successfully.\n";
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    static void listUsers(pqxx::connection& conn) {
        try {
            pqxx::work txn(conn);
            pqxx::result res = txn.exec("SELECT * FROM users");
            for (const auto& row : res) {
                std::cout << "ID: " << row["id"].as<int>() << ", Name: " << row["name"].c_str() << ", Registration Date: " << row["registration_date"].c_str() << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }
};

// Главная функция
int main() {
    try {
        // Подключение к базе данных
        pqxx::connection conn("dbname=library user=postgres password=your_password");

        if (conn.is_open()) {
            std::cout << "Connected to the database successfully.\n";

            // Пример добавления автора
            Author author("John Doe", 1980);
            author.saveToDatabase(conn);

            // Пример вывода списка авторов
            std::cout << "List of authors:\n";
            Author::listAuthors(conn);

            // Пример добавления книги
            Book book("C++ Programming", 1, 2021, "Education");
            book.saveToDatabase(conn);

            // Пример вывода списка книг
            std::cout << "List of books:\n";
            Book::listBooks(conn);

            // Пример добавления пользователя
            User user("Alice", "2023-12-20");
            user.saveToDatabase(conn);

            // Пример вывода списка пользователей
            std::cout << "List of users:\n";
            User::listUsers(conn);

            conn.disconnect();
        } else {
            std::cerr << "Failed to connect to the database.\n";
        }
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
