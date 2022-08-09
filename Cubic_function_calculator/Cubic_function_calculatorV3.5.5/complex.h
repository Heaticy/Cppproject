#pragma once

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

/*
复数类实现：

功能实现：
复数的输入输出，获取复数的实部虚部，判断是否相等或者共轭，复数的四则运算，
复数运算中有一个为实数的四则运算,乘方运算，重载了二元算术运算符，复合运算符，
复数的一元运算没有太多实际作用故没有重载
虚数单位ie的定义在最后

注意事项：
输入复数时若有实部则先输入实部再输入虚部，
如1+i，i，3i，-3i，1-2i，-1-3i，都是合法字符
只有虚部时可以直接输入，都完全可以实现数学符号语言的输入输出

*/

class complex
{
	private:
		//复数的实部
		double x = 0;
		//复数的虚部
		double y = 0;


	public:
		//默认无参构造函数
		complex() {};
		//构造函数的第一种重载形式(传入参数有实部和虚部)
		complex(double theX, double theY) {
			x = theX;
			y = theY;
		}
		//构造函数的第二种重载形式(只传入一个参数时，默认为实部，是一个纯虚数)
		complex(double theX) {
			x = theX;
		}
	
		//拷贝构造函数
		complex(const complex& theComplex)
		{
			x = theComplex.x;
			y = theComplex.y;
		}

		//重载输入流函数
		friend istream& operator>> (istream& is, complex& theComplex) {
			//两个临时存放实部和虚部数据的变量
			double numberOne = -1;
			double numberTwo = -1;
			//创建一个长度为80的char型数组以储存输入数据
			char input[80];
			//将输入数据传入数组之中
			cin >> input;
			//设置对实部虚部正负型判断的变量(默认为正)
			int isOne = 1;
			int isTwo = 1;
			//设置是否有小数点判断的布尔型变量(默认没有小数点)
			bool pointOne = false;
			bool pointTwo = false;
			//设置是否有虚部的布尔型变量(默认为无)
			bool isI = false;
			bool sign = false;
			//设置循环变量
			int i = 0;
			//判断第一个字符是否是正负号,如果是则跳过这一次循环进入下一循环
			if (input[i] == '-') {
				isOne = -1;
				i++;
			}
			else if (input[i] == '+') {
				i++;
			}
			else if (input[i] != 'i') {
				numberOne = 0;
			}
			int n = i;
			//将实部的单个数字转换为可以计算的十进制数字(若未输入实部此步输入的就是虚部)
			for (;; i++) {
				//当读取到符号或空格或小数点时退出循环时退出循环
				if (input[i] == 'i'||input[i]=='+' || input[i] == '-'||input[i] == '.'|| input[i] == '\0') {
					if (input[i] == '-') {
						isTwo = -1;
						sign = true;
					}
					else if (input[i] == '.') {
						pointOne = true;
					}
					else if (input[i] == 'i') {
						isI = true;
					}
					else if (input[i] == '+') {
						sign = true;
					}
					break;
				}
				if (n == i) {
					numberOne = 0;
				}
				numberOne = 10 * numberOne + int(input[i] - '0');
			}
			int j = i;
			i++;
			//当存在小数点时进行小数点后读取操作
			if (pointOne == true) {
				for (;; i++) {
					//当读取到符号或i时退出循环时退出循环
					if (input[i] == 'i' || input[i] == '+' || input[i] == '-' || input[i] == '\0') {
						if (input[i] == '-') {
							isTwo = -1;
							sign = true;
						}
						else if (input[i] == 'i') {
							isI = true;
						}
						else if (input[i] == '+') {
							sign = true;
						}
						break;
					}
					//按数位缩小数字
					double temp = int(input[i] - '0');
					for (int k = 0; k < i - j; k++) {
						temp /= 10;
					}
					numberOne += temp;
				}
			}
			if (input[i] == 'i') {
				isI = true;
			}
			if (input[i] != 'i') {
				numberTwo = 0;
			}
			if (pointOne == true) {
				i++;
			}
			//将虚部(若存在)的单个数字转换为可以计算的十进制数字
			for (;; i++) {
				//当读取到i或小数点时退出循环时退出循环
				if (input[i] == 'i' || input[i] == '.'|| input[i] == '\0') {
					if (input[i] == '.') {
						pointTwo = true;
					}
					else if (input[i] == 'i') {
						isI = true;
					}
					break;
				}
				numberTwo = 10 * numberTwo + int(input[i] - '0');
			}
			int m = i;
			i++;
			//当存在小数点时进行小数点后读取操作
			if (pointTwo == true) {
				for (;; i++) {
					//当读取到i时退出循环时退出循环
					if (input[i] == 'i'|| input[i] == '\0') {
						isI = true;
						break;
					}
					//按数位缩小数字
					double temp = int(input[i] - '0');
					for (int k = 0; k < i - m; k++) {
						temp /= 10;
					}
					numberTwo += temp;
				}
			}
			//将读取的数字转换到对象的成员变量中
			if (numberOne >= 0 && numberTwo < -10 && sign == false && isI == false && isOne == 1 && isTwo == 1) {
				theComplex.x = numberOne;
			}
			else if (numberOne >= 0 && numberTwo < -10 && sign == false && isI == false && isOne == -1 && isTwo == 1) {
				theComplex.x = -numberOne;
			}
			else if (numberOne == -1 && numberTwo == 0 && sign == false && isI == true && isOne == 1 && isTwo == 1) {
				theComplex.y = 1;
			}
			else if (numberOne == -1 && numberTwo == 0 && sign == false && isI == true && isOne == -1 && isTwo == 1) {
				theComplex.y = -1;
			}
			else if (numberOne >= 0 && numberTwo == 0 && sign == false && isI == true && isOne == 1 && isTwo == 1) {
				theComplex.y = numberOne;
			}
			else if (numberOne >= 0 && numberTwo == -1 && sign == false && isI == true && isOne == 1 && isTwo == 1) {
				theComplex.y = numberOne;
			}
			else if (numberOne >= 0 && numberTwo == -1 && sign == false && isI == true && isOne == -1 && isTwo == 1) {
				theComplex.y = -numberOne;
			}
			else if (numberOne >= 0 && numberTwo == 0 && sign == false && isI == true && isOne == -1 && isTwo == 1) {
				theComplex.y = -numberOne;
			}
			else if (numberOne >= 0 && numberTwo == -1 && sign == true && isI == true && isOne == 1 && isTwo == 1) {
				theComplex.x = numberOne;
				theComplex.y = 1;
			}
			else if (numberOne >= 0 && numberTwo == -1 && sign == true && isI == true && isOne == 1 && isTwo == -1) {
				theComplex.x = numberOne;
				theComplex.y = -1;
			}
			else if (numberOne >= 0 && numberTwo == -1 && sign == true && isI == true && isOne == -1 && isTwo == -1) {
				theComplex.x = -numberOne;
				theComplex.y = -1;
			}
			else if (numberOne >= 0 && numberTwo == -1 && sign == true && isI == true && isOne == -1 && isTwo == 1) {
				theComplex.x = -numberOne;
				theComplex.y = 1;
			}
			else if (numberOne >= 0 && numberTwo == 1 && sign == true && isI == true && isOne == -1 && isTwo == -1) {
				theComplex.x = numberOne;
				theComplex.y = numberTwo;
			}
			else if (numberOne >= 0 && numberTwo > 0 && sign == true && isI == true && isOne == 1 && isTwo == 1) {
				theComplex.x = numberOne;
				theComplex.y = numberTwo;
			}
			else if (numberOne >= 0 && numberTwo == 0 && sign == true && isI == true && isOne == -1 && isTwo == 1) {
				theComplex.x = -numberOne;
				theComplex.y = 1;
			}
			else if (numberOne >= 0 && numberTwo == 0 && sign == true && isI == true && isOne == 1 && isTwo == 1) {
				theComplex.x = numberOne;
				theComplex.y = 1;
			}
			else if (numberOne >= 0 && numberTwo == 0 && sign == true && isI == true && isOne == -1 && isTwo == -1) {
				theComplex.x = -numberOne;
				theComplex.y = -1;
			}
			else if (numberOne >= 0 && numberTwo > 0 && sign == true && isI == true && isOne == 1 && isTwo == -1) {
				theComplex.x = numberOne;
				theComplex.y = -numberTwo;
			}
			else {
				theComplex.x = numberOne * isOne;
				theComplex.y = numberTwo * isTwo;
			}
			return is;
		}

		//重载输出流函数
		friend ostream& operator<< (ostream& os, const complex& theComplex) {
			//实部不为0时输出实部
			if (theComplex.x != 0) {
				os << theComplex.x;
				if (theComplex.y > 0 && theComplex.y != 1) {
					os << "+" << theComplex.y;
				}
				else if (theComplex.y < 0 && theComplex.y != -1) {
					os << theComplex.y;
				}
				else if (theComplex.y == 1) {
					os << "+";
				}
				else if (theComplex.y == -1) {
					os << "-";
				}
				if (theComplex.y != 0) {
					os << "i";
				}
			}
			else if (theComplex.x == 0) {
				if (theComplex.y < 0 && theComplex.y != -1) {
					os << theComplex.y;
				}
				else if (theComplex.y == -1) {
					os << "-";
				}
				if (theComplex.y > 0 && theComplex.y != 1) {
					os << theComplex.y;
				}
				if (theComplex.y != 0) {
					os << "i";
				}
				else {
					os << 0;
				}
			}
			return os;
		}

		//获取实部 
		double getreal(){
			return x;
		}

		//获取虚部 
		double getimage(){
			return y;
		}

		//重载逻辑运算符"=="
		friend complex operator==(const complex& complexOne, const complex& complexTwo)
		{
			return (complexOne.x == complexTwo.x && complexOne.y == complexTwo.y);
		}

		//是否共轭判断函数
		bool isConjugated(const complex& complexOne, const complex& complexTwo)
		{
			return (complexOne.x == complexTwo.x && complexOne.y + complexTwo.y == 0);
		}

		//加运算 
		complex add(const complex& theComplex) const{
			complex newComplex;
			newComplex.x = x + theComplex.x;
			newComplex.y = y + theComplex.y;
			return newComplex;
		}

		//减运算 
		complex sub(const complex& theComplex) const{
			complex newComplex;
			newComplex.x = x - theComplex.x;
			newComplex.y = y - theComplex.y;
			return newComplex;
		}

		//乘运算 
		complex mul(const complex& theComplex) const{
			complex newComplex;
			newComplex.x = x * theComplex.x - y * theComplex.y;
			newComplex.y = y * theComplex.x + x * theComplex.y;
			return newComplex;
		}


		//除运算 
		complex div(const complex& theComplex) const{
			if (theComplex.x == 0 && theComplex.y == 0){
				cout << "分母不能为零" << endl;
			}
			complex t;
			t.x = (x * theComplex.x + y * theComplex.y) / (theComplex.x * theComplex.x + theComplex.y * theComplex.y);
			t.y = (theComplex.x * y - theComplex.y * x) / (theComplex.x * theComplex.x + theComplex.y * theComplex.y);
			return t;
		}

		//加运算(前浮点型后复数)
		friend complex operator+(double realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber + theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//加运算(前整型后复数)
		friend complex operator+(int realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber + theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//加运算(前复数后浮点型)
		friend complex operator+(const complex& c, double r)
		{
			complex newComplex;
			newComplex.x = r + c.x;
			newComplex.y = c.y;
			return newComplex;
		}

		//加运算(前复数后整型)
		friend complex operator+(const complex& theComplex, int realNumber)
		{
			complex newComplex;
			newComplex.x = realNumber + theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//减运算(前浮点型后复数)
		friend complex operator-(double realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber - theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//减运算(前整型后复数)
		friend complex operator-(int r, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = r - theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//减运算(前复数后浮点型)
		friend complex operator-(const complex& theComplex, double reaNumber)
		{
			complex newComplex;
			newComplex.x = reaNumber - theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//减运算(前复数后整型)
		friend complex operator-(const complex& theComplex, int realNumber)
		{
			complex newNumber;
			newNumber.x = realNumber - theComplex.x;
			newNumber.y = theComplex.y;
			return newNumber;
		}

		//乘运算(前浮点型后复数)
		friend complex operator*(double realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber * theComplex.x;
			newComplex.y = realNumber * theComplex.y;
			return newComplex;
		}

		//乘运算(前整型后复数)
		friend complex operator*(int realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber * theComplex.x;
			newComplex.y = realNumber * theComplex.y;
			return newComplex;
		}

		//乘运算(前复数后浮点型)
		friend complex operator*(const complex& theComplex, double realNumber)
		{
			complex newNumber;
			newNumber.x = realNumber * theComplex.x;
			newNumber.y = realNumber * theComplex.y;
			return newNumber;
		}

		//乘运算(前复数后整型)
		friend complex operator*(const complex& theNumber, int realNumber)
		{
			complex newComplex;
			newComplex.x = realNumber * theNumber.x;
			newComplex.y = realNumber * theNumber.y;
			return newComplex;
		}

		//除运算(前浮点型后复数)
		friend complex operator/(double realNumber, const complex& theComplex)
		{
			complex newComplex(realNumber, 0);
			return newComplex.div(theComplex);
		}

		//除运算(前整型后复数)
		friend complex operator/(int realNumber, const complex& theComplex)
		{
			complex newComplex((double)realNumber, 0);
			return newComplex.div(theComplex);
		}

		//除运算(前复数后浮点型)
		friend complex operator/(const complex& theComplex, double realNumber)
		{
			complex newComplex;
			newComplex.x = theComplex.x / realNumber;
			newComplex.y = theComplex.y / realNumber;
			return newComplex;
		}

		//除运算(前复数后整型)
		friend complex operator/(const complex& theComplex, int realNumber)
		{
			complex newComplex;
			newComplex.x = theComplex.x / (double)realNumber;
			newComplex.y = theComplex.y / (double)realNumber;
			return newComplex;
		}

		//复数之间加法运算
		friend complex operator+(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.add(complexTwo);
		}

		//复数之间减法运算
		friend complex operator-(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.sub(complexTwo);
		}

		//复数之间乘法运算
		friend complex operator*(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.mul(complexTwo);
		}

		//复数之间除法运算
		friend complex operator/(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.div(complexTwo);
		}

		//重载复合运算符'+='
		friend complex operator+= (complex& complexOne, const complex& complexTwo) {
			return complexOne = complexOne + complexTwo;
		}
		friend complex operator+= (complex& complexOne, const int& realNumber) {
			return complexOne = complexOne + realNumber;
		}
		friend complex operator+= (complex& complexOne, const double& realNumber) {
			return complexOne = complexOne + realNumber;
		}

		 //重载复合运算符'-='
		friend complex operator-= (complex& complexOne, const complex& complexTwo)
		{
			return complexOne = complexOne - complexTwo;
		}
		friend complex operator-= (complex& complexOne, const int& realNumber) {
			return complexOne = complexOne - realNumber;
		}
		friend complex operator-= (complex& complexOne, const double& realNumber) {
			return complexOne = complexOne - realNumber;
		}

		 //重载复合运算符'*='
		friend complex operator*= (complex& complexOne, const complex& complexTwo)
		{
			return complexOne = complexOne * complexTwo;
		}
		friend complex operator*= (complex& complexOne, const int& realNumber) {
			return complexOne = complexOne * realNumber;
		}
		friend complex operator*= (complex& complexOne, const double& realNumber) {
			return complexOne = complexOne * realNumber;
		}

		//重载复合运算符'/='
		friend complex operator/= (complex& complexOne, const complex& complexTwo) {
			return complexOne = complexOne / complexTwo;
		}
		friend complex operator/= (complex& complexOne, const int& realNumber) {
			return complexOne = complexOne / realNumber;
		}
		friend complex operator/= (complex& complexOne, const double& realNumber) {
			return complexOne = complexOne / realNumber;
		}

		//乘方运算
		complex power(int n) {
			complex theComplex(x, y);
			complex newComplex(1, 0);
			for (int i=0; i < n; i++) {
				newComplex = theComplex * newComplex;
			}
			return newComplex;
		}
};
//定义虚数单位ie 
const complex ie(0, 1);


#endif // COMPLEX_H
