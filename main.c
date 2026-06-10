#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define total 100

typedef struct {
    int id;
    char name[50];
    char designation[30];
    float initial;
    float allowances;
    float deductions;
    float final_;
} Employee;


Employee employees[total];
int Total_employees = 0;
const char *FILENAME = "employees.txt";


void menu();
void add();
void calculate(int index);
void show_all();
void search();
void save_file();
void load_file();


int main() {
    int choice;
    load_file();
    printf("---Welcome to the Employee Payroll System---\n");

    do {
        menu();
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            while(getchar() != '\n');
            choice = -1;
        }
        switch (choice) {
            case 1:
                add();
                save_file();
                break;
            case 2:
                show_all();
                break;
            case 3:
                search();
                break;
            case 4:
                printf("\nExiting the Program. Goodbye!\n");
                break;
            default:
                printf("\nInvalid choice. Please select an option between 1 and 4.\n");
        }
    } while (choice != 4);

    return 0;
}

void menu() {
    printf("\n--- Main Menu ---\n");
    printf("1. Add New Employee\n");
    printf("2. View All Employees & Payroll\n");
    printf("3. Search Employee by ID\n");
    printf("4. Exit\n");
    printf("-----------------\n");
}

void calculate(int i) {
    employees[i].allowances = employees[i].initial * 0.10;
    employees[i].deductions = employees[i].initial * 0.05;
    employees[i].final_ = employees[i].initial +employees[i].allowances -employees[i].deductions;
}

void add() {
    if (Total_employees >= total) {
        printf("\nDatabase is full! Cannot add more employees.\n");
        return;
    }

    printf("\n--- Add New Employee ---\n");
    int newId;
    printf("Enter Employee ID: ");
    scanf("%d", &newId);
    while(getchar() != '\n');
    for (int i = 0; i < Total_employees; i++) {
        if (employees[i].id == newId) {
            printf("\nError: Employee with ID %d already exists.\n", newId);
            return;
        }
    }

    employees[Total_employees].id = newId;

    printf("Enter Name: ");
    fgets(employees[Total_employees].name, 50, stdin);
    employees[Total_employees].name[strcspn(employees[Total_employees].name, "\n")] = 0;

    printf("Enter Designation: ");
    fgets(employees[Total_employees].designation, 30, stdin);
    employees[Total_employees].designation[strcspn(employees[Total_employees].designation, "\n")] = 0;

    printf("Enter Basic Salary: ");
    scanf("%f", &employees[Total_employees].initial);
    calculate(Total_employees);

    printf("\nEmployee %s added successfully! Payroll calculated.\n", employees[Total_employees].name);
    Total_employees++;
}

void show_all() {
    if (Total_employees == 0) {
        printf("\nNo employee records to display.\n");
        return;
    }

    printf("\n -----------------------------------------------------------------------------------------------------------------------\n");
    printf("| %-4s | %-20s | %-15s | %-15s | %-15s | %-15s | %-15s |\n",
           "ID", "Name", "Designation", "Basic Salary", "Allowances", "Deductions", "Net Salary");
    printf(" -----------------------------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < Total_employees; i++) {
        printf("| %-4d | %-20s | %-15s | %-15.2f | %-15.2f | %-15.2f | %-15.2f |\n",
               employees[i].id,
               employees[i].name,
               employees[i].designation,
               employees[i].initial,
               employees[i].allowances,
               employees[i].deductions,
               employees[i].final_);
    }
    printf(" -----------------------------------------------------------------------------------------------------------------------\n");
}

void search() {
    if (Total_employees == 0) {
        printf("\nNo employee records to search.\n");
        return;
    }

    int searchId;
    printf("\n--- Search Employee ---\n");
    printf("Enter Employee ID to search: ");
    if (scanf("%d", &searchId) != 1) {
        printf("\n Invalid input.\n");
        while(getchar() != '\n');
        return;
    }

    for (int i = 0; i < Total_employees; i++) {
        if (employees[i].id == searchId) {
            printf("\nEmployee Found:\n");
            printf("  ID: %d\n", employees[i].id);
            printf("  Name: %s\n", employees[i].name);
            printf("  Designation: %s\n", employees[i].designation);
            printf("  Basic Salary: %.2f\n", employees[i].initial);
            printf("  Net Salary: %.2f\n", employees[i].final_);
            return;
        }
    }

    printf("\nEmployee with ID %d not found.\n", searchId);
}


void save_file() {
    FILE *file = fopen(FILENAME, "w");
    if (file == NULL) {
        printf("\nError opening file for saving!\n");
        return;
    }

    fprintf(file, "%d\n", Total_employees);
    for (int i = 0; i < Total_employees; i++) {
        fprintf(file, "%d,%s,%s,%.2f,%.2f,%.2f,%.2f\n",
                employees[i].id,
                employees[i].name,
                employees[i].designation,
                employees[i].initial,
                employees[i].allowances,
                employees[i].deductions,
                employees[i].final_);
    }

    fclose(file);
}


void load_file() {
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL) {
        Total_employees = 0;
        return;
    }
    if (fscanf(file, "%d\n", &Total_employees) != 1) {
        Total_employees = 0;
        fclose(file);
        return;
    }
    if (Total_employees > total) {
        printf("\nWarning: File has too many records. Reading maximum allowed.\n");
        Total_employees = total;
    }
    for (int i = 0; i < Total_employees; i++) {
        int result = fscanf(
            file,
            "%d,%49[^,],%29[^,],%f,%f,%f,%f\n",
            &employees[i].id,
            employees[i].name,
            employees[i].designation,
            &employees[i].initial,
            &employees[i].allowances,
            &employees[i].deductions,
            &employees[i].final_
        );
        if (result != 7) {
            printf("\nError reading record %d from file. Data might be corrupted.\n", i + 1);
            Total_employees = i;
            break;
        }
    }
    fclose(file);
}
