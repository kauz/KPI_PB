#include <string>
#include <iostream>
#include <stdio.h>


using namespace std;

string intToEngLocale(int number);
string intToUkrLocale(int number);

int main() {
  int x;

  cout << "Input value of x\n";
  cin >> x;

  if (x > 5) {
    return 1;
  }

  cout << "en: " << intToEngLocale(x) << " \n";
  cout << "ua: " << intToUkrLocale(x) << " \n";

  return 0;
}

string intToEngLocale(int number) {
  switch (number) {
    case 1: return "one";
    case 2: return "two";
    case 3: return "three";
    case 4: return "four";
    case 5: return "five";
    default: return "";
  }
}
string intToUkrLocale(int number) {
    switch (number) {
    case 1: return "один";
    case 2: return "два";
    case 3: return "три";
    case 4: return "чотири";
    case 5: return "п'ять";
    default: return "";
  }
}
