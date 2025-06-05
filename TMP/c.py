import socket

HOST = '127.0.0.1'  # IP سرور
PORT = 12345        # پورت سرور

client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
client_socket.connect((HOST, PORT))

message = "sssssss AAAAAAA"
client_socket.sendall(message.encode())

client_socket.close()
