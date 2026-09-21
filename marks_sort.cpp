#include <iostream>
using namespace std;

int main() {
    int marks[5];
    cout << "Enter 5 Marks:\n";
    
    // 1. Input: Read 5 Book IDs
    for (int i = 0; i < 5; i++) {
        cin >> marks[i]; // Fixed: was book[1], now correctly uses book[i]
    }
    
    // 2. Sorting: Bubble Sort algorithm
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4 - i; j++) { // Fixed: changed comma to semicolon
            if (marks[j] < marks[j + 1]) {
                int temp = marks[j];
                marks[j] = marks[j + 1];
                marks[j + 1] = temp; // Fixed: added missing semicolon
            }
        }
    }
    
    // 3. Output: Print the sorted array
    cout <<"\n student marks after sorting:\n"; // Fixed: added missing semicolon and space
    for (int i = 0; i < 5; i++) {
        cout << marks[i] << " ";
    }
    cout << endl;
    
    return 0;
}
