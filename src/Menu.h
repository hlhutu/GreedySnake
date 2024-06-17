//
// Created by zhu on 2024/6/14.
//

#ifndef CLION1_MENU_H
#define CLION1_MENU_H

#include "GlobalConfig.h"
#include <functional>
#include <map>
#include <string>
#include <iostream>
#include "windowTools.h"

/**
 * 几个交互菜单
 */
namespace Menu {

    /**
     * 渲染选项
     */
    void drawSelection(int flag, int col, int buttonRow) {
        if(flag==1) {
            Tools::AtPosition(col+5, buttonRow, [](){
                Tools::SetBackColor();
                std::cout << "RESTART" ;
            });
            Tools::AtPosition(col+15, buttonRow, [](){
                Tools::SetColor(11);// 重置背景色
                std::cout << "CANCEL" ;
            });
        }else {
            Tools::AtPosition(col+5, buttonRow, [](){
                Tools::SetColor(11);// 重置背景色
                std::cout << "RESTART" ;
            });
            Tools::AtPosition(col+15, buttonRow, [](){
                Tools::SetBackColor();
                std::cout << "CANCEL" ;
            });
        }
        Tools::SetCursorPosition(WIDTH-1, HEIGHT-1);
    }

    /**
     * 游戏结束弹出
     */
    int gameOver() {
        /*绘制游戏结束界面*/
        Sleep(500);
        int col = 10, row = 8;
        Tools::PrintAt(col, row++, "╔═════════════════════════════════════════╗", 11);
        Tools::PrintAt(col, row++, "║                                         ║", 11);
        Tools::PrintAt(col, row++, "║         GAME OVER !!!                   ║", 11);
        Tools::PrintAt(col, row++, "║                                         ║", 11);
        Tools::PrintAt(col, row++, "║                                         ║", 11);
        Tools::PrintAt(col, row, "║         SCORE：                         ║", 11);
        Tools::PrintAt(col+8, row++, "100", 11);
        Tools::PrintAt(col, row++, "║                                         ║", 11);
        Tools::PrintAt(col, row++, "║                                         ║", 11);
        int buttonRow = row;// 标记按钮所在的行
        Tools::PrintAt(col, row++, "║         RESTART             CANCEL      ║", 11);
        Tools::PrintAt(col, row++, "║                                         ║", 11);
        Tools::PrintAt(col, row++, "╚═════════════════════════════════════════╝", 11);
        Tools::SetCursorPosition(col+1, row);

        int selected = 1;// 默认选中第一项
        drawSelection(selected, col, buttonRow);// 渲染选项

        int ch;
        bool finish = false;
        while (!finish){
            ch = getch();// 获取键盘输入
            switch (ch){
                case 75://LEFT
                    selected = 1;
                    drawSelection(selected, col, buttonRow);// 重新渲染选项
                    break;
                case 77:// RIGHT
                    selected = 2;
                    drawSelection(selected, col, buttonRow);// 重新渲染选项
                    break;
                case 13:// Enter
                    finish = true;
                    break;
                default:
                    break;
            }
        }
        return selected;
    }
}


#endif //CLION1_MENU_H
