import requests

def get_public_ip():
    """
    gets the public IP address of the machine by making an HTTP request to 'https://api.ipify.org/?format=json', which returns the public IP address in JSON format. If the request is successful, it extracts and returns the IP address from the JSON response. In case of any request exceptions, it prints an error message and returns None.

    Returns:
    str: The public IP address as a string if the request is successful.
    None: If there is an error while making the request.
    """
    try:
        response = requests.get('https://api.ipify.org/?format=json')
        ip_info = response.json()
        return ip_info
    except requests.RequestException as e:
        print(f"Error fetching public IP: {e}")
        return None


public_ip = get_public_ip()
if public_ip:
    print(public_ip)
