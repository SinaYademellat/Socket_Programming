import socket

HOST = '127.0.0.1'  # لوکال هاست (localhost)
PORT = 12345        # پورت دلخواه

# for  test in range(1):
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_socket.bind((HOST, PORT))
server_socket.listen(1)

print(f"[*] Server listening on {HOST}:{PORT} ...")

conn, addr = server_socket.accept()
print(f"[+] Connected by {addr}")

data = conn.recv(1024)
d = data.decode()
print(f"[>] Received: {d}")
print(type(d), d.split())
print('-'*20)

conn.send(b"OK")
print('-'*20)

conn.close()
server_socket.close()
