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
 * are recieved line by line, and because the information will might not be received
 * as a whole line each time we first move the buffer pointer, buffer[i], until we first
 * encounter a \n char then we prepare to read the line in a while loop where we concatenate
 * every char that is not a comma to form a string, totaling in 36 separate strings that
 * represent double type values that are inserted to a double type values vector.
 * That vector will be sent to be processed in updateFromSimulator.
 * */
void openDataServer::processInfo(char* buffer) {
    char delimiter = ',';
    char back_slash_n = '\n';
    // map value
    string str_value;
    // value by location from sim input
    std::size_t val_num = 0;
    int i = 0;
    vector<double> values;
    ReadingData* readingData = ReadingData::getInstance();

    while (buffer[i] != back_slash_n) {
        i++;
    }

    i++;

    while (buffer[i] != back_slash_n) {
        // concatenate string value between two commas
        while(buffer[i] != delimiter) {
            // if end of input
            if(buffer[i] == back_slash_n)
                break;
            str_value += buffer[i];
            i++;
        }
        values.push_back(stod(str_value));
        i++;
    }
    readingData->updateFromSimulator(values);
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
    ReadingData* readingData = ReadingData::getInstance();
    int port = stod(readingData->getWordsVector().at(readingData->getInd()));
    // skip port string to get next command when finished
    readingData->incInd(2);
    openDataServer openDataServer;
    try {
        std::thread t1(&openDataServer::openServer, &openDataServer, port);
        t1.join();
    } catch (const char* e) {
        cout << e << endl;
    }
    return 0;
}

//    for (; buffer[i] != back_slash_n; i++) {
//
//        // next location in input
//        val_num++;
//        // switch case sets the inputted value received with the help of the val_num
//        switch (val_num) {
//            case 1:
//                // airspeed-indicator_indicated-speed-kt
//                readingData->findInMap("airspeed-indicator_indicated-speed-kt", stod(str_value));
//                break;
//            case 2:
//                // time_warp
//                readingData->findInMap("time_warp", stod(str_value));
//                break;
//            case 3:
//                // switches_magnetos
//                readingData->findInMap("switches_magnetos", stod(str_value));
//                break;
//            case 4:
//                // heading-indicator_offset-deg
//                readingData->findInMap("heading-indicator_offset-deg", stod(str_value));
//                break;
//            case 5:
//                // altimeter_indicated-altitude-ft
//                readingData->findInMap("altimeter_indicated-altitude-ft", stod(str_value));
//                break;
//            case 6:
//                // altimeter_pressure-alt-ft
//                sim = "/instrumentation/altimeter/pressure-alt-ft";
//                readingData->findInMap("altimeter_pressure-alt-ft", stod(str_value));
//                break;
//            case 7:
//                // attitude-indicator_indicated-pitch-deg
//                readingData->findInMap("attitude-indicator_indicated-pitch-deg", stod(str_value));
//
//                break;
//            case 8:
//                // attitude-indicator_indicated-roll-deg
//                readingData->findInMap("attitude-indicator_indicated-roll-deg", stod(str_value));
//                break;
//            case 9:
//                // attitude-indicator_internal-pitch-deg
//                readingData->findInMap("attitude-indicator_internal-pitch-deg", stod(str_value));
//                break;
//            case 10:
//                // attitude-indicator_internal-roll-deg
//                readingData->findInMap("attitude-indicator_internal-roll-deg", stod(str_value));
//                break;
//            case 11:
//                // encoder_indicated-altitude-ft
//                readingData->findInMap("encoder_indicated-altitude-ft", stod(str_value));
//                break;
//            case 12:
//                // encoder_pressure-alt-ft
//                readingData->findInMap("encoder_pressure-alt-ft", stod(str_value));
//                break;
//            case 13:
//                // gps_indicated-altitude-ft
//                readingData->findInMap("gps_indicated-altitude-ft", stod(str_value));
//                break;
//            case 14:
//                // gps_indicated-ground-speed-kt
//                readingData->findInMap("gps_indicated-ground-speed-kt", stod(str_value));
//                break;
//            case 15:
//                // gps_indicated-vertical-speed
//                readingData->findInMap("gps_indicated-vertical-speed", stod(str_value));
//                break;
//            case 16:
//                // indicated-heading-deg
//                readingData->findInMap("indicated-heading-deg", stod(str_value));
//                break;
//            case 17:
//                // magnetic-compass_indicated-heading-deg
//                readingData->findInMap("magnetic-compass_indicated-heading-deg", stod(str_value));
//                break;
//            case 18:
//                // slip-skid-ball_indicated-slip-skid
//                readingData->findInMap("slip-skid-ball_indicated-slip-skid", stod(str_value));
//                break;
//            case 19:
//                // turn-indicator_indicated-turn-rate
//                readingData->findInMap("turn-indicator_indicated-turn-rate", stod(str_value));
//                break;
//            case 20:
//                // vertical-speed-indicator_indicated-speed-fpm
//                readingData->findInMap("vertical-speed-indicator_indicated-speed-fpm", stod(str_value));
//                break;
//            case 21:
//                // flight_aileron
//                readingData->findInMap("flight_aileron", stod(str_value));
//                break;
//            case 22:
//                // flight_elevator
//                readingData->findInMap("flight_elevator", stod(str_value));
//                break;
//            case 23:
//                // flight_rudder
//                readingData->findInMap("flight_rudder", stod(str_value));
//                break;
//            case 24:
//                // flight_flaps
//                readingData->findInMap("flight_flaps", stod(str_value));
//                break;
//            case 25:
//                // engine_throttle
//                readingData->findInMap("engine_throttle", stod(str_value));
//                break;
//            case 26:
//                // current-engine_throttle
//                readingData->findInMap("current-engine_throttle", stod(str_value));
//                break;
//            case 27:
//                // switches_master-avionics
//                readingData->findInMap("switches_master-avionics", stod(str_value));
//                break;
//            case 28:
//                // switches_starter
//                readingData->findInMap("switches_starter", stod(str_value));
//                break;
//            case 29:
//                // active-engine_auto-start
//                readingData->findInMap("active-engine_auto-start", stod(str_value));
//                break;
//            case 30:
//                // flight_speedbrake
//                readingData->findInMap("flight_speedbrake", stod(str_value));
//            case 31:
//                // c172p_brake-parking
//                readingData->findInMap("c172p_brake-parking", stod(str_value));
//                break;
//            case 32:
//                // engine_primer
//                readingData->findInMap("engine_primer", stod(str_value));
//                break;
//            case 33:
//                // current-engine_mixture
//                readingData->findInMap("current-engine_mixture", stod(str_value));
//                break;
//            case 34:
//                // switches_master-bat
//                readingData->findInMap("switches_master-bat", stod(str_value));
//                break;
//            case 35:
//                // switches_master-alt
//                readingData->findInMap("switches_master-alt", stod(str_value));
//                break;
//            case 36:
//                // engine_rpm
//                readingData->findInMap("engine_rpm", stod(str_value));
//                break;
//            default:
//                break;
//        }
//        str_value = "";
//    }
