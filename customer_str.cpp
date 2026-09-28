#include <iostream>
#include <string>
using  namespace std;

int main() {
  int queue[5];
  int front = 0;
  int rear = 0;
  
  cout<<"Enter 5 customer order numbers: \n";
  
  for (int i = 0; i < 5; i++)
  {
    cin >> queue[rear];
    rear++;
  }
  
  cout << "\nProcessing Orders:\n";

  while (front < rear)
  {
    cout << "processing Order: "<< queue[front] << endl;
    front++;
  }
  
  return 0;

}
