//
// Created by zhu on 2024/6/14.
//

#ifndef CLION1_MAP_H
#define CLION1_MAP_H

#include "GlobalConfig.h"
#include "Anime.h"
#include "vector"

/**
 * 游戏地图
 */
namespace Map {
    // 地图矩阵，是一个数组
    std::vector<Anime::Pixel> walls;
    // 地图的宽高
    int h, w;

    // 获取所有墙
    std::vector<Anime::Pixel>& getWalls() {
        return walls;
    }

    // 初始化地图
    void initMap() {
        h = HEIGHT-1, w = WIDTH - 1 - 10;// 右边预留一些空间
        for (int x = 0; x <= w ; ++x) {
            if(x==0 || x==w) {// 边界部分全部打印
                for (int y = 0; y <= h ; ++y) {
                    walls.push_back({x, y, "■", 1});
                }
            }else {// 非边界部分只打印上下
                walls.push_back({x, 0, "■", 1});
                walls.push_back({x, h, "■", 1});
            }
        }
    }

    // 刷新地图，就是循环展示
    void fresh() {
        if(walls.empty()) {
            initMap();
        }
        // 展示所有节点
        for (const auto &item: walls) {
            item.show();
        }
    }
}

#endif //CLION1_MAP_H
