#include "telemetry_hub.hpp"
#include "sensor.hpp"

void TelemetryHub::register_sensor(std::unique_ptr<Sensor> new_sensor) {
    active_sensors_.push_back(std::move(new_sensor));
}

void TelemetryHub::execute_poll() {
    for (const auto& sensor : active_sensors_) {
        sensor->capture_data();
    }
}