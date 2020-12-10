#include <iostream>
#include <stack>
using namespace std;

int main() {
    cout << "\nFood Stack" << endl;
    
    stack<int> mystack;
    
    mystack.push(4);
    mystack.push(2);
    mystack.push(1);
    mystack.push(3);
    
	struct Food{
		bool tastesGood;
		int quantity;
		string name;
		
		Food(bool taste, int quant, string n){
			tastesGood = taste;
			quantity = quant;
			name = n;
		}
			
		Food(): tastesGood(false), quantity(0), name("Air") {}
    };
	
	stack<Food*> foodstack;
	return 0;
}