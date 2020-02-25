#pragma once
#include <random>
#include <algorithm>
#include <iterator>
#include <iostream>

void PrintCardDeck(std::vector<int> myV);
void ShuffleCardDeck(std::vector<int> &myV, std::mt19937 myG);