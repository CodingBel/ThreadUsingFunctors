#include <iostream>
#include <thread>

// This program illustrates how we could create threads using fucntors
// we could also overload the operator() function. 

class Abel{
	char printChar; 
public: 
	void operator()(int num1, int num2) {
		for (int i = num1; i < num2; i++) {
			std::cout << "@"; 
		}
	}

	void operator()(int num1, int num2, int num3) {
		if (num1 < num2)
			printChar = '&';
		else
			printChar = '%'; 

		for (int i = num1; i < num3; i++)
			std::cout << printChar; 
	}
}; 

class Bel {
public: 
	void operator()(int num1, int num2) {
		for (int i = num1; i < num2; i++) {
			std::cout << "#"; 
		}
	}
};

int main() {
	Abel obj1; 
	Bel obj2; 
	Abel obj3; 

	std::thread Thread1(obj1, 0, 10);
	std::thread Thread2(obj2, 0, 10);
	std::thread Thread3(obj3, 4, 1, 12);

	Thread1.join(); 
	Thread2.join(); 
	Thread3.join(); 

	return 0;
}