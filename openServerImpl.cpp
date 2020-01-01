/**
 * This class is in charge of openenig a server and processing the info received
 * by the client.
 * */
#include <thread>
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "readingData.h"

std::mutex locker;
/**
 * the information received from the simulator, i.e. comma separated values,
 * are recieved line by line, because the information will might not be recieved
 * as a whole line each time we first move the buffer pointer, buffer[i], until we first
 * encounter a \n char then we prepare to read the line in a for loop that starts
 * right after some \n until the next one.
 * */
void openDataServer::processInfo(char* buffer) {
    char delimiter = ',';
    char back_slash_n = '\n';
    // map value
    string str_value;
    string sim;
    // value by location from sim input
    std::size_t val_num = 0;
    int i = 0;
    ReadingData* readingData = ReadingData::getInstance();

    while (buffer[i] != back_slash_n) {
        i++;
    }
    i++;

    for (; buffer[i] != back_slash_n; i++) {
        // concatenate string value between two commas
        while(buffer[i] != delimiter) {
            // if end of input
            if(buffer[i] == back_slash_n)
                break;
            str_value += buffer[i];
            i++;
        }
        // next location in input
        val_num++;
        // switch case sets the inputted value received with the help of the val_num
        switch (val_num) {
            case 1:
                // airspeed-indicator_indicated-speed-kt
                //sim = "/instrumentation/airspeed-indicator/indicated-speed-kt";
                readingData->getSimToVariableMap().find
                ("airspeed-indicator_indicated-speed-kt")->second->setVal(stod(str_value));
                break;
            case 2:
                // time_warp
                //sim = "/sim/time/warp";
                readingData->getSimToVariableMap().find
                        ("time_warp")->second->setVal(stod(str_value));
                break;
            case 3:
                // switches_magnetos
                //sim = "/controls/switches/magnetos";
                readingData->getSimToVariableMap().find
                        ("switches_magnetos")->second->setVal(stod(str_value));
                break;
            case 4:
                // heading-indicator_offset-deg
                sim = "/instrumentation/heading-indicator/offset-deg";
                readingData->getSimToVariableMap().
                find("heading-indicator_offset-deg")->second->setVal(stod(str_value));
                break;
            case 5:
                // altimeter_indicated-altitude-ft
                sim = "/instrumentation/altimeter/indicated-altitude-ft";
                readingData->getSimToVariableMap().
                        find("altimeter_indicator-altitude-ft")->second->setVal(stod(str_value));
                break;
            case 6:
                // altimeter_pressure-alt-ft
                sim = "/instrumentation/altimeter/pressure-alt-ft";
                readingData->getSimToVariableMap().
                        find("altimeter_pressure-alt-ft")->second->setVal(stod(str_value));
                break;
            case 7:
                // attitude-indicator_indicated-pitch-deg
                //sim = "/instrumentation/attitude-indicator/indicated-pitch-deg";
                readingData->getSimToVariableMap().
                        find("attitude-indicator_indicated-pitch-deg")->second->setVal(stod(str_value));
                break;
            case 8:
                // attitude-indicator_indicated-roll-deg
                //sim = "/instrumentation/attitude-indicator/indicated-roll-deg";
                readingData->getSimToVariableMap().
                        find("attitude-indicator_indicated-roll-deg")->second->setVal(stod(str_value));
                break;
            case 9:
                // attitude-indicator_internal-pitch-deg
                //sim = "/instrumentation/attitude-indicator/internal-pitch-deg";
                readingData->getSimToVariableMap().
                        find("attitude-indicator_internal-pitch-deg")->second->setVal(stod(str_value));
                break;
            case 10:
                // attitude-indicator_internal-roll-deg
                //sim = "/instrumentation/attitude-indicator/internal-roll-deg";
                readingData->getSimToVariableMap().
                        find("attitude-indicator_internal-roll-deg")->second->setVal(stod(str_value));
                break;
            case 11:
                // encoder_indicated-altitude-ft
                //sim = "/instrumentation/encoder/indicated-altitude-ft";
                readingData->getSimToVariableMap().
                        find("encoder_indicated-altitude-ft")->second->setVal(stod(str_value));
                break;
            case 12:
                // encoder_pressure-alt-ft
                //sim = "/instrumentation/encoder/pressure-alt-ft";
                readingData->getSimToVariableMap().
                        find("encoder_pressure-alt-ft")->second->setVal(stod(str_value));
                break;
            case 13:
                // gps_indicated-altitude-ft
                //sim = "/instrumentation/gps/indicated-altitude-ft";
                readingData->getSimToVariableMap().
                        find("gps_indicated-altitude-ft")->second->setVal(stod(str_value));
                break;
            case 14:
                // gps_indicated-ground-speed-kt
                //sim = "/instrumentation/gps/indicated-ground-speed-kt";
                readingData->getSimToVariableMap().
                        find("gps_indicated-ground-speed-kt")->second->setVal(stod(str_value));
                break;
            case 15:
                // gps_indicated-vertical-speed
                //sim = "/instrumentation/gps/indicated-vertical-speed";
                readingData->getSimToVariableMap().
                        find("gps_indicated-vertical-speed")->second->setVal(stod(str_value));
                break;
            case 16:
                // indicated-heading-deg
                //sim = "/instrumentation/heading-indicator/indicated-heading-deg";
                readingData->getSimToVariableMap().
                        find("indicated-heading-deg")->second->setVal(stod(str_value));
                break;
            case 17:
                // magnetic-compass_indicated-heading-deg
                //sim = "/instrumentation/magnetic-compass/indicated-heading-deg";
                readingData->getSimToVariableMap().
                        find("magnetic-compass_indicated-heading-deg")->second->setVal(stod(str_value));
                break;
            case 18:
                // slip-skid-ball_indicated-slip-skid
                //sim = "/instrumentation/slip-skid-ball/indicated-slip-skid";
                readingData->getSimToVariableMap().
                        find("slip-skid-ball_indicated-slip-skid")->second->setVal(stod(str_value));
                break;
            case 19:
                // turn-indicator_indicated-turn-rate
                //sim = "/instrumentation/turn-indicator/indicated-turn-rate";
                readingData->getSimToVariableMap().
                        find("turn-indicator_indicated-turn-rate")->second->setVal(stod(str_value));
                break;
            case 20:
                // vertical-speed-indicator_indicated-speed-fpm
                //sim = "/instrumentation/vertical-speed-indicator/indicated-speed-fpm";
                readingData->getSimToVariableMap().
                        find("vertical-speed-indicator_indicated-speed-fpm")->second->setVal(stod(str_value));
                break;
            case 21:
                // flight_aileron
                //sim = "/controls/flight/aileron";
                readingData->getSimToVariableMap().
                        find("flight_aileron")->second->setVal(stod(str_value));
                break;
            case 22:
                // flight_elevator
                //sim = "/controls/flight/elevator";
                readingData->getSimToVariableMap().
                        find("flight_elevator")->second->setVal(stod(str_value));
                break;
            case 23:
                // flight_rudder
                //sim = "/controls/flight/rudder";
                readingData->getSimToVariableMap().
                        find("flight_rudder")->second->setVal(stod(str_value));
                break;
            case 24:
                // flight_flaps
                //sim = "/controls/flight/flaps";
                readingData->getSimToVariableMap().
                        find("flight_flaps")->second->setVal(stod(str_value));
                break;
            case 25:
                // engine_throttle
                //sim = "/controls/engines/engine/throttle";
                readingData->getSimToVariableMap().
                        find("engine_throttle")->second->setVal(stod(str_value));
                break;
            case 26:
                // current-engine_throttle
                //sim = "/controls/engines/current-engine/throttle";
                readingData->getSimToVariableMap().
                        find("current-engine_throttle")->second->setVal(stod(str_value));
                break;
            case 27:
                // switches_master-avionics
                //sim = "/controls/switches/master-avionics";
                readingData->getSimToVariableMap().
                        find("switches_master-avionics")->second->setVal(stod(str_value));
                break;
            case 28:
                // switches_starter
                //sim = "/controls/switches/starter";
                readingData->getSimToVariableMap().
                        find("switches_starter")->second->setVal(stod(str_value));
                break;
            case 29:
                // active-engine_auto-start
                //sim = "/engines/active-engine/auto-start";
                readingData->getSimToVariableMap().
                        find("active-engine_auto-start")->second->setVal(stod(str_value));
                break;
            case 30:
                // flight_speedbrake
                //sim = "/controls/flight/speedbrake";
                readingData->getSimToVariableMap().
                        find("flight_speedbrake")->second->setVal(stod(str_value));
            case 31:
                // c172p_brake-parking
                //sim = "/sim/model/c172p/brake-parking";
                readingData->getSimToVariableMap().
                        find("c172p_brake-parking")->second->setVal(stod(str_value));
                break;
            case 32:
                // engine_primer
                //sim = "/controls/engines/engine/primer";
                readingData->getSimToVariableMap().
                        find("engine_primer")->second->setVal(stod(str_value));
                break;
            case 33:
                // current-engine_mixture
                //sim = "/controls/engines/current-engine/mixture";
                readingData->getSimToVariableMap().
                        find("current-engine_mixture")->second->setVal(stod(str_value));
                break;
            case 34:
                // switches_master-bat
                //sim = "/controls/switches/master-bat";
                readingData->getSimToVariableMap().
                        find("switches_master-bat")->second->setVal(stod(str_value));
                break;
            case 35:
                // switches_master-alt
                //sim = "/controls/switches/master-alt";
                readingData->getSimToVariableMap().
                        find("switches_master-alt")->second->setVal(stod(str_value));
                break;
            case 36:
                // engine_rpm
                //sim = "/engines/engine/rpm";
                readingData->getSimToVariableMap().
                        find("engine_rpm")->second->setVal(stod(str_value));
                break;
            default:
                break;
        }
        str_value = "";
    }

}
/**
 * This method is in charge of establishing a connection to the
 * simulator as a server
 * */
void openDataServer::openServer(int port) {

    //create socket
    int socketfd = socket(AF_INET, SOCK_STREAM, 0);
    if (socketfd == -1) {
        throw "Unable To Create Socket";
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
    // accepting a client, and waiting until a client is accepted
    int client_socket = accept(socketfd, (struct sockaddr *)&address,
                               (socklen_t*)&address);
    while (client_socket == -1) {
        client_socket = accept(socketfd, (struct sockaddr *)&address,
                               (socklen_t*)&address);
    }
    //reading from client
    char buffer[1024] = {0};
    int valread;

    // while the singleton instance says its ok to run this loop will run
    while (ReadingData::getInstance()->getShouldRun()) {
        locker.lock();
        valread  = read( client_socket , buffer, 1024);
        // information received from the simulator to be processed
        processInfo(buffer);
        locker.unlock();
    }


    close(socketfd);
}
/**
 * This execute method gets the singleton ReadingData instace to use its vector
 * in order to get the information regarding this class, i.e. the port number, then it opens up a
 * thread to connect as a server to the simulator.
 * */
int openDataServer::execute() {
    vector<string> vector = ReadingData::getInstance()->getWordsVector();
    int port = stod(vector.at(ReadingData::getInstance()->getInd()));
    openDataServer* tmp = new openDataServer();
    try {
        std::thread t1(&openDataServer::openServer, tmp, port);
        t1.join();
    } catch (const char* e) {
        cout << e << endl;
    }
    delete tmp;
    return 2;
}