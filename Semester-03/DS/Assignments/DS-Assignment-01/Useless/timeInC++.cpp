#include <iostream>
#include <sstream>
#include <chrono>
#include <ctime>
using namespace std;


// int main()
// {
//     std::time_t t = std::time(0);  // t is an integer type
//     std::cout << t << " seconds since 01-Jan-1970\n";
//     return 0;
// }

// std::string timeStamp(){
//     std::ostringstream strStream;
//     std::time_t t = std::time(nullptr);
//     strStream<< "[" << std::put_time(std::localtime(&t), "%F %T %Z") << "] ";
//     return strStream.str();
// }

// int main(){
//     std::cout<<timeStamp()<<" Testing!";   
//     return 0;
// }

int main() {
    // Get current time as a time_point
    auto timeRightNow = chrono::system_clock::now();
    
    // Convert to time_t to work with C-style time functions
    time_t currentTime = chrono::system_clock::to_time_t(timeRightNow);
    
    // Convert to a readable format
    cout << "Current time: " << ctime(&currentTime);
    
    return 0;
}
