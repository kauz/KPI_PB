#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;

int main() {
  float x;
  int a;
  double y;

  cout << "Input value of x\n";
  cin >> x;
  cout << "Input value of a\n";
  cin >> a;


  if (x > 0.5 && a == -2) {
    y = log(pow(x, 2) + 1) + (pow(x, 3) + 1);
  } else {
    y = a * sin(x) - cos(a * x);
  }

  cout << "x=" << x << " " << "a=" << a << " " << "y=" << y << '\n';

  return 0;
}
