import os
def get_env_var (variable_name):
    variable_value = os.getenv(variable_name)
    if variable_value:
        return variable_value
    else:
        print("couldn't find the variable")



input_name = input("Enter the variable name: ")
value = get_env_var(input_name)
print(f"{input_name}: {value}")



