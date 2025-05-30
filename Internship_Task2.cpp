#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to register a new user
void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    // Check if the user already exists
    ifstream infile(username + ".txt");
    if (infile.is_open()) {
        cout << "User already exists. Try a different username.\n";
        infile.close();
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream file(username + ".txt");
    file << username << endl;
    file << password << endl;
    file.close();

    cout << "Registration successful!\n";
}

// Function to login an existing user
void loginUser() {
    string username, password, storedUsername, storedPassword;

    cout << "Enter your username: ";
    cin >> username;

    ifstream file(username + ".txt");
    if (!file.is_open()) {
        cout << "No such user found. Please register first.\n";
        return;
    }

    getline(file, storedUsername);
    getline(file, storedPassword);

    cout << "Enter your password: ";
    cin >> password;

    if (password == storedPassword) {
        cout << "Login successful! Welcome, " << storedUsername << "!\n";
    } else {
        cout << "Incorrect password. Try again.\n";
    }

    file.close();
}

// Main menu
int main() {
    int choice;

    while (true) {
        cout << "\n--- Login and Registration System ---\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
