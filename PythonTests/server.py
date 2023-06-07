#!/usr/bin/python

import socket
import os, os.path
import platform

#	first identify platform
if (platform.system == 'Windows'):
    print("UUI-Server started on Windows")
else:
    print("UUI-Server started on a UNIX-like OS")
    

def SetAddress():
    print("setting address")
    return



try:
  address, port = SetAddress()
except:
  print("an error occurred")


"""
# 	set server address
serverAddress = ()

#	bufferSize
bufferSize = 1024

#  	check if server address exists
if os.path.exists(serverAddress):
  os.remove(serverAddress)

#  	create UDS socket
sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

print("starting server at " + serverAddress)

sock.bind(serverAddress)


while True:

    (data, address) = sock.recvfrom(bufferSize)

    try:
        print(address + ": " + data.decode('utf-8'))

    except:

        print("an error occured")
        sock.close()

"""

