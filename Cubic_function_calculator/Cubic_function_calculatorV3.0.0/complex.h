#pragma once

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

/*
������ʵ�֣�

����ʵ�֣�
�����������������ȡ������ʵ���鲿���ж��Ƿ���Ȼ��߹���������������㣬
������������һ��Ϊʵ������������,�˷����㣬�����˶�Ԫ����������������������
������һԪ����û��̫��ʵ�����ù�û������
������λie�Ķ��������

ע�����
���븴��ʱ����ʵ����������ʵ���������鲿��
��1+i��i��3i��-3i��1-2i��-1-3i�����ǺϷ��ַ�
ֻ���鲿ʱ����ֱ�����룬����ȫ����ʵ����ѧ�������Ե��������

*/

class complex
{
	private:
		//������ʵ��
		double x = 0;
		//�������鲿
		double y = 0;


	public:
		//Ĭ���޲ι��캯��
		complex() {};
		//���캯���ĵ�һ��������ʽ(���������ʵ�����鲿)
		complex(double theX, double theY) {
			x = theX;
			y = theY;
		}
		//���캯���ĵڶ���������ʽ(ֻ����һ������ʱ��Ĭ��Ϊʵ������һ��������)
		complex(double theX) {
			x = theX;
		}
	
		//�������캯��
		complex(const complex& theComplex)
		{
			x = theComplex.x;
			y = theComplex.y;
		}

		//��������������
		friend istream& operator>> (istream& is, complex& theComplex) {
			//������ʱ���ʵ�����鲿���ݵı���
			double numberOne = -1;
			double numberTwo = -1;
			//����һ������Ϊ80��char�������Դ�����������
			char input[80];
			//���������ݴ�������֮��
			cin >> input;
			//���ö�ʵ���鲿�������жϵı���(Ĭ��Ϊ��)
			int isOne = 1;
			int isTwo = 1;
			//�����Ƿ���С�����жϵĲ����ͱ���(Ĭ��û��С����)
			bool pointOne = false;
			bool pointTwo = false;
			//�����Ƿ����鲿�Ĳ����ͱ���(Ĭ��Ϊ��)
			bool isI = false;
			bool sign = false;
			//����ѭ������
			int i = 0;
			//�жϵ�һ���ַ��Ƿ���������,�������������һ��ѭ��������һѭ��
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
			//��ʵ���ĵ�������ת��Ϊ���Լ����ʮ��������(��δ����ʵ���˲�����ľ����鲿)
			for (;; i++) {
				//����ȡ�����Ż�ո��С����ʱ�˳�ѭ��ʱ�˳�ѭ��
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
			//������С����ʱ����С������ȡ����
			if (pointOne == true) {
				for (;; i++) {
					//����ȡ�����Ż�iʱ�˳�ѭ��ʱ�˳�ѭ��
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
					//����λ��С����
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
			//���鲿(������)�ĵ�������ת��Ϊ���Լ����ʮ��������
			for (;; i++) {
				//����ȡ��i��С����ʱ�˳�ѭ��ʱ�˳�ѭ��
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
			//������С����ʱ����С������ȡ����
			if (pointTwo == true) {
				for (;; i++) {
					//����ȡ��iʱ�˳�ѭ��ʱ�˳�ѭ��
					if (input[i] == 'i'|| input[i] == '\0') {
						isI = true;
						break;
					}
					//����λ��С����
					double temp = int(input[i] - '0');
					for (int k = 0; k < i - m; k++) {
						temp /= 10;
					}
					numberTwo += temp;
				}
			}
			//����ȡ������ת��������ĳ�Ա������
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

		//�������������
		friend ostream& operator<< (ostream& os, const complex& theComplex) {
			//ʵ����Ϊ0ʱ���ʵ��
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

		//��ȡʵ�� 
		double getreal(){
			return x;
		}

		//��ȡ�鲿 
		double getimage(){
			return y;
		}

		//�����߼������"=="
		friend complex operator==(const complex& complexOne, const complex& complexTwo)
		{
			return (complexOne.x == complexTwo.x && complexOne.y == complexTwo.y);
		}

		//�Ƿ����жϺ���
		bool isConjugated(const complex& complexOne, const complex& complexTwo)
		{
			return (complexOne.x == complexTwo.x && complexOne.y + complexTwo.y == 0);
		}

		//������ 
		complex add(const complex& theComplex) const{
			complex newComplex;
			newComplex.x = x + theComplex.x;
			newComplex.y = y + theComplex.y;
			return newComplex;
		}

		//������ 
		complex sub(const complex& theComplex) const{
			complex newComplex;
			newComplex.x = x - theComplex.x;
			newComplex.y = y - theComplex.y;
			return newComplex;
		}

		//������ 
		complex mul(const complex& theComplex) const{
			complex newComplex;
			newComplex.x = x * theComplex.x - y * theComplex.y;
			newComplex.y = y * theComplex.x + x * theComplex.y;
			return newComplex;
		}


		//������ 
		complex div(const complex& theComplex) const{
			if (theComplex.x == 0 && theComplex.y == 0){
				cout << "��ĸ����Ϊ��" << endl;
			}
			complex t;
			t.x = (x * theComplex.x + y * theComplex.y) / (theComplex.x * theComplex.x + theComplex.y * theComplex.y);
			t.y = (theComplex.x * y - theComplex.y * x) / (theComplex.x * theComplex.x + theComplex.y * theComplex.y);
			return t;
		}

		//������(ǰ�����ͺ���)
		friend complex operator+(double realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber + theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//������(ǰ���ͺ���)
		friend complex operator+(int realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber + theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//������(ǰ�����󸡵���)
		friend complex operator+(const complex& c, double r)
		{
			complex newComplex;
			newComplex.x = r + c.x;
			newComplex.y = c.y;
			return newComplex;
		}

		//������(ǰ����������)
		friend complex operator+(const complex& theComplex, int realNumber)
		{
			complex newComplex;
			newComplex.x = realNumber + theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//������(ǰ�����ͺ���)
		friend complex operator-(double realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber - theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//������(ǰ���ͺ���)
		friend complex operator-(int r, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = r - theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//������(ǰ�����󸡵���)
		friend complex operator-(const complex& theComplex, double reaNumber)
		{
			complex newComplex;
			newComplex.x = reaNumber - theComplex.x;
			newComplex.y = theComplex.y;
			return newComplex;
		}

		//������(ǰ����������)
		friend complex operator-(const complex& theComplex, int realNumber)
		{
			complex newNumber;
			newNumber.x = realNumber - theComplex.x;
			newNumber.y = theComplex.y;
			return newNumber;
		}

		//������(ǰ�����ͺ���)
		friend complex operator*(double realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber * theComplex.x;
			newComplex.y = realNumber * theComplex.y;
			return newComplex;
		}

		//������(ǰ���ͺ���)
		friend complex operator*(int realNumber, const complex& theComplex)
		{
			complex newComplex;
			newComplex.x = realNumber * theComplex.x;
			newComplex.y = realNumber * theComplex.y;
			return newComplex;
		}

		//������(ǰ�����󸡵���)
		friend complex operator*(const complex& theComplex, double realNumber)
		{
			complex newNumber;
			newNumber.x = realNumber * theComplex.x;
			newNumber.y = realNumber * theComplex.y;
			return newNumber;
		}

		//������(ǰ����������)
		friend complex operator*(const complex& theNumber, int realNumber)
		{
			complex newComplex;
			newComplex.x = realNumber * theNumber.x;
			newComplex.y = realNumber * theNumber.y;
			return newComplex;
		}

		//������(ǰ�����ͺ���)
		friend complex operator/(double realNumber, const complex& theComplex)
		{
			complex newComplex(realNumber, 0);
			return newComplex.div(theComplex);
		}

		//������(ǰ���ͺ���)
		friend complex operator/(int realNumber, const complex& theComplex)
		{
			complex newComplex((double)realNumber, 0);
			return newComplex.div(theComplex);
		}

		//������(ǰ�����󸡵���)
		friend complex operator/(const complex& theComplex, double realNumber)
		{
			complex newComplex;
			newComplex.x = theComplex.x / realNumber;
			newComplex.y = theComplex.y / realNumber;
			return newComplex;
		}

		//������(ǰ����������)
		friend complex operator/(const complex& theComplex, int realNumber)
		{
			complex newComplex;
			newComplex.x = theComplex.x / (double)realNumber;
			newComplex.y = theComplex.y / (double)realNumber;
			return newComplex;
		}

		//����֮��ӷ�����
		friend complex operator+(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.add(complexTwo);
		}

		//����֮���������
		friend complex operator-(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.sub(complexTwo);
		}

		//����֮��˷�����
		friend complex operator*(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.mul(complexTwo);
		}

		//����֮���������
		friend complex operator/(const complex& complexOne, const complex& complexTwo)
		{
			return complexOne.div(complexTwo);
		}

		//���ظ��������'+='
		friend complex operator+= (complex& complexOne, const complex& complexTwo) {
			return complexOne = complexOne + complexTwo;
		}
		friend complex operator+= (complex& complexOne, const int& realNumber) {
			return complexOne = complexOne + realNumber;
		}
		friend complex operator+= (complex& complexOne, const double& realNumber) {
			return complexOne = complexOne + realNumber;
		}

		 //���ظ��������'-='
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

		 //���ظ��������'*='
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

		//���ظ��������'/='
		friend complex operator/= (complex& complexOne, const complex& complexTwo) {
			return complexOne = complexOne / complexTwo;
		}
		friend complex operator/= (complex& complexOne, const int& realNumber) {
			return complexOne = complexOne / realNumber;
		}
		friend complex operator/= (complex& complexOne, const double& realNumber) {
			return complexOne = complexOne / realNumber;
		}

		//�˷�����
		complex power(int n) {
			complex theComplex(x, y);
			complex newComplex(1, 0);
			for (int i=0; i < n; i++) {
				newComplex = theComplex * newComplex;
			}
			return newComplex;
		}
};
//����������λie 
const complex ie(0, 1);


#endif // COMPLEX_H
