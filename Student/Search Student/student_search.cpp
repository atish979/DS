#include <iostream>
#include <string>
using namespace std;

int main(){
   int studentID[5];
   int roll_no;


   cout<<"==========Available StudentID========== \n";
   cout<<"Enter 5 roll no.:\n";
   for (int i = 0;i<5; i++)
   {
     cin>>studentID[i];
   }
   
   cout<<"\nEnter roll no. to search: ";
   cin>>roll_no;

   for (int i = 0; i < 5; i++)
   {
       if (studentID[i] == roll_no)
       {
          cout<<"student Found! \n";
          return 0;
       }
   }
   cout<<"Student not found!.... \n";
   return 0;
}


