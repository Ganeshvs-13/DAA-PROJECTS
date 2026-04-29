#include <iostream>
#include <cstring>
using namespace std;

#define MAX 256

int shiftTable[MAX];

void shiftTableCreation(char pattern[])
{
    int m = strlen(pattern);

    for(int i = 0; i < MAX; i++)
        shiftTable[i] = m;

    for(int j = 0; j < m - 1; j++)
        shiftTable[(int)pattern[j]] = m - 1 - j;
}

int horspool(char text[], char pattern[])
{
    int n = strlen(text);
    int m = strlen(pattern);

    int i = m - 1;

    while(i < n)
    {
        int k = 0;

        while(k < m && pattern[m - 1 - k] == text[i - k])
            k++;

        if(k == m)
            return i - m + 1;
        else
            i = i + shiftTable[(int)text[i]];
    }

    return -1;
}

int main()
{
    char text[100], pattern[100];

    cout << "Enter the text: ";
    cin >> text;

    cout << "Enter the pattern: ";
    cin >> pattern;

    shiftTableCreation(pattern);

    int pos = horspool(text, pattern);

    if(pos >= 0)
        cout << "Pattern found at position: " << pos + 1 << endl;
    else
        cout << "Pattern not found" << endl;

    return 0;
}