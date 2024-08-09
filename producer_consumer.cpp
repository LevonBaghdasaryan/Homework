#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <vector>

const unsigned int bufferSize = 10;
int buffer[bufferSize];
int count = 0;
int in = 0;
int out = 0;
bool done = false;

std::mutex mtx;
std::condition_variable cv;

void producer(const int& id, const int produceCount) {
    for(std::size_t i = 0; i < produceCount; ++i) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{return count < bufferSize; });

        buffer[in] = i;
        in = (in + 1) % bufferSize;
        ++count;
        std::cout << "Producer " << id << " produced " << i  << std::endl;
    }

    std::unique_lock<std::mutex> lock(mtx);
    done = true;
    cv.notify_all();
}

void  consumer(const int& id) {
    while(true) {
        std::unique_lock<std::mutex> lock(mtx);
        cv.wait(lock, []{return count > 0 || done; });

        if(count > 0) {
            int value = buffer[out];
            out = (out + 1) % bufferSize;
            --count;
            std::cout << "Cunsumer " << id << " consumed " << value << std::endl;

            cv.notify_all();
        }
        else if(done) {
            break;
        }
    }
}

int main() {

    const int numProducers = 3;
    const int numConsumers = 3;
    const int produceCount = 20;

    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    for(std::size_t i = 0; i < numProducers; ++i) {
        producers.emplace_back(producer, i, produceCount);
    }

    for(std::size_t i = 0; i < numConsumers; ++i) {
        consumers.emplace_back(consumer, i);
    }

    for(auto& producer : producers) {
        producer.join();
    }

    for(auto& consumer : consumers) {
        consumer.join();
    }

    return 0;
}