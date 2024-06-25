import requests

def get_public_ip():
    try:
        response = requests.get('https://api.ipify.org?format=json')
        ip_info = response.json()
        return ip_info['ip']
    except requests.RequestException as e:
        print(f"Error fetching public IP: {e}")
        return None


public_ip = get_public_ip()
if public_ip:
    print(f"My public IP address is: {public_ip}")
