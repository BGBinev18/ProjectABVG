//*** HOTEL ***//

#include <iostream>
using namespace std;

struct STAFF {                                                            
    string employeeName;                                                    
    string employeePosition;                                                
    int employeeSalary;                                                     
    char employeePhone[14];                                                 
    float monthlyIncome;                                                    
    int id;                                                                 
};

int generateId(int& maxId)                                                  
{
    return maxId++;
}

void insertStaff(STAFF employee[], int& employeeCount, int& maxId)
{
    cout << "\nEnter the name of employee:" << endl;
    cin >> employee[employeeCount].employeeName;
    cout << "Enter position:" << endl;
    cin >> employee[employeeCount].employeePosition;
    cout << "Enter the phone number:" << endl;
    cin >> employee[employeeCount].employeePhone, 13;
    cout << "Enter the salary in $:" << endl;
    cin >> employee[employeeCount].employeeSalary;
    cout << "Enter monthly income:" << endl;
    cin >> employee[employeeCount].monthlyIncome;
    employee[employeeCount].id = generateId(maxId);
    employeeCount++;

}

void showStaff(STAFF employee)
{
    cout << "\nName of employee:" << employee.employeeName << endl;
    cout << "Position of employee:" << employee.employeePosition << endl;
    cout << "Salary of employee:" << employee.employeeSalary << endl;
    cout << "Phone of the employee:" << employee.employeePhone << endl;
    cout << endl;
}

void showAllStaff(STAFF employee[], int employeeCount)
{
    cout << "\nYou have entered the following employee:" << endl;
    for (int i = 0; i < employeeCount; i++)
    {
        showStaff(employee[i]);
    }
}

void showEmployeeIncomeOver(STAFF* employee, int& employeeCount, int income)
{
    for (int i = 0; i < employeeCount; i++)
    {
        if (employee[i].monthlyIncome > income)
        {
            showStaff(employee[i]);
        }
    }
}

void showEmployeeIncomeOverMenu(STAFF* employee, int& employeeCount)



{
    int income;
    cout << "Enter monthly income:";
    cin >> income;
    showEmployeeIncomeOver(employee, employeeCount, income);
}

int getEmployeeById(STAFF* employee, int& employeeCount, int id)
{

    for (int i = 0; i < employeeCount; i++)
    {
        if (employee[i].id == id)
        {
            return i;
        }
    }
    return -1;
}

void deleteEmployee(STAFF* employee, int& employeeCount, int id)
{
    int index = getEmployeeById(employee, employeeCount, id);

    for (int i = index; i < employeeCount - 1; i++)
    {
        employee[i] = employee[i + 1];



    }
    employeeCount--;
}

void deleteEmployeeMenu(STAFF* employee, int& employeeCount, int& maxId)
{
    int id;
    cout << "Enter employeeID(it's start from zero to one,two....):";
    cin >> id;
    deleteEmployee(employee, employeeCount, id);
}

bool showMainList(STAFF* employee, int& employeeCount, int& maxId/* int index, STAFF newEmployee*/)
{
    int choice;
    cout << "Main List:" << endl;
    cout << "1. Add new person to the staff" << endl;
    cout << "2. Show staff" << endl;
    cout << "3. Delete someone of the staff" << endl;
    cout << "4. Show all employees with a monhtly income above the set" << endl;
    cout << "9. Exit" << endl;
    cout << "Enter your choice:" << endl;
    cin >> choice;




    switch (choice)
    {
    case 1:
        insertStaff(employee, employeeCount, maxId);
        break;
    case 2:
        showAllStaff(employee, employeeCount);
        break;
    case 3:

        deleteEmployeeMenu(employee, employeeCount, maxId);
        break;
    case 4:
        showEmployeeIncomeOverMenu(employee, employeeCount);
        break;
    case 9:
        return false;
    }
    return true;
}

int main()
{
    int employeeCount = 0;
    STAFF employee[10];
    int maxId = 0;
    bool doShowMenu = true;
    do {
        showMainList(employee, employeeCount, maxId);

    } while (doShowMenu);
}