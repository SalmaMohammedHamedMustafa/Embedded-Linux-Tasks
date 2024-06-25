import csv

class EmployeeDatabase:
    def __init__(self, database):
        self.database = database
    
    def _generate_next_id(self):
        """
        Counts the number of rows in the database to determine the ID of the new employee.
        
        Returns:
        int: The ID of the new employee.
        """
        with open(self.database, 'r') as file:
            reader = csv.reader(file)
            row_count = sum(1 for row in reader)
        return row_count + 1
    
    def add_employee(self, name, job, salary):
        """
        Adds a new employee to the database.
        
        Parameters:
        name (str): The name of the employee.
        job (str): The job title of the employee.
        salary (int): The salary of the employee.
        
        Returns:
        None
        """
        ID = self._generate_next_id()
        with open(self.database, 'a', newline='') as csvfile:
            csvwriter = csv.writer(csvfile)
            csvwriter.writerow([ID, name, job, salary])
        print("Employee added successfully.")
        self.print_employee_data(ID)
    
    def print_employee_data(self, ID):
        """
        Prints employee data based on the provided ID.
        
        Parameters:
        ID (int): The ID of the employee to print.
        
        Returns:
        None
        """
        with open(self.database, 'r') as file:
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
    
    def delete_employee(self, ID):
        """
        Deletes an employee from the database based on the provided ID.
        
        Parameters:
        ID (int): The ID of the employee to delete.
        
        Returns:
        None
        """
        employees = []
        
        # Read all employees from the CSV file into a list
        with open(self.database, 'r') as file:
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
        with open(self.database, 'w', newline='') as file:
            writer = csv.writer(file)
            writer.writerows(employees)
        
        print(f"Employee with ID {ID} has been deleted successfully.")
    
    def menu(self):
        """
        Displays a menu and handles user input to perform operations on the database.
        
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
                name = input("Enter the employee name: ")
                job = input("Enter the employee job: ")
                salary = int(input("Enter the employee salary: "))
                self.add_employee(name, job, salary)
            elif choice == '2':
                employee_id = int(input("Enter the employee ID: "))
                self.print_employee_data(employee_id)
            elif choice == '3':
                employee_id = int(input("Enter the employee ID to delete: "))
                self.delete_employee(employee_id)
            elif choice == '4':
                print("Exiting program.")
                break
            else:
                print("Invalid choice. Please enter a number from 1 to 4.")

if __name__ == "__main__":
    database_path = 'database.csv'
    employee_db = EmployeeDatabase(database_path)
    employee_db.menu()
