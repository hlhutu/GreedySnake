//
// Created by zhu on 2024/6/13.
//

#ifndef CLION1_GAMECONTROLLER_H
#define CLION1_GAMECONTROLLER_H

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
}

#endif //CLION1_GAMECONTROLLER_H
