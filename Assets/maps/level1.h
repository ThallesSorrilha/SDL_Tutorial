#pragma once

#include <set>

int level1[9][12] = {
    {1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 1, 1, 9, 9, 1, 1, 1, 1},
    {5, 5, 5, 5, 5, 1, 1, 9, 1, 1, 1, 1},
    {1, 1, 1, 1, 5, 1, 1, 9, 1, 5, 5, 5},
    {1, 1, 1, 1, 5, 5, 1, 9, 1, 5, 1, 1},
    {1, 1, 1, 1, 1, 5, 5, 5, 5, 5, 1, 1},
    {1, 1, 1, 1, 1, 1, 1, 9, 1, 1, 1, 1},
    {1, 1, 1, 1, 9, 9, 9, 9, 1, 1, 1, 1},
    {1, 1, 1, 1, 9, 1, 1, 1, 1, 1, 1, 1}};

std::set<int> walls = {9, 10, 11, 12};