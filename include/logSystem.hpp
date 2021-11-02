#include <iostream>

namespace logSystem
{
    void log(std::string message, uint8_t errorCode)
    {
        std::cout << "[SYSTEM]";
        switch ()
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

        std::cout << message << std::endl;
    }

    void log(int number)
    {
        log(std::to_string(number));
    }

    void log(float number)
    {
        log(std::to_string(number));
    }

}