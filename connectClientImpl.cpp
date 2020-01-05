//
// Created by dor on 12/27/19.
//
#include <sys/socket.h>
#include <iostream>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <mutex>
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

void ConnectControlClient::messageSim(int client_socket) {
    // if = happened there is a message to send
    int is_sent;
    mutex mutex;
    ReadingData* readingData = ReadingData::getInstance();
    while (readingData->getShouldRun()) {
        if (!readingData->getMessages()->empty()) {
            for (string message : *readingData->getMessages()) {
                mutex.lock();
                is_sent  = send(client_socket, &message, message.size(), 0);
                if(is_sent == -1) {
                    cout << "Error sending to server" << endl;
                }
                mutex.unlock();
            }
        }
    }
    close(client_socket);
}

void ConnectControlClient::joinThread() {
    connect_thread.join();
}