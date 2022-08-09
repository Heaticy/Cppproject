#include <iostream>
#include <math.h>
#include <iomanip>
#include "complex.h"
using namespace std;
double cur(double P)
{if(P>0){return pow(P,1.0/3.0);}
if(P==0){return 0;}
if(P<0){return -pow(-P,1.0/3.0);}
} 
double a,b,c,d;
int main()
{   cout<<"V0.5.0 用爆算法计算最值"<<endl
<<"V1.0.0 重大更新，改用全新求导算法计算最值，并可求极值，优化对无穷的界定"<<endl
<<"V1.5.0 修复部分函数无法正常输出最值的bug"<<endl
<<"V2.0.0 增加求二次函数最值的功能"<<endl
<<"V3.0.0 重大更新，增加以卡丹公式算法求部分三次函数零点的功能，增加复数类"<<endl
<<"V3.5.0 更换零点算法为二分法，将求解范围扩增到全体三次方程"<<endl
<<"V3.5.1 更换算法为牛顿迭代法，进一步精确结果"<<endl
<<"V3.5.2 更换算法为盛金公式，优化复数类，精确零点求解"<<endl
<<"V3.5.3 优化界面，增加更新日志" <<endl
<<"V3.5.4 优化三次方根的计算，修复部分函数无法计算零点的bug" <<endl;
	int n = 1;
	while (n) {
		cout << "函数最值计算器" << endl << "请输入函数(二次函数a=0)ax^3+bx^2+cx+d" << endl << "a=";
		double  min,max;

		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "c=";
		cin >> c;
		cout << "d=";
		cin >> d;
		cout << "计算零点请输入1      求最值极值请输入2     重新输入函数请输入0" << endl;
		int g;
		cin >> g;
		switch (g) {
		case 1:
			if (a != 0) {
			 double A, B, C, delta, si;
    double x1, x2, x3;
   
    if (a > 500 || b > 500 || c > 500)
    {
        cout << "数值溢出无法计算！！！" << endl;
        return 0;
    }

    //使用盛金公式
    A = b * b - 3 * a * c;
    B = b * c - 9 * a * d;
    C = c * c - 3 * b * d;
    delta = B * B - 4 * A * C;

    ///有三个重根的情况
    if (A == B && A == 0)
    {
        x1 = -b / (3 * a);
        x2 = x1;
        x3 = x1;
        cout << "有三个等实根" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << fixed << setprecision(3) << x3 << " ";
        cout << "x3=" << fixed << setprecision(3) << x2 << " ";
    }

    //有两个等根的情况
    else if (delta <= 1e-5 && delta >= -1e-5 && (A != B || A != 1e-5))
    {
        double K = B / A;
        x1 = -b / a + K;
        x2 = -K / 2;
        x3 = x2;
        cout << "有三个实根，其中两个为等根" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << fixed << setprecision(3) << x3 << " ";
        cout << "x3=" << fixed << setprecision(3) << x2 << " ";
    }

    //存在三个不同实根的情况
    else if (delta < -1e-5 && (A != B || A != 1e-5))
    {
        double T = (2 * A * b - 3 * a * B) / (2 * pow(A, 1.5));
        si = acos(T);
        x1 = (-b - 2 * sqrt(A) * cos(si / 3)) / (3 * a);
        x2 = (-b + sqrt(A) * (cos(si / 3) + sqrt(3) * sin(si / 3))) / (3 * a);
        x3 = (-b + sqrt(A) * (cos(si / 3) - sqrt(3) * sin(si / 3))) / (3 * a);
        cout << "有三个实根，各不相等" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << fixed << setprecision(3) << x3 << " ";
        cout << "x3=" << fixed << setprecision(3) << x2 << " ";
    }

    //存在共轭虚根的情况
    else
    {
        double Y1 = A * b + 3 * a * ((-B + pow(delta, 1.0 / 2.0)) / 2);
        double Y2 = A * b + 3 * a * ((-B - pow(delta, 1.0 / 2.0)) / 2);
        double U = cur(Y1) +cur(Y2);
        double UU= cur(Y1) -cur(Y2);
        x1 = (-b - U )/ (3 * a);
        complex xc2, xc3;
        complex V1(0.5*U-b, UU*sqrt(3) / 2.0);
        complex V2(0.5*U-b, -UU*sqrt(3) / 2.0);
        xc2 = V1 / (3 * a);
        xc3 = V2 / (3 * a);
        cout << "有一个实根，两个共轭虚根" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << xc2 << " ";
        cout << "x3=" << xc3 << " ";
    }
			}
			cout << endl << "重新输入函数输入1，退出输入0" << endl;
			cin >> n;
			break;


		case 2:
			cout << "请输入范围【min，max】若需要使用无穷，请自行输入一个较大或较小的数字" << endl << "min=";
			cin >> min;
			cout << "max=";
			cin >> max;
			while (min > max)
			{
				cout << "min>max 请重新输入" << endl;
				cout << "min=";
				cin >> min;
				cout << "max=";
				cin >> max;
			}

			if (a > 0) {
				//3ax^2+2bx^2+c
				double e = 4 * b * b - 12 * a * c;
				if (e > 0)
				{
					double f = sqrt(e);
					double x1 = (-2 * b - f) / (6 * a);
					double x2 = (-2 * b + f) / (6 * a);
					cout.precision(2);
					cout.setf(ios::fixed);
					if (min <= x1 && x1 < x2 && x2 <= max) {
						double fx1, fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						if (fx1 > fmax) { fxmax = fx1; xmax = x1; }
						else { fxmax = fmax; xmax = max; }
						if (fx2 < fmin) { fxmin = fx2; xmin = x2; }
						else { fxmin = fmin; xmin = min; }
						cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
							<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
							<< "极大值" << "f(" << x1 << ")=" << fx1 << ",  "
							<< "极小值" << "f(" << x2 << ")=" << fx2;
					}
					if (min <= x1 && x1 <= max && max < x2) {
						double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmax = fx1; xmax = x1;
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "最大值=" << "f(" << x1 << ")=" << fx1 << "，"
							<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
							<< "极大值=" << "f(" << x1 << ")=" << fx1 << ",  "
							<< "无极小值";
					}
					if (x1 < min && min <= x2 && x2 <= max) {
						double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmin = fx2; xmin = x2;
						if (fmin > fmax) { fxmax = fmin; xmax = min; }
						else { fxmax = fmax; xmax = max; }
						cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
							<< "最小值=" << "f(" << x2 << ")=" << fx2 << endl
							<< "极小值=" << "f(" << x2 << ")=" << fx2 << ",  "
							<< "无极大值";
					}
					if (x1 < min && min <= max && max < x2) {
						double fmin, fmax;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						cout << "最大值=" << "f(" << min << ")=" << fmin << "，"
							<< "最小值=" << "f(" << max << ")=" << fmax << endl
							<< "无极大值" << ",  "
							<< "无极小值";
					}
					if (x2<min || x1>max)
					{
						double fxmin, fxmax;
						fxmin = a * min * min * min + b * min * min + c * min + d;
						fxmax = a * max * max * max + b * max * max + c * max + d;
						cout << "最大值=" << "f(" << max << ")=" << fxmax << "，"
							<< "最小值=" << "f(" << min << ")=" << fxmin << endl
							<< "无极大值" << ",  "
							<< "无极小值";
					}
				}
				if (e <= 0) {
					double fxmin, fxmax;
					fxmin = a * min * min * min + b * min * min + c * min + d;
					fxmax = a * max * max * max + b * max * max + c * max + d;
					cout << "最大值=" << "f(" << max << ")=" << fxmax << "，"
						<< "最小值=" << "f(" << min << ")=" << fxmin << endl
						<< "无极大值" << ",  "
						<< "无极小值";
				}
			}



			if (a < 0) {
				//3ax^2+2bx+c
				double e = 4 * b * b - 12 * a * c;
				if (e > 0)
				{
					double f = sqrt(e);
					double x2 = (-2 * b - f) / (6 * a);
					double x1 = (-2 * b + f) / (6 * a);
					cout.precision(2);
					cout.setf(ios::fixed);
					if (min <= x1 && x2 <= max) {
						double fx1, fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						if (fx2 > fmin) { fxmax = fx2; xmax = x2; }
						else { fxmax = fmin; xmax = min; }
						if (fx1 < fmax) { fxmin = fx1; xmin = x1; }
						else { fxmin = fmax; xmin = max; }
						cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
							<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
							<< "极大值" << "f(" << x2 << ")=" << fx2 << ",  "
							<< "极小值" << "f(" << x1 << ")=" << fx1;
					}
					if (min <= x1 && x1 <= max && max < x2) {
						double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmin = fx1; xmin = x1;
						if (fmin > fmax) { fxmax = fmin; xmax = min; }
						else { fxmax = fmax; xmax = max; }
						cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
							<< "最小值=" << "f(" << x1 << ")=" << fx1 << endl
							<< "极小值=" << "f(" << x1 << ")=" << fx1 << ",  "
							<< "无极大值";
					}
					if (x1 < min && min <= x2 && x2 <= max) {
						double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmax = fx2; xmax = x2;
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "最大值=" << "f(" << x2 << ")=" << fx2 << "，"
							<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
							<< "极大值=" << "f(" << x2 << ")=" << fx2 << ",  "
							<< "无极小值";
					}
					if (x1 < min && min <= max && max < x2) {
						double fxmin, fxmax;
						fxmin = a * min * min * min + b * min * min + c * min + d;
						fxmax = a * max * max * max + b * max * max + c * max + d;
						cout << "最大值=" << "f(" << max << ")=" << fxmax << "，"
							<< "最小值=" << "f(" << min << ")=" << fxmin << endl
							<< "无极大值" << ",  "
							<< "无极小值";
					}
					if (x2<min || x1>max) {
						double fmin, fmax;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						cout << "最大值=" << "f(" << min << ")=" << fmin << "，"
							<< "最小值=" << "f(" << max << ")=" << fmax << endl
							<< "无极大值" << ",  "
							<< "无极小值";
					}
				}
				if (e <= 0) {
					double fmin, fmax;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					cout << "最大值=" << "f(" << min << ")=" << fmin << "，"
						<< "最小值=" << "f(" << max << ")=" << fmax << endl
						<< "无极大值" << ",  "
						<< "无极小值";
				}

			}

			if (a == 0) { //2bx+c 
				double x0 = -c / （2 * b）;
				double fmin = b * min * min + c * min + d;
				double fmax = b * max * max + c * max + d;
				double fxmax, fxmin, xmax, xmin;
				double fx0 = b * x0 * x0 + c * x0 + d;
				if (min <= x0 && x0 <= max)
				{
					if (b > 0) {
						fxmin = fx0; xmin = x0;
						if (fmin > fmax) { fxmax = fmin; xmax = min; }
						else { fxmax = fmax; xmax = max; }
						cout << "最小值=" << "f(" << xmin << ")=" << fxmin << "，"
							<< "最大值=" << "f(" << xmax << ")=" << fxmax << endl;
					}
					if (b < 0) {
						fxmax = fx0; xmax = x0;
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "最小值=" << "f(" << xmin << ")=" << fxmin << "，"
							<< "最大值=" << "f(" << xmax << ")=" << fxmax << endl;
					}
					if (b == 0) {
						if (fmin > fmax) { fxmax = fmin; xmax = min; }
						else { fxmax = fmax; xmax = max; }
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "最小值=" << "f(" << xmin << ")=" << fxmin << "，"
							<< "最大值=" << "f(" << xmax << ")=" << fxmax << endl;
					}

				}
				if (x0<min || x0>max) {
					if (fmin > fmax) { fxmax = fmin; xmax = min; }
					else { fxmax = fmax; xmax = max; }
					if (fmax < fmin) { fxmin = fmax; xmin = max; }
					else { fxmin = fmin; xmin = min; }
					cout << "最小值=" << "f(" << xmin << ")=" << fxmin << "，"
						<< "最大值=" << "f(" << xmax << ")=" << fxmax << endl;

				}
			}
			cout << endl << "重新输入函数输入1，退出输入0" << endl;
			cin >> n;
			break;
			

             default:
				n = 1;

		}

	}
		
	return 0;
}



