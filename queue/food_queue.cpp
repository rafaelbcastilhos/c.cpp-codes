#include <iostream>
#include <queue>
using namespace std;

int main(){
    cout << "\nFood Queue" << endl;

    queue<int> q;

    q.push(4);
    q.push(2);
    q.push(1);
    q.push(3);

    cout << "Printed queue: " << endl;
    while(q.empty() == false){
        int frontnum = q.front();
        cout << frontnum << " ";
        q.pop();
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

	queue<Food*> foodq;

	foodq.push(new Food(false, 1, "Apple"));
	foodq.push(new Food(true, 2, "Banana"));
	foodq.push(new Food(true, 5, "Eclair"));
	foodq.push(new Food(true, 3, "Chocolate"));
	foodq.push(new Food(true, 4, "French Fries"));

	cout << endl << "Printed Food queue: " << endl;
	int counter = 0;
	while(foodq.empty() == false){
		counter += 1;
		Food* food = foodq.front();
		foodq.pop();
		cout << "Food number " << counter << " has " << food->quantity << " of " << food->name << " and it ";
		if(food->tastesGood == true)
			cout << "tastes good!" << endl;
		else
			cout << "tastes bad!" << endl;
    }

	return 0;
}