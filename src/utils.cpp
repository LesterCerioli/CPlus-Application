#include "utils.h
#include <iomanip>
#include <sstream>

std::string getCurrentDateTime() {
    std::time_t now = std::time(0);
    std::tm* ltm = std::localtime(&now);
    std::ostringstream oss;
    oss << std::put_time(ltm, "%Y-%m-%d %H-%M-%S"); return oss.str();
}