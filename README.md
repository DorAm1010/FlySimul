# FlySimul
This project connects as a client and server to FlighGear simulator.

## Installation
in oreder to use this projects you need to download Flightgear, preferrably 2019.

## Compilation
g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread

## Run
./a.out file_name.txt
explanations about what file_name.txt should include @ ##Usage

## Usage
insert a .txt file in cmd line containing instructions to the simulator with wrap directions
about information in the simulator for example "propelor -> ("/address_in_simulator")"
to have a variable that can instruct the simulator, or "rpm <- ("/address_in_simulator")"
to have a variable that receive information from the simulator.
This projects supports various commands such as opening a server and client sockets, if, while,
sleep, print, assign and variable defining, like in the examples above.
Print command: Print(argument); argument can be a mathematical expression comprised fromp
previously defined variables containing values, or a message if you the argument is in this format
"message", meaning it has quotes around it.
Sleep: Sleep(argument); same as print except it doesnt support messages, but any mathematical expression
will have the program hold for as its value in milliseconds.
Opening a serever: openDataServer(port); port can only be some mathematical expression.
Connecting to a client: connectControlClient(IP, port); IP - will always be "127.0.0.1", local terminal,
                                                        port - same as above.
If: if condition: in this format - "if left expression conditional operator right condition {
                                       scope
                                       }"
While: same format as if.
Assign command: assigning a variable that you have defined before in this format: variable_name = some_mathematical_expression.
this program will first lex all the words in the .txt file then parse the words and operate on appropriate meaning.
All files should reside in the same folder.

## Contributing
Pull requests are welcome. For major changes, please open an issue first to discuss what you would like to change.

Please make sure to update tests as appropriate.
