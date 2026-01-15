#include<iostream>
#include<cmath>

using namespace std;

int main ()
{
	// Input 
	double R = 0;
	double Ke = 0;
	double Kt = 0;
	double Vs = 0;
	double duty;
	double Load_torque = 0;

	cout << "\n----DC Motor Control-----\n";
	cout << "\n Motor Information \n";

	while (R <= 0)
	{
		cout << "Enter the value of armature resistance (Ohm's) : ";
		cin >> R;
	}

	while (Ke <= 0)
	{
		cout << "Enter the value of Ke : ";
		cin >> Ke;
	}

	while (Kt <= 0)
	{
		cout << "Enter the value of Kt (Nm/A) : ";
		cin >> Kt;
	}

	while (Vs <= 0)
	{
		cout << "Enter the value of Supply Voltage (V) : ";
		cin >> Vs;
	}

	cout << "\nSimulation condition\n";

	cout << "Enter the value of duty: ";
	cin >> duty;

	while (duty < 0 || duty > 1)
	{
		cout << "Enter the value of duty (0 - 1, PWM) : ";
		cin >> duty;
	}
	while (Load_torque <= 0)
	{
		cout << "Enter the value of Load torque (Nm) : ";
		cin >> Load_torque;
	}

	// Calculation

	double I = Load_torque / Kt;
	double V_eff = Vs * duty;
	double E = V_eff - (I * R);
	double omega;

	if (E > 0) 
	{
		omega = E / Ke;
	}

	else
	{
		omega = 0;
	}

	const double pi = 3.1416 ;

	double RPM = (60 / (2 * pi)) * omega;

	// Output

	cout << "\n---DC Motor SImulation---\n";
	cout << "Motor Current        :" << I << "A\n";
	cout << "Efficient voltage    :" << V_eff << "V\n";
	cout << "EMP                  :" << E << "V\n";
	cout << "Motor Speed          :" << omega << "rad/s\n";
	cout << "Motor Speed (RPM)    :" << RPM << "RPM\n";

	if (omega == 0) {
		cout << "⚠ Motor is STALLED (load too high or voltage too low)\n";
	}

	return 0;

}