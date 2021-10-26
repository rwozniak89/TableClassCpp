#include <iostream>


class SpecialTable {       // The class
private:

	int* dynamicArray;
	int len = 0;
public:             // Access specifier
	void addValueOnEnd(int x)
	{
		if (len == 0) {
			dynamicArray = new int[1];
			dynamicArray[0] = x;
		}
		else {
			int newLen = len + 1;
			int* tempDynamicArray = new int[len];
			for (int i = 0; i < len; i++)
			{
				tempDynamicArray[i] = dynamicArray[i];
			}
			delete[] dynamicArray;
			dynamicArray = new int[newLen];
			for (int i = 0; i < len; i++)
			{
				dynamicArray[i] = tempDynamicArray[i];
			}
			dynamicArray[newLen - 1] = x;
			delete[] tempDynamicArray;
		}
		len++;
	}

	int checkEqualityOfAllValues()
	{
		std::cout << "checkEqualityOfAllValues" << std::endl;
		if (len == 0)
		{
			std::cout << "tablica jest pusta!";
			return -1;
		}
		if (len == 1)
		{
			std::cout << "w tablicy jest tylko 1 element!";
			return -1;
		}
		int before = dynamicArray[0];
		bool result = true;
		for (int i = 1; i < len; i++)
		{
			if (before != dynamicArray[i])
			{
				result = false;
				break;
			}
		}
		return result;
	}

	int checkIfValueExists(int x)
	{
		std::cout << "checkIfValueExists for " << x << std::endl;
		if (len == 0)
		{
			std::cout << "tablica jest pusta!";
			return -1;
		}
		for (int i = 0; i < len; i++)
		{
			if (x == dynamicArray[i])
			{
				return i;
			}
		}
		return -1;
	}

	int countValueExists(int x)
	{
		std::cout << "countValueExists for "<< x << std::endl;
		if (len == 0)
		{
			std::cout << "tablica jest pusta!";
			return -1;
		}
		int counter = 0;
		for (int i = 0; i < len; i++)
		{
			if (x == dynamicArray[i])
			{
				counter++;
			}
		}
		return counter;
	}

	int sumOfValues()
	{
		std::cout << "sumOfValues" << std::endl;
		if (len == 0)
		{
			std::cout << "tablica jest pusta!";
			return -1;
		}
		int sum = 0;
		for (int i = 0; i < len; i++)
		{
			sum += dynamicArray[i];
		}
		return sum;
	}

	void printAsVector()
	{
		std::cout << "printAsVector" << std::endl;
		if (len == 0)
		{
			std::cout << "tablica jest pusta!";
		}
		std::cout << "[";
		for (int i = 0; i < len; i++)
		{
			std::cout << dynamicArray[i];
			if (i < len - 1) std::cout << ",";
		}
		std::cout << "]" << std::endl;
	}

	void printTable()
	{
		for (int i = 0; i < len; i++)
		{
			std::cout << i << ":" << dynamicArray[i] << "; ";
		}
		std::cout << std::endl;
	}

	void clearMemmory() {
		delete[] dynamicArray;
	}
};


int main()
{
	std::cout << "Start!\n";

	SpecialTable myObj;
	std::cout << "TEST" << std::endl;
	std::cout << "ppkt1: Wstawianie elementow..." << std::endl;
	for (int i = 1; i <= 3; i++) myObj.addValueOnEnd(1);
	std::cout << "ppkt1: Wyswietlenie elementow..." << std::endl;
	myObj.printTable();
	int ppkt2a = myObj.checkEqualityOfAllValues();
	std::cout << "ppkt2: " << ppkt2a << std::endl;


	std::cout << "ppkt1: Wstawianie elementow..." << std::endl;
	for (int i = 1; i <= 12; i++) myObj.addValueOnEnd(rand() % 10);
	std::cout << "ppkt1: Wyswietlenie elementow..." << std::endl;
	myObj.printTable();
	int ppkt2b = myObj.checkEqualityOfAllValues();
	std::cout << "ppkt2b: " << ppkt2b << std::endl;
	

	int ppkt3a = myObj.checkIfValueExists(11);
	std::cout << "ppkt3a: " << ppkt3a << std::endl;
	myObj.addValueOnEnd(11);
	myObj.addValueOnEnd(12);
	myObj.printTable();
	int ppkt3b = myObj.checkIfValueExists(11);
	std::cout << "ppkt3b: " << ppkt3b << std::endl;
	
	
	int ppkt4a = myObj.countValueExists(1);
	std::cout << "ppkt4a: " << ppkt4a << std::endl;
	int ppkt4b = myObj.countValueExists(13);
	std::cout << "ppkt4b: " << ppkt4b << std::endl;

	int ppkt5 = myObj.sumOfValues();
	std::cout << "ppkt5: " << ppkt5 << std::endl;

	
	std::cout << "ppkt6: " << std::endl;
	myObj.printAsVector();


	myObj.clearMemmory();
	std::cout << "Stop!\n";
	return 0;
}