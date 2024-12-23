#include <iostream>
#include <string>
#include <cctype>
#include <vector>

using namespace std;
string WelcomeMessage() {
	string message = "----------------------------------------------------------------------"
		"\n\t\tWELCOME TO THE CALULATOR PROJECT\n";
	return message;
}
string ExitMessage() {
	string message = "----------------------------------------------------------------------"
		"\n\t\tExited THE CALULATOR PROJECT\n"
		"----------------------------------------------------------------------";
	return message;
}

int menu(){
	char choice;
	do {
		cout << "----------------------------------------------------------------------" << endl;
		cout << "A.) Addition" << endl; //2 done
		cout << "B.) Subtraction" << endl; //3 done
		cout << "C.) Multiplication" << endl; //4 done
		cout << "D.) Division" << endl; //5 done
		cout << "E.) Roots (Only Positive Numbers)" << endl;//6 done
		cout << "F.) Power (Only Positive Numbers)" << endl;//7 done
		cout << "G.) Percentage" << endl;//8 done
		cout << "H.) Least Common Multiplier" << endl;//9 done
		cout << "I.) Greatest Common Divisor" << endl;//10 done
		cout << "J.) Modulus (only positive numbers)" << endl;//11 done
		cout << "K.) Display Function Execution" << endl; // 12 -- bonus
		cout << "L.) Quit" << endl; // reread directions and see what i have to do with this
		cout << "----------------------------------------------------------------------" << endl << endl;
		cout << "Please Select an operation: ";
		cin >> choice;
		choice = toupper(choice);
		while(cin.fail()){
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!!!! Please enter a character value..." << endl;
			cin >> choice;
		}
		if (choice == 'A')
			return 2;
		else if (choice == 'B')
			return 3;
		else if (choice == 'C')
			return 4;
		else if (choice == 'D')
			return 5;
		else if (choice == 'E')
			return 6;
		else if (choice == 'F')
			return 7;
		else if (choice == 'G')
			return 8;
		else if (choice == 'H')
			return 9;
		else if (choice == 'I')
			return 10;
		else if (choice == 'J')
			return 11;
		else if (choice == 'K')
			return 12;
	} while (choice != 'L');
	return 1;
}

float ComputeSum(const float &a, const float &b) {
	return a + b;
}
float ComputeSub(const float& a, const float& b) {
	return a - b;
}
float ComputeMul(const float& a, const float& b) {
	return a * b; 
}
float ComputeDiv(const float& a, const float& b) {
	return a / b;
}
float ComputePower(const float& x, const int& n)
{
	float numProduct = 1.0;
	int i;
	for (i = 0; i < n; i++)
		numProduct *= x;
	return numProduct;
}
float computeRoot(const float& root, const int& index)
{
	float tp, mid, low = 0.0, high = root;
	do {
		mid = (low + high) / 2;
		if (ComputePower(mid, index) > root)
			high = mid;
		else
			low = mid;
		mid = (low + high) / 2;
		tp = (ComputePower(mid, index) - root);
		if (tp < 0)
		{//grab absolute value
			tp = -tp;
		}
	} while (tp > .00005); //accuracy of our root
	return mid;
}
float ComputePerc(const float& a, const float& b) {
	float answer = (b / a) * 100;
	return answer;
}
int ComputeGCD(int a, int b)
{
	while (a != b)
	{
		if (a > b)
			a -= b;
		else
			b -= a;
	}
	return a;
}
int ComputeLCM(int a, int b)
{
	return ((a * b) / ComputeGCD(a, b));
}
float ComputeMod(const int a, const int b) {
	int quot = a / b;
	return a - static_cast<float>(quot) * b; 
}
void DisplayExec(const vector<pair<string, string>> &funcExecuteState) {

	int counter = 0;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "\t\tWELCOME TO THE CALULATOR PROJECT" << endl;
	cout << "----------------------------------------------------------------------" << endl;


	while (counter < funcExecuteState.size()) {
		cout << funcExecuteState[counter].first << " -- Function " << funcExecuteState[counter].second << endl;
		++counter;
	}
}

int main() {

	vector<pair<string, string>> funcExecuteState = {
		{ "A.) Addition", "Skipped" },
		{ "B.) Subtraction", "Skipped" },
		{ "C.) Multiplication", "Skipped" },
		{ "D.) Division", "Skipped" },
		{ "E.) Roots", "Skipped" },
		{ "F.) Power", "Skipped" },
		{ "G.)Percentage", "Skipped" },
		{ "H.) LCM", "Skipped" },
		{ "I.) GCD", "Skipped" },
		{ "J.) Modulus", "Skipped" }
	};
	int opp, num, num2, answerVal;
	float a, b, answer;

	cout << WelcomeMessage() << endl;
	
	do {
		opp = menu();
		if (opp == 2) {
			cout << "You chose Addition" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> a;
			cout << "Please enter your second number: ";
			cin >> b;
			answer = ComputeSum(a, b);
			cout << a << " + " << b << " = " << answer << endl << endl;
			funcExecuteState[0].second = "Executed";
		}
		else if (opp == 3) {
			cout << "You chose Subtraction" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> a;
			cout << "Please enter your second number: ";
			cin >> b;
			answer = ComputeSub(a, b);
			cout << a << " - " << b << " = " << answer << endl << endl;
			funcExecuteState[1].second = "Executed";
		}
		else if (opp == 4) {
			cout << "You chose Multiplication" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> a;
			cout << "Please enter your second number: ";
			cin >> b;
			answer = ComputeMul(a, b);
			cout << a << " * " << b << " = " << answer << endl << endl;
			funcExecuteState[2].second = "Executed";
		}
		else if (opp == 5) {
			cout << "You chose Division" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> a;
			cout << "Please enter your second number: ";
			cin >> b;
			answer = ComputeDiv(a, b);
			cout << a << " / " << b << " = " << answer << endl << endl;
			funcExecuteState[3].second = "Executed";
		}
		else if (opp == 6) {
			cout << "You chose the root" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> a;
			cout << "Please enter your second number: ";
			cin >> num;
			answer = computeRoot(a, num);
			cout << a << " root " << num << " = " << answer << endl << endl;
			funcExecuteState[4].second = "Executed";
		}
		else if (opp == 7) {
			cout << "You chose Power" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> a;
			cout << "Please enter your second number: ";
			cin >> num;
			answer = ComputePower(a, num);
			cout << a << "raised to the power of " << num << " is equal to " << answer << endl << endl;
			funcExecuteState[5].second = "Executed";
		}
		else if (opp == 8) {
			cout << "You chose Percentage" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> a;
			cout << "Please enter your second number: ";
			cin >> b;
			answer = ComputePerc(a, b);
			cout << b << " is " << answer << "% of " << a << endl << endl;
			funcExecuteState[6].second = "Executed";
		}
		else if (opp == 9) {
			cout << "You chose LCM" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> num;
			cout << "Please enter your second number: ";
			cin >> num2;
			answerVal = ComputeLCM(num, num2);
			cout << "The LCM of " << num << " and " << num2 << " is equal to " << answerVal << endl << endl;
			funcExecuteState[7].second = "Executed";
		}
		else if (opp == 10) {
			cout << "You chose GCD" << endl;
			cout << "\nPlease enter your first number: ";
			cin >> num;
			cout << "Please enter your second number: ";
			cin >> num2;
			answerVal = ComputeGCD(num, num2);
			cout << "The GCM of " << num << " and " << num2 << " is equal to " << answerVal << endl << endl;
			funcExecuteState[8].second = "Executed";
		}
		else if (opp == 11) {
			cout << "You chose modulo" << endl;
			do {
				cout << "\nPlease enter your first number: ";
				cin >> num;
			} while (num <= 0);
			do{
				cout << "Please enter your second number: ";
				cin >> num2;
			} while (num2 <= 0);
		 
			answer = ComputeMod(num, num2);
			cout << num << " modulo " << num2 << " is equal to " << answer << endl << endl;
			funcExecuteState[9].second = "Executed";
		}
		else if (opp == 12) {
			DisplayExec(funcExecuteState);
			cout << endl << endl;
		}
	} while (opp != 1);

	cout << ExitMessage() << endl;

	return 0;
}