#include<stack>
#include<iostream>

using namespace std;

bool Brackets_Check(char *str) {
	//char str[30] = "{9+[3-1*(9-8)]}*[(9/3)+2]";

	stack<char> stk;
	
	int i = 0;
	while (str[i] != '\0') {
		switch (str[i]) {
			//left side: into stack
			case '(':
				stk.push(str[i]);
				break;
			case '[':
				stk.push(str[i]); 
				break;
			case '{':
				stk.push(str[i]);
				break;
		
			//right side: check
			case ')':
				if (!stk.empty()) {
					if (stk.top() != '(') {
						return false;
					}
					else
						stk.pop();
				}
				else
					return false;
				break;
			case ']':
				if (!stk.empty()) {
					if (stk.top() != '[') {
						return false;
					}
					else
						stk.pop();
				}
				else
					return false;
				break;
			case '}':
				if (!stk.empty()) {
					if (stk.top() != '{') {
						return false;
					}
					else
						stk.pop();
				}
				else
					return false;
				break;
			default:
				break;
		}
		
		i++;
	}
	
	if (!stk.empty()) {//left side is more than right side
		cout << "not matched, left side is more." << endl;
		return false;
	}
	else {
		cout << "matched" << endl;
		return true;
	}
}

//int main(void) {
//	char str[30] = "{9+[3-1*(9-8)]}*[(9/3)+2]";
//	
//	bool result = Brackets_Check(str);
//	cout << result;
//	
//	return 0;
//}