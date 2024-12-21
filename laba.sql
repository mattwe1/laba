CREATE DATABASE library;
-- Таблица authors
CREATE TABLE authors (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    birth_year INT
);

-- Таблица books
CREATE TABLE books (
    id SERIAL PRIMARY KEY,
    title VARCHAR(200),
    author_id INT REFERENCES authors(id),
    publication_year INT,
    genre VARCHAR(50)
);

-- Таблица users
CREATE TABLE users (
    id SERIAL PRIMARY KEY,
    name VARCHAR(100),
    registration_date DATE
);

-- Таблица borrowed_books
CREATE TABLE borrowed_books (
    user_id INT REFERENCES users(id),
    book_id INT REFERENCES books(id),
    borrow_date DATE,
    return_date DATE
);
-- Индекс на поле name таблицы authors
CREATE INDEX idx_authors_name ON authors(name);

-- Индекс на поле title таблицы books
CREATE INDEX idx_books_title ON books(title);

-- Индекс на поле borrow_date таблицы borrowed_books
CREATE INDEX idx_borrowed_books_borrow_date ON borrowed_books(borrow_date);
