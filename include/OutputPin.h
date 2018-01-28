#ifndef OUTPUTPIN_H
#define OUTPUTPIN_H

#include <string>

#include "Pin.h"
#include "Utils.h"

namespace Giga
{

class OutputPin : public detail::Pin
{
    public:
        OutputPin(PinNum num);
        
        OutputPin(PinNum num, Value defaultVal);

        OutputPin(const OutputPin&) = delete;

        void set(Value outVal) const;
};

}

#endif