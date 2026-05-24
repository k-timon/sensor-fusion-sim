#pragma once

#include <vector>
#include <memory>

class Sensor;

class TelemetryHub{
    std::vector<std::unique_ptr<Sensor>> active_sensors_;

    public:
        /**
         * @brief Registers a new sensor into the hub.
         * @param new_sensor A unique_ptr to the sensor.
         * @warning The hub takes full ownership of the pointer.
         */
        void register_sensor(std::unique_ptr<Sensor> new_sensor);
        void execute_poll();
};