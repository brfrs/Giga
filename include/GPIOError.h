#ifndef GPIOERROR_H
#define GPIOERROR_H

#include <string>
#include <stdexcept>

namespace Giga
{
    class GPIOError : public std::runtime_error
    {
        public:
            GPIOError(const std::string& errorMessage) : std::runtime_error(errorMessage) {};
    };
}

#endif