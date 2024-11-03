#include <bits/stdc++.h>
using namespace std;

// Observer Interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
    virtual ~Observer() {}
};

// Subject Interface
class Subject {
public:
    virtual void registerObserver(Observer* o) = 0;
    virtual void removeObserver(Observer* o) = 0;
    virtual void notifyObservers() = 0;
    virtual ~Subject() {}
};

class WeatherStation : public Subject {
private:
    list<Observer*> observers;
    float temperature;
    float humidity;
    float pressure;

public:
    void registerObserver(Observer* o) override {
        observers.push_back(o);
    }

    void removeObserver(Observer* o) override {
        observers.remove(o); // Using std::list's remove function
    }

    void notifyObservers() override {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temp, float hum, float pres) {
        temperature = temp;
        humidity = hum;
        pressure = pres;
        notifyObservers();
    }
};

class CurrentConditionsDisplay : public Observer {
private:
    float temperature;
    float humidity;

public:
    void update(float temp, float hum, float pressure) override {
        temperature = temp;
        humidity = hum;
        display();
    }

    void display() {
        cout << "Current conditions: " << temperature << "F degrees and " << humidity << "% humidity" << endl;
    }
};

class StatisticsDisplay : public Observer {
private:
    float maxTemp = 0.0f;
    float minTemp = 200.0f; // Arbitrary high value for initialization
    float tempSum = 0.0f;
    int numReadings = 0;

public:
    void update(float temp, float humidity, float pressure) override {
        tempSum += temp;
        numReadings++;

        if (temp > maxTemp) {
            maxTemp = temp;
        }
        if (temp < minTemp) {
            minTemp = temp;
        }
        display();
    }

    void display() {
        cout << "Avg/Max/Min temperature: " << (tempSum / numReadings) << "/" << maxTemp << "/" << minTemp << endl;
    }
};
int main() {
    WeatherStation weatherStation;

    CurrentConditionsDisplay currentDisplay;
    StatisticsDisplay statisticsDisplay;

    weatherStation.registerObserver(&currentDisplay);
    weatherStation.registerObserver(&statisticsDisplay);

    weatherStation.setMeasurements(80, 65, 30.4f);
    weatherStation.setMeasurements(82, 70, 29.2f);
    weatherStation.setMeasurements(78, 90, 29.2f);

    return 0;
}

/*Explanation
Observer Pattern: The WeatherStation class is the subject that maintains a list of observers.
 When the weather data changes, notifyObservers() is called to update all observers.
Observers: CurrentConditionsDisplay and StatisticsDisplay implement the Observer interface
 and display the data in their own way.
Ease of Extension: You can add more observer classes with different behaviors without modifying the WeatherStation class.*/