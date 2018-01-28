#include "Utils.h"

using std::ofstream;

using namespace Giga::detail;

bool directoryAccessible(const std::string& path) 
{
    struct stat status;
    if (stat(path.c_str(), &status) == 0) 
        return S_ISDIR(status.st_mode) && (status.st_mode & X_OK);

    return false;
}

bool fileAccessible(const std::string& path)
{
    struct stat status;
    if (stat(path.c_str(), &status) == 0) 
        return S_ISREG(status.st_mode) && (status.st_mode & (R_OK | W_OK));

    return false;
}

void write(const std::string& path, const std::string& out)
{
    ofstream outfile(path);
    outfile << out;
    outfile.close();
}