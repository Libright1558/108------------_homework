#include <iostream>
#include <vector>
using namespace std;


class fac {
    int ecof[17000];

public:
    fac();
    void getfacto(int d);
};


fac::fac() {
    for(int i = 0; i < 17000; i++) {
        ecof[i] = 0;
    }
}


void fac::getfacto(int d) {
    int i = 0;
    int temp = d;
    if(temp >= 1) {
    while(temp / 10 >= 1 || temp % 10 > 0) {
        ecof[i] = temp % 10;
        if(temp / 10 > 0) {
            temp = ecof[i + 1] = temp / 10;
        }
        else {
            temp = temp / 10;
        }
        i++;
        }    
    }

    for(d = d - 1; d >= 2; d--) {
        for(int a = 0; a <= i - 1; a++) {
            ecof[a] = ecof[a] * d;
        }
        for(int b = 0; b <= i - 1; b++) {
            if(ecof[b] / 10 >= 1 || ecof[b] % 10 >= 0) {
                if(ecof[b] >= 10 && ecof[b + 1] == ecof[i] && b + 1 == i) {
                    i++;
                }
                ecof[b + 1] = ecof[b + 1] + ecof[b] / 10;
                ecof[b] = ecof[b] % 10;
            }
        }  
    }
    for(int m = i - 1; m >= 0; m--) {
        cout << ecof[m];
    }
}



int main() {
    int x;
    vector<int> v;
    cin >> x;
    while(x != 0) {
        v.push_back(x);
        cin >> x;
    }
    for(int it = 0; it <= v.size(); it++) {
        cout << endl;
        for(int i = 1; i <= v[it]; i++) {
            fac obj1;
            cout << i << "!" << "=";
            obj1.getfacto(i);
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}