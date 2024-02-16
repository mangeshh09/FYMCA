#include <iostream>

class weather_report {
private:
    int day_of_month;
    double high_temp;
    double low_temp;
    double amount_rain;
    double amount_snow;

public:
    
    weather_report() : day_of_month(1), high_temp(0), low_temp(0), amount_rain(0), amount_snow(0) {}

    
    weather_report(int day, double high, double low, double rain, double snow)
        : day_of_month(day), high_temp(high), low_temp(low), amount_rain(rain), amount_snow(snow) {}

    
    void set_values() {
        std::cout << "Enter day of the month: ";
        std::cin >> day_of_month;
        std::cout << "Enter high temperature: ";
        std::cin >> high_temp;
        std::cout << "Enter low temperature: ";
        std::cin >> low_temp;
        std::cout << "Enter amount of rain: ";
        std::cin >> amount_rain;
        std::cout << "Enter amount of snow: ";
        std::cin >> amount_snow;
    }

    
    void calculate_average(int num_days) {
        double avg_high = high_temp / num_days;
        double avg_low = low_temp / num_days;
        double avg_rain = amount_rain / num_days;
        double avg_snow = amount_snow / num_days;

        std::cout << "Monthly report:" << std::endl;
        std::cout << "Average High Temperature: " << avg_high << std::endl;
        std::cout << "Average Low Temperature: " << avg_low << std::endl;
        std::cout << "Average Amount of Rain: " << avg_rain << std::endl;
        std::cout << "Average Amount of Snow: " << avg_snow << std::endl;
    }
};

int main() {
    int num_days;
    std::cout << "Enter the number of days in the month: ";
    std::cin >> num_days;

    std::vector<weather_report> monthly_report(num_days);

    int choice;
    do {
        std::cout << "\n1. Enter weather data for each day\n";
        std::cout << "2. Generate monthly report\n";
        std::cout << "3. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: {
                for (int i = 0; i < num_days; ++i) {
                    std::cout << "Day " << i + 1 << ":" << std::endl;
                    monthly_report[i].set_values();
                }
                break;
            }
            case 2: {
                double total_high = 0, total_low = 0, total_rain = 0, total_snow = 0;
                for (const auto& report : monthly_report) {
                    total_high += report.high_temp;
                    total_low += report.low_temp;
                    total_rain += report.amount_rain;
                    total_snow += report.amount_snow;
                }
                weather_report monthly_total(0, total_high, total_low, total_rain, total_snow);
                monthly_total.calculate_average(num_days);
                break;
            }
            case 3: {
                std::cout << "Exiting...\n";
                break;
            }
            default: {
                std::cout << "Invalid choice. Please enter again.\n";
            }
        }
    } while (choice != 3);

    return 0;
}

