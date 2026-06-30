# 📚 Library Management System (C++)

A simple **Library Management System** developed in **C++** using **Object-Oriented Programming (OOP)** concepts and **file handling**. The project stores book records in a text file (`library.txt`) and allows basic library operations through a menu-driven interface.

## ✨ Features

* ➕ Add a new book
* 📖 Display all books
* 🔍 Search a book by ID
* 📕 Issue a book
* 📗 Return a book
* ❌ Delete a book
* 💾 Persistent storage using file handling (`library.txt`)

## 🛠️ Technologies Used

* C++
* Object-Oriented Programming (OOP)
* File Handling (`fstream`)
* Standard Template Library (STL)

## 📂 Project Structure

```text
Library-Management-System/
│── githublibraryproject.cpp
│── library.txt          (Generated automatically)
│── README.md
```
library.txt is created automatically when the first book is added.

## ▶️ How to Run

1. Compile the program:

```bash
g++ githublibraryproject.cpp -o library
```

2. Run the executable:

```bash
./library
```

**Windows (MinGW):**

```bash
g++ githublibraryproject.cpp -o library.exe
library.exe
```

## 📋 Menu Options

```text
1. Add Book
2. Display Books
3. Search Book
4. Issue Book
5. Return Book
6. Delete Book
7. Exit
```

## 💾 File Format

Book records are stored in `library.txt` in the following format:

```text
BookID,BookTitle,AuthorName,Available
```

Example:

```text
101,Clean Code,Robert C. Martin,Available
102,The C++ Programming Language,Bjarne Stroustrup,Issued
```

## 📚 Concepts Demonstrated

* Classes and Objects
* Functions
* File Handling
* Menu-driven Programming
* String Manipulation
* Basic Data Management

## 🚀 Future Improvements

* Update/Edit book details
* Student management
* Due date tracking
* Fine calculation
* Login and authentication
* Separate admin and user roles
* Better file format or database integration

## 👨‍💻 Author

**Manoj Paliwal**

GitHub: https://github.com/manojpaliwal0153

---

This project was created as a learning project to practice C++, Object-Oriented Programming, and File Handling.
