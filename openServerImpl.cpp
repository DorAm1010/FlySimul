
#include "command.h"
#include <thread>
#include <sys/socket.h>
#include <string>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>

void openDataServer::processInfo(char* buffer) {
    char delimiter = ',';
    // map value
    string str_value;
    // value by location from sim input
    std::size_t val_num = 0;

    for (int i = 0; buffer[i] != '\0'; i+=1) {
        // concatenate string value
        while(buffer[i] != delimiter) {
            // if end of input
            if(buffer[i] == '\0')
                break;
            str_value += buffer[i];
            i+=1;
        }
        val_num+=1;
        switch (val_num) {
            case 1:
                // airspeed-indicator_indicated-speed-kt
                openDataServer::val_map["airspeed-indicator_indicated-speed-kt"] = stod(str_value);
                break;
            case 2:
                // time_warp
                val_map["time_warp"] = stod(str_value);
                break;
            case 3:
                // switches_magnetos
                val_map["switches_magnetos"] = stod(str_value);
                break;
            case 4:
                // heading-indicator_offset-deg
                val_map["heading-indicator_offset-deg"] = stod(str_value);
                break;
            case 5:
                // altimeter_indicated-altitude-ft
                val_map["altimeter_indicator-altitude-ft"] = stod(str_value);
                break;
            case 6:
                // altimeter_pressure-alt-ft
                val_map["altimeter_pressure-alt-ft"] = stod(str_value);
                break;
            case 7:
                // attitude-indicator_indicated-pitch-deg
                val_map["attitude-indicator_indicated-pitch-deg"] = stod(str_value);
                break;
            case 8:
                // attitude-indicator_indicated-roll-deg
                val_map["attitude-indicator_indicated-roll-deg"] = stod(str_value);
                break;
            case 9:
                // attitude-indicator_internal-pitch-deg
                val_map["attitude-indicator_internal-pitch-deg"] = stod(str_value);
                break;
            case 10:
                // attitude-indicator_internal-roll-deg
                val_map["attitude-indicator_internal-roll-deg"] = stod(str_value);
                break;
            case 11:
                // encoder_indicated-altitude-ft
                val_map["encoder_indicated-altitude-ft"] = stod(str_value);
                break;
            case 12:
                // encoder_pressure-alt-ft
                val_map["encoder_pressure-alt-ft"] = stod(str_value);
                break;
            case 13:
                // gps_indicated-altitude-ft
                val_map["gps_indicated-altitude-ft"] = stod(str_value);
                break;
            case 14:
                // gps_indicated-ground-speed-kt
                val_map["gps_indicated-ground-speed-kt"] = stod(str_value);
                break;
            case 15:
                // gps_indicated-vertical-speed
                val_map["gps_indicated-vertical-speed"] = stod(str_value);
                break;
            case 16:
                // indicated-heading-deg
                val_map["indicated-heading-deg"] = stod(str_value);
                break;
            case 17:
                // magnetic-compass_indicated-heading-deg
                val_map["magnetic-compass_indicated-heading-deg"] = stod(str_value);
                break;
            case 18:
                // slip-skid-ball_indicated-slip-skid
                val_map["slip-skid-ball_indicated-slip-skid"] = stod(str_value);
                break;
            case 19:
                // turn-indicator_indicated-turn-rate
                val_map["turn-indicator_indicated-turn-rate"] = stod(str_value);
                break;
            case 20:
                // vertical-speed-indicator_indicated-speed-fpm
                val_map["vertical-speed-indicator_indicated-speed-fpm"] = stod(str_value);
                break;
            case 21:
                // flight_aileron
                val_map["flight_aileron"] = stod(str_value);
                break;
            case 22:
                // flight_elevator
                val_map["flight_elevator"] = stod(str_value);
                break;
            case 23:
                // flight_rudder
                val_map["flight_rudder"] = stod(str_value);
                break;
            case 24:
                // flight_flaps
                val_map["flight_flaps"] = stod(str_value);
                break;
            case 25:
                // engine_throttle
                val_map["engine_throttle"] = stod(str_value);
                break;
            case 26:
                // current-engine_throttle
                val_map["current-engine_throttle"] = stod(str_value);
                break;
            case 27:
                // switches_master-avionics
                val_map["switches_master-avionics"] = stod(str_value);
                break;
            case 28:
                // switches_starter
                val_map["switches_starter"] = stod(str_value);
                break;
            case 29:
                // active-engine_auto-start
                val_map["active-engine_auto-start"] = stod(str_value);
                break;
            case 30:
                // flight_speedbrake
                val_map["flight_speedbrake"] = stod(str_value);
                break;
            case 31:
                // c172p_brake-parking
                val_map["c172p_brake-parking"] = stod(str_value);
                break;
            case 32:
                // engine_primer
                val_map["engine_primer"] = stod(str_value);
                break;
            case 33:
                // current-engine_mixture
                val_map["current-engine_mixture"] = stod(str_value);
                break;
            case 34:
                // switches_master-bat
                val_map["switches_master-bat"] = stod(str_value);
                break;
            case 35:
                // switches_master-alt
                val_map["switches_master-alt"] = stod(str_value);
                break;
            case 36:
                // engine_rpm
                val_map["engine_rpm"] = stod(str_value);
                break;
            default:
                break;
        }
        str_value = "";
    }

}
void openDataServer::openServer(int port) {

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    while (socketfd == -1) {
        cout << "Waiting For Connection...";
        this_thread::sleep_for(1s);
        socketfd = socket(AF_INET, SOCK_STREAM, 0);
    }

    //bind socket to IP address
    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(port);
    if (bind(socketfd, (struct sockaddr *) &address, sizeof(address)) == -1) {
        throw "Could not bind the socket to an IP";
    }
    //making socket listen to the port
    if (listen(socketfd, 1) == -1) {
        throw "Error during listening command";
    } else {
        std::cout<<"Server is now listening ..."<<std::endl;
    }
    // accepting a client
    int client_socket = accept(socketfd, (struct sockaddr *)&address,
                               (socklen_t*)&address);

    if (client_socket == -1) {
        throw "Error accepting client";
    }
    //reading from client
    char buffer[1024] = {0};
    int valread = read( client_socket , buffer, 1024);

    processInfo(buffer);
    
    close(socketfd);
}
int openDataServer::execute(vector<string> vec) {
    int port = stod(vec.at(0));
    openDataServer* tmp = new openDataServer();
    std::thread t1(&openDataServer::openServer, tmp, port);
    t1.join();
    delete tmp;
    return 2;
}