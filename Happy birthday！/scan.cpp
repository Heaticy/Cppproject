#include <conio.h>
#include "scan.h"

using namespace std;
 
int ch;
void scan(int &n) {
   
        if (_kbhit())
        {
            //如果有按键按下，则_kbhit()函数返回真
            ch = _getch();//使用_getch()函数获取按下的键值
            if (ch == 27) {
                n=0;
            }//当按下ESC时循环，ESC键的键值时27.
        }
    }



