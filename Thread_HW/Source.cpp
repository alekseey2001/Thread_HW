#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int sharedData = 0;

void writerThread() {
    for (int i = 0; i < 5; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        sharedData = i;
        std::cout << "Writer Thread: Writing data " << i << std::endl;
    }
}

void readerThread() {
    for (int i = 0; i < 5; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        std::cout << "Reader Thread: Reading data " << sharedData << std::endl;
    }
}

int main() {
    std::thread writer(writerThread);
    std::thread reader(readerThread);

    writer.join();
    reader.join();

    return 0;
}
