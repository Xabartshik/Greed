#pragma once
#include <iostream>
using namespace std;



// Функция для считывания расстояний до заправок
void read_gas_stations(int* gas_stations, int n);

// Функция для поиска следующей заправки
int find_next_station(int current_station, int* gas_stations, int n, int fuel_capacity);
//Вычисление минимального числа заправок бака
unsigned num_fills(int* gas_stations, int n, int fuel_capacity);
//Тест num_fills
void test_num_fills();
//Тест find_next_station
void test_find_next_station();