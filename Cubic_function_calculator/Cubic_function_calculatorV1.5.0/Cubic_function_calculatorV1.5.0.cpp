#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n = 1;
	while (n) {
		cout << "函数最值计算器" << endl << "请输入函数(二次函数a=0)ax^3+bx^2+cx+d" << endl << "a=";
		double a, b, c, d, min, max;

		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "c=";
		cin >> c;
		cout << "d=";
		cin >> d;
		cout << "请输入范围【min，max】若需要使用无穷，请自行输入一个较大或较小的数字"<< endl << "min=";
		cin >> min;
		cout << "max=";
		cin >> max;
		while (min>max)
		{
			cout<<"min>max 请重新输入"<<endl;
			cout<<"min=";
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
						if (min <= x1&&x1< x2&&x2<= max) {
							double fx1, fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
							fx1 = a *x1*x1*x1 + b * x1*x1 + c * x1 + d;
							fx2 = a *x2*x2*x2 + b * x2*x2 + c * x1 + d;
							fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							if (fx1 > fmax) { fxmax = fx1; xmax = x1; }
							else { fxmax = fmax; xmax = max; }
							if (fx2 < fmin) { fxmin = fx2; xmin = x2; }
							else { fxmin = fmin; xmin = min; }
							cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
								<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
								<< "极大值" << "f(" << x1 << ")=" << fx1 << ",  "
								<< "极小值" << "f(" << x2 << ")=" << fx2;
						}
						if (min <= x1 &&x1<= max&&max< x2) {
							double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
							fx1 = a *x1*x1*x1 + b * x1*x1 + c * x1 + d;
							fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							fxmax = fx1; xmax = x1;
							if (fmax < fmin) { fxmin = fmax; xmin = max; }
							else { fxmin = fmin; xmin = min; }
							cout << "最大值=" << "f(" << x1 << ")=" << fx1 << "，"
								<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
								<< "极大值=" << "f(" << x1 << ")=" << fx1 << ",  "
								<< "无极小值";
						}
						if (x1 < min &&min<= x2 &&x2<= max) {
							double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
							fx2 = a *x2*x2*x2 + b * x2*x2 + c * x1 + d;
							fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							fxmin = fx2; xmin = x2;
							if (fmin > fmax) { fxmax = fmin; xmax = min; }
							else { fxmax = fmax; xmax = max; }
							cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
								<< "最小值=" << "f(" << x2 << ")=" << fx2 << endl
								<< "极小值=" << "f(" << x2 << ")=" << fx2 << ",  "
								<< "无极大值";
						}
						if (x1 < min&&min <= max &&max< x2) {
							double fmin, fmax;
                            fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							cout << "最大值=" << "f(" << min << ")=" << fmin << "，"
								<< "最小值=" << "f(" << max << ")=" << fmax << endl
								<< "无极大值" << ",  "
								<< "无极小值";
						}
						if(x2<min||x1>max)
						{	double fxmin, fxmax;
							fxmin = a *min*min*min+ b *min*min + c * min + d;
							fxmax = a *max*max*max+ b *max*max + c * max + d;
							cout << "最大值=" << "f(" << max << ")=" << fxmax << "，"
								<< "最小值=" << "f(" << min << ")=" << fxmin << endl
								<< "无极大值" << ",  "
								<< "无极小值";
						}
                      }
						if (e <= 0) {
							double fxmin, fxmax;
	                        fxmin = a *min*min*min+ b *min*min + c * min + d;
							fxmax = a *max*max*max+ b *max*max + c * max + d;
							cout << "最大值=" << "f(" << max << ")=" << fxmax << "，"
								<< "最小值=" << "f(" << min << ")=" << fxmin << endl
								<< "无极大值" << ",  "
								<< "无极小值";
						}
				}
				
				
				
				if(a<0){
						//3ax^2+2bx^2+c
					double e = 4 * b * b - 12 * a * c;
					if (e > 0)
					{
						double f = sqrt(e);
						double x2 = (-2 * b - f) / (6 * a);
						double x1 = (-2 * b + f) / (6 * a);
						cout.precision(2);
						cout.setf(ios::fixed);
						if (min <= x1&&x2<= max) {
							double fx1, fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
							fx1 = a *x1*x1*x1 + b * x1*x1 + c * x1 + d;
							fx2 = a *x2*x2*x2 + b * x2*x2 + c * x1 + d;
							fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							if (fx2 > fmin) { fxmax = fx2; xmax = x2; }
							else { fxmax = fmin; xmax = min; }
							if (fx1 < fmax) { fxmin = fx1; xmin = x1; }
							else { fxmin = fmax; xmin = max; }
							cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
								<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
								<< "极大值" << "f(" << x2 << ")=" << fx2 << ",  "
								<< "极小值" << "f(" << x1 << ")=" << fx1;
						}
						if (min <= x1&&x1<= max&&max< x2) {
								double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
							fx1 = a *x1*x1*x1 + b * x1*x1 + c * x1 + d;
							fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							fxmin = fx1; xmin = x1;
							if (fmin > fmax) { fxmax = fmin; xmax = min; }
							else { fxmax = fmax; xmax = max; }
							cout << "最大值=" << "f(" << xmax << ")=" << fxmax << "，"
								<< "最小值=" << "f(" << x1 << ")=" << fx1 << endl
								<< "极小值=" << "f(" << x1 << ")=" << fx1 << ",  "
								<< "无极大值";
						}
						if (x1 < min && min<= x2 &&x2<= max) {
						double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
							fx2 = a *x2*x2*x2 + b * x2*x2 + c * x2 + d;
							fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							fxmax = fx2; xmax = x2;
							if (fmax < fmin) { fxmin = fmax; xmin = max; }
							else { fxmin = fmin; xmin = min; }
							cout << "最大值=" << "f(" << x2 << ")=" << fx2 << "，"
								<< "最小值=" << "f(" << xmin << ")=" << fxmin << endl
								<< "极大值=" << "f(" << x2 << ")=" << fx2 << ",  "
								<< "无极小值";
						}
						if (x1 < min&&min <= max &&max< x2) {
							double fxmin, fxmax;
							fxmin = a *min*min*min+ b *min*min + c * min + d;
							fxmax = a *max*max*max+ b *max*max + c * max + d;
							cout << "最大值=" << "f(" << max << ")=" << fxmax << "，"
								<< "最小值=" << "f(" << min << ")=" << fxmin << endl
								<< "无极大值" << ",  "
								<< "无极小值";
						}
						if (x2<min || x1>max) {
						    double fmin, fmax;
                            fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							cout << "最大值=" << "f(" << min << ")=" << fmin << "，"
								<< "最小值=" << "f(" << max << ")=" << fmax << endl
								<< "无极大值" << ",  "
								<< "无极小值";
						}
                      }
						if (e <= 0) {
						  double fmin, fmax;
                            fmin = a *min*min*min+ b *min*min + c * min + d;
							fmax = a *max*max*max+ b *max*max + c * max + d;
							cout << "最大值=" << "f(" << min << ")=" << fmin << "，"
								<< "最小值=" << "f(" << max << ")=" << fmax << endl
								<< "无极大值" << ",  "
								<< "无极小值";
						}
					
				}
				
		//if(a=0){ if(b>0)   }
	
	
			 
		
        cout << endl << "重新输入函数输入1，退出输入0" << endl;
		cin >> n;
		}
		return 0;	
}
	


