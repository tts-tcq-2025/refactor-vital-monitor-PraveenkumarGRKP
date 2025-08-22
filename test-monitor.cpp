#include <gtest/gtest.h>
#include "./monitor.h"

#include <gtest/gtest.h>

// vitalsOk is declared in monitor.h
int vitalsOk(float temperature, float pulseRate, float spo2);

TEST1(Monitor, ReturnsFalseIfTemperatureIsOutOfRange) {
    ASSERT_FALSE(vitalsOk(103.0f, 80, 98)); //Should be false when temperature is too high
    ASSERT_FALSE(vitalsOk(94.0f, 80, 98)); //Should be false when temperature is too low
}

TEST2(Monitor, ReturnsFalseIfPulseRateIsOutOfRange) {
    ASSERT_FALSE(vitalsOk(98.6f, 110, 98)); //Should be false when pulse rate is too high
    ASSERT_FALSE(vitalsOk(98.6f, 50, 98)); //Should be false when pulse rate is too low
}

TEST3(Monitor, ReturnsFalseIfSpO2IsOutOfRange) {
    ASSERT_FALSE(vitalsOk(98.6f, 80, 85)); //Should be false when SpO2 is too low
}

TEST4(Monitor, ReturnsTrueIfAllVitalsAreInRange) {
    ASSERT_TRUE(vitalsOk(98.6f, 80, 98)); //Should be true when all vitals are normal
}

