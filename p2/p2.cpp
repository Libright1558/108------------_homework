#include <iostream>
#include <string>
using namespace std;

class set {
int arr[256];
public:
friend void getset(set &s);
set();
set(char c);
void addchar(char c);
set operator+(const set &obj);
set operator*(const set &obj);
set operator-(const set &obj);
bool operator>=(const set &obj);
};

void getset(set &s) {
    char c[80];
    int e = 0;
    for(int i = 0; i <= 255; i++) {
        if(s.arr[i] == 1) {
            c[e] = char(i);
            e++;
        }
    }
    for(int n = 0; n < e; n++) {
        cout << c[n];
    }
}

set::set() {
    for(int i = 0; i <= 255; i++) {
        arr[i] = 0;
    }
}

set::set(char c) {
    int x = int(c);
    arr[x] = 1;
}

void set::addchar(char c) {
    int x = int(c);
    arr[x] = 1;
}

set set::operator+(const set &obj) {
    set result;
    for(int a = 0; a <= 255; a++) {
        if(arr[a] == 0 && obj.arr[a] == 0) {
            result.arr[a] = 0;
        }
        else {
            result.arr[a] = 1;
        }       
    }
    return result;
}

set set::operator*(const set &obj) {
    set result;
    for(int a = 0; a <= 255; a++) {
        if(arr[a] == 1 && obj.arr[a] == 1) {
            result.arr[a] = 1;
        }
        else {
            result.arr[a] = 0;
        }
    }
    return result;
}

set set::operator-(const set &obj) {
    set result;
    set alt;
    for(int a = 0; a <= 255; a++) {
        if(obj.arr[a] == 0) {
            alt.arr[a] = 1;
        }
        else {
            alt.arr[a] = 0;
        }
    }
    for(int a = 0; a <= 255; a++) {
        if(arr[a] == 1 && alt.arr[a] == 1) {
            result.arr[a] = 1;
        }
        else {
            result.arr[a] = 0;
        }
    }
    return result;
}

bool set::operator>=(const set &obj) {
    set result;
    for(int a = 0; a <= 255; a++) {
        if(arr[a] == 1 && obj.arr[a] == 1) {
            result.arr[a] = 1;
        }
        else {
            result.arr[a] = 0;
        }
    }
    int a = 0;
    while(result.arr[a] == obj.arr[a]) {
        a++;
        if(a > 255) {
            return true;
        }
    }
    return false;
}

string Iscontain(bool b) {
    string s;
    if(b == true) {
        s = " contains ";
    }
    else {s = " does not contain ";}
    return s;
}

string Isin(bool b) {
    string s;
    if(b == true) {
        s = " is in ";
    }
    else {s = " is not in ";}
    return s;
}

int main() {
    set obj1[20], obj2[20], obj3[20], objc[20];
    string str1, str2;
    int n;
    char x[20];

    cin >> n;
    cin.ignore();
    for(int c = 0; c < n; c++) {
        getline(cin, str1);
        getline(cin, str2);
        for(auto i = str1.begin(); i != str1.end(); i++) {
            obj1[c].addchar(*i);
        }
        for(auto i = str2.begin(); i != str2.end(); i++) {
            obj2[c].addchar(*i);
        }
        cin >> x[c];
        objc[c].addchar(x[c]);
        cin.ignore();
    }

    for(int c = 0; c <= n - 1; c++) {
        cout<< endl;
        
        cout << "Test Case " << c + 1 << ":" << endl;
        cout << "A" << ":" << "{";
        getset(obj1[c]); 
        cout << "}" << endl;

        cout << "B" << ":" << "{";
        getset(obj2[c]); 
        cout << "}" << endl;

        obj3[c] = obj1[c] + obj2[c];
        cout << "A+B" << ":" << "{"; 
        getset(obj3[c]); 
        cout << "}" << endl;

        obj3[c] = obj1[c] * obj2[c];
        cout << "A*B" << ":" << "{"; 
        getset(obj3[c]); 
        cout << "}" << endl;

        obj3[c] = obj1[c] - obj2[c];
        cout << "A-B" << ":" << "{";
        getset(obj3[c]); 
        cout << "}" << endl;

        obj3[c] = obj2[c] - obj1[c];
        cout << "B-A" << ":" << "{"; 
        getset(obj3[c]); 
        cout << "}" << endl;
        
        bool a = obj1[c] >= obj2[c];
        cout << "A" << Iscontain(a) << "B" << endl;

        bool b = obj2[c] >= obj1[c];
        cout << "B" << Iscontain(b) << "A" << endl;

        bool e = obj1[c] >= objc[c];
        cout << "'" << x[c] << "'" << Isin(e) << "A" << endl;

        bool d = obj2[c] >= objc[c];
        cout << "'" << x[c] << "'" << Isin(d) << "B" << endl;

        cout << endl;
        cout << endl;
    }
    return 0;
}