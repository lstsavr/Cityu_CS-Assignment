#include<iostream>
using namespace std;

int main() {
    int a, b, c, d, n;
    cin >> a >> b >> c >> d >> n;
    int count = 0;
    for (int i = 0; i <= a; i++) {
        for (int j = 0; j <= b; j++) {
            for (int k = 0; k <= c; k++) {
                for (int l = 0; l <= d; l++) {
                    int sum = i * 1 + j * 3 + k * 5 + l * 10;
                    if (sum == n) {
                        count = count + 1;
                    }
                }
            }
        }
    }
    if (count > 0) 
        cout << count;
    else
        cout << "no";
}