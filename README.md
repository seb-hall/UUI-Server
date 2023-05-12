# UUI-Server
UniversalUI Server

## Motivation

Development of UniversalUI has shown the need for tradeoffs between memory and computational efficiency.

Many of these such tradeoffs can be overcome by providing a singular server instance that can provide clients with a set of services.
By doing so, complex operations and interfaces can be moved away from applications themselves.

The server is responsible for all graphics operations and rendering, as well as window and event management. 

## Clients

UniversalUI clients will often consist of compiled C++ applications that have a lean library that depends heavily (but exclusively) on the presence of a server.
Client installers will detect if there is an existing server installation and if not, they will install it.
The server will be queried by clients on launch and started if not already running.

Other clients will consist of interpreted applets that can be programmed in a variety of different languages (e.g Python, Shell Script, Java etc).

## Inter-Process-Communication

IPC will be a headlining feature of UniversalUI clients. 
This will allow extremely easy communication between applications, and reduce the complexity of developing modular software.
