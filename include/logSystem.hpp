#include <iostream>

namespace logSystem
{

    void log(std::string message)
    {
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