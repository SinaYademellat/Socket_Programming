# # import socket
# # import ipaddress

# # def is_valid_ip(ip: str) -> bool:
# #     try:
# #         # Check if the IP address is valid
# #         socket.inet_pton(socket.AF_INET, ip)
# #         return True
# #     except socket.error:
# #         return False

# # def is_ip_in_subnet(ip: str, subnet_mask: str) -> bool:
# #     try:
# #         # Convert the IP address and subnet mask to network objects
# #         ip_obj = ipaddress.IPv4Address(ip)
# #         network_obj = ipaddress.IPv4Network(f'0.0.0.0/{subnet_mask}', strict=False)
# #         # Check if the IP is in the range of the subnet
# #         return ip_obj in network_obj
# #     except ValueError:
# #         return False

# # # Test the function
# # ip = "192.168.1.10"
# # subnet_mask = "255.255.255.0"

# # # if is_valid_ip(ip):
# # #     print(f"{ip} is a valid IP address.")
# # #     if is_ip_in_subnet(ip, subnet_mask):
# # #         print(f"{ip} is within the subnet {subnet_mask}.")
# # #     else:
# # #         print(f"{ip} is not within the subnet {subnet_mask}.")
# # # else:
# # #     print(f"{ip} is an invalid IP address.")




# n = 5  # decimal number
# res = ''  # binary result

# while n > 0:
#     res = str(n & 1) + res
#     n >>= 1
# print(res)


print(format(5, '08b'))