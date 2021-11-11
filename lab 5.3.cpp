#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double f(const double x);
double fuctorial(double num);

int main()
{
	double tp, tk, z;
	int n;

	cout << "tp = "; cin >> tp;
	cout << "tk = "; cin >> tk;
	cout << "n = "; cin >> n;

	double dt = (tk - tp) / n;

	cout << fixed;
	cout << "----------------------" << endl;
	cout << "|" << setw(7) << "t" << " |"
		<< setw(10) << "z" << " |"
		<< endl;
	cout << "----------------------" << endl;

	double t = tp;

	while (t <= tk)
	{
		z = f(2 * t) + pow(f(t * t + 1), 2);

		cout << "|" << setw(7) << setprecision(2) << t << " |"
			<< setw(10) << setprecision(5) << z << " |"
			<< endl;

		t += dt;
	}

	cout << "----------------------" << endl;
	return 0;
}

double f(const double x)
{
	if (abs(x) >= 1)
		return (sin(2*x)+1)/(sin(x)+pow(cos(x),2));
	else
	{
		double S = 0;
		int n = 0;
		double a = pow(x,4*x+2) / fuctorial(1 + 2 * n);

		S = a;

		do
		{
			n++;
			double R = (x * x * fuctorial(4 * x - 1)) / fuctorial(2 * n + 1);
			a *= R;
			S += a;
		} while (n < 7);

		return S;
	}
}

double fuctorial(double num) {
	double factorial = 1.0;
	for (int n = 1; n <= num; ++n) {
		factorial *= n;
	}
	return factorial;
}