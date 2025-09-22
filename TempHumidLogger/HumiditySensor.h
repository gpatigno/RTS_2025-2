#ifndef HUMIDITY_SENSOR_H
#define HUMIDITY_SENSOR_H

#include "SharedResources.h"
#include <thread>
#include <chrono>
#include <iostream>
#include <cstdlib>

void humidity_sensor_task() {
    while (true) {
        int hum = 40 + rand() % 20;  // Simulated humidity
        humidity_queue.buffer.push(hum);
        std::cout << "[Humidity Sensor] Produced: " << hum << "%\n";

        std::this_thread::sleep_for(std::chrono::milliseconds(700));
    }
}

#endif // HUMIDITY_SENSOR_H
