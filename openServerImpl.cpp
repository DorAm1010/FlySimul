/**
 * This class is in charge of opening a server and processing the info received
 * by the client.
 * */
#include <sys/socket.h>
#include <iostream>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <mutex>
#include "readingData.h"
#include "openDataServer.h"
using namespace std;
/**
 * the information received from the simulator, i.e. comma separated values,
 * are recieved line by line, and because the information will might not be received
 * as a whole line each time we first move the buffer pointer, buffer[i], until we first
 * encounter a \n char then we prepare to read the line in a while loop where we concatenate
 * every char that is not a comma to form a string, totaling in 36 separate strings that
 * represent double type values that are inserted to a double type values vector.
 * That vector will be sent to be processed in updateFromSimulator.
 * */
void OpenDataServer::processInfo(char* buffer) {

}
/**
 * This method is in charge of establishing a connection to the
 * simulator as a server
 * */
void OpenDataServer::openServer(int port) {

    mutex mutex;
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


    // while the singleton instance says its ok to run this loop will run
    while (ReadingData::getInstance()->getShouldRun()) {
        char delimiter = ',';
        char back_slash_n = '\n';
        // map value
        string str_value = "";
        // value by location from sim input
        int i = 0;
        vector<double> values;
        ReadingData* readingData = ReadingData::getInstance();
        char buffer[1024] = {0};

        int valread = read( client_socket , buffer, 1024);
        if (valread == -1) {
            throw "Could not read from server";
        }

//        while (buffer[i] != back_slash_n) {
//            i++;
//            cout << i << endl;
//        }
//
//        i++;

        while (buffer[i] != back_slash_n) {
            // concatenate string value between two commas
            while(buffer[i] != delimiter) {
                // if end of input
                if(buffer[i] == back_slash_n)
                    break;
                str_value += buffer[i];
                i++;
            }

            try {
                double value = stod(str_value);
                values.push_back(value);
            } catch (exception &e) {
                cout << e.what() << endl;
            }

            str_value = "";
            if(buffer[i] == back_slash_n)
                break;
            i++;
        }
        if (values.size() == 36) {
            readingData->updateFromSimulator(&values);
            values.erase(values.begin(), values.end());
        }
    }

    close(socketfd);
}
/**
 * This execute method gets the singleton ReadingData instace to use its vector
 * in order to get the information regarding this class, i.e. the port number, then it opens up a
 * thread to connect as a server to the simulator.
 * */
int OpenDataServer::execute() {
    ReadingData* readingData = ReadingData::getInstance();
    readingData->incInd(1);
    int port = stoi(readingData->getWordsVector()->at(readingData->getInd()));
    // skip port string to get next command when finished
    readingData->incInd(1);
    OpenDataServer openDataServer;
    open_server_thread = std::thread(&OpenDataServer::openServer, &openDataServer, port);
//    try {
//        open_server_thread = std::thread(&OpenDataServer::openServer, &openDataServer, port);
//    } catch (const char* e) {
//        cout << e << endl;
//    }
    return 0;
}

void OpenDataServer::joinThread() {
    open_server_thread.join();
}