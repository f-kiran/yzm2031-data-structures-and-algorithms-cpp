#include <iostream>
#include <chrono> // Required library for modern time tracking

int main() {
    // 1. Capture the start time
    auto start = std::chrono::high_resolution_clock::now();

    // 2. Execute your for loop
    long long sum = 0;
    for (int i = 0; i < 100000000; ++i) {
        sum += i;
    }

    // 3. Capture the end time
    auto end = std::chrono::high_resolution_clock::now();

    // 4. Calculate the duration
    std::chrono::duration<double, std::milli> duration = end - start;

    std::cout << "Loop took: " << duration.count() << " milliseconds." << std::endl;
    std::cout << "Result: " << sum << std::endl;

    return 0;
    // Note: To capture time in microseconds or nanoseconds instead, replace 
    // std::milli with std::micro or std::nano.
}
