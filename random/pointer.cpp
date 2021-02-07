#include<iostream>
using namespace std;

int main(void) {
    int *pc, c;

    c = 22;
    cout << "Address of c: " << (void *) &c << endl;
    cout << "Value of c: " << c << endl ;

    pc = &c;
    cout << "Address of c: " << (void *) pc << endl;
    cout << "Content of c: " << * pc << endl;

    c = 11;
    cout << "Address of c: " << (void *) pc << endl;
    cout << "Content of c: " << * pc << endl;

    *pc = 2;
    cout << "Address of c: " << (void *) &c << endl;
    cout << "Value of c: " << c << endl;

    return 0;
}