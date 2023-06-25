/*
* Name: Jamie Javis
* Date: 6/16/23
* Class: CS-210
*/
#include <iostream>            // input/output stream
#include <unordered_map>       // hash map data structure
#include <fstream>             // file input/output
#include <string>              // string data type

using namespace std;

class CornerGrocer {
private:
    int input;
    string inputFilePath = "CS210_Project_Three_Input_File.txt";
    string backupFilePath = "frequency.dat";  // Backup file path

    void menuDisplay() {
        // displays the menu options
        cout << "|===============================================================================|" << endl;
        cout << "|                             MENU SELECTION OPTIONS                            |" << endl;
        cout << "|===============================================================================|" << endl;
        cout << "|                                                                               |" << endl;
        cout << "|                      (1) List All Purchased Items                             |" << endl;
        cout << "|                      (2) Search for a Specific Item                           |" << endl;
        cout << "|                      (3) Create a File and Histogram for All Items            |" << endl;
        cout << "|                      (4) Exit the Program                                     |" << endl;
        cout << "|                                                                               |" << endl;
        cout << "|===============================================================================|" << endl;
    }

    void menuOne() {
        ifstream inputFile("CS210_Project_Three_Input_File.txt");  // opens the input file stream

        if (!inputFile.is_open()) {
            // checks if the file failed to open
            cout << "Failed to open the file." << endl;
            return;
        }

        string userInput;
        cout << "Options: Spinach, Radishes, Potatoes, Pears, Peas, Broccoli, Cranberries, Cucumbers, Peaches, Zucchini" << endl;
        cout << "Cantaloupe, Beets, Pumpkins, Apples, Cauliflower, Onions, Yams, Celery, Limes, Garlic" << endl;
        cout << "~ Enter the Item You Wish to Look For: " << endl;

        cin >> userInput;  // reads user input

        unordered_map<string, int> wordCount;  // map to store word frequencies
        string word;
        while (inputFile >> word) {
            wordCount[word]++;  // increments the word's frequency
        }

        inputFile.close();  // closes the input file stream

        int frequency = wordCount[userInput];  // retrieves the frequency of the user's input
        cout << "Frequency of " << userInput << ": " << frequency << endl;

        // Backup the word frequencies to the backup file
        ofstream backupFile(backupFilePath);
        for (const auto& pair : wordCount) {
            backupFile << pair.first << " " << pair.second << endl;
        }
        backupFile.close();

        cout << "Data backed up to " << backupFilePath << endl;
    }

    void menuTwo() {
        ifstream inputFile("CS210_Project_Three_Input_File.txt");  // opens the input file stream

        if (!inputFile.is_open()) {
            // checks if the file failed to open
            cout << "Failed to open the file." << endl;
            return;
        }

        unordered_map<string, int> wordCount;  // map to store word frequencies
        string word;
        while (inputFile >> word) {
            wordCount[word]++;  // increments the word's frequency
        }

        inputFile.close();  // closes the input file stream

        for (const auto& pair : wordCount) {
            cout << "~ " << pair.first << " " << pair.second << endl;  // prints each word and its frequency
        }
    }

    void menuThree() {
        ifstream inputFile("CS210_Project_Three_Input_File.txt");  // opens the input file stream

        if (!inputFile.is_open()) {
            // checks if the file failed to open
            cout << "Failed to open the file." << endl;
            return;
        }

        unordered_map<string, int> wordCount;  // map to store word frequencies
        string word;
        while (inputFile >> word) {
            wordCount[word]++;  // increments the word's frequency
        }

        inputFile.close();  // closes the input file stream

        for (const auto& pair : wordCount) {
            cout << "~ " << pair.first << " ";  // prints each word
            for (int i = 0; i < pair.second; i++) {
                cout << "*";  // prints asterisks equal to the word's frequency
            }
            cout << endl;
        }
    }

public:
    void run() {
        while (input != 4) {
            menuDisplay();  // displays the menu
            cin >> input;   // reads user input

            if (input == 1) {
                menuOne();  // executes menu option one
            }
            else if (input == 2) {
                menuTwo();  // executes menu option two
            }
            else if (input == 3) {
                menuThree();  // executes menu option three
            }
        }
    }
};

int main() {
    CornerGrocer grocer;
    grocer.run();  // starts the program

    return 0;
}