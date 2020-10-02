#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string ElapsedTime(long seconds[[maybe_unused]]) { 
    int hour = seconds/3600000;
    long remaining = seconds%3600000;
    int minutes = remaining/60000;
    remaining = remaining%60000;
    int rseconds = remaining/1000;
    char buff[100];
    snprintf(buff, sizeof(buff), "%02d:%02d:%02d",hour,minutes,rseconds );
    std::string buffAsStdStr = buff;
    return buffAsStdStr;
    }


long UpTime() { 
    std::ifstream filestream("./proc/uptime");
    string line;
    std::getline(filestream, line);
    std::istringstream stream(line);
    long uptime;
    stream >> uptime;
    return uptime;
}

int main(){
    std::cout<< ElapsedTime(UpTime());
}

