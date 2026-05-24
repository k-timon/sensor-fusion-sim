#include "sensor.hpp"
#include "telemetry_hub.hpp"

int main() {
    TelemetryHub telemetry_manager;
    std::unique_ptr<Sensor> lidar = std::make_unique<LidarSensor>("Lidar");
    std::unique_ptr<Sensor> temp = std::make_unique<TempSensor>("Thermometer");

    telemetry_manager.register_sensor(std::move(lidar));
    telemetry_manager.register_sensor(std::move(temp));
    telemetry_manager.execute_poll();

    return 0;
}

