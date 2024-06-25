# main.py

import firelink
import sys

#dectionary that contains the number, name and url of a website
websites = {
    "1": ("Facebook", firelink.facebook_link),
    "2": ("Google", firelink.google_link),
    "3": ("YouTube", firelink.youtube_link),
    "4": ("Twitter", firelink.twitter_link)
}

def print_menu():
    """
    Prints the mene of websites
    Parameters:
    None
    return: None
    """
    print("Select a website to open:")
    for key, (name, _) in websites.items():
        print(f"{key}. {name}")

def choice_input():
    """
    takes the required website and handels the choice
    Parameters:
    None
    return: None
    """
    choice = input("Enter the number of the website to open (or 'q' to quit): ")
    if choice.lower() == 'q':
        sys.exit(0) #terminates the program
    elif choice in websites:
        _, url = websites[choice]
        firelink.firefox(url)
    else:
        print("Invalid choice. Please try again.")


while True:
    print_menu()
    choice_input()
    
