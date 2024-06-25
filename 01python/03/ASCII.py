def get_ascii_value(character):
    """
    Get the ASCII value of a character.

    Args:
        character (str): The character for which ASCII value is to be obtained.

    Returns:
        int: The ASCII value of the character.
    """
    return ord(character)

if __name__ == "__main__":

    character = input("Enter a character: ")
    ascii_value = get_ascii_value(character)
    print(f"The ASCII value of '{character}' is {ascii_value}.")
