// hiho #1014
#include <iostream>
#include <vector>
#include <string>

typedef struct Node *tp;
typedef struct Node Trie;
struct Node
{
	int cnt;
	char val;
	bool isEnd;
	std::vector<tp> children; // Faster Find: use map/array
};

tp findLetter(tp parent, char letter)
{
	for (auto p : parent->children)
		if (p->val == letter)
			return p;
	return nullptr;
}

void insertLetter(tp &parent, const char letter, const bool isEndOfLetter)
{
	tp n = new Node;
	n->cnt = 1;
	n->val = letter;
	n->isEnd = isEndOfLetter;

	parent->children.push_back(n);
	parent = n;
}

void insertString(tp tt, std::string s)
{
	tp parent = tt;
	parent->cnt += 1;
	for (size_t j = 0; j < s.size(); ++j)
	{
		tp pos = findLetter(parent, s[j]);
		if (pos != nullptr)
		{
			pos->cnt += 1;
			parent = pos;
			continue;
		}

		insertLetter(parent, s[j], j == s.size() - 1);
	}
}

int countPrefix(tp tt, std::string prefix)
{
	tp parent = tt, pos;
	for (auto c : prefix)
	{
		pos = findLetter(parent, c);
		if (pos == nullptr)
			return 0;
		parent = pos;
	}
	return pos->cnt;
}

int main()
{
	int N;
	std::cin >> N;
	tp tt = new Trie; // Assume a Dummy Head
	tt->cnt = 0;
	tt->isEnd = false;
	for (int i = 0; i < N; ++i)
	{
		std::string s;
		std::cin >> s;
		insertString(tt, s);
	}
	
	int M;
	std::cin >> M;
	for (int i = 0; i < M; ++i)
	{
		std::string prefix;
		std::cin >> prefix;
		std::cout << countPrefix(tt, prefix) << std::endl;
	}
}