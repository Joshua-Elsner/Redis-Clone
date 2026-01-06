#include "../include/RedisServer.h"
#include <iostream>
#include <chrono>
#include <thread>

int main(int argc, char* argv[]) {
    int port = 6379; //default port
    //TODO: Error handling
    if (argc >= 2) {
        port = std::stoi(argv[1]);
    }

    RedisServer server(port);

    //Background persistence: dump database every 5 min (300 seconds)
    std::thread persistenceThread([](){
        while(true) {
            std::this_thread::sleep_for(std::chrono::seconds(300));
            //TODO: dump the database
        }
    });
    persistenceThread.detach();

    server.run();
    return 0;
}