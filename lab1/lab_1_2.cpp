#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>

using namespace std;

double calcA(double x);
double calcB(double x);
double calcC(double x);

int main() {
  double x;
  string allowedJobs = "ABC";
  char jobPicked;
  double jobTotal;
  double jobTaxes;
  double jobIncome;


  cout << "Specify the type of job\n";
  cin >> jobPicked;
  cout << "Input value of x\n";
  cin >> x;

  if (allowedJobs.find(jobPicked) == string::npos) {
    cout << "Job type must be one of the following - " << allowedJobs  << "\n";
    return 1;
  }

  if (jobPicked == 'A') {
    jobTotal = calcA(x);
  } else if (jobPicked == 'B') {
    jobTotal = calcB(x);
  } else {
    jobTotal = calcC(x);
  }

  double taxes = jobPicked == 'A' 
    ? 0.1
    : jobPicked == 'B'
    ? 0.15
    : 0.2;

  jobTaxes = jobTotal * taxes;

  cout << "Job total - " << jobTotal << "\n";
  cout << "Tax - " << taxes << "\n";
  cout << "Counted taxes - " << jobTaxes << "\n";
  cout << "Job income - " << jobTotal - jobTaxes << "\n";

  return 0;
}

double calcA(double x) {
  return 2 * sin(abs(2 * x)) * cos(2 * x) - 11.6 * sin(x / 0.4 - 1);
}

double calcB(double x) {
  return sin(abs(x)) / 0.1 + 9.4 * sin(3 * x - 2.5);
}

double calcC(double x) {
  return 10.8 * cos(pow(x, 2) / 1.13) * sin(x + 1.4);
}