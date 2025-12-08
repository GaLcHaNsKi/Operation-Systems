#include <iostream>
#include <thread>
#include <chrono>
#include <mutex>
#include <format>
#include <string>
#include <iomanip>
#include <sstream>

std::string currentTime() {
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    ss.str("");

    ss << std::put_time(std::localtime(&t), "%H:%M:%S");

    return ss.str();
}

struct Station {
public:
    std::string name;
    std::mutex mutex;

    Station* prev = nullptr;
    Station* next = nullptr;

    double timeToNext;
    double timeToPrev;

    Station(std::string name, Station* prev, Station* next, double timeToPrev, double timeToNext) : name(name), prev(prev), next(next), timeToNext(timeToNext), timeToPrev(timeToPrev) {}
};

void train(Station* s, int side=1, int id=1) {
    /// side=1 - в сторону от Душанбе
    /// side=0 - в обратную сторону

    s->mutex.lock();

    std::cout << std::format("{1} - Train {2} at {0} station.\n", s->name, currentTime(), id);

side1:    if (side==1) {
        if (s->next == nullptr) {
            side = 0;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds((int)(s->timeToNext * 1000)));
            
            s->mutex.unlock();
            train(s->next, side, id);
            return;
        }
    }

    if (side==0) {
        if (s->prev == nullptr) {
            side = 1;
            goto side1;
        } else {
            std::this_thread::sleep_for(std::chrono::milliseconds((int)(s->timeToPrev * 1000)));
            
            s->mutex.unlock();
            train(s->prev, side, id);
            return;
        }
    }
}

int main() {
    /*
    Станции и расстояние в км между ними
        Душанбе-1
        8
        Рохаты
        14
        Вахдат
        5
        Иляк
        40
        Яван
        37
        Вахш
        19
        Курган-Тюбе
        26
        Сангтуда
        26
        Дангара
        20
        Олимтой
        32
        Курбоншахид
        27
        Куляб
    */

    Station dush1("Dushanbe-1", nullptr, nullptr, 0, 0.8);
    Station roh("Rokhata", &dush1, nullptr, 0.8, 1.4);
    Station vahdat("Vahdat", &roh, nullptr, 1.4, 0.5);
    Station ilak("Ilyak", &vahdat, nullptr, 0.5, 4.0);
    Station yavan("Yavan", &ilak, nullptr, 4.0, 3.7);
    Station vahsh("Vahsh", &yavan, nullptr, 3.7, 1.9);
    Station kurgan("Kurgan-Tube", &vahsh, nullptr, 1.9, 2.6);
    Station sangt("Sangtuda", &kurgan, nullptr, 2.6, 2.6);
    Station dangara("Dangara", &sangt, nullptr, 2.6, 2.0);
    Station olim("Olimtoy", &dangara, nullptr, 2.0, 3.2);
    Station kurbon("Kurbonshahid", &olim, nullptr, 3.2, 2.7);
    Station kulab("Kulab", &kurbon, nullptr, 2.7, 0);

    dush1.next = &roh;
    roh.next = &vahdat;
    vahdat.next = &ilak;
    ilak.next = &yavan;
    yavan.next = &vahsh;
    vahsh.next = &kurgan;
    kurgan.next = &sangt;
    sangt.next = &dangara;
    dangara.next = &olim;
    olim.next = &kurbon;
    kurbon.next = &kulab;

    std::thread t1(train, &dush1, 1, 1);
    std::thread t2(train, &kulab, 0, 2);
    std::thread t3(train, &vahdat, 1, 3);
    std::thread t4(train, &olim, 0, 4);
    std::thread t5(train, &yavan, 1, 5);
    std::thread t6(train, &dangara, 0, 6);
    std::thread t7(train, &kurgan, 1, 7);
    std::thread t8(train, &sangt, 0, 8);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    t7.join();
    t8.join();
}