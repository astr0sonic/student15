#include "rpn.h"
#include <string>
#include <stack>
using namespace std;

double calculateRPN(const std::string& expr) {
	stack<double> st;
	string l = "";
	for (int i = 0; i < expr.size(); i++) {
		char c = expr[i];
		if (c <= '9' && c >= '0') l += c;
		if (c == ' ' && !l.empty()) {
			st.push(stod(l));
			l = "";
		}
		if (c == '+' || c == '-' || c == '*' || c == '/') {

			double a = st.top();
			st.pop();
			double b = st.top();
			st.pop();
			switch (c) {
			case '+':
				st.push(a + b);
				break;
			case '-':
				st.push(b - a);
				break;
			case '*':
				st.push(a * b);
				break;
			case '/':
				st.push(b / a);
				break;
			}
		}
	}
	return st.top();
}
