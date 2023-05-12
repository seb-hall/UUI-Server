#!/usr/bin/python

import socket
import os, os.path
import time
from collections import deque

#   set server address
serverAddress = "./pythonServer"

#   check if server address exists
if os.path.exists(serverAddress):
  os.remove(serverAddress)

#   create UDS socket
sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

print("starting socket at " + serverAddress)

sock.bind(serverAddress)


while True:
    sock.listen(1)

    connection, clientAddress = sock.accept()

    try:
        print("connection from " + clientAddress)

    except:

        print("an error occured")
        connection.close()
