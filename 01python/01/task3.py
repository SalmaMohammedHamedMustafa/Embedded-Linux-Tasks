import os
def get_env_var (variable_name):
    return os.getenv(variable_name)



input_name = input("Enter the variable name: ")
value = get_env_var(input_name)
print(f"{input_name}: {value}")



