#include "kmp.h"
#include <vector>
#include <string>

std::vector<int> prefixFunction(std::string s) {
	std::vector<int> p(s.size());
	p[0] = 0;
	for (int i = 1; i < s.size(); i++) {
		int k = p[i - 1];
		while (k > 0 && s[i] != s[k]) {
			k = p[k - 1];
		}
		if (s[i] == s[k]) k++;
		p[i] = k;
	}
	return p;
}

std::vector<int> getIndices(const std::string& my_template, const std::string& text) {
	int pl = my_template.size();
	int tl = text.size();
	std::vector<int> answer;
	std::vector<int> pref = prefixFunction(my_template + "#" + text);
	int count = 0;
	for (int i = 0; i < tl; i++) {
		if (pref[pl + i + 1] == pl) answer.push_back(i - pl + 1);
	}
	return answer;
}
