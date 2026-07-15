#include "../include/redis_lite.h"

#include <cctype>
#include <iostream>
#include <sstream>
#include <string>

// Constructor
RedisLite::RedisLite()
{
    // HashMap constructor is automatically called.
}

// Run Redis Lite
void RedisLite::run()
{
    std::string inputLine;
    std::string command;

    std::cout << "Welcome to Redis Lite!" << std::endl;
    std::cout << "Type EXIT to quit." << std::endl;

    while (true)
    {
        std::cout << "Redis> ";

        if (!std::getline(std::cin, inputLine))
        {
            break;
        }

        std::stringstream commandStream(inputLine);
        commandStream >> command;

        // Ignore empty input
        if (command.empty())
        {
            continue;
        }

        // Convert command to uppercase
        for (char &ch : command)
        {
            ch = std::toupper(static_cast<unsigned char>(ch));
        }

        if (command == "SET")
        {
            handleSet(commandStream);
        }
        else if (command == "GET")
        {
            handleGet(commandStream);
        }
        else if (command == "DEL")
        {
            handleDel(commandStream);
        }
        else if (command == "EXISTS")
        {
            handleExists(commandStream);
        }
        else if (command == "COUNT")
        {
            handleCount();
        }
        else if (command == "CLEAR")
        {
            handleClear();
        }
        else if (command == "EXIT")
        {
            std::cout << "Exiting Redis Lite..." << std::endl;
            break;
        }
        else
        {
            std::cout << "ERROR: Unknown command." << std::endl;
        }
    }
}

// Handle SET command
void RedisLite::handleSet(std::stringstream &commandStream)
{
    std::string key;
    std::string value;

    commandStream >> key;
    std::getline(commandStream, value);

    // Remove leading space from value
    if (!value.empty() && value[0] == ' ')
    {
        value.erase(0, 1);
    }

    if (key.empty() || value.empty())
    {
        std::cout << "ERROR: Usage: SET <key> <value>" << std::endl;
        return;
    }

    if (database.contains(key))
    {
        database.remove(key);
    }
    database.insert(key, value);
    std::cout << "OK" << std::endl;
}

// Handle GET command
void RedisLite::handleGet(std::stringstream &commandStream)
{
    std::string key;
    commandStream >> key;

    if (key.empty())
    {
        std::cout << "ERROR: Usage: GET <key>" << std::endl;
        return;
    }

    if (database.contains(key))
    {
        std::cout << database.get(key) << std::endl;
    }
    else
    {
        std::cout << "ERROR: Key not found." << std::endl;
    }
}

// Handle DEL command
void RedisLite::handleDel(std::stringstream &commandStream)
{
    std::string key;
    commandStream >> key;

    if (key.empty())
    {
        std::cout << "ERROR: Usage: DEL <key>" << std::endl;
        return;
    }

    if (database.contains(key))
    {
        database.remove(key);
        std::cout << "OK" << std::endl;
    }
    else
    {
        std::cout << "ERROR: Key not found." << std::endl;
    }
}

// Handle EXISTS command
void RedisLite::handleExists(std::stringstream &commandStream)
{
    std::string key;
    commandStream >> key;

    if (key.empty())
    {
        std::cout << "ERROR: Usage: EXISTS <key>" << std::endl;
        return;
    }

    if (database.contains(key))
    {
        std::cout << "TRUE" << std::endl;
    }
    else
    {
        std::cout << "FALSE" << std::endl;
    }
}

// Handle COUNT command
void RedisLite::handleCount()
{
    std::cout << database.size() << std::endl;
}

// Handle CLEAR command
void RedisLite::handleClear()
{
    database.clear();
    std::cout << "OK" << std::endl;
}