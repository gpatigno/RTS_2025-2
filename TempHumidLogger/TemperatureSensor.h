#ifndef TEMPERATURE_SENSOR_H
#define TEMPERATURE_SENSOR_H

#include "SharedResources.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>

void temperature_sensor_task() {
    while (true) {
        int temp = 20 + rand() % 10;  // Simulated temperature
        temp_queue.buffer.push(temp);
        std::cout << "[Temp Sensor] Produced: " << temp << "°C\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }
}

#endif // TEMPERATURE_SENSOR_H
