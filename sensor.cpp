#include "sensor.h"
#include <iostream>
#include <iomanip>

Sensor::Sensor(std::string name) : sensor_name_(std::move(name)) {}

std::string Sensor::get_name() const{
    return sensor_name_;
}

LidarSensor::LidarSensor(std::string n) : Sensor(std::move(n)) {}
void LidarSensor::capture_data() {
    // Hardcoded values are for simulation testing only.
    scanned_distances_.clear();
    scanned_distances_.reserve(drone_config::kMaxRecords);
    scanned_distances_.push_back(15.423);
    scanned_distances_.push_back(42.911);
    scanned_distances_.push_back(108.005);

    std::cout << sensor_name_ << " Scan Data: ";
    std::cout << std::fixed << std::setprecision(2);

    for (double dist : scanned_distances_) {
        std::cout << dist << " m | ";
    }

    std::cout << std::endl;
}

TempSensor::TempSensor(std::string n) : Sensor(std::move(n)) {}
void TempSensor::capture_data() {
    current_celsius_ = 24.896;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << sensor_name_ << " Temperature: " << current_celsius_ << " °C" << std::endl;
}

