#pragma once

#include <iostream>
#include<sstream>
#include<string>

#include <iomanip> // For std::put_time
#include <chrono>  // For std::chrono functions
#include <ctime>   // For std::time_t and std::localtime


using namespace std;

string getLocalDateTime(){
    auto now = std::chrono::system_clock::now();
    
    // Convert to std::time_t for use with std::localtime
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    
    // Convert to local time
    std::tm* localTime = std::localtime(&currentTime);
    
    // Print formatted date and time
    // std::cout << "Current date and time: " 
    //           << std::put_time(localTime, "%Y-%m-%d %H:%M:%S") 
    //           << std::endl;
    ostringstream time ;
    time << put_time(localTime, "%Y-%m-%d %H:%M:%S") ;
    return time.str();
}
