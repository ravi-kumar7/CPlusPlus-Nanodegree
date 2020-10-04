#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <dirent.h>
#include <unistd.h>
#include <regex>
#include <vector>
using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string ElapsedTime(long seconds) { 
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

string Uid(int pid) {
    std::ifstream filestream("./proc/"+std::to_string(pid)+"/status");
    string line,key;
    int value;
    while(std::getline(filestream, line)){
        std::istringstream linestream(line);
        linestream >> key>> value;
        if(key == "Uid:")
         break;
    }
    return std::to_string(value); 
}

string User(int pid) { 
    string user_id =  Uid(pid);
    std::ifstream filestream("./etc/passwd");
    string line,key,value;
    while(std::getline(filestream, line)){
        std::replace(line.begin(),line.end(),':',' ');
        std::istringstream linestream(line);
        linestream >> key>> value;
        if(value == user_id)
         break;
    }
    return key;
    
}


string Command(int pid) { 
    std::ifstream filestream("./proc/"+std::to_string(pid)+"/cmdline");
    string line;
    std::getline(filestream, line);
    return line;
}

// TODO: Read and return the total number of processes
int TotalProcesses() { 
    std::ifstream filestream("./proc/stat");
    string line,key;
    int value;
    while(std::getline(filestream, line)){
        std::istringstream linestream(line);
        linestream >> key>> value;
        if(key == "processes")
         break;
    }
    return value; 
}

// TODO: Read and return the number of running processes
int RunningProcesses() { 

    return 0; 
    }


    float MemoryUtilization() { 
        std::ifstream filestream("./proc/meminfo");
        string line, key;
        std::getline(filestream, line);
        std::istringstream linestream(line);
        long total_mem, free_mem;
        linestream >> key >> total_mem;

        std::getline(filestream, line);
        std::istringstream secondlinestream(line);
        secondlinestream >> key >> free_mem;
        float mem_utilization = (total_mem - free_mem)/1000.0f;
        return mem_utilization; 
    }

    string Ram(int pid) {
            std::ifstream filestream("./proc/"+std::to_string(pid)+"/status");
    string line,key;
    long value;
    while(std::getline(filestream, line)){
        std::istringstream linestream(line);
        linestream >> key>> value;
        if(key == "VmSize:")
         break;
    }
    float ram = value/1000.0;
    return std::to_string(ram) + " MB"; 
         
   }

   long UpTime(int pid) { 
    std::ifstream filestream("./proc/"+std::to_string(pid)+"/stat");
    string line,key;
    long value;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> value>> key >> key >> value>> value>> value>> value>> value>> value>> value >> value>> value>> value>> value>> value>> value>> value>> value>> value>> value>> value>> value ;
    return value; 
    }

std::vector<string> CpuUtilization() { 

    std::vector<string> cpu_data;
    std::ifstream filestream("./proc/stat");
    string line,value;
    std::getline(filestream, line);
    std::istringstream linestream(line);
    linestream >> value;
    while(linestream >> value ){
        if(value!= "")
        cpu_data.push_back(value);
    }
    return cpu_data; 
}


int main(){
    for(string val: CpuUtilization())
    std::cout<<val<<"\n";
}

