#include "lzw.h"
#include <map>

using namespace std;

std::vector<int> compress(const std::string& s) {
	map<string, int> codes;
	for (int i = 0; i < 256; i++) {
		codes[{char(i)}] = i;
	}
	vector<int> encode;
	string x = { s[0] };
	for (int i = 1; i < s.size(); i++) {
		char y = s[i];
		string xy = x + y;
		if (codes[xy]) {
			x = xy;
		}
		else {
			encode.push_back(codes[x]);
			codes[xy] = codes.size();
			x = y;
		}
	}
	encode.push_back(codes[x]);
	return encode;
}

std::string decompress(const std::vector<int>& compressed) {
	map<int, string> codes;
	int codesSize = 256;
	for (int i = 0; i < codesSize; i++) {
		codes[i] = char(i);
	}
	string decode;
	string x(1, compressed[0]);
	decode = x;

	for (int i = 1; i < compressed.size(); i++) {
		int y = compressed[i];
		string entryStr;
		if (codes.find(y) != codes.end()) {
			entryStr = codes[y];
		}
		else if (y == codesSize) {
			entryStr = x + x[0];
		}

		decode += entryStr;
		codes[codesSize++] = x + entryStr[0];
		x = entryStr;
	}
	return decode;
}
