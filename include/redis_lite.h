
//for UNIT TESTING 
#ifndef REDIS_LITE_H
#define REDIS_LITE_H

#include <iostream>
#include <sstream>
#include <string>

#include "../include/hash_map.h"

class RedisLite
{
private:
    HashMap<std::string, std::string> database;

public:
    RedisLite();

    // Public only for unit testing
    void handleSet(std::stringstream& commandStream);
    void handleGet(std::stringstream& commandStream);
    void handleDel(std::stringstream& commandStream);
    void handleExists(std::stringstream& commandStream);
    void handleCount();
    void handleClear();

    HashMap<std::string, std::string>& getDatabase()
    {
        return database;
    }

    void run();
};

#endif