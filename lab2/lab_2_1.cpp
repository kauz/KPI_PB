#include <iostream>
#include <stdio.h>
#include <iterator>
#include <vector>


/*
Дано натуральне число n. Обчислити добуток перших n спів-
множників:

1/2 * 3/4 * 5/6 * ...
*/

int main() {
  int x;
  std::vector<float> values;
  float y = 1;

  std::cout << "Input value of x\n";
  std::cin >> x;

  for (int i = 1; values.size() < x; i++) {
    if (i % 2 != 0) {
      float iR = (float)i / (float)(i + 1);
      values.push_back(iR);
      y *= iR;
    }
  }

  std::copy(values.begin(),values.end(),std::ostream_iterator<float>(std::cout, " " ));

  std::cout << "\ny=" << y << '\n';

  return 0;
}
