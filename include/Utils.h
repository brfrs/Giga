#ifndef UTILS_H
#define UTILS_H

#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>

#include <string>
#include <fstream>

namespace Giga
{
    namespace detail
    {
        bool directoryAccessible(const std::string& path);

        bool fileAccessible(const std::string& path);

        void write(const std::string& path, const std::string& out);
    }
}

#endif