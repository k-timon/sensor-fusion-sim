#include "telemetry_hub.h"
#include "sensor.h"
void TelemetryHub::register_sensor(std::unique_ptr<Sensor> new_sensor) {
    active_sensors_.push_back(std::move(new_sensor));
}

void TelemetryHub::execute_poll() {
    for (const auto& sensor : active_sensors_) {
        sensor->capture_data();
    }
}