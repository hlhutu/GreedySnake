//
// Created by zhu on 2024/6/13.
//

#ifndef CLION1_FOOD_H
#define CLION1_FOOD_H

#include "Anime.h"
#include <cstdlib>
#include "GlobalConfig.h"
#include <ctime>

/**
 * 食物相关
 */
namespace Food {
    // 食物对象
    Anime::Pixel food;

    // 刷新食物
    void fresh() {
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        // 随机位置
        int xTemp = rand()%WIDTH;
        int yTemp = rand()%HEIGHT;
        // 展示食物
        food = {xTemp, yTemp, "★", 3};
        food.show();
    }
};

#endif //CLION1_FOOD_H
