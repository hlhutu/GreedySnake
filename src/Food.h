//
// Created by zhu on 2024/6/13.
//

#ifndef CLION1_FOOD_H
#define CLION1_FOOD_H

#include <cstdlib>
#include "GlobalConfig.h"
#include <ctime>
#include "Map.h"
#include "GameController.h"

/**
 * 食物相关
 */
namespace Food {
    // 食物对象
    Anime::Pixel food;
    // 食物数量
    int foodCount = 0;
    // 食物最大数量
    int maxFoodCount = 1;

    // 吃掉指定数量的食物
    void eatFood(int i) {
        foodCount-=i;//这里不需要清理坐标，因为每次只能吃一个，食物的位置直接被蛇头占用了
    }

    // 吃掉全部，这个只清空计数器，不清理坐标，多个食物的情况下会有问题
    void eatAll() {
        foodCount = 0;
    }

    // 获取随机位置，指定一个区域内获取，如果这个位置有内容，则重新获取
    std::pair<int, int> randomPixel(int startX, int startY, int endX, int endY, int count) {
        if(count>5) {// 超过5次失败，就不再重试
            return std::make_pair(-1, -1);// 返回-1,-1的位置表示失败
        }
        int xTemp = rand()%(endX+1)+startX;// 随机获取一个 startX~endX 的数字（头尾包含）
        int yTemp = rand()%(endY+1)+startY;
        // 发生了碰撞就再次随机获取
        if(Game::isCollide(xTemp, yTemp)) {
            count++;
            return randomPixel(startX, startY, endX, endY, count);
        }else {
            return std::make_pair(xTemp, yTemp);
        }
    }

    // 刷新食物
    void fresh() {
        if(foodCount>=maxFoodCount) {
            return;
        }
        // 设置随机种子
        std::srand(static_cast<unsigned int>(std::time(nullptr)));
        // 获取随机位置
        std::pair<int, int> pair = randomPixel(1, 1, Map::w-1, Map::h-1, 0);
        if(pair.first>=0 && pair.second>-0) {// 如果得到一个有效的位置，才表示刷新成功
            // 展示食物
            foodCount++;
            food = {pair.first, pair.second, "★", 12};
            food.show();
        }
    }
}

#endif //CLION1_FOOD_H
