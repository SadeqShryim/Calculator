#include <iostream>
#include <string>

using namespace std;
void WelcomeMes() {
	cout << "----------------------------------------------------------------------" << endl;
	cout << "\t\t\tWELCOME TO THE CALCULATOR APP" << endl;
	cout << "----------------------------------------------------------------------" << endl;


}
void ExitMes() {
	cout << "----------------------------------------------------------------------" << endl;
	cout << "\t\t\tGOOD BYE!!!" << endl;
	cout << "----------------------------------------------------------------------" << endl;
}
int menu(){
	int choice;
	cout << "----------------------------------------------------------------------" << endl;
	cout << "1.) Addition" << endl; //2 
	cout << "2.) Subtraction" << endl; //3 
	cout << "3.) Multiplication" << endl; //4 
	cout << "4.) Division" << endl; //5 
	cout << "5.) Roots (Only Positive Numbers)" << endl;//6 
	cout << "6.) Power (Only Positive Numbers)" << endl;//7 
	cout << "7.) Percentage" << endl;//8 
	cout << "8.) Least Common Multiplier" << endl;//9 
	cout << "9.) Greatest Common Divisor" << endl;//10 done
	cout << "10.) Modulus (only positive numbers)" << endl;//11 
	cout << "11.) Quit" << endl; //
	cout << "----------------------------------------------------------------------" << endl << endl;
	cout << "Please Select an operation: ";
	cin >> choice;
	while (cin.fail()) {
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << "Invalid input!!!! Please enter an integer value..." << endl;
		cin >> choice;
	}
	if (choice > 0 && choice <= 11) {
		return choice;
	}
	else
		return -1;
}
bool Quit() {
	char choice;
	do {
		cout << "Would you like to quit or continue (Y or N): ";
		cin >> choice;
		choice = toupper(choice);
		while (cin.fail()) {
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input!!!! Please enter an integer value..." << endl;
			cin >> choice;
			if(!(choice == 'Y' or choice == 'N')){
				cout << "Invalid choice!!! Please enter Y or N to proceed..." << endl;
			}
		}	
	} while (!(choice == 'Y' or choice == 'N'));

	if (choice == 'N')
		return true;
	else if (choice == 'Y')
		return false;

}
void ComputeAdd(int amount) {
	double num, total = 0;

	for (int i = 0; i < amount; i++) {
		cout << i + 1 << ".) number, What is the value: ";
		cin >> num;
		total += num;
	}
	cout << "Your total: " << total << endl; 
}
void ComputeSub(int amount) {
	double num, total = 0;
	for (int i = 0; i < amount; i++) {
		cout << i + 1 << ".), what is the value: ";
		cin >> num;
		total -= num;
	}
	cout << "Your choose to subtract " << amount << " numbers, your total is: " << total << endl;
}
void ComputeMultiply(int amount) {
	double num, total = 1;

	for (int i = 0; i < amount; i++) {
		cout << i + 1 << ".) number, What is the value: ";
		cin >> num;
		total *= num;
	}
	cout << "Your total: " << total << endl;
}
void ComputeDiv(int amount) {
	double num, total = 1;
	for (int i = 0; i < amount; i++) {
		cout << i + 1 << ".) number, What is the value: ";
		cin >> num;
		total /= num;
	}
	cout << "Your total: " << total << endl;
}
float ComputePower(float num1, int num2 ) {
	float product = 1;
	
	for (int i = 0; i < num2; i++) {
		product *= num1;
	}
	return product;
}
void ComputeRoots(float root, int index) {
	float total, mid, low = 0.0, high = root;
	do {
		mid = (low + high) / 2;
		if (ComputePower(mid, index) > root)
			high = mid;
		else
			low = mid;

		mid = (low + high) / 2;
		total = (ComputePower(mid, index) - root);

		if (total < 0)
		{//grab absolute value
			total = -total;
		}

	} while (total > .00005); //accuracy of our root
	cout << root << " root " << index << " = " << mid << endl;
}
void ComputePercent() {
	double num1, num2, total;
	cout << "\nPlease enter your first number: ";
	cin >> num1;
	cout << "Please enter your second number: ";
	cin >> num2;
	total = (num2 / num1) * 100;
	cout << num2 << " is " << total << "% of " << num1 << endl;
}
int ComputeGCD(int x, int y)
{
	while (x != y)
	{
		if (x > y)
			x -= y;
		else
			y -= x;
	}
	return x;
}
void ComputeLCM(){
	int num1, num2;
	cout << "\nPlease enter your first number: ";
	cin >> num1;
	cout << "Please enter your second number: ";
	cin >> num2;
	cout << "The LCM of " << num1 << " and " << num2 << " is equal to " << (( num1 * num2) / ComputeGCD(num1, num2)) << endl;
}

void ComputeModulo() {
	int num1, num2, quotient;
	
	do {
		cout << "\nPlease enter your first number: ";
		cin >> num1;
	} while (num1 <= 0);
	do {
		cout << "Please enter your second number: ";
		cin >> num2;
	} while (num2 <= 0);
	quotient = num1 / num2;
	cout << num2 << " modulo " << num2 << " is equal to " << num1 - quotient * num2 << endl;

}



int main() {
	WelcomeMes();
	float num1, PowerTotal;
	int num2, num3, GCD, amount, choice = menu();
	bool v;
		
	cout << choice << endl;

	do {
		if (choice == -1) {
			cout << "You choose an invalid integer.... please try again!!!" << endl;
			choice = menu();
		}
		else if (choice == 1) {
			cout << "You choose Addition\nHow many numbers would you like to add: ";
			cin >> amount;
			ComputeAdd(amount);
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 2){
			cout << "You choose Subtraction\nHow many numbers would you like to subtract: ";
			cin >> amount;
			ComputeSub(amount);
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 3) {
			cout << "You choose Multiplication\nHow many numbers would you like to multiply: ";
			cin >> amount;
			ComputeMultiply(amount);
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 4) {
			cout << "You choose Division\nHow many numbers would you like to Divide: ";
			cin >> amount;
			ComputeDiv(amount);
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 5) {
			
			cout << "You choose Roots, it accepts real numbers for the base and int values for the root value" << endl;
			cout << "Enter first number: ";
			cin >> num1;
			cout << "Enter second number: ";
			cin >> num2;
			ComputeRoots(num1, num2);
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 6) {
			cout << "You choose the Power option, it accepts real numbers for the base and int values for the power value" << endl;
			cout << "Enter your first number: " << endl;
			cin >> num1;
			cout << "Enter your first number: " << endl;
			cin >> num2;
			PowerTotal = ComputePower(num1, num2);
			cout << "Total: " << PowerTotal << endl;
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 7) {
			cout << "You chose Percentage" << endl;
			ComputePercent();
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 8) {
			cout << "You chose LCM" << endl;
			ComputeLCM();
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 9) {
			cout << "You chose GCD" << endl;
			cout << "Please enter your first number: ";
			cin >> num2;
			cout << "Please enter your second number: ";
			cin >> num3;
			GCD = ComputeGCD(num2, num3);
			cout << "The GCM of " << num2 << " and " << num3 << " is equal to " << GCD << endl;
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
		else if (choice == 10) {
			cout << "You chose modulo" << endl;
			
			ComputeModulo();
			v = Quit();
			v ? choice = menu() : choice = 11;
		}
	} while (choice != 11);

	ExitMes();
	return 0;
}