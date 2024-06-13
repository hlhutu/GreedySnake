#ifndef TOOLS_H
#define TOOLS_H
#include <functional>
#include "windows.h"

/**
 * 定义一些窗口工具
 */
namespace Tools {
    /**
     * 设置窗口size
     * @param cols
     * @param lines
     */
    void SetWindowSize(int cols, int lines);

    /**
     * 设置光标位置
     * @param x
     * @param y
     */
    void SetCursorPosition(const int x, const int y);

    /**
     * 设置颜色
     * @param colorID
     */
    void SetColor(int colorID);

    /**
     * 设置背景颜色
     */
    void SetBackColor();

    /**
     * 在指定位置执行操作
     */
    void AtPosition(int x, int y, const std::function<void()> &func);
}

#endif // TOOLS_H
