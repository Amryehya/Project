#include <iostream>
#include"Menu.h"
using namespace std;
int main()
{ 
	cout << "The Program has started : \n";
	Menu z;
	z.displayMainMenu();
	z.getUserChoice();
	return 0;

}
