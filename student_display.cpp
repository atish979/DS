#include <iostream>
#include <string>
using namespace std;

int main(){
   int roll_no[5];

   cout << "=== Student Roll Number Entry System ===" << endl;
   
   for (int i = 0; i < 5; ++i) {
        cout << "Enter roll number for student " << (i + 1) << ": ";
        cin >> roll_no[i];
    }

   cout << "\n=== Displaying All Entered Roll Numbers ===" << endl;
   for (int i = 0; i < 5; ++i) {
        cout << "Student " << (i + 1) << " Roll No: " << roll_no[i] << endl;
    }

   return 0;
}
