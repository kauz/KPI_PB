#include <iostream>


using namespace std;

int euclid_gcd(int a, int b);

int main() {
  int sz;
  cout<<"Enter the size of array::";
  cin>>sz;

  int firstArray[sz];
  int secondArray[sz];
  int resultingArray[sz];

  for(int i=0;i<sz;i++) {
    firstArray[i]=rand() % 100;
    secondArray[i]=rand() % 100;
    resultingArray[i] = euclid_gcd(firstArray[i], secondArray[i]);
  }

  
  cout<<"\nElements of the array::" << endl;
  
  for(int i = 0; i < sz; i++)
    cout << "gcd(" << firstArray[i] << " + " << secondArray[i] << ") = " << resultingArray[i] << endl;
  return 0;
}

int euclid_gcd(int a, int b) {
  while (a != b) {
    if (a > b) {
       a -= b;
    } else {
       b -= a;
    }
  }
  return a;
}