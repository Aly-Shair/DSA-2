#include<iostream>
using namespace std;

void fun(int arr[][4], int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";    
        }
        cout << endl;
    }
}

int main() {
    int n = 3, m = 4;
    int arr[n][4] = {
                        {1, 2, 3, 4},
                        {2, 2, 3, 4},
                        {3, 2, 3, 4}
                  };
    fun(arr, n, m);
    return 0;
}

