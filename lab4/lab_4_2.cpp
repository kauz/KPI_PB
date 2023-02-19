#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

double arithmetic_mean(vector<int>& arr) {
    double sum = accumulate(arr.begin(), arr.end(), 0);
    double mean = sum / arr.size();
    return mean;
}

double median(vector<int>& arr) {
    vector<int> sorted_arr = arr;
    sort(sorted_arr.begin(), sorted_arr.end());
    double median;
    int size = sorted_arr.size();
    if (size % 2 == 0) {
        median = (sorted_arr[size/2 - 1] + sorted_arr[size/2]) / 2.0;
    } else {
        median = sorted_arr[size/2];
    }
    return median;
}

vector<double> convert_array(vector<int>& arr) {
    double mean = arithmetic_mean(arr);
    double median_val = median(arr);
    vector<double> result(arr.size());
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] % 2 == 0) {
            result[i] = arr[i] / mean;
        } else {
            result[i] = arr[i] / median_val;
        }
    }
    return result;
}

int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    vector<double> result = convert_array(arr);
    cout << "The converted array is: ";
    for (int i = 0; i < n; i++) {
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
