#include<iostream>
using namespace std;

// Function to perform iteration 
int iterativeFunction(int n) {
    for(int i = 0; i < n; i++) {
        cout << ": " << i + 1 << endl;
    }
    return 0;
}

int main() {
    int n;
    cout << "Enter the number of iterations: ";
    cin >> n;

    iterativeFunction(n);

    return 0;
}