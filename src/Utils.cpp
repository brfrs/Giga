#include "Utils.h"

using std::ofstream;

bool Giga::detail::directoryAccessible(const std::string& path) 
{
    return access(path.c_str, X_OK) == 0;
}

bool Giga::detail::fileAccessible(const std::string& path)
{
    return access(path.c_str, W_OK) == 0;
}

void Giga::detail::write(const std::string& path, const std::string& out)
{
    ofstream outfile(path);
    outfile << out;
    outfile.close();
}