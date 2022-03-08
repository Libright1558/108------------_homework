#include <iostream>
using namespace std;

//magic square - 3 
int masq3(int a, int b) {
    int arr3[3][3];
    int i = 0, j = 1;
    int k = 1;
    arr3[i][j] = k;
    int c, d;
    int m;

    while(k < 9) {
        m = 1;
        for(m = 1 ; m <= 2; m++) {
            c = i - 1;
            d = j - 1;
            if(c < 0) {
                c = 2;
            }
            if(d < 0) {
                d = 2;
            }   
            k++;
            i = c;
            j = d;
            arr3[i][j] = k;
        }
        if(k < 9){
            k++;
            i = i + 1;
            arr3[i][j] = k;
        }
    }
    return arr3[a][b];
}

//magic square - 5 
int masq5(int a, int b) {
    int arr5[5][5];
    int i = 0, j = 2;
    int k = 1;
    arr5[i][j] = k;
    int c, d;
    int m;

    while(k < 25) {
        m = 1;
        for(m = 1 ; m <= 4; m++) {
            c = i - 1;
            d = j - 1;
            if(c < 0) {
                c = 4;
            }
            if(d < 0) {
                d = 4;
            }   
            k++;
            i = c;
            j = d;
            arr5[i][j] = k;
        }
        if(k < 25){
            k++;
            i = i + 1;
            arr5[i][j] = k;
        }
    }
    return arr5[a][b];
}

//magic square - 7 
int masq7(int a, int b) {
    int arr7[7][7];
    int i = 0, j = 3;
    int k = 1;
    arr7[i][j] = k;
    int c, d;
    int m;

    while(k < 49) {
        m = 1;
        for(m = 1 ; m <= 6; m++) {
            c = i - 1;
            d = j - 1;
            if(c < 0) {
                c = 6;
            }
            if(d < 0) {
                d = 6;
            }   
            k++;
            i = c;
            j = d;
            arr7[i][j] = k;
        }
        if(k < 49){
            k++;
            i = i + 1;
            arr7[i][j] = k;
        }
    }
    return arr7[a][b];
}

//magic square - 9 
int masq9(int a, int b) {
    int arr9[9][9];
    int i = 0, j = 4;
    int k = 1;
    arr9[i][j] = k;
    int c, d;
    int m;

    while(k < 81) {
        m = 1;
        for(m = 1 ; m <= 8; m++) {
            c = i - 1;
            d = j - 1;
            if(c < 0) {
                c = 8;
            }
            if(d < 0) {
                d = 8;
            }   
            k++;
            i = c;
            j = d;
            arr9[i][j] = k;
        }
        if(k < 81){
            k++;
            i = i + 1;
            arr9[i][j] = k;
        }
    }
    return arr9[a][b];
}

int main() {
    for(int x = 0; x <= 2; x++) {
        cout << endl;
        for(int y = 0; y <= 2; y++) {
            cout << masq3(x, y) << " ";
        }
    }
    cout << endl;
    for(int x = 0; x <= 4; x++) {
        cout << endl;
        for(int y = 0; y <= 4; y++) {
            cout << masq5(x, y) << " ";
        }
    }
    cout << endl;

    for(int x = 0; x <= 6; x++) {
        cout << endl;
        for(int y = 0; y <= 6; y++) {
            cout << masq7(x, y) << " ";
        }
    }
    cout << endl;

    for(int x = 0; x <= 8; x++) {
        cout << endl;
        for(int y = 0; y <= 8; y++) {
            cout << masq9(x, y) << " ";
        }
    }
    cout << endl;

    return 0;
}