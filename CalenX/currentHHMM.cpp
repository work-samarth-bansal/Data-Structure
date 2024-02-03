#include <iostream>
#include <chrono>

// Function to get current hour and minute
std::pair<int, int> getCurrentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
    std::tm* timeInfo = std::localtime(&currentTime);

    int hour = timeInfo->tm_hour;
    int minute = timeInfo->tm_min;

    return std::make_pair(hour, minute);
}

int main() {
    // Get current hour and minute
    std::pair<int, int> currentTime = getCurrentTime();

    int hour = currentTime.first;
    int minute = currentTime.second;

    std::cout << "Current time: " << hour << ":" << minute << std::endl;

    return 0;
}
