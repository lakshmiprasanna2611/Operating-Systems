#include <stdio.h>
#include <stdlib.h>

// Define the structure for employee details
struct Employee {
    int id;
    char name[50];
    float salary;
};

// Function to add a new employee record to the file
void addEmployee(FILE *file) {
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    // Move the file pointer to the end of the file
    fseek(file, 0, SEEK_END);

    // Write the employee details to the file
    fwrite(&emp, sizeof(struct Employee), 1, file);

    printf("Employee added successfully!\n");
}

// Function to display all employee records from the file
void displayEmployees(FILE *file) {
    struct Employee emp;

    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    printf("\nEmployee Details:\n");
    printf("ID\tName\tSalary\n");

    // Read and display each employee record
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        printf("%d\t%s\t%.2f\n", emp.id, emp.name, emp.salary);
    }
}

// Function to search for an employee by ID
void searchEmployee(FILE *file) {
    struct Employee emp;
    int searchID;

    printf("Enter Employee ID to search: ");
    scanf("%d", &searchID);

    // Move the file pointer to the beginning of the file
    fseek(file, 0, SEEK_SET);

    // Search for the employee by ID
    while (fread(&emp, sizeof(struct Employee), 1, file) == 1) {
        if (emp.id == searchID) {
            printf("\nEmployee Details:\n");
            printf("ID\tName\tSalary\n");
            printf("%d\t%s\t%.2f\n", emp.id, emp.name, emp.salary);
            return;
        }
    }

    printf("Employee with ID %d not found!\n", searchID);
}

int main() {
    FILE *employeeFile;

    // Open the file for random access
    employeeFile = fopen("employee.dat", "r+");

    if (employeeFile == NULL) {
        // If the file does not exist, create a new file
        employeeFile = fopen("employee.dat", "w+");
    }

    if (employeeFile == NULL) {
        fprintf(stderr, "Error opening file!\n");
        return 1;
    }

    int choice;

    do {
        // Display menu
        printf("\nEmployee Database Menu:\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee(employeeFile);
                break;
            case 2:
                displayEmployees(employeeFile);
                break;
            case 3:
                searchEmployee(employeeFile);
                break;
            case 4:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 4);

    // Close the file
    fclose(employeeFile);

    return 0;
}


/*
Employee Database Menu:
1. Add Employee
2. Display Employees
3. Search Employee
4. Exit
Enter your choice: 1
Enter Employee ID: 1
Enter Employee Name: harsha
Enter Employee Salary: 100000
Employee added successfully!

Employee Database Menu:
1. Add Employee
2. Display Employees
3. Search Employee
4. Exit
Enter your choice: 1
Enter Employee ID: 2
Enter Employee Name: lakshmi
Enter Employee Salary: 200000
Employee added successfully!

Employee Database Menu:
1. Add Employee
2. Display Employees
3. Search Employee
4. Exit
Enter your choice: 1
Enter Employee ID: teja
Enter Employee Name: Enter Employee Salary: 150000
Employee added successfully!

Employee Database Menu:
1. Add Employee
2. Display Employees
3. Search Employee
4. Exit
Enter your choice: 2

Employee Details:
ID      Name    Salary
4       ghjkl   85.00
1       harsha  100000.00
2       lakshmi 200000.00
1       teja    150000.00

Employee Database Menu:
1. Add Employee
2. Display Employees
3. Search Employee
4. Exit
Enter your choice: 3
Enter Employee ID to search: 2

Employee Details:
ID      Name    Salary
2       lakshmi 200000.00