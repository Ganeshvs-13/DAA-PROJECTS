#include <iostream>
#include <vector>
using namespace std;

// Function to find fake coin index
int findFakeCoin(vector<int>& coins, int left, int right) {
    // Base case: only one coin
    if (left == right)
        return left;

    int mid = (left + right) / 2;

    // Calculate sum of left half
    int sumLeft = 0, sumRight = 0;

    for (int i = left; i <= mid; i++)
        sumLeft += coins[i];

    for (int i = mid + 1; i <= right; i++)
        sumRight += coins[i];

    // Compare sums
    if (sumLeft < sumRight)
        return findFakeCoin(coins, left, mid);      // fake in left
    else
        return findFakeCoin(coins, mid + 1, right); // fake in right
}

int main() {
    int n;
    cout << "Enter number of coins: ";
    cin >> n;

    vector<int> coins(n);

    cout << "Enter weights of coins:\n";
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int fakeIndex = findFakeCoin(coins, 0, n - 1);

    cout << "Fake coin found at position: " << fakeIndex + 1 << endl;
    cout << "Weight of fake coin: " << coins[fakeIndex] << endl;

    return 0;
}