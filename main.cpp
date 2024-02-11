// This c++ program converts decimal numbers to binary, hexadecimal, and Binary Coded Decimal.

#include<iostream>
#include <stack>
#include <fstream>

using std::stack;
using std::ofstream;
using std::cout;


// Constant base values
const int HEXADECIMAL_BASE = 16;
const int BINARY_BASE = 2;
const int BINARY_BIT_LENGTH = 4;
const int HEX_BIT_LENGTH = 2;
const int BCD_DIGIT_LENGTH = 3;
const int INPUT_SET_LENGTH = 255;


int main()
{
	return 0;
}


void decimalToBinary(int input, ofstream& outputFile)
{
	int tempVar = input;
	stack<int> binaryStack; // This stack holds the binary value
	int binaryIndex = 0; // Index variable for formatting

	// This loop divids by base 2 and the puts the remainders in a stack
	// to get the binary value
	while (tempVar > 0)
	{
		// Adding the remainder to the stack
		// The last digit of the binary number is added first
		binaryStack.push(tempVar % BINARY_BASE);

		// incrementing index by 1
		binaryIndex += 1;

		// Dividing by base to get the next value
		tempVar = tempVar / BINARY_BASE;
	}

	// Making the binary number the correct bit length
	while (binaryIndex < BINARY_BIT_LENGTH * 2)
	{

		binaryStack.push(0); // Default value for formatting
		binaryIndex += 1;   // incrementing index by 1

	}

	// Resetting index
	binaryIndex = 0;

	// Print loop prints until the stack is empty
	while (!binaryStack.empty())
	{
		// Adding a space after 4 digits are printed
		if (binaryIndex == 4)
		{
			cout << " "; // output formatting for console
			outputFile << " "; // output formatting for output file
		}

		// Printing top value and removing it from the stack
		cout << binaryStack.top(); // binary output for console
		outputFile << binaryStack.top(); // binary output for output file
		binaryStack.pop(); // Removing top value from stack

		// incrementing index by 1 counting how digits have been printed
		binaryIndex += 1;
	}

	return;

}// End of decimalToBinary function