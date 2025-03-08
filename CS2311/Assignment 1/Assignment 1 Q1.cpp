#include <iostream>
#include <limits>
using namespace std;

int main() {
beginning:
    cout << "Enter up to 5 positive integers, separated by blanks. To stop, enter -1 and press Enter: " << endl;

    int n = 0;
    int num;
    int smallest_num = 2147483647;
    bool validity = true;

    while (n <= 5) {
        if (!(cin >> num)) {
            cout << "Error: Non-integer value." << endl;
            validity = false;
            goto HAPPY;
        }
        if (num == -1) {
            if (n == 0) {
                validity = false;
                cout << "Error: Only -1." << endl;
                goto HAPPY;
            }
            else
                break;

        }
        if (num <= 0) {
            validity = false;
            cout << "Error: Non-positive integer." << endl;
            goto HAPPY;
        }
        if (num < smallest_num) {
            smallest_num = num;
        }
        n++;
    }
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    if (n > 5) {
        cout << "Error: Not ended with -1.\n";
        goto HAPPY;
    }
    else if (n == 5 && num != -1) {
        cout << "Error: Not ended with -1.\n";
        goto HAPPY;
    }
    else if (validity && n > 0) {
        cout << "The smallest positive number is: " << smallest_num << endl;
    }
    cout << "Do you want to find the smallest positive number again? (Y/N):  " << endl;

    char choice;
    cin >> choice;
    switch (choice) {
    case 'Y':
        goto beginning;
    case 'N': cout << "Thank you for using the program!" << endl;
        break;
    HAPPY:
    default: cout << "Thank you for using the program!" << endl;
        break;
    }
    return 0;
}