#include<queue>
using namespace std;

queue<int> manager(queue<int> q1, queue<int> q2) {
	queue<int> q;

	int num_of_bus = 0, total_num = 0;

	while (total_num < 10) {

		if (!q1.empty() && num_of_bus < 4) {
			q.push(q1.front());
			q1.pop();
			num_of_bus++;
			total_num++;
		}
		else if (num_of_bus == 4 && !q2.empty()) {
			q.push(q2.front());
			q2.pop();
			num_of_bus = 0;//reset to 0
			total_num++;
		}
		else {//q1 is empty or q2 is empty
			//the rest bus in q1 is less than 4, then q1 is empty
			//when q2 is not empty, 
			//use trunk as bus to make the num_of_bus get 4.
			while (total_num < 10 && num_of_bus < 4 && !q2.empty()) {
				q.push(q2.front());
				q2.pop();
				num_of_bus++;//trunk is used as bus
				total_num++;
			}
			//when q2 is empty or num_of_bus is 4(faked)
			num_of_bus = 0;//rest, to make bus on board
		}

		//when all vehicles are put together ,still less than 10
		if (q1.empty() && q1.empty()) {
			total_num = 11;//exit while
		}

	}


	return q;
}