#include "windowTools.h"
#include "Snake.h"
#include "Food.h"
#include "Map.h"
#include "GameController.h"
#include "GlobalConfig.h"
#include "Menu.h"

// 游戏开始
int gameStart() {
    // 游戏结束标志
    bool over = false;
    // 游戏刷新率，值越小，刷新越快，难度越高
    int speed = 50;
    // 创建蛇
    Snake snake(3);
    // 清屏
    Anime::cls();
    // 绘制地图
    Map::fresh();
    // 清空食物
    Food::eatAll();

    // 指令对应的操作
    std::map<int, std::function<void(int)>> handlerMap;
    // 改变蛇方向的处理函数
    std::function<void(int)> changeDirectionHandler = [&](int ch) {
        snake.changeDirection(ch);// 根据第二个数字改变方向
    };
    // 四个方向键对应的处理函数相同
    handlerMap[72] = changeDirectionHandler;
    handlerMap[80] = changeDirectionHandler;
    handlerMap[75] = changeDirectionHandler;
    handlerMap[77] = changeDirectionHandler;
    // 退出键
    handlerMap[27] = [](int ch) {
        // 弹出对话框
        int i = Menu::gameOver();
        if(i==1) {
            return gameStart();// 重新启动游戏
        }
        return 0;
    };

    // 主循环
    while (!over) {
        // 接收用户输入，并处理
        Game::handlerKeyInput(handlerMap);

        snake.render();// 渲染蛇
        Food::fresh();// 刷新食物

        // 检测蛇头是否撞墙
        over = Game::isCollide({snake.getHead()}, Map::getWalls());
        if (over) break;// 立即结束游戏
        // 检测蛇头是否撞到自己的身体
        over = Game::isCollide({snake.getHead()}, snake.getBodies());
        if (over) break;// 立即结束游戏

        // 检测是否吃到食物
        bool eat = Game::isCollide(snake.getHead().x, snake.getHead().y, Food::food.x, Food::food.y);
        // 如果吃到，蛇的长度+1，食物数量-1
        if(eat) {
            snake.eat(1);// 蛇的肚子吃进1食物
            Food::eatFood(1);// 食物减少1
        }
        Sleep(speed);
    }
    // 结束弹出提示
    int i = Menu::gameOver();
    if(i==1) {
        return gameStart();// 重新启动游戏
    }
    return 0;
}

int main() {
    // 设置窗口
    Tools::SetWindowSize(WIDTH, HEIGHT);
    // 启动游戏
    gameStart();
    return 0;
}