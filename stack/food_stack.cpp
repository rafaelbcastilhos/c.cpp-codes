#include <iostream>
#include <stack>
using namespace std;

int main(){
    cout << "\nFood Stack" << endl;

    stack<int> mystack;

    mystack.push(4);
    mystack.push(2);
    mystack.push(1);
    mystack.push(3);

    cout << "Stack: " << endl;
    while(mystack.empty() == false){
        int topnum = mystack.top();
        cout << topnum << " ";
        mystack.pop();
    }
	cout << endl;

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

	foodstack.push(new Food(false, 1, "Apple"));
	foodstack.push(new Food(true, 2, "Banana"));
	foodstack.push(new Food(true, 5, "Eclair"));
	foodstack.push(new Food(true, 3, "Chocolate"));
	foodstack.push(new Food(true, 4, "French Fries"));

	cout << endl << "Printed Food stack: " << endl;
	int counter = 0;
	while(foodstack.empty() == false){
		counter += 1;
		Food* food = foodstack.top();
		foodstack.pop();
		cout << "Food number " << counter << " has " << food->quantity << " of " << food->name << " and it ";
		if(food->tastesGood == true)
			cout << "tastes good!" << endl;
		else
			cout << "tastes bad!" << endl;
    }

	return 0;
}