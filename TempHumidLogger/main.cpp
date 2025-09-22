#include "TemperatureSensor.h"
#include "HumiditySensor.h"
#include "DataLogger.h"
#include "SharedResources.h"
#include <thread>

SharedQueue temp_queue;
SharedQueue humidity_queue;

int main() {
    std::thread temperature(temperature_sensor_task);
    std::thread humidity(humidity_sensor_task);
    std::thread Logger(data_logger_task);

    temperature.join();
    humidity.join();
    Logger.join();

    return 0;
}
