#include <iostream>
#include <cstring>
using namespace std;

#define SIZE 256

void badCharHeuristic(char pattern[], int m, int badchar[]) {
    for (int i = 0; i < SIZE; i++) {
        badchar[i] = -1;
    }

    for (int i = 0; i < m; i++) {
        badchar[(unsigned char)pattern[i]] = i;
    }
}

void boyerMoore(char text[], char pattern[]) {
    int m = strlen(pattern);
    int n = strlen(text);

    if (m == 0) {
        cout << "Pattern is empty";
        return;
    }

    int badchar[SIZE];
    badCharHeuristic(pattern, m, badchar);

    int s = 0;

    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            cout << "Pattern found at position: " << s + 1;
            return;
        } else {
            s += max(1, j - badchar[(unsigned char)text[s + j]]);
        }
    }

    cout << "Pattern not found";
}

int main() {
    char text[100], pattern[100];

    cout << "Enter text: ";
    cin >> text;

    cout << "Enter pattern: ";
    cin >> pattern;

    boyerMoore(text, pattern);

    return 0;
}
