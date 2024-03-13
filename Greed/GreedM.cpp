
#include "GreedM.h"
#include <cassert>



// Считываем расстояния до заправок
void read_gas_stations(int* gas_stations, int n) {
    for (int i = 0; i < n; i++) {
        cin >> gas_stations[i];
    }
}

// Находим следующую заправку, до которой можно доехать
int find_next_station(int current_station, int* gas_stations, int n, int gas_count) {
    // Максимальное расстояние, которое можно проехать
    int max_distance = gas_count;

    // Индекс следующей заправки
    int next_station = current_station;

    // Перебираем все заправки после текущей
    for (int i = current_station + 1; i < n; i++) {
        // Если до заправки можно доехать
        if (gas_stations[i] - gas_stations[current_station] <= max_distance) {
            // Обновляем индекс следующей заправки
            next_station = i;
        }
    }

    // Возвращаем индекс следующей заправки
    return next_station;
}

// Находим следующую заправку, до которой можно доехать
int find_next_station_from_distance(int distance, int* gas_stations, int n, int gas_count) {
    // Максимальное расстояние, которое можно проехать
    int max_distance = gas_count;

    // Индекс следующей заправки
    int current_station = 0, next_station = current_station;

    // Перебираем все заправки после текущей
    for (int i = current_station + 1; i < n; i++) {
        // Если до заправки можно доехать
        if (gas_stations[i] - distance <= max_distance) {
            // Обновляем индекс следующей заправки
            next_station = i;
        }
    }

    // Возвращаем индекс следующей заправки
    return next_station;
}

//Вычисление минимального числа заправок бака
unsigned num_fills(int* gas_stations, int n, int fuel_capacity)
{
    // Текущая заправка
    int current_station = 0, num_refills=0, gas_count = fuel_capacity;
    //Для проверки, сможем ли мы уехать с 0
    int next_station = find_next_station(0, gas_stations, n, fuel_capacity);
    gas_count -= (gas_stations[next_station] - 0);
    // Если до следующей заправки не хватает топлива
    if ((gas_stations[next_station] - 0) >= gas_count) {
        // Увеличиваем количество заправок
        num_refills++;
        gas_count = fuel_capacity;
    }


    // Пока не доехали до конечной точки
    while (current_station < (n-1)) {
        // Находим следующую заправку
        int next_station = find_next_station(current_station, gas_stations, n, fuel_capacity);
        gas_count -= (gas_stations[next_station] - gas_stations[current_station]);
        // Если до следующей заправки не хватает топлива
        if ((gas_stations[next_station] - gas_stations[current_station]) >= gas_count) {
            // Увеличиваем количество заправок
            if (next_station != (n - 1))
            {
            num_refills++;
            }
            gas_count = fuel_capacity;
        }

        // Перемещаемся на следующую заправку
        current_station = next_station;
    }
    return num_refills;
}
//Тест find_next_station
void test_find_next_station() {
    int n = 3;
    int gas_stations[3] = { 10, 20, 30 };
    int current_station = 0;
    int fuel_capacity = 15;

    int next_station = find_next_station(current_station, gas_stations, n, fuel_capacity);

    assert(next_station == 1);

    current_station = 1;
    fuel_capacity = 10;

    next_station = find_next_station(current_station, gas_stations, n, fuel_capacity);

    assert(next_station == 2);
}
//Тест num_fills
void test_num_fills() {
    int n = 3;
    int gas_stations[3] = { 10, 20, 30 };
    int fuel_capacity = 15;

    int num_refills = num_fills(gas_stations, n, fuel_capacity);

    assert(num_refills == 2);

    n = 4;
    int gas_stations2[4] = { 10, 20, 40, 60 };
    fuel_capacity = 20;

    num_refills = num_fills(gas_stations2, n, fuel_capacity);

    assert(num_refills == 3);
}
