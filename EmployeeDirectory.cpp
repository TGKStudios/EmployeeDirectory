// EmployeeDirectory.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct employee
{
	unsigned short int age, ID, yearsEmployed;
	std::string name, role;
};

class buildEmployee
{
private:
	std::vector<employee> employeeDatabase;
	int lptr, rptr, count;
public:
	buildEmployee():lptr(0), rptr(0), count(0)
	{}
	template <typename T, typename U>
	void getInput()
	{
		employee *emp = new employee;
		T temp;
		U temp2;
		std::cout << "Enter employee age...\n";
		std::cin >> temp;
		if (!std::cin) {std::cout << "invlid input, exiting.\n"; exit(0);}
		else if (temp < 18) { std::cout << "That is too young to work here! Please try again.\n"; std::cin >> temp; }
		else if (temp > 90) { std::cout << "That is too old to work here! Please try again.\n"; std::cin >> temp; }
		else { emp->age = temp; }

		std::cout << "Enter employee ID Number\n";
		std::cin >> temp;

		if (!std::cin) { std::cout << "invlid input, exiting.\n"; exit(0); }
		else { emp->ID = temp; }

		std::cout << "Enter the employee years of employement.\n";
		std::cin >> temp;

		if (!std::cin) { std::cout << "invlid input, exiting.\n"; exit(0); }
		else if (temp > 80) { std::cout << "That doesn't seem correct. Please try again.\n"; std::cin >> temp; }
		else { emp->yearsEmployed; }

		std::cin.clear();
		std::cin.ignore();
		std::cout << "Enter the employee name.\n";
		std::getline(std::cin, temp2);
		emp->name = temp2;
		std::cout << "Enter the role of the employee.\n";
		std::getline(std::cin, temp2);
		emp->role = temp2;
		addEmployee(emp);
	}

	
	void addEmployee(employee *employed)
	{
		employeeDatabase.push_back(*employed);
		std::cout << "A new employee has been added to the vector\n";
		std::cout << "There are now " << employeeDatabase.size() << " employees\n";
		std::cout << "The directory of the last employee is index: " << employeeDatabase.size() - 1 << "\n";
	}
	void removeEmployee(std::string Name)
	{
		for (int i = 0; i < employeeDatabase.size(); i++)
		{
			std::transform(employeeDatabase[i].name.begin(), employeeDatabase[i].name.end(), employeeDatabase[i].name.begin(), ::toupper);
			std::transform(Name.begin(), Name.end(), Name.begin(), ::toupper);

			if (employeeDatabase[i].name == Name)
			{

				employeeDatabase.erase(employeeDatabase.begin() + i);
				std::cout << "The employee has been removed.";
			}
			else if (i == employeeDatabase.size())
			{
				std::cout << "Name was not found!";
				return;
			}
		}
	}

};

int main()
{
	int t = 0;
	int input;
	std::cout << "How many employees do you have to add to the database?\n";
	std::cin >> input;
	
	buildEmployee be;
	while (t < input)
	{
		be.getInput<int, std::string>();
		t++;
	}
	be.removeEmployee("Jim");
	

}
