#include <iostream>
#include <vector>
using namespace std;

class poly {
    public:
    class node {
    public:
        int coe, exp;
        node* next;

        node() {
            coe = 0;
            exp = 0;
            next = nullptr;
        }

        node(int c, int e) {
            coe = c;
            exp = e;
            next = nullptr;
        }
    };

    node* head;

    poly() {
        head = new node();
    }

    poly(int c, int e) {
        head = new node(c, e);
    }

    poly(const poly& other) {
        while(head != nullptr) {
            poly::node* d = head;
            head = head->next;
            delete d;
        }
        head = new node();
        node* curr = head;
        for (node* p = other.head->next; p != nullptr; p = p->next) {
            curr->next = new node(p->coe, p->exp);
            curr = curr->next;
        }
    }

    ~poly() {
        while(head != nullptr) {
            poly::node* d = head;
            head = head->next;
            delete d;
        }
    }

    poly operator+(const poly& b) {
        node* h1 = head->next;
        node* h2 = b.head->next;

        poly temp;
        node* iter = temp.head;
        while(h1 && h2) {
            if(h1->exp > h2->exp) {
                if(h1->coe != 0) {
                    iter->next = new node(h1->coe, h1->exp);
                    iter = iter->next;
                }
                h1 = h1->next;
            }
            else if(h1->exp < h2->exp) {
                if(h2->coe != 0) {
                    iter->next = new node(h2->coe, h2->exp);
                    iter = iter->next;   
                }
                h2 = h2->next;
            }
            else {
                int n = h1->coe + h2->coe;
                if(n != 0) {
                    iter->next = new node(n, h1->exp);
                    iter = iter->next;
                }
                h1 = h1->next;
                h2 = h2->next;
            }
        }

        while(h1) {
            if(h1->coe != 0) {
                iter->next = new node(h1->coe, h1->exp);
                iter = iter->next;
            }
            h1 = h1->next;
        }

        while(h2) {
            if(h2->coe != 0) {
                iter->next = new node(h2->coe, h2->exp);
                iter = iter->next;
            }
            h2 = h2->next;
        }

        if(temp.head -> next == nullptr) {
            temp.head -> next = new node(0,0);
        }

        return temp;
    }

    poly operator*(const poly& b) {
        poly result;

        node* h1 = head->next;
        node* h2 = b.head->next;

        
        while(h2 != nullptr) {
            poly temp;
            node* iter = temp.head;
            while(h1 != nullptr) {
                int m = (h1->coe) * (h2->coe);
                if(m != 0) {
                    iter->next = new node(m, h1->exp + h2->exp);
                    iter = iter->next;
                }
                h1 = h1->next;
            }
            
            if(result.head -> next == nullptr) {
                node* h = result.head;
                iter = temp.head->next;
                while(iter != nullptr) {
                    h->next = new node(iter->coe, iter->exp);
                    h = h->next;

                    iter = iter->next;
                }
            }
            else {
                poly sum = result + temp;
                node * curr = result.head->next;
                while(curr != nullptr) {
                    node* d = curr;
                    curr = curr->next;
                    delete d;
                }
                
                curr = sum.head->next;
                node* h = result.head;
                h->next = nullptr;
                while(curr != nullptr) {
                    h->next = new node(curr->coe, curr->exp);
                    h = h->next;
                    curr = curr->next;
                }
            }

            h1 = head->next;
            h2 = h2->next;
        }

        if(result.head -> next == nullptr) {
            result.head -> next = new node(0, 0);
        }

        return result;
    }
};


void del(poly::node* head) {
    poly::node* prev = head;
    poly::node* curr = prev->next;
    head->next = curr->next;
    delete curr;
}// delete node

void add(poly::node* head, int c, int e) {
    poly::node* prev = head;
    poly::node* curr = prev->next;
    prev->next = new poly::node(c, e);
    prev->next->next = curr;
}// add node

void insert(poly::node* head, int c, int e) {
    poly::node* i = head;
    while(i != nullptr) {
        if(!(i->next)) {
            add(i, c, e);
            return;
        }
        else if(i->next->exp < e) {
            add(i, c, e);
            return;
        }
        else if(i->next->exp == e) {
            i->next->coe += c;
            if(i->next->coe == 0) del(i);
            return;
        }
        i = i->next;
    }
}

void traverse_and_print(poly::node* head) {
    poly::node* i = head->next;
    while(i != nullptr) {
        cout << i->coe << " " << i->exp << endl;
        i = i->next;
    }
}



int main() {
    int P = -1, Q = -1;
    int coe = -1, exp = -1;
    vector<poly> pl;

    while(P != 0 || Q != 0) {
        poly A, B;

        cin >> P;
        
        if(P != 0) {
            for(int x = 0; x < P; x++) {
                cin >> coe;
                cin >> exp;
                
                insert(A.head, coe, exp);
            }
        }
        

        cin >> Q;
        
        if(Q != 0) {
            for(int x = 0; x < Q; x++) {
                cin >> coe;
                cin >> exp;
                
                insert(B.head, coe, exp);
            }
        }
        

        if(A.head->next == nullptr) {
            A.head->next = new poly::node(0, 0);
        }

        if(B.head->next == nullptr) {
            B.head->next = new poly::node(0, 0);
        }

        if(P != 0 || Q != 0) {
            pl.push_back(A);
            pl.push_back(B);
        }
    }

    for(int t = 1, v = 0; v + 1 < pl.size(); t++, v += 2) {
        cout << endl;
        cout << "CASE" << t << ":" << endl;
        cout << "ADD" << endl;
        poly C = pl[v] + pl[v + 1];
        traverse_and_print(C.head);
        cout << "MULTIPLY" << endl;
        poly D = pl[v] * pl[v + 1];
        traverse_and_print(D.head);
    }

    return 0;
}