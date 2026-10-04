#include <iostream>
using namespace std;

int main() {
    int book[5];
    cout << "Enter 5 Book IDs:\n";
    
    // 1. Input: Read 5 Book IDs
    for (int i = 0; i < 5; i++) {
        cin >> book[i]; 
    }
    
    // 2. Sorting: Bubble Sort algorithm
    for (int i = 0; i < 4; i++) { 
        for (int j = 0; j < 4 - i; j++) { 
            if (book[j] > book[j + 1]) {
                int temp = book[j];
                book[j] = book[j + 1];
                book[j + 1] = temp; 
            }
        }
    }
    
    // 3. Output: Print the sorted array
    cout << "\nBooks after sorting:\n"; 
    for (int i = 0; i < 5; i++) {
        cout << book[i] << " ";
    }
    cout << endl;
    
    return 0;
}
