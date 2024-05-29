#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to print the optimal parenthesization of the matrix chain product
void printOptimalParenthesization(vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i;
    } else {
        cout << "(";
        printOptimalParenthesization(s, i, s[i][j]);
        printOptimalParenthesization(s, s[i][j] + 1, j);
        cout << ")";
    }
}

// Function to compute the matrix chain order
int matrixChainOrder(vector<int>& p, int n) {
    vector<vector<int>> m(n, vector<int>(n, 0));
    vector<vector<int>> s(n, vector<int>(n, 0));

    for (int l = 2; l < n; l++) {
        for (int i = 1; i < n - l + 1; i++) {
            int j = i + l - 1;
            m[i][j] = INT_MAX;
            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Optimal Parenthesization: ";
    printOptimalParenthesization(s, 1, n - 1);
    cout << endl;

    return m[1][n - 1];
}

int main() {
    int n;
    cout << "Enter number of matrices: ";
    cin >> n;
    vector<pair<int,int>> take(n);
     vector<int> p(n + 1);
         cout << "Enter dimensions: ";
    for(int i=0;i<n;i++){
        cin>>take[i].first>>take[i].second;
        p[i]=take[i].first;
    }
   p[n] = take[n - 1].second;
   
cout<<"the matrix i converted it into:"<<endl;
    for (int i = 0; i <= n; i++) {
        cout<<p[i]<<" ";
    }

    int minCost = matrixChainOrder(p, n + 1);
    cout << "Minimum number of multiplications: " << minCost << endl;

    return 0;
}
