#ifndef DATA_LOGGER_H
#define DATA_LOGGER_H

#include "SharedResources.h"
#include <thread>
#include <chrono>
#include <iostream>

void data_logger_task() {
    while (true) {
        int temp = -1;
        int hum = -1;

        {
            temp = temp_queue.buffer.front();
            temp_queue.buffer.pop();
        }

        {
            hum = humidity_queue.buffer.front();
            humidity_queue.buffer.pop();
        }

        std::cout << "[Data Logger] Logged: Temp=" << temp << "°C, Hum=" << hum << "%\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(300));
    }
}

#endif // DATA_LOGGER_H
