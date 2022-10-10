#include <iostream>

void toUpperCaseString(std::string& wordToUpper) {

	for (int i = 0; i < wordToUpper.length(); i++) {
		char c = wordToUpper[i];
		if (wordToUpper[i] < 97)
			c += 32;

		wordToUpper[i] = c;
	}

}

void toUpperCaseLetter(char& c) {

	if (c < 97)
		c += 32;

}
