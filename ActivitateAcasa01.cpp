#include <iostream>
using namespace std;	// se foloseste ca sa nu mai scriem de fiecare data std::cout , std::cin, std::endl


int main()
{
	int favourite_number;
	cout << "Enter your favourite number between 1 and 100: ";
	cin >> favourite_number;

	cout << "Amazing!" << favourite_number << " is my favourite number too!" << endl;

	return 0;

}