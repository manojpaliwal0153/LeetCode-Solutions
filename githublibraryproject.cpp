#include<bits/stdc++.h>  // heading or header file for all the librries in cpp


using namespace std;

// Book Class to handle data and file saving
class Book {
public:
    int id;
    string title;
    string author;

    void inputDetails() {
        cout << "\nEnter Book ID: ";
        cin >> id;
        cin.ignore(); 
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
    }

    void saveToFile() {
        ofstream file("library.txt", ios::app);
        if (file) {
            file << id << "," << title << "," << author << ",Available"<<endl;
            file.close();
            cout << "\n[✔] Book added successfully!" << endl;
        } else {
            cout << "\n[✘] Error opening file!" << endl;
        }
    }
};

// Global function to display the list (Simplified version of Step 2)
void displayAllBooks() {
    ifstream file("library.txt");
    string line;
    cout << "\n--- Current Book List ---" << endl;
    if (file.is_open()) {
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "No records found." << endl;
    }
}
void searchBook(int searchId) {
    ifstream file("library.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(to_string(searchId) + ",") == 0) {
            cout << "\nBook Found:\n" << line << endl;
            found = true;
            break;
        }
    }

    if (!found)
        cout << "\n[✘] Book not found!";
}
void issueBook(int issueId) {
    ifstream file("library.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;

    if (!file || !temp) {
        cout << "\n[✘] File error!";
        return;
    }

    while (getline(file, line)) {
        if (!found &&
            line.find(to_string(issueId) + ",") == 0 &&
            line.rfind(",Available") != string::npos) {

            line.replace(line.rfind("Available"), 9, "Issued");
            found = true;
        }
        temp << line << endl;
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found)
        cout << "\n[✔] Book issued successfully!";
    else
        cout << "\n[✘] Book not found or already issued!";
}


void returnBook(int returnId) {
    ifstream file("library.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(to_string(returnId) + ",") == 0 &&
            line.find("Issued") != string::npos) {

            line.replace(line.find("Issued"), 6, "Available");
            found = true;
        }
        temp << line << endl;
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found)
        cout << "\n[✔] Book returned successfully!";
    else
        cout << "\n[✘] Book not issued or not found!";
}
void deleteBook(int deleteId) {
    ifstream file("library.txt");
    ofstream temp("temp.txt");
    string line;
    bool found = false;

    while (getline(file, line)) {
        if (line.find(to_string(deleteId) + ",") == 0) {
            found = true; // skip writing
        } else {
            temp << line << endl;
        }
    }

    file.close();
    temp.close();

    remove("library.txt");
    rename("temp.txt", "library.txt");

    if (found)
        cout << "\n[✔] Book deleted successfully!";
    else
        cout << "\n[✘] Book not found!";
}



int main() {
    int choice;
    Book b;

    while (true) {
        // Step 1: Display Main Menu
        cout << "\n============================";
        cout << "\n   LIBRARY MANAGEMENT SYSTEM";
        cout << "\n============================";
        cout << "\n1. Add Book";
        cout << "\n2. Display Books";
        cout << "\n3. Search Book";
        cout << "\n4. Issue Book";
        cout << "\n5. Return Book";
        cout << "\n6. Delete Book";
        cout << "\n7. Exit";
        cout << "\n\nEnter Choice: ";
        cin >> choice;

        // Step 2 & 3: Validate Choice and Perform Operation
switch (choice) {
            
case 1:
     b.inputDetails(); // Sub-flowchart: Add Book
     b.saveToFile();
     break;
            
case 2:
     displayAllBooks();
     break;
case 3: {
    int id;
    cout << "Enter Book ID to search: ";
    cin >> id;
    searchBook(id);
    break;
}
case 4: {
    int id;
    cout << "Enter Book ID to issue: ";
    cin >> id;
    issueBook(id);
    break;
}
case 5: {
    int id;
    cout << "Enter Book ID to return: ";
    cin >> id;
    returnBook(id);
    break;
}
case 6: {
    int id;
    cout << "Enter Book ID to delete: ";
    cin >> id;
    deleteBook(id);
    break;
}

case 7:{
    cout<<"\n exiting...goodbye!\n";
    
}

default:
     cout<<"invalid choice plese enter 1-7"; 
      // Return to Main Menu happens automatically because of 'while' loop
    }
if (cin.fail()) 
{
    cin.clear();
    cin.ignore(1000, '\n');
    cout << "Invalid input!" << endl;
    continue;
}

    }
    return 0;
}
