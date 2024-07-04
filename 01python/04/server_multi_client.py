import socket
import threading

# Function to handle each client connection
def handle_client(client_socket, client_address):
    print(f"Accepted connection from {client_address}")
    while True:
        data = client_socket.recv(1024)
        if not data:
            break
        client_socket.send(data)

    print(f"Connection from {client_address} closed.")
    client_socket.close()



#main logic
if __name__ == "__main__":
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    server_address = ('', 8888)  
    server_socket.bind(server_address)

    server_socket.listen(5)
    print("Server is listening for incoming connections...")

    while True:
        client_socket, client_address = server_socket.accept()

        client_thread = threading.Thread(target=handle_client, args=(client_socket, client_address))
        client_thread.start()