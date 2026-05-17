#pragma once

#include <string>
#include <vector>
#include <memory>

namespace drone_config{
        constexpr int kMaxRecords = 3;
}

/**
 * @brief Base class for all drone hardware interfaces.
 */
class Sensor{
    protected:
        std::string sensor_name_;

    public:
        explicit Sensor(std::string name);

        virtual ~Sensor() = default;

        virtual void capture_data() = 0;

        std::string get_name() const;
};

class LidarSensor : public Sensor {
    private:
        std::vector<double> scanned_distances_;

    public:
        LidarSensor(std::string n);

        void capture_data() override;
};

class TempSensor : public Sensor {
    private:
        double current_celsius_;

    public:
        TempSensor(std::string n);

        void capture_data() override;
};