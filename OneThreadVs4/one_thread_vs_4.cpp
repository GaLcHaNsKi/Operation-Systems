#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <thread>

int sumVector(const std::vector<int> &a, int start, int end) {
    int sum = 0;

    for (int i=start; i<end; i++) {
        sum += a[i];
    }

    return sum;
}

int main() {
    std::vector<int> vec(10000000);

    std::srand(time(0));
    
    for (int i = 0; i < 10000000; i++) {
        vec[i] = std::rand() % 100;
    }

    std::clock_t st = std::clock();
    
    int sum = sumVector(vec, 0, 10000000);
    std::cout << sum << "\n";
    
    std::cout << "One thread: " << (double)(std::clock() - st) / CLOCKS_PER_SEC << "\nFour threads: ";
    
    st = std::clock();
    
    int s1, s2, s3, s4;
    std::thread t1([&]() { s1 = sumVector(vec, 0, 2500000); });
    std::thread t2([&]() { s2 = sumVector(vec, 2500000, 5000000); });
    std::thread t3([&]() { s3 = sumVector(vec, 5000000, 7500000); });
    std::thread t4([&]() { s4 = sumVector(vec, 7500000, 10000000); });
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    
    sum = s1 + s2 + s3 + s4;
    std::cout << sum << "\n";

    std::cout << (double)(std::clock() - st) / CLOCKS_PER_SEC;
}
