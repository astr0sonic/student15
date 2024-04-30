#include "huffman.h"
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <unordered_map>

using namespace std;

struct Tree {
	char c;
	int count;
	Tree* left, * right;
};

struct comp
{
	bool operator()(Tree* l, Tree* r)
	{
		return l->count > r->count;
	}
};

void c(Tree* root, string s, unordered_map<char, string>& code) {
	if (root == nullptr) return;

	if (!root->left && !root->right) {
		code[root->c] = s;
	}

	encode(root->left, s + '0', code);
	encode(root->right, s + '1', code);
}

std::string encode(const std::string& s) {
	map<char, int> symbols;
	for (int i = 0; i < s.size(); i++) {
		symbols[s[i]]++;
	}
	priority_queue<Tree*, vector<Tree*>, comp> pq;

	for (auto pair : symbols) {
		Tree* tree = new Tree();
		tree->c = pair.first;
		tree->count = pair.second;
		tree->left = nullptr;
		tree->right = nullptr;
		pq.push(tree);
	}

	while (pq.size() != 1) {
		Tree* left = pq.top();
		pq.pop();
		Tree* right = pq.top();
		pq.pop();

		Tree* tree = new Tree();
		tree->c = '\0';
		tree->count = left->count + right->count;
		tree->left = left;
		tree->right = right;
		pq.push(tree);
	}

	Tree* root = pq.top();

	unordered_map<char, string> code;
	c(root, "", code);

	string codeBuild = "";
	for (int i = 0; i < s.size(); i++) {
		codeBuild += code[s[i]];
	}

	return codeBuild;
}

std::string decode(const std::string& encoded, std::map<char, std::string>& codes) {
	std::string decoded = "";
	string l = "";
	for (int i = 0; i < encoded.size(); i++) {
		l += encoded[i];
		for (auto pair : codes) {
			if (pair.second == l) {
				decoded += pair.first;
				l = "";
				break;
			}
		}
	}
	return decoded;
}
