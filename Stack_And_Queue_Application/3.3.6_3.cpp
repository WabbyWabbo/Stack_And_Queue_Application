#include <iostream>
using namespace std;

double p(int n, double x) {
	double fv1 = 1, fv2 = 2 * x;
	if (n == 0)
		return fv1;

	int i;
	for (i = 2; i <= n; i++) {
		double temp = 2 * x * fv2 - 2 * (i -1) * fv1;
		fv1 = fv2;
		fv2 = temp;
	}
	return fv2;
}

//the answer
double p1(int n, double x) {
	struct stack {
		int no;
		double val;
	}st[50];
	int top = -1;
	double fv1 = 1, fv2 = 2 * x;
	//push
	for (int i = n; i >= 2; i--) {
		top++;
		st[top].no = i;
	}
	//pop
	while (top >= 0) {
		st[top].val = 2 * x * fv2 - 2 * (st[top].no - 1) * fv1;
		fv1 = fv2;
		fv2 = st[top].val;
		top--;
	}
	if (n == 0) {
		return fv1;
	}
	return fv2;
}

int main(void) {
	double result = p1(10, 1);
	cout << result;
}