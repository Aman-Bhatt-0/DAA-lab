#include <iostream>
#include <algorithm>

using namespace std;

// Function to generate the next lexicographically greater permutation
bool next_permutation(string &s) {
    int n = s.size();
    
    // Find the largest index k such that s[k] < s[k + 1]
    int k = -1;
    for (int i = 0; i < n - 1; ++i) {
        if (s[i] < s[i + 1]) {
            k = i;
        }
    }
    
    // If no such index exists, return false
    if (k == -1) {
        return false;
    }
    
    // Find the largest index l greater than k such that s[k] < s[l]
    int l = -1;
    for (int i = k + 1; i < n; ++i) {
        if (s[k] < s[i]) {
            l = i;
        }
    }
    
    // Swap s[k] with s[l]
    swap(s[k], s[l]);
    
    // Reverse the sequence from s[k + 1] up to and including the final element s[n]
    reverse(s.begin() + k + 1, s.end());
    
    return true;
}

// Function to print all permutations of a string in lexicographic order
void all_permutations(string s) {
    sort(s.begin(), s.end()); // Sort the string initially
    
    do {
        cout << s << endl; // Print the current permutation
    } while (next_permutation(s));
}

int main() {
    string input_string;
    cout << "Enter a string: ";
    cin >> input_string;

    cout << "All permutations in lexicographic order:" << endl;
    all_permutations(input_string);

    return 0;
}
