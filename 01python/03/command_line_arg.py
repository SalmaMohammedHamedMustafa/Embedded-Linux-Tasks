import sys

def command_line_arg():
    """
    gets commant line arguments for the running script
    parameters:
    None
    return:
    script_name, arguments
    """

    script_name = sys.argv[0]
    arguments = sys.argv[1:]

    return script_name, arguments


if __name__ == "__main__":
    name, args = command_line_arg()

    print("Script name:", name)
    print("Command-line arguments:", args)