#include <iostream>
#include <string>
#include <cmath>
using namespace std;

class board {
    int init;
    int ** arr;

    public:
    board(int init);
    ~board();
    void set(int a, int j, int i);
    int checkarr(int j, int i) {
        int checkarr = arr[j][i];
        return checkarr;
    }
};

board::board(int in) {
    init = in;
    arr = new int * [init];
    for(int i = 0; i < init; i++) {
        arr[i] = new int[init];
    }
    for(int x = 0; x < init; x++) {
        for(int y = 0; y < init; y++) {
            arr[x][y] = 0;
        }
    }
}

board::~board() {
    for(int i= 0; i < init; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}

void board::set(int a, int j, int i) {
    arr[j][i] = a;
}

class knight {
    int i, j, k;
    
    public:
    knight();
    void set(int ii, int jj, int kk);
    void move(int attempt);
    void setk(int c);
    int checki() {
        return i;
    }
    int checkj() {
        return j;
    }
    int checkk() {
        return k;
    }
};

knight::knight() {
    i = 1;
    j = 1;
}

void knight::set(int ii, int jj, int kk) {
    i = ii;
    j = jj;
    k = kk;
}

void knight::move(int attempt) {
    switch(attempt / 1) {
        case 1:
        i = i - 2;
        j = j + 1;
        break;
        case 2:
        i = i - 1;
        j = j + 2;
        break;
        case 3:
        i = i + 1;
        j = j + 2;
        break;
        case 4:
        i = i + 2;
        j = j + 1;
        break;
        case 5:
        i = i + 2;
        j = j - 1;
        break;
        case 6:
        i = i + 1;
        j = j - 2;
        break;
        case 7:
        i = i - 1;
        j = j - 2;
        break;
        case 8:
        i = i - 2;
        j = j - 1;
        break;
    }
}

void knight::setk(int c) {
    k = c; 
}



class stack: private knight {
    knight arr[36];
    int top;

    public:
    stack();
    knight pop();
    void push(knight &kn);
};

stack::stack() {
    int top = -1; 
}

knight stack::pop() {
    knight k = arr[top];
    top--;
    return k;
}

void stack::push(knight &kn) {
    top++;
    arr[top].set(kn.checki(), kn.checkj(), kn.checkk());
}



int main() {
    for(int i = 2; i <= 7; i ++) {
        board b(i);
        knight gow;
        stack sta;
    
        int n = 1;
        b.set(1, gow.checkj(), gow.checki());
        for(int k = 1; k <= 8; k++) {
            gow.setk(k);
            sta.push(gow);
            gow.move(k);
            if(1 <= gow.checkj() && gow.checkj() <= i - 1 && 1 <= gow.checki() && gow.checki() <= i - 1 && b.checkarr(gow.checkj(), gow.checki()) == 0) {
                n++;
                b.set(n, gow.checkj(), gow.checki());
                k = 0;
            }
            else {
                gow = sta.pop();
                k = gow.checkk();
                while(k == 8) {
                    if(n > 1) {
                        b.set(0, gow.checkj(), gow.checki());
                        n--;
                        gow = sta.pop();
                        k = gow.checkk();
                    }
                    else if(n == 1) {
                        break;
                    }
                }
            }
        
            if(n >= pow(i - 1, 2)) {
                break;
            }
        }
        cout << "N = " << i - 1 << endl;
        for(int x = 1; x <= i - 1; x++) {
            cout << endl;
            
            if(n < pow(i - 1, 2) || n == 1) {
                cout << " no solution ";
                break;
            }
            for(int y = 1; y <= i - 1; y++) {
                cout << b.checkarr(y, x) << " ";
            }
        }
        cout << endl;
        cout << endl;
    }
    return 0;
}