#include <iostream>
#include "windowTools.h"
#include "Snake.h"
#include "Food.h"
#include <conio.h>
#include "GameController.h"
#include "GlobalConfig.h"

// 游戏是否结束
bool over = false;
// 创建蛇
Snake snake;
// 声明键盘输入函数
int handlerKeyInput();

int main() {
    Tools::SetWindowSize(WIDTH, HEIGHT);

    // 主循环
    bool eat;// 是否吃到食物
    // 先刷新一个食物
    Food::fresh();
    while (!over) {
        handlerKeyInput();// 循环处理键盘点击事件
        snake.render();// 渲染蛇
        // 检测是否撞墙
        // 检测是否撞到自己
        // 检测是否吃到食物
        eat = Game::isCollide(snake.getHead().x, snake.getHead().y, Food::food.x, Food::food.y);
        // 如果吃到，蛇的长度+1，并且刷新食物
        if(eat) {
            snake.eat(1);
            Food::fresh();// 刷新食物
        }
        Sleep(50);
    }

    // 结束后暂停游戏
    Tools::AtPosition(5, HEIGHT-2, [](){
        Tools::SetColor(1);
        system("pause");
    });
    return 0;
}

/**
 * 键盘输入
 * @return
 */
int handlerKeyInput() {
    if(!kbhit()) {
        return 0;// 没点击键盘
    }
    int ch = getch();// 获取输入的字符
    if(ch == 224) {// 方向键表示控制蛇的移动
        ch = getch();// 获取第二个字符
        snake.changeDirection(ch);// 根据第二个字符修改蛇的运动方向
    }else if(ch == 27){// 游戏结束
        over = true;
    }
    return ch;
}