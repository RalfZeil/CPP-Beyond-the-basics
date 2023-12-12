#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

int counter = 0;
bool done = false;

std::queue<int> goods;

std::condition_variable cv;
std::mutex mtx;

void producer() {
    std::cout << "Starting producer..." << std::endl;
    std::unique_lock<std::mutex> lk(mtx);
    for (int i = 0; i < 500; ++i) {
        goods.push(i);
        counter++;
    }

    done = true;

    lk.unlock();
    cv.notify_one();
    std::cout << "Finished producer..." << std::endl;
}

void consumer() {
    std::cout << "Starting consumer..." << std::endl;

    while (true) {
        std::unique_lock<std::mutex> lk(mtx);
        cv.wait(lk, [] { return done || !goods.empty(); });

        while (!goods.empty()) {
            goods.pop();
            counter--;
        }

        bool localDone = done; 

        lk.unlock();
        cv.notify_one();

        break;
    }

    std::cout << "Finished consumer..." << std::endl;
}

int main() {
    counter = 0;
    std::thread producerThread(producer);
    std::thread consumerThread(consumer);

    producerThread.join();
    consumerThread.join();

    std::cout << "Net: " << counter << " " << goods.size() << std::endl;
}
