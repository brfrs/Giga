#ifndef PIN_H
#define PIN_H

#include "Utils.h"
#include "GPIOError.h"

#include <string>

namespace Giga
{

using PinNum = int;

enum Value { LOW, HIGH };

    namespace detail
    {
        class Pin
        {
            public:
                Pin(PinNum num);

                PinNum getNum() const { return gpioNum; }

                ~Pin();

            protected:
                std::string getPath() const;

            private:
                PinNum gpioNum;
                std::string gpioPath;
        };
    }

}

#endif