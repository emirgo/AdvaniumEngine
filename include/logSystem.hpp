#include <iostream>

namespace logSystem
{
    void log(std::string message, uint8_t statusCode)
    {
        std::cout << "[SYSTEM]";
        switch (statusCode)
        {
            default:
                std::cout << "[DEBUG]";
                break;
            case 1:
                std::cout << "[WARNING]";
                break;
            case 2:
                std::cout << "[ERROR]"; 
        }

        std::cout << ": " << message << std::endl;
    }

    void log(std::string message)
    {
        log(message, 0);
    }

    void log(int number, uint8_t statusCode)
    {
        log(std::to_string(number), statusCode);
    }

    void log(float number, uint8_t statusCode)
    {
        log(std::to_string(number), statusCode);
    }
}