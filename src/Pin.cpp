#include "Pin.h"

using std::string;
using std::to_string;

using namespace Giga::detail;

const string GPIO_EXPORT_PATH = "/sys/class/gpio/export";
const string GPIO_UNEXPORT_PATH = "/sys/class/gpio/unexport";
const string GPIO_PIN_PATH_PREFIX = "/sys/class/gpio/gpio";

Pin::Pin(Giga::PinNum num)
{
    gpioNum = num;
    gpioPath = GPIO_PIN_PATH_PREFIX + to_string(gpioNum);

    if (detail::fileAccessible(GPIO_EXPORT_PATH))
        detail::write(GPIO_EXPORT_PATH, to_string(gpioNum));
    else
        throw Giga::GPIOError("Could not access the /sys/class/gpio/export");
}

string Pin::getPath() const
{
    return gpioPath;
}

Pin::~Pin()
{
    detail::write(GPIO_UNEXPORT_PATH, to_string(gpioNum));
}