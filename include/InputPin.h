#ifndef INPUTPIN_H
#define INPUTPIN_H

#include "Pin.h"

#include <fstream>

namespace Giga
{

class InputPin : public detail::Pin
{
    public:
        InputPin(PinNum num);

        InputPin(const InputPin&) = delete;

        Value read() const;

        ~InputPin();

    private:

};

}

#endif