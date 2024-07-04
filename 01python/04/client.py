import socket

server_address = ('localhost', 8888)

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

client_socket.connect(server_address)
print(f"Connected to {server_address}")

try:

    message = "Hello, server!"
    client_socket.sendall(message.encode())

    data = client_socket.recv(1024)
    print(f"Received from server: {data.decode()}")

finally:
    print("Closing connection to the server.")
    client_socket.close()
