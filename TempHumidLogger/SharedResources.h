#ifndef SHARED_RESOURCES_H
#define SHARED_RESOURCES_H

#include <queue>
#include <mutex>
#include <condition_variable>

struct SharedQueue {
    std::queue<int> buffer;
    const size_t max_size = 10;
};

extern SharedQueue temp_queue;
extern SharedQueue humidity_queue;

#endif // SHARED_RESOURCES_H
