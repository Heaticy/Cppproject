#include <conio.h>
#include "scan.h"

using namespace std;
 
int ch;
void scan(int &n) {
   
        if (_kbhit())
        {
            //����а������£���_kbhit()����������
            ch = _getch();//ʹ��_getch()������ȡ���µļ�ֵ
            if (ch == 27) {
                n=0;
            }//������ESCʱѭ����ESC���ļ�ֵʱ27.
        }
    }



