import socket
import sys

# Create a UDS socket
sock = socket.socket(socket.AF_UNIX, socket.SOCK_STREAM)

# Connect the socket to the port where the server is listening
serverAddress = "./pythonServer"

print("connecting to " + serverAddress)
try:
    sock.connect(serverAddress)
except (socket.error, msg):
    print >>sys.stderr, msg
    sys.exit(1)