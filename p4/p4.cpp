#include <iostream>
using namespace std;

class board {
public:

    int** ChessBoard;
    int i, j; // chessboard size

    board(int i, int j) {
        ChessBoard = new int*[i];
        for(int x = 0; x < i; x++) {
            ChessBoard[x] = new int[j];
        }

        this->i = i;
        this->j = j;

        for(int x = 0; x < i; x++) {
            for(int y = 0; y < j; y++) {
                ChessBoard[x][y] = 0;
            }
        }
    }

    ~board() {
        for(int x = 0; x < i; x++) {
            delete [] ChessBoard[x];
        }
        delete [] ChessBoard;
    }
};


void direction(int d, int& i, int& j) {
    switch(d) {
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

void backtrack(int d, int& i, int& j) {
    switch(d) {
        case 1:
        direction(5, i, j);
        break;

        case 2:
        direction(6,i,j);
        break;

        case 3:
        direction(7,i,j);
        break;

        case 4:
        direction(8,i,j);
        break;

        case 5:
        direction(1,i,j);
        break;

        case 6:
        direction(2,i,j);
        break;

        case 7:
        direction(3,i,j);
        break;

        case 8:
        direction(4,i,j);
        break;
    }
}

void recursion(board& obj, int& pi, int& pj, int& count, int& bound) {
    if(pi >= obj.i || pj >= obj.j || pi < 0 || pj < 0) return;
    if(count > bound) return;
    if(obj.ChessBoard[pi][pj] != 0) return;

    obj.ChessBoard[pi][pj] = count;

    for(int n = 1; n <= 8; n++) {
        count++;
        direction(n, pi, pj);
        recursion(obj, pi, pj, count, bound);
        if(count > bound) return;
        backtrack(n, pi, pj);
        count--;
    }

    obj.ChessBoard[pi][pj] = 0;
}


int main() {
    for(int n = 1; n <= 6; n++) {
        int pi = 0, pj = 0, count = 1, bound = n * n;
        board obj(n, n);
        recursion(obj, pi, pj, count, bound);

        cout << endl;
        cout << "n = " << n << " :" << endl;
        cout << endl;
        if(count < bound) {
            cout << "no solution" << endl;
        }
        else {
            for(int y = 0; y < n; y++) {
                for(int x = 0; x < n; x++) {
                    cout << obj.ChessBoard[y][x];
                    if(x < n - 1) cout << ", ";
                }
                cout << endl;
            }
        }
    }

    return 0;
}