//
// Created by zhu on 2024/6/13.
//

#ifndef CLION1_ANIME_H
#define CLION1_ANIME_H

#include "windowTools.h"
#include <iostream>
#include <set>
#include "GlobalConfig.h"

/**
 * 动画相关
 */
namespace Anime {
    /**
     * 一个像素点
     */
    struct Pixel {
        // x,y坐标
        int x, y;
        // 要显示的字符
        std::string s;
        // 颜色
        int color;
        // 展示当前像素
        void show() const {
            screen[x][y] = 1;
            // 会存在超出边界的问题，暂时不处理
            if(x>WIDTH || x<0 || y>HEIGHT|| y<0) {
            }
            Tools::AtPosition(x, y, [&](){
                Tools::SetColor(color);
                std::cout << s;
            });
        };
        // 清除当前像素
        void clean() const {
            screen[x][y] = 0;
            Tools::AtPosition(x, y, [](){
                std::cout << "  ";
            });
        }
    };

    /**
     * 测试所有像素点
     * @param color 
     */
    void testScreen() {
        int color = 0;
        for (int x = 0; x < WIDTH; ++x) {
            for (int y = 0; y < HEIGHT; ++y) {
                ++color;
                Tools::PrintAt(x, y, "■", color);
            }
        }
    }
}

#endif //CLION1_ANIME_H
