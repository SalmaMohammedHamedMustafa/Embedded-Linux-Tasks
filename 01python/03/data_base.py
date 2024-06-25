import csv


def ID_generation(database):
    """
    Counts the number of rows in the database to determine the ID of the new employee.
    
    Parameters:
    database (str): The path of the database file.
    
    Returns:
    int: The ID of the new employee.
    """
    with open(database, 'r') as file:
        reader = csv.reader(file)
        row_count = sum(1 for row in reader)
    return row_count + 1


def add_new_employee(database):
    """
    Adds a new employee and its info to the database.
    
    Parameters:
    database (str): The path of the database file.
    
    Returns:
    None
    """
    name = input("Enter the employee name: ")
    job = input("Enter the employee job: ")
    salary = int(input("Enter the employee salary: "))
    ID = ID_generation(database)
    with open(database, 'a', newline='') as csvfile:
        csvwriter = csv.writer(csvfile)
        csvwriter.writerow([ID, name, job, salary])
    print("Employee added successfully.")
    print_employee_data(database, ID)


def print_employee_data(database, ID):
    """
    Prints employee data based on the provided ID.
    
    Parameters:
    database (str): The path of the database file.
    ID (int): The ID of the employee to print.
    
    Returns:
    None
    """
    with open(database, 'r') as file:
        reader = csv.reader(file)
        for current_line, row in enumerate(reader, start=1):
            if current_line == ID:
                data = row
                print(f"ID: {data[0]}")
                print(f"Name: {data[1]}")
                print(f"Job: {data[2]}")
                print(f"Salary: {data[3]}")
                return
    print(f"Employee with ID {ID} not found.")


def delete_employee(database, ID):
    """
    Deletes an employee from the database based on the provided ID.
    
    Parameters:
    database (str): The path of the database file.
    ID (int): The ID of the employee to delete.
    
    Returns:
    None
    """
    employees = []
    
    # Read all employees from the CSV file into a list
    with open(database, 'r') as file:
        reader = csv.reader(file)
        employees = list(reader)
    
    # Check if the ID is valid
    found = False
    for employee in employees:
        if employee[0] == str(ID):
            employees.remove(employee)
            found = True
            break
    
    if not found:
        print(f"Employee with ID {ID} not found.")
        return
    
    # Write the updated list of employees back to the CSV file
    with open(database, 'w', newline='') as file:
        writer = csv.writer(file)
        writer.writerows(employees)
    
    print(f"Employee with ID {ID} has been deleted successfully.")


def menu(database):
    """
    Displays a menu and handles user input to perform operations on the database.
    
    Parameters:
    database (str): The path of the database file.
    
    Returns:
    None
    """
    while True:
        print("\n===== Employee Database Menu =====")
        print("1. Add New Employee")
        print("2. Print Employee Data")
        print("3. Delete Employee")
        print("4. Exit")
        
        choice = input("Enter your choice (1-4): ")
        
        if choice == '1':
            add_new_employee(database)
        elif choice == '2':
            employee_id = int(input("Enter the employee ID: "))
            print_employee_data(database, employee_id)
        elif choice == '3':
            employee_id = int(input("Enter the employee ID to delete: "))
            delete_employee(database, employee_id)
        elif choice == '4':
            print("Exiting program.")
            break
        else:
            print("Invalid choice. Please enter a number from 1 to 4.")


if __name__ == "__main__":
    database_path = 'database.csv'
    menu(database_path)
