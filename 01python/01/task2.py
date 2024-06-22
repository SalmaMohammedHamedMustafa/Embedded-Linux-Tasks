def isvowel(character):
    vowels = ['A', 'E', 'I', 'O', 'U']
    letter = character.strip().upper()
    
    if len(letter) == 1 and letter.isalpha():
        return letter in vowels
    else:
        print("Please enter a single alphabetical character.")
        return False

inputCharacter = input("Enter a letter: ")

if isvowel(inputCharacter):
    print(f"The letter '{inputCharacter.strip().upper()}' is a vowel.")
else:
    print(f"The letter '{inputCharacter.strip().upper()}' is not a vowel.")
