//
// Created by dor on 12/27/19.
//
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>
#include <cstring>
#include "readingData.h"
#include "connectControlClient.h"

using namespace std;

int ConnectControlClient::execute() {
    ConnectControlClient connectControlClient;
    ReadingData* readingData = ReadingData::getInstance();

    // get index to be at port location
    readingData->incInd(2);
    int port = stoi(readingData->getWordsVector()->at(readingData->getInd()));
    // get index to point to next command
    readingData->incInd(1);

    // create socket
    int client_socket = socket(AF_INET, SOCK_STREAM, 0);
    if (client_socket == -1) {
        cout << "Could not create connection to server as client";
        return 0;
    }

    sockaddr_in address;
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons(port);

    int is_connected = connect(client_socket, (struct sockaddr*)&address, sizeof(address));
    while (is_connected == -1) {
        is_connected = connect(client_socket, (struct sockaddr*)&address, sizeof(address));
    }

    cout << "Client is Connected" << endl;

    connect_thread = std::thread(&ConnectControlClient::messageSim, &connectControlClient, client_socket);

}
/**
 * This method runs all the while the parser is working,
 * the method gets every message in the message vector and sends
 * it to the simulator.
 **/
void ConnectControlClient::messageSim(int client_socket) {
    int is_sent;
    string message;
    ReadingData* readingData = ReadingData::getInstance();
    while (readingData->getShouldRun()) {
        while (!readingData->getMessages()->empty()) {
            message = readingData->getMessages()->front();
            is_sent  = send(client_socket, message.c_str(), strlen(message.c_str()), 0);
            if(is_sent == -1) {
                cout << "Error sending to server" << endl;
            }
            readingData->getMessages()->pop();
        }
    }
    close(client_socket);
}

void ConnectControlClient::joinThread() {
    connect_thread.join();
}