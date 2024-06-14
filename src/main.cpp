#include <iostream>
#include "windowTools.h"
#include "Snake.h"
#include "Food.h"
#include "Map.h"
#include <conio.h>
#include "GameController.h"
#include "GlobalConfig.h"

// 游戏是否结束
bool over = false;
// 游戏刷新率，值越小，刷新越快，难度越高
int speed = 100;
// 创建蛇
Snake snake(1);
// 声明键盘输入函数
bool handlerKeyInput();

int main() {
    Tools::SetWindowSize(WIDTH, HEIGHT);
    // 绘制地图
    Map::fresh();

    // 是否吃到食物
    bool eat;
    // 主循环
    while (!over) {
        over = handlerKeyInput();// 循环处理键盘点击事件
        if (over) break;// 立即结束游戏

        snake.render();// 渲染蛇
        Food::fresh();// 刷新食物

        // 检测蛇头是否撞墙
        over = Game::isCollide({snake.getHead()}, Map::getWalls());
        if (over) break;// 立即结束游戏
        // 检测蛇头是否撞到自己的身体
        over = Game::isCollide({snake.getHead()}, snake.getBodies());
        if (over) break;// 立即结束游戏

        // 检测是否吃到食物
        eat = Game::isCollide(snake.getHead().x, snake.getHead().y, Food::food.x, Food::food.y);
        // 如果吃到，蛇的长度+1，食物数量-1
        if(eat) {
            snake.eat(1);// 蛇的肚子吃进1食物
            Food::eatFood(1);// 食物减少1
        }
        Sleep(speed);
    }

    // 结束后暂停游戏
    Tools::AtPosition(5, HEIGHT-2, [](){
        Tools::SetColor(2);
        system("pause");
    });
    return 0;
}

/**
 * 键盘输入，返回true表示游戏结束
 * @return
 */
bool handlerKeyInput() {
    if(!kbhit()) {
        return false;// 没点击键盘
    }
    int ch = getch();// 获取输入的字符
    if(ch == 224) {// 方向键表示控制蛇的移动
        ch = getch();// 获取第二个字符
        snake.changeDirection(ch);// 根据第二个字符修改蛇的运动方向
    }else if(ch == 27){// 游戏结束
        return true;
    }
    return false;
}