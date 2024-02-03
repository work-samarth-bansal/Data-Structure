#include <iostream>
#include <sstream>
#include <string>

bool compareDates(const std::string& date1, const std::string& date2) {
    // Split the first date into day and month
    std::istringstream ss1(date1);
    std::string day1_str, month1_str;
    getline(ss1, day1_str, '/');
    getline(ss1, month1_str, '/');

    // Split the second date into day and month
    std::istringstream ss2(date2);
    std::string day2_str, month2_str;
    getline(ss2, day2_str, '/');
    getline(ss2, month2_str, '/');

    // Convert day and month strings to integers
    int day1 = std::stoi(day1_str);
    int month1 = std::stoi(month1_str);
    int day2 = std::stoi(day2_str);
    int month2 = std::stoi(month2_str);

    // Compare the dates
    if (month1 < month2) {
        return true;
    } else if (month1 == month2) {
        return day1 < day2;
    } else {
        return false;
    }
}

int main() {
    std::string date1, date2;

    // Input two dates in the format dd/mm
    std::cout << "Enter the first date (dd/mm): ";
    std::cin >> date1;
    std::cout << "Enter the second date (dd/mm): ";
    std::cin >> date2;

    // Compare the dates
    if (compareDates(date1, date2)) {
        std::cout << date1 << " comes before " << date2 << std::endl;
    } else {
        std::cout << date1 << " comes after " << date2 << std::endl;
    }

    return 0;
}
