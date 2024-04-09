#include "bracket.h"

bool isCorrect(string s) {
	bool flag = true;;
	for (int i = 0; i < s.size(); i++) {
		char c = s[i];
		string l = "";
		switch (c) {
		case '(':
			i++;
			c = s[i];
			while (c != ')' || !flag) {
				if (i >= s.size()) return false;
				if (c == '(') flag = false;
				if (c == ')' && !flag) flag = true;
				l += c;
				i++;
				c = s[i];
			}
			if (!isCorrect(l)) return false;
			break;
		case '[':
			i++;
			c = s[i];
			while (c != ']' || !flag) {
				if (i >= s.size()) return false;
				if (c == '[') flag = false;
				if (c == ']' && !flag) flag = true;
				l += c;
				i++;
				c = s[i];
			}
			if (!isCorrect(l)) return false;
			break;
		case '{':
			i++;
			c = s[i];
			while (c != '}' || !flag) {
				if (i >= s.size()) return false;
				if (c == '{') flag = false;
				if (c == '}' && !flag) flag = true;
				l += c;
				i++;
				c = s[i];
			}
			if (!isCorrect(l)) return false;
			break;
		case '<':
			i++;
			c = s[i];
			while (c != '>' || !flag) {
				if (i >= s.size()) return false;
				if (c == '<') flag = false;
				if (c == '>' && !flag) flag = true;
				l += c;
				i++;
				c = s[i];
			}
			if (!isCorrect(l)) return false;
			break;
		default:
			if (c == ')' || c == ']' || c == '}' || c == '>') return false;
			break;
		}
	}
	return true;
}

bool checkBrackets(const std::string& s) {
    return isCorrect(s);
}

