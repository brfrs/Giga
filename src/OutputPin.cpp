#include "OutputPin.h"

using namespace Giga;

OutputPin::OutputPin(PinNum num) : detail::Pin(num)
{
    detail::write(getPath()+"/direction", "out");
}

OutputPin::OutputPin(PinNum num, Value defaultVal) : Pin(num)
{
    if (defaultVal == HIGH)
        detail::write(getPath()+"/direction", "high");
    else
        detail::write(getPath()+"/direction", "low");
}

void OutputPin::set(Value outVal) const
{
    if (outVal == HIGH) 
        detail::write(getPath()+"/value", "1");
    else
        detail::write(getPath()+"/value", "0");
}