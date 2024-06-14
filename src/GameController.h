//
// Created by zhu on 2024/6/13.
//

#ifndef CLION1_GAMECONTROLLER_H
#define CLION1_GAMECONTROLLER_H

#include <vector>
#include <set>

/**
 * 游戏控制
 */
namespace Game {

    /**
     * 碰撞检测
     */
    bool isCollide(int x1, int y1, int x2, int y2) {
        return x1==x2 && y1==y2;
    }
    /**
     * 碰撞检测，检测两个集合是否交叉
     */
    bool isCollide(std::vector<Anime::Pixel> const &v1, std::vector<Anime::Pixel> const &v2) {
        for (const auto &item1: v1) {
            for (const auto &item2: v2) {
                if(item1.x == item2.x && item1.y == item2.y) {
                    return true;
                }
            }
        }
        return false;
    }
    /**
     * 检测这个像素是否被占用
     */
    bool isCollide(int x, int y) {
        return screen[x][y];
    }
}

#endif //CLION1_GAMECONTROLLER_H
