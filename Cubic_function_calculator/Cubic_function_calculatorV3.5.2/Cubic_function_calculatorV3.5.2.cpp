#include <iostream>
#include <math.h>
#include <iomanip>
#include "complex.h"
using namespace std;
double a,b,c,d;
int main()
{
	int n = 1;
	while (n) {
		cout << "������ֵ������" << endl << "�����뺯��(���κ���a=0)ax^3+bx^2+cx+d" << endl << "a=";
		double  min,max;

		cin >> a;
		cout << "b=";
		cin >> b;
		cout << "c=";
		cin >> c;
		cout << "d=";
		cin >> d;
		cout << "�������������1      ����ֵ��ֵ������2     �������뺯��������0" << endl;
		int g;
		cin >> g;
		switch (g) {
		case 1:
			if (a != 0) {
			 double A, B, C, delta, si;
    double x1, x2, x3;
   
    if (a > 500 || b > 500 || c > 500)
    {
        cout << "��ֵ����޷����㣡����" << endl;
        return 0;
    }

    //ʹ��ʢ��ʽ
    A = b * b - 3 * a * c;
    B = b * c - 9 * a * d;
    C = c * c - 3 * b * d;
    delta = B * B - 4 * A * C;

    ///�������ظ������
    if (A == B && A == 0)
    {
        x1 = -b / (3 * a);
        x2 = x1;
        x3 = x1;
        cout << "��������ʵ��" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << fixed << setprecision(3) << x3 << " ";
        cout << "x3=" << fixed << setprecision(3) << x2 << " ";
    }

    //�������ȸ������
    else if (delta <= 1e-5 && delta >= -1e-5 && (A != B || A != 1e-5))
    {
        double K = B / A;
        x1 = -b / a + K;
        x2 = -K / 2;
        x3 = x2;
        cout << "������ʵ������������Ϊ�ȸ�" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << fixed << setprecision(3) << x3 << " ";
        cout << "x3=" << fixed << setprecision(3) << x2 << " ";
    }

    //����������ͬʵ�������
    else if (delta < -1e-5 && (A != B || A != 1e-5))
    {
        double T = (2 * A * b - 3 * a * B) / (2 * pow(A, 1.5));
        si = acos(T);
        x1 = (-b - 2 * sqrt(A) * cos(si / 3)) / (3 * a);
        x2 = (-b + sqrt(A) * (cos(si / 3) + sqrt(3) * sin(si / 3))) / (3 * a);
        x3 = (-b + sqrt(A) * (cos(si / 3) - sqrt(3) * sin(si / 3))) / (3 * a);
        cout << "������ʵ�����������" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << fixed << setprecision(3) << x3 << " ";
        cout << "x3=" << fixed << setprecision(3) << x2 << " ";
    }

    //���ڹ�����������
    else
    {
        double Y1 = A * b + 3 * a * ((-B + pow(delta, 1.0 / 2.0)) / 2);
        double Y2 = A * b + 3 * a * ((-B - pow(delta, 1.0 / 2.0)) / 2);
        double U = pow(Y1, 1.0 / 3.0) - pow(-Y2, 1.0 / 3.0);
        double UU= pow(Y1, 1.0 / 3.0) + pow(-Y2, 1.0 / 3.0);
        x1 = (-b - U )/ (3 * a);
        complex xc2, xc3;
        complex V1(0.5*U-b, UU*sqrt(3) / 2.0);
        complex V2(0.5*U-b, -UU*sqrt(3) / 2.0);
        xc2 = V1 / (3 * a);
        xc3 = V2 / (3 * a);
        cout << "��һ��ʵ���������������" << endl;
        cout << "x1=" << fixed << setprecision(3) << x1 << " ";
        cout << "x2=" << xc2 << " ";
        cout << "x3=" << xc3 << " ";
    }
			}
			cout << endl << "�������뺯������1���˳�����0" << endl;
			cin >> n;
			break;


		case 2:
			cout << "�����뷶Χ��min��max������Ҫʹ���������������һ���ϴ���С������" << endl << "min=";
			cin >> min;
			cout << "max=";
			cin >> max;
			while (min > max)
			{
				cout << "min>max ����������" << endl;
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
						cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
							<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
							<< "����ֵ" << "f(" << x1 << ")=" << fx1 << ",  "
							<< "��Сֵ" << "f(" << x2 << ")=" << fx2;
					}
					if (min <= x1 && x1 <= max && max < x2) {
						double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmax = fx1; xmax = x1;
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "���ֵ=" << "f(" << x1 << ")=" << fx1 << "��"
							<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
							<< "����ֵ=" << "f(" << x1 << ")=" << fx1 << ",  "
							<< "�޼�Сֵ";
					}
					if (x1 < min && min <= x2 && x2 <= max) {
						double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x1 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmin = fx2; xmin = x2;
						if (fmin > fmax) { fxmax = fmin; xmax = min; }
						else { fxmax = fmax; xmax = max; }
						cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
							<< "��Сֵ=" << "f(" << x2 << ")=" << fx2 << endl
							<< "��Сֵ=" << "f(" << x2 << ")=" << fx2 << ",  "
							<< "�޼���ֵ";
					}
					if (x1 < min && min <= max && max < x2) {
						double fmin, fmax;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						cout << "���ֵ=" << "f(" << min << ")=" << fmin << "��"
							<< "��Сֵ=" << "f(" << max << ")=" << fmax << endl
							<< "�޼���ֵ" << ",  "
							<< "�޼�Сֵ";
					}
					if (x2<min || x1>max)
					{
						double fxmin, fxmax;
						fxmin = a * min * min * min + b * min * min + c * min + d;
						fxmax = a * max * max * max + b * max * max + c * max + d;
						cout << "���ֵ=" << "f(" << max << ")=" << fxmax << "��"
							<< "��Сֵ=" << "f(" << min << ")=" << fxmin << endl
							<< "�޼���ֵ" << ",  "
							<< "�޼�Сֵ";
					}
				}
				if (e <= 0) {
					double fxmin, fxmax;
					fxmin = a * min * min * min + b * min * min + c * min + d;
					fxmax = a * max * max * max + b * max * max + c * max + d;
					cout << "���ֵ=" << "f(" << max << ")=" << fxmax << "��"
						<< "��Сֵ=" << "f(" << min << ")=" << fxmin << endl
						<< "�޼���ֵ" << ",  "
						<< "�޼�Сֵ";
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
						cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
							<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
							<< "����ֵ" << "f(" << x2 << ")=" << fx2 << ",  "
							<< "��Сֵ" << "f(" << x1 << ")=" << fx1;
					}
					if (min <= x1 && x1 <= max && max < x2) {
						double fx1, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx1 = a * x1 * x1 * x1 + b * x1 * x1 + c * x1 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmin = fx1; xmin = x1;
						if (fmin > fmax) { fxmax = fmin; xmax = min; }
						else { fxmax = fmax; xmax = max; }
						cout << "���ֵ=" << "f(" << xmax << ")=" << fxmax << "��"
							<< "��Сֵ=" << "f(" << x1 << ")=" << fx1 << endl
							<< "��Сֵ=" << "f(" << x1 << ")=" << fx1 << ",  "
							<< "�޼���ֵ";
					}
					if (x1 < min && min <= x2 && x2 <= max) {
						double fx2, fmin, fmax, fxmin, fxmax, xmax, xmin;
						fx2 = a * x2 * x2 * x2 + b * x2 * x2 + c * x2 + d;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						fxmax = fx2; xmax = x2;
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "���ֵ=" << "f(" << x2 << ")=" << fx2 << "��"
							<< "��Сֵ=" << "f(" << xmin << ")=" << fxmin << endl
							<< "����ֵ=" << "f(" << x2 << ")=" << fx2 << ",  "
							<< "�޼�Сֵ";
					}
					if (x1 < min && min <= max && max < x2) {
						double fxmin, fxmax;
						fxmin = a * min * min * min + b * min * min + c * min + d;
						fxmax = a * max * max * max + b * max * max + c * max + d;
						cout << "���ֵ=" << "f(" << max << ")=" << fxmax << "��"
							<< "��Сֵ=" << "f(" << min << ")=" << fxmin << endl
							<< "�޼���ֵ" << ",  "
							<< "�޼�Сֵ";
					}
					if (x2<min || x1>max) {
						double fmin, fmax;
						fmin = a * min * min * min + b * min * min + c * min + d;
						fmax = a * max * max * max + b * max * max + c * max + d;
						cout << "���ֵ=" << "f(" << min << ")=" << fmin << "��"
							<< "��Сֵ=" << "f(" << max << ")=" << fmax << endl
							<< "�޼���ֵ" << ",  "
							<< "�޼�Сֵ";
					}
				}
				if (e <= 0) {
					double fmin, fmax;
					fmin = a * min * min * min + b * min * min + c * min + d;
					fmax = a * max * max * max + b * max * max + c * max + d;
					cout << "���ֵ=" << "f(" << min << ")=" << fmin << "��"
						<< "��Сֵ=" << "f(" << max << ")=" << fmax << endl
						<< "�޼���ֵ" << ",  "
						<< "�޼�Сֵ";
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
						cout << "��Сֵ=" << "f(" << xmin << ")=" << fxmin << "��"
							<< "���ֵ=" << "f(" << xmax << ")=" << fxmax << endl;
					}
					if (b < 0) {
						fxmax = fx0; xmax = x0;
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "��Сֵ=" << "f(" << xmin << ")=" << fxmin << "��"
							<< "���ֵ=" << "f(" << xmax << ")=" << fxmax << endl;
					}
					if (b == 0) {
						if (fmin > fmax) { fxmax = fmin; xmax = min; }
						else { fxmax = fmax; xmax = max; }
						if (fmax < fmin) { fxmin = fmax; xmin = max; }
						else { fxmin = fmin; xmin = min; }
						cout << "��Сֵ=" << "f(" << xmin << ")=" << fxmin << "��"
							<< "���ֵ=" << "f(" << xmax << ")=" << fxmax << endl;
					}

				}
				if (x0<min || x0>max) {
					if (fmin > fmax) { fxmax = fmin; xmax = min; }
					else { fxmax = fmax; xmax = max; }
					if (fmax < fmin) { fxmin = fmax; xmin = max; }
					else { fxmin = fmin; xmin = min; }
					cout << "��Сֵ=" << "f(" << xmin << ")=" << fxmin << "��"
						<< "���ֵ=" << "f(" << xmax << ")=" << fxmax << endl;

				}
			}
			cout << endl << "�������뺯������1���˳�����0" << endl;
			cin >> n;
			break;
			

             default:
				n = 1;

		}

	}
		
	return 0;
}



