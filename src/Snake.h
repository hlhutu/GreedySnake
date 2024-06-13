//
// Created by zhu on 2024/6/13.
//

#ifndef CLION1_SNAKE_H
#define CLION1_SNAKE_H
#include <deque>
#include <utility>
#include "Anime.h"

/**
 * 蛇类
 */
class Snake {
public:
    enum Direction {UP, DOWN, LEFT, RIGHT};// 方向的枚举
    Direction direction = DOWN;// 蛇的方向
private:
    std::deque<Anime::Pixel> steps;// 蛇就是一个像素的队列
    int food = 0;// 未消化的食物
public:
    // 构造函数，一个长度为3的蛇
    explicit Snake(): food(0) {
        initFront(0, 0);
        addFront();
        addFront();
    }
    // 获取蛇头
    Anime::Pixel getHead() {
        return steps.front();
    }
    // 吃i个食物
    void eat(int i) {
        food += i;
    }
    // 初始化一个头
    void initFront(int x, int y) {
        steps.emplace_front(Anime::Pixel{x, y, "●", 13});// 最原始的头
        steps.front().show();// 展示新头
    }
    // 添加一个头
    void addFront() {
        const Anime::Pixel& oldFront = steps.front();
        // 新的头
        Anime::Pixel newFront;
        if(this->direction==Snake::UP) {
            newFront = {oldFront.x, oldFront.y-1, oldFront.s, oldFront.color};
        }else if(this->direction==Snake::DOWN) {
            newFront = {oldFront.x, oldFront.y+1, oldFront.s, oldFront.color};
        }else if(this->direction==Snake::LEFT) {
            newFront = {oldFront.x-1, oldFront.y, oldFront.s, oldFront.color};
        }else if(this->direction==Snake::RIGHT) {
            newFront = {oldFront.x+1, oldFront.y, oldFront.s, oldFront.color};
        }
        steps.emplace_front(newFront);// 加入队列
        steps.front().show();// 展示新头
    }
    // 每一帧移动蛇的位置，即创建新头，移除尾巴
    void render() {
        // 移除尾巴
        if(food>0) {
            food--;// 如果还有没消化的食物，则尾巴不变短
        }else {
            // 去掉尾部
            steps.back().clean();// 清理尾部
            steps.pop_back();// 然后出列
        }
        // 增加新的头
        addFront();
    }
    // 根据键盘输入的值，修改蛇的方向
    void changeDirection(int ch) {
        switch (ch) {
            case 72:
                if (direction != Snake::Direction::DOWN)// 不能移动到相反的方向
                    direction = Snake::Direction::UP;
                break;
            case 80:
                if (direction != Snake::Direction::UP)
                    direction = Snake::Direction::DOWN;
                break;
            case 75:
                if (direction != Snake::Direction::RIGHT)
                    direction = Snake::Direction::LEFT;
                break;
            case 77:
                if (direction != Snake::Direction::LEFT)
                    direction = Snake::Direction::RIGHT;
                break;
            default:
                break;
        }
    }
};


#endif //CLION1_SNAKE_H
