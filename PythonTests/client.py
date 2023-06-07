import socket
import os, os.path

#   set server address
#serverAddress = "./pythonServer"
serverAddress = ('localhost', 49152)

#   set server address
#clientAddress = "./pythonClient"
clientAddress = ('localhost', 49151)

#   check if server address exists
#if os.path.exists(clientAddress):
#  os.remove(clientAddress)


# Create a UDS socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
sock.bind(clientAddress)

#print("client bound to " + clientAddress)

while (1):

    try: 
        sock.sendto(str.encode(input()), serverAddress)

    except:
        print("server was not found :(")

