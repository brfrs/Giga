#include "InputPin.h"


using std::ifstream;
using namespace Giga;

InputPin::InputPin(PinNum num) : detail::Pin(num)
{
    detail::write(getPath(), "in");
}

Value InputPin::read() const
{
    ifstream valueFile(getPath());

    if (valueFile.get() == '1') 
        return HIGH;
    else
        return LOW;
}