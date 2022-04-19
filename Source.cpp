// Amanda Violet Moore
// SNHU CS 210 Project 3

#include <Python.h>
#include <iostream>
#include <Windows.h>
#include <cmath>
#include <string>
#include <iomanip>
#include <fstream>
#include <vector>

using namespace std;

/*Description:
		To call this function, simply pass the function name in Python that you wish to call.
Example:
		callProcedure("printsomething");
Output:
		Python will print on the screen: Hello from python!
Return: 
		None
*/
void CallProcedure(string pName)
{
	char* procname = new char[pName.length() + 1];
	std::strcpy(procname, pName.c_str());

	Py_Initialize();
	PyObject* my_module = PyImport_ImportModule("CS210_Starter_PY_Code");
	PyErr_Print();
	PyObject* my_function = PyObject_GetAttrString(my_module, procname);
	PyObject* my_result = PyObject_CallObject(my_function, NULL);

	delete[] procname;
}

/*
Description:
		To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
		int x = callIntFunc("PrintMe", "Test");
Output:
		Python will print on the screen:
			You sent me: Test
Return: 
		100 is returned to the C++
*/
int callIntFunc(string proc, string param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	char* paramval = new char[param.length() + 1];
	std::strcpy(paramval, param.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python Interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(z)", paramval);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean
	delete[] procname;
	delete[] paramval;

	return _PyLong_AsInt(presult);
}

/*
Description:
		To call this function, pass the name of the Python function you wish to call and the string parameter you want to send
Example:
		int x = callIntFunc("doublevalue", 5);
Return:
		25 is returned to the C++
*/
int callIntFunc(string proc, int param)
{
	char* procname = new char[proc.length() + 1];
	std::strcpy(procname, proc.c_str());

	PyObject* pName, * pModule, * pDict, * pFunc, * pValue = nullptr, * presult = nullptr;
	// Initialize the Python interpreter
	Py_Initialize();
	// Build the name object
	pName = PyUnicode_FromString((char*)"CS210_Starter_PY_Code");
	// Load the module object
	pModule = PyImport_Import(pName);
	// pDict is a borrowed reference
	pDict = PyModule_GetDict(pModule);
	// pFunc is also a borrowed reference
	pFunc = PyDict_GetItemString(pDict, procname);
	if (PyCallable_Check(pFunc))
	{
		pValue = Py_BuildValue("(i)", param);
		PyErr_Print();
		presult = PyObject_CallObject(pFunc, pValue);
		PyErr_Print();
	}
	else
	{
		PyErr_Print();
	}
	//printf("Result is %d\n", _PyLong_AsInt(presult));
	Py_DECREF(pValue);
	// Clean up
	Py_DECREF(pModule);
	Py_DECREF(pName);
	// Finish the Python Interpreter
	Py_Finalize();

	// clean 
	delete[] procname;

	return _PyLong_AsInt(presult);
}

// outputs menu options to user
void printMenu()
{
	cout << setw(50) << setfill('*') << "" << endl;
	cout << setw(14) << "" << "Corner Grocer Records" << setw(15) << "" << endl;
	cout << "1. Displays daily items purchased" << endl;
	cout << "2. Displays how many times a specific item was purchased" << endl;
	cout << "3. Displays a histogram of daily items purchased" << endl;
	cout << "4. Exits program" << endl;
	cout << "\nPlease enter your menu selection as number 1, 2, 3, or 4" << endl;
}

// opens file created in Python and modifies the output to have *'s instead of numbers
int printHistogram()
{
	vector<string> vecItems;
	vector<int> vecTimesSold;
	ifstream itemFile;
	string item;
	int timesSold;

	itemFile.open("frequency.dat");

	// checks that the file was opened
	if (!itemFile.is_open())
	{
		cout << "Could not open the file frequency.dat" << endl;
		return 1;
	}
	else
	{
		// loop goes through each line of the file and builds a vector for item names and a vector for times the item was sold
		while (!itemFile.eof())  
		{
			itemFile >> item >> timesSold;
			vecItems.push_back(item);
			vecTimesSold.push_back(timesSold);
		}
	}

	// closes file
	itemFile.close();

	// outputs each item's name and times it was sold represented by *'s
	for (int i = 0; i < vecItems.size(); i++)
	{
		cout << vecItems.at(i) << " " << setw(vecTimesSold.at(i)) << setfill('*') << "" << endl;
	}
}

int main()
{
	int menuCommand;       
	string menuLoop = "y";
	string groceryItem;

	while (menuLoop == "y") 
	{
		// gets the user input and assigns to appropiate menu command
		printMenu();
		cin >> menuCommand;
		if (menuCommand == 1)
		{
			CallProcedure("DailyItemsPurchased"); // calls Python function
		}
		else if (menuCommand == 2)
		{
			cout << "Enter the item's name (case sensitive): " << endl;
			cin >> groceryItem;
			cout << groceryItem << ": ";
			cout << callIntFunc("TimesItemPurchased", groceryItem) << endl; // calls Python function and passes user input
		}
		else if (menuCommand == 3)
		{
			CallProcedure("WriteFile"); // calls Python function
			printHistogram();           // calls histogram function (C++)
		}
		// closes program 
		else if (menuCommand == 4)
		{
			cout << "Program closed." << endl;
			break;
		}
		// prints error statement, returns user to menu
		else if (menuCommand <= 0 || menuCommand >= 5)
		{
			cout << "Invalid Command. Please enter your menu selection as number 1, 2, 3, or 4." << endl;
		}

	}

	return 0;
}