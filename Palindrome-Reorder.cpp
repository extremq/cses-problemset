/*
* Firstly, such string can be created only and only if there is an even amount of characters.
* However, there can be an exception: if there is only one character which is appears an odd amount of times, then it's fine.
* Consider ABCCBDAA
* You could start by pairing A's, C's and B's,
* ABC**CBA
* Since you have more than one letter apearing an odd amount of times, there is no way you could fix A and D there.
* Consider the example ABCCBDA
* Now, this works because A, B AND C appear an even amount of times, allowing you to simply border the string with each letter.
* This algorithm counts the appearances of each letter, checks if it's valid and just places half of the letters alphabetically ordered, 
* then puts the odd character if there is one and finishes off with placing the other half of the letters in inverse alphabetical order.
* For example, take ABBCCDDDADDEE
* D appears an odd amount of times, we keep it.
* We iterate through the alphabet and place half of the letters.
* ABCDDE
* Then we append the odd D
* ABCDDED
* And we finish
* ABCDDEDEDDCBA
*/
#include <iostream>

int main()
{
	std::string input;
	long long int freq[100] = { 0 };
	bool hasOdd = false;
	char oddChar = 0;

	std::ios_base::sync_with_stdio(false);
	std::cin >> input;

	for (size_t i = 0; i < input.length(); ++i) {
		freq[(int)input[i]] += 1;
	}

	for (char c = 'A'; c <= 'Z'; ++c) {
		if (freq[(int)c] % 2) {
			if (hasOdd) {
				std::cout << "NO SOLUTION\n";
				return 0;
			}

			oddChar = c;
			hasOdd = true;
		}
	}

	int count;
	for (char c = 'A'; c <= 'Z'; ++c) {
		count = freq[(int)c] / 2;
		while (count--) {
			std::cout << c;
		}
	}

	if (hasOdd)
		std::cout << oddChar;

	for (char c = 'Z'; c >= 'A'; --c) {
		count = freq[(int)c] / 2;
		while (count--) {
			std::cout << c;
		}
	}
}
