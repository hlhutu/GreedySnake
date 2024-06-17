//
// Created by zhu on 2024/6/13.
//

#ifndef CLION1_GAMECONTROLLER_H
#define CLION1_GAMECONTROLLER_H

#include <vector>
#include <set>
#include <map>
#include <functional>
#include <conio.h>

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
    /**
     * 根据键盘输入处理事件
     */
    void handlerKeyInput(const std::map<int, std::function<void(int)>>& map) {
        if(!kbhit()) {
            return;// 没点击键盘
        }
        // 获取所有字符，一次输入可能有2个字符
        int ch = getch();
        if(ch==0 || ch==224) {
            ch = getch();
        }
        // 取到对应的处理函数
        auto it = map.find(ch);
        // 如果找到对应的处理函数
        if(it!=map.end()) {
            it->second(ch);//执行处理函数
        }
    }
}

#endif //CLION1_GAMECONTROLLER_H
