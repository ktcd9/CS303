#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <iterator>
#include <stdexcept>

using namespace std;

void find(int target, int arr[], int arrSize);
int modify(int index, int newVal, int arr[], int arrSize);
void add(int val, int arr[], int arrSize);
void removeIndex(int index, int arr[], int arrSize);