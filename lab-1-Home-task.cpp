#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int CITIES = 4;
const int DAYS = 7;
const int MONTH_DAYS = 28;

void inputAQIData(int aqi[CITIES][DAYS]) {
    for (int i = 0; i < CITIES; i++) {
        for (int j = 0; j < DAYS; j++) {
            cout << "Enter AQI for City " << i + 1 << " on Day " << j + 1 << ": ";
            cin >> aqi[i][j];
        }
    }
}

void calculateWeeklyAverage(int aqi[CITIES][DAYS], double avg[CITIES]) {
    for (int i = 0; i < CITIES; i++) {
        double sum = 0;
        for (int j = 0; j < DAYS; j++) {
            sum += aqi[i][j];
        }
        avg[i] = sum / DAYS;
    }
}

int findWorstCity(double avg[CITIES]) {
    int worstCity = 0;
    for (int i = 1; i < CITIES; i++) {
        if (avg[i] > avg[worstCity]) {
            worstCity = i;
        }
    }
    return worstCity;
}

void identifyCriticalDays(int aqi[CITIES][DAYS]) {
    cout << "Critical Pollution Days:\n";
    for (int i = 0; i < CITIES; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (aqi[i][j] > 150) {
                cout << "City " << i + 1 << " on Day " << j + 1 << " (AQI: " << aqi[i][j] << ")\n";
            }
        }
    }
}

void visualizeAQI(int aqi[CITIES][DAYS]) {
    cout << "AQI Visualization:\n";
    for (int i = 0; i < CITIES; i++) {
        cout << "City " << i + 1 << ": ";
        for (int j = 0; j < DAYS; j++) {
            int stars = aqi[i][j] / 50;
            for (int k = 0; k < stars; k++) {
                cout << "*";
            }
            cout << " ";
        }
        cout << endl;
    }
}

void monthlyAQIComparison(int aqi[CITIES][MONTH_DAYS], double monthlyAvg[CITIES]) {
    for (int i = 0; i < CITIES; i++) {
        double sum = 0;
        for (int j = 0; j < MONTH_DAYS; j++) {
            sum += aqi[i][j];
        }
        monthlyAvg[i] = sum / MONTH_DAYS;
    }
}

int main() {
    int aqi[CITIES][DAYS];
    double weeklyAvg[CITIES];
    
    inputAQIData(aqi);
    calculateWeeklyAverage(aqi, weeklyAvg);
    
    cout << fixed << setprecision(2);
    for (int i = 0; i < CITIES; i++) {
        cout << "Average AQI for City " << i + 1 << ": " << weeklyAvg[i] << endl;
    }
    
    int worstCity = findWorstCity(weeklyAvg);
    cout << "City with the worst air quality: City " << worstCity + 1 << endl;
    
    identifyCriticalDays(aqi);
    visualizeAQI(aqi);
    
    int aqiMonthly[CITIES][MONTH_DAYS];

    double monthlyAvg[CITIES];
    monthlyAQIComparison(aqiMonthly, monthlyAvg);
    
    for (int i = 0; i < CITIES; i++) {
        cout << "Monthly Average AQI for City " << i + 1 << ": " << monthlyAvg[i] << endl;
    }
    
    return 0;
}
