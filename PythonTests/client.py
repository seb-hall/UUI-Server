import socket
import os, os.path

#   set server address
serverAddress = "./pythonServer"

#   set server address
clientAddress = "./pythonClient"

#   check if server address exists
if os.path.exists(clientAddress):
  os.remove(clientAddress)


# Create a UDS socket
sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)
sock.bind(clientAddress)

print("client bound to " + clientAddress)

while (1):

    try: 
        sock.sendto(str.encode(input()), serverAddress)

    except:
        print("server was not found :(")

