#!/usr/bin/python

import socket
import os, os.path

# 	set server address
serverAddress = "./pythonServer"

#	bufferSize
bufferSize = 1024

#  	check if server address exists
if os.path.exists(serverAddress):
  os.remove(serverAddress)

#  	create UDS socket
sock = socket.socket(socket.AF_UNIX, socket.SOCK_DGRAM)

print("starting server at " + serverAddress)

sock.bind(serverAddress)


while True:

    (data, address) = sock.recvfrom(bufferSize)

    try:
        print(address + ": " + data.decode('utf-8'))

    except:

        print("an error occured")
        connection.close()
