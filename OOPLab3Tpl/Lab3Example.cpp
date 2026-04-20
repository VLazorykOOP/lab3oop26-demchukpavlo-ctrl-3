#include <iostream>
using namespace std;

const int MAX = 200;

void task1() {
    double A[MAX], B[MAX];
    int N, i, nB = 0;

    cout << "Enter N: ";
    cin >> N;

    cout << "Enter array A:\n";
    for (i = 0; i < N; i++) {
        cin >> A[i];
    }

    for (i = 0; i < N; i++) {
        if (A[i] > 0) {
            B[nB++] = A[i];
        }
    }

    cout << "Result array B:\n";
    for (i = 0; i < nB; i++) {
        cout << B[i] << " ";
    }
    cout << endl;
}

void task2() {
    int A[50][50];
    int n, m;

    cout << "Enter rows and cols: ";
    cin >> n >> m;

    cout << "Enter matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> A[i][j];

    int min = A[0][0];

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (A[i][j] < min)
                min = A[i][j];

    cout << "Min element = " << min << endl;
}

int main() {
    int choice;

    do {
        cout << "\n===== MENU =====\n";
        cout << "1 - Task 1\n";
        cout << "2 - Task 2\n";
        cout << "0 - Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
        case 1: task1(); break;
        case 2: task2(); break;
        }

    } while (choice != 0);

    return 0;
}