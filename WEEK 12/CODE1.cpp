#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

pair<string, int> longest_common_subsequence(const string& seq1, const string& seq2) {
    int m = seq1.size();
    int n = seq2.size();
    vector<vector<int>> lcs_table(m + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (seq1[i - 1] == seq2[j - 1]) {
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;
            } else {
                lcs_table[i][j] = max(lcs_table[i - 1][j], lcs_table[i][j - 1]);
            }
        }
    }
    int lcs_length = lcs_table[m][n];
    string lcs_sequence(lcs_length, ' ');
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (seq1[i - 1] == seq2[j - 1]) {
            lcs_sequence[--lcs_length] = seq1[i - 1];
            --i;
            --j;
        } else if (lcs_table[i - 1][j] > lcs_table[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }

    return make_pair(lcs_sequence, lcs_table[m][n]);
}

int main() {
    string sequence1, sequence2;
    cout << "Enter sequence 1: ";
    cin >> sequence1;
    cout << "Enter sequence 2: ";
    cin >> sequence2;
    pair<string, int> result = longest_common_subsequence(sequence1, sequence2);
    cout << "Longest common subsequence: " << result.first << endl;
    cout << "Length: " << result.second << endl;
    return 0;
}
