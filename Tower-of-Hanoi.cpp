/*
	Basic permutation algorithm but with the help of "set" for automatically dealing with multiple solutions and sorting it for us.
*/
#include <iostream>
#include <set>
#include <vector>

void search(int len, std::string input, int* used, std::vector<char>& out, std::set<std::string>& answerList) {
	if (len == input.length()) {
		std::string temp = "";
		for (int i = 0; i < out.size(); ++i) {
			temp += out[i];
		}

		answerList.insert(temp);
		return;
	}

	for (int i = 0; i < input.length(); ++i) {
		if (!used[i]) {
			used[i] = 1;
			out.push_back(input[i]);
			search(len + 1, input, used, out, answerList);
			out.pop_back();
			used[i] = 0;
		}
	}
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::string input;

	std::cin >> input;

	std::vector<char> out;
	std::set<std::string> answerList;
	int used[8] = {0};

	search(0, input, used, out, answerList);

	std::cout << answerList.size() << '\n';
	for (auto it = answerList.begin(); it != answerList.end(); ++it) {
		std::cout << *it << '\n';
	}
}
