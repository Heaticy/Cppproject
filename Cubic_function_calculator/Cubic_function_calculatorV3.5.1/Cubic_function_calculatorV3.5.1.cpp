#include<iostream>
#include<vector>
using namespace std;

vector<double >v;//stl vector链型数组
vector<double >::iterator it;//vector迭代器

int X0 = 5;

double a, b, c, d;

double f(double X) { return a * X * X * X + b * X * X + c * X + d; }

double fd(double X) { return 3 * a * X * X + 2 * b * X + c; }

bool u;//用来判断是否重复

void newton()
{
	for (X0 = -5000; X0 <= 5000; X0++)//在一个大区域中逐个点用牛顿法，可找出大多数3次方程所有根    
	{
		double X1 = X0;
		while (abs(f(X1)) > 0.001)
		{
			double X = X1;
			X1 = X - f(X) / fd(X);
		}
		for (it = v.begin(); it != v.end(); it++)
		{
			if (abs((*it - X1)) < 0.01) { u = 1; break; }
		}
		if (u != 1 && X1 < 1000000000)
		{
			cout << X1 << " ";
			v.push_back(X1);//把已得到的解添加到vector，用于防止重复         
		}
		u = 0;
	}
}


int main()
{
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
				newton();
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
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x1 + d;
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
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x1 + d;
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
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x1 + d;
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
				double x0 = -c / 2 * b;
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



