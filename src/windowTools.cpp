#include "windowTools.h"
#include <windows.h>
#include <cstdio>
#include <string>

/**
 * windows工具类
 */
namespace Tools {
    void SetWindowSize(int cols, int rows)//设置窗口大小
    {
        system("chcp 65001");// 设置编码
        system("title GreedyDemo");//设置窗口标题
        char cmd[30];
        sprintf(cmd, "mode con cols=%d lines=%d", cols * 2, rows);//一个图形■占两个字符，故宽度乘以2
        system(cmd);//system(mode con cols=88 lines=88)设置窗口宽度和高度
    }

    void SetCursorPosition(const int x, const int y)//设置光标位置
    {
        COORD position;
        position.X = x * 2;
        position.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), position);
    }

    void SetColor(int colorID)//设置文本颜色
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorID);
    }

    void SetBackColor()//设置文本背景色
    {
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),
                                FOREGROUND_BLUE |
                                BACKGROUND_BLUE |
                                BACKGROUND_GREEN |
                                BACKGROUND_RED );
    }

    /**
     * 在指定位置执行操作
     */
    void AtPosition(int x, int y, const std::function<void()> &fun) {
        SetCursorPosition(x, y);
        fun();
    }

    /**
     * 在指定位置打印
     * @param x
     * @param y
     * @param chars
     * @param color
     */
    void PrintAt(int x, int y, std::string s, int color) {
        AtPosition(x, y, [&](){
            SetColor(color);
            printf("%s", s.c_str());
        });
    }
}
