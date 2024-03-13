// Greed.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "GreedM.h"

int main() {
    test_find_next_station();
    test_num_fills();
    // Переменные для хранения емкости бака, 
    // количества АЗС и количества заправок бака
    int fuel_capacity, n, num_refills = 0;
    cout << "Input fuel capacity in km, number of points" << endl;
    // Считываем входные данные
    cin >> fuel_capacity >> n;
    int* gas_stations = new int[n];

    cout << "Input distances to gas stations " << endl;
    // Считываем расстояния до заправок
    read_gas_stations(gas_stations, n);

    // Текущая заправка
    int current_station = 0;
    //Вычисление числа заправок бака
    num_refills = num_fills(gas_stations, n, fuel_capacity);
    cout << "Число заправок минимальное:" << endl;
    // Выводим количество заправок
    cout << num_refills << endl;

    // Освобождаем выделенную память
    delete[] gas_stations;

    return 0;
}