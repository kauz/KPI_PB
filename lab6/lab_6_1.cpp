#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cout << "Enter the number of lines: ";
    cin >> n;

    vector<string> lines(n);
    cout << "Enter " << n << " lines of text:\n";
    cin.ignore(); // ignore any newline characters left in the input buffer

    for (int i = 0; i < n; i++) {
        getline(cin, lines[i]);
    }

    string alignment;
    do {
        cout << "Align left or right (L/R)? ";
        getline(cin, alignment);
    } while (alignment != "L" && alignment != "R");

    int max_width = 0;
    for (const string& line : lines) {
        max_width = max(max_width, static_cast<int>(line.length()));
    }

    if (alignment == "L") {
        for (const string& line : lines) {
            string trimmed_line = line;
            size_t start_pos = line.find_first_not_of(' ');
            if (start_pos != string::npos) {
                trimmed_line = line.substr(start_pos);
            }
            cout << trimmed_line << '\n';
        }
    } else {
        for (const string& line : lines) {
            string trimmed_line = line;
            size_t end_pos = line.find_last_not_of(' ');
            if (end_pos != string::npos) {
                trimmed_line = line.substr(0, end_pos + 1);
            }
            int num_spaces = max_width - static_cast<int>(trimmed_line.length());
            cout << string(num_spaces, ' ') << trimmed_line << '\n';
        }
    }

    return 0;
}
