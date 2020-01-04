/**
 * This class is in charge of opening a server and processing the info received
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
        valread  = read( client_socket , buffer, 1024);
        locker.lock();
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