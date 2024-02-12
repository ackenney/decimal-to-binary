// This c++ program converts decimal numbers to binary, hexadecimal, and Binary Coded Decimal.

#include<iostream>
#include <stack>
#include <fstream>

using std::stack;
using std::ofstream;
using std::cout;
using std::endl;


// Constant base values
const int HEXADECIMAL_BASE = 16;
const int BINARY_BASE = 2;
const int BINARY_BIT_LENGTH = 4;
const int HEX_BIT_LENGTH = 2;
const int BCD_DIGIT_LENGTH = 3;
const int INPUT_SET_LENGTH = 255;


// Prototype functions
void decimalToBinary(int x, ofstream& oFile);
void decimalToHexadecimal(int x, ofstream& Ofile);
void decimalToBinaryCodedDecimal(int x, ofstream& oFile);

int main()
{
	// Declaring stream variable
	ofstream outputFile;

	outputFile.open("Output"); // Opening output file

	// Header for console
	cout << "DECIMAL\t  " << "BINARY\t" << "HEXADECIMAL\t" << "BCD\n";

	// Header for output file
	outputFile << "DECIMAL\t  " << "BINARY\t" << "HEXADECIMAL\t" << "BCD\n";

	// This for loop tests each conversion function with input from 1 to 255
	for (int input = 0; input <= INPUT_SET_LENGTH; input++)
	{
		// Binary output
		cout << input << "\t  "; // Formatting output to console
		outputFile << input << "\t  "; // Formatting output to output file
		decimalToBinary(input, outputFile); // Function call

		// Hexadecimal output
		cout << "\t"; // Formatting output to console
		outputFile << "\t"; // Formatting output to output file
		decimalToHexadecimal(input, outputFile); // Function call

		// BCD output
		cout << "\t\t"; // Formatting output to console
		outputFile << "\t\t"; // Formatting output to output file
		decimalToBinaryCodedDecimal(input, outputFile); // Function call
		cout << endl; // Adding a line for formatting
		outputFile << endl;

	} // End of for loop 

	outputFile.close(); // closing file
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

void decimalToHexadecimal(int input, ofstream& outputFile)
{
	// Declaring variables
	int inputValue = input;
	int tempVar;
	int count = 0;
	stack<char> hexStack; // Stack to hold the hexadecimal digits

	while (inputValue > 0)
	{
		// Getting the remainder
		tempVar = inputValue % HEXADECIMAL_BASE;

		// Hexadecimal numbers go to 9 then user 'A' - 'F'
		// so if the remainder is less than 10 it gets added to the stack 
		// and isn't changed to a letter

		if (tempVar < 10)
		{
			hexStack.push(tempVar + 48);
			count += 1;
		}

		// If the remainder is 10 or greater the switch in this else statement
		// adds the correct character value to the stack
		else
		{

			switch (tempVar)
			{

			case 10:
				hexStack.push('A');
				count += 1;
				break;

			case 11:
				hexStack.push('B');
				count += 1;
				break;

			case 12:
				hexStack.push('C');
				count += 1;
				break;

			case 13:
				hexStack.push('D');
				count += 1;
				break;

			case 14:
				hexStack.push('E');
				count += 1;
				break;

			case 15:
				hexStack.push('F');
				count += 1;
				break;
			}
		}

		// Dividing by base to get the next value
		inputValue = inputValue / HEXADECIMAL_BASE;
	}

	// Making sure the stack has to values in it for formatting
	while (count < HEX_BIT_LENGTH)
	{
		hexStack.push('0'); // Default value
		count += 1; // Adding 1 to the number count
	}



	// Print loop prints until the stack is empty
	while (!hexStack.empty())
	{
		cout << hexStack.top(); // Printing top value to console
		outputFile << hexStack.top(); // Printing top value to output file
		hexStack.pop(); // Removing top value
	}

	return;
} // End of decimalToHexadecimal function


void decimalToBinaryCodedDecimal(int input, ofstream& outputFile)
{
	// Stack of each value that needs to be converted to binary
	stack<int> bcdStack;

	// Stack that hold the value of the binary number
	stack<int> binaryStack;
	int temp;
	int BCDIndex = 0;

	// This while loop will separate each digit and put it in a stack.
	// Each digit will be individually converted to binary to get the BCD code
	while (input > 0)
	{
		temp = input % 10; // Getting digit
		input = input / 10; // Going to next value
		bcdStack.push(temp); // adding the digit to the stack
		BCDIndex += 1; // counting how many numbers are added

	}

	// This while loop checks if the stack has at least three digits
	// If it doesn't then it will add a zero as a default 
	while (BCDIndex < BCD_DIGIT_LENGTH)
	{
		bcdStack.push(0); // default value
		BCDIndex += 1;	  // adding to the count BCD digits
	}

	//
	while (!bcdStack.empty())
	{
		// Temp is being set to one of the BCD values 
		// that needs to be conveted to binary
		temp = bcdStack.top();

		// Index variable to count the number of bits
		int binaryIndex = 0;

		// This while loop converts one of the BCD digits to binary
		while (temp > 0)
		{
			// Adding the remainder to the stack of binary values
			binaryStack.push(temp % BINARY_BASE);

			// incrementing index by 1 
			// Counting the number of bits in the binary value
			binaryIndex += 1;

			// Going to next value
			temp = temp / BINARY_BASE;
		}

		// Making the binary number the correct length
		while (binaryIndex < BINARY_BIT_LENGTH)
		{

			binaryStack.push(0); // default zero value
			binaryIndex += 1;	// counting how long the binary number is

		}

		// Print loop for binary number
		while (!binaryStack.empty())
		{
			// outputing top digit of stack
			cout << binaryStack.top(); // output to console
			outputFile << binaryStack.top(); // output to file
			binaryStack.pop();// going to the next digit
		}

		// Printing a space after every number
		cout << " ";  // output to console
		outputFile << " "; // output to file

		bcdStack.pop(); // Going to the next value to be converted
	}
} // End of decimalToBinaryCodedDecimal function