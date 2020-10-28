/* Alexander Mendez 10-25-20
Dr.Tyson McMillan, Tarrant County College
Create a decision program menu to help students who are taking a Physics (Mechanics) class perform simple foundation calculations.
Replit macOS
*/
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"   	/* Cyan */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define WHITE   "\033[37m"		/* White */
#define BOLDWHITE   "\033[1m\033[37m"      /* Bold White */
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
#include "Input_Validation_Extended.h"
using namespace std;

void showMenu()
{
	// shows the menu
	cout << "\n\t\tMenu: " << endl;
	cout << GREEN << "Enter 'V' to calculate Velocity: " << RESET << endl;
	cout << YELLOW << "Enter 'A' to calculate Acceleration: " << RESET << endl;
	cout << BLUE << "Enter 'M' to calculate Motion: " << RESET << endl;
	cout << MAGENTA << "Enter 'N' to calculate Newton's Second Law: " << RESET << endl;
	cout << CYAN << "Enter 'W' to calculate Weight(Earth): "<< RESET << endl;
	cout << BOLDGREEN << "Enter 'T' to calculate Momentum: "<< RESET << endl;
	cout << RED << "Enter 'E' to Exit: " << RESET << endl;
	cout << WHITE << "Enter 'X' to clear screen: " << RESET << endl;
}

void veloCalc()
{
	// velocity calculator
	double ds = 0.0, dt = 0.0, velo = 0.0;
	cout << "\nWelcome to the velocity calculator" << endl;
	cout << GREEN << "Please enter the delta distacnce in km"<< RESET << endl;
	ds = validateDouble(ds);
	cout << GREEN << "Please enter the delata time in hours" << RESET << endl;
	dt = validateDouble(dt);
	velo = ds/dt;
	cout << GREEN << "Velocity equals: " << RESET << ds << " km / " << dt << " hr = " << setprecision(4) << velo << " km/hr " << endl;
}

void accelCalc()
{
	// acceleration calculator
	double dv = 0.0, dt = 0.0, accel = 0.0;
	cout << "\nWelcome to the acceleration calculator" << endl;
	cout << YELLOW << "Please enter the delta velocity in m/s" << RESET << endl;
	dv = validateDouble(dv);
	cout << YELLOW <<"Please enter the delata time in seconds" << RESET << endl;
	dt = validateDouble(dt);
	accel = dv/dt;
	cout << YELLOW << "Acceleration equals: " << RESET << dv << " m/s / " << dt << " s = " << setprecision(4) << accel << " m/s^2 " << endl;
}

void motionCalc()
{
	// motion calculator
	double 	v = 0.0, a = 0.0, v0 = 0.0, t = 0.0, s = 0.0, s0 = 0.0, v2 = 0.0, v_bar = 0.0;
	cout << "\nWelcome to the motion calculator" << endl;
	cout << BLUE << "Please enter the the intial velocity in m/s" << RESET << endl;
	v0 = validateDouble(v0);
	cout << BLUE << "Please enter the accleration in m/s^2" << RESET << endl;
	a = validateDouble(a);
	cout << BLUE << "Please enter the time in seconds" << RESET << endl;
	t = validateDouble(t);
	v = v0 + a * t;
	cout << BLUE << "Enter the inital distance in m" << RESET << endl;
	s0 = validateDouble(s0);
	s = s0 + (v0 * t) + (.5*a*(pow(t,2)));
	v2 = (pow(v0,2) + (2*a*(s-s0)));
	v_bar = .5*(v + v0);
	cout << BLUE << "Velocity equals: " << RESET << v0 << " m/s + " << a << " m/s^2 * " << t << " s = " << setprecision(4) << v << " m/s" << endl;
	cout << BLUE << "Distance equals: " << RESET << s0 << " m + " << v0 << "m/s * " << t << "s + 1/2 " << a << "m/s^2 *(" << t << "s ^2) = " << setprecision(4) << s << " m" << endl;
	cout << BLUE << "Velocity^2 equals : " << RESET << "("  << v0 << "^2) + 2" << a << "(" << s << "-" << s0 << ") = " << setprecision(4) << v2 << " ^2 m/s" << endl;
	cout << BLUE <<"Velocity bar equals : " << RESET <<  "1/2("  << v << "+" << v0 << ") = "  << setprecision(4) << v_bar << " m/s" << endl;
}

void forceCalc()
{
	// Newton's Second Law calculator
	double m = 0.0, a = 0.0, n = 0.0;
	cout << "\nWelcome to the Newton's Second Law calculator" << endl;
	cout << MAGENTA << "Please enter the mass in kg" << RESET << endl;
	m = validateDouble(m);
	cout << MAGENTA <<  "Please enter the accleration in m/s^2" << RESET << endl;
	a = validateDouble(a);
	n = m*a;
	cout << MAGENTA << "Newton's Second Law(Force) equals: " << RESET << m << " kg * " << a << " m/s^2 = " << setprecision(4) << n << " N or kg/(m/s^2)" << endl;
}

void weightCalc()
{
	// weight calculator
	double m = 0.0, w = 0.0, g = 9.8;
	cout << "\nWelcome to the Weight on Earth calculator" << endl;
	cout << CYAN << "Please enter the mass in kg" << RESET << endl;
	m = validateDouble(m);
	cout << CYAN << "Force of gravity on Earth = 9.8 m/s^2" << RESET << endl;
	w = m*g;
	cout << CYAN << "Weight on Earth equals: " << RESET << m << "kg *" << g << "m/s^2 =" << setprecision(4) << w << "N or kg/(m/s^2)" << endl;
}

void momenCalc()
{
	// momentum calculator
	double m = 0.0, v = 0.0, p = 0.0;
	cout << "\nWelcome to the Momentum calculator" << endl;
	cout << BOLDGREEN << "Please enter the mass in kg" << RESET << endl;
	m = validateDouble(m);
	cout << BOLDGREEN << "Please enter the velocity in m/s" << RESET << endl;
	v = validateDouble(v);
	p = m*v;
	cout << BOLDGREEN << "Momentum equals: " << RESET << m << "kg *" << v << "m/s=" << setprecision(4) << p << "kg/(m/s)" << endl;
}

void handleOption(string userOption)
{
	//transform all user input to lowercase
	transform(userOption.begin(), userOption.end(), userOption.begin(), ::tolower);  
	if(userOption == "v")
	{
		veloCalc();
	}
	else if(userOption == "a")
	{
		accelCalc(); 
	}
	else if(userOption == "m")
	{
		motionCalc(); 
	}		
	else if(userOption == "n")
	{
		forceCalc(); 
	}
	else if(userOption == "w")
	{
		weightCalc(); 
	}
	else if(userOption == "t")
	{
		momenCalc(); 
	}
	else if(userOption == "e")
	{
		cout << RED << "\nGoodbye" << RESET << endl;    
	}   
	else if(userOption == "x")
	{
		system("clear");   
	}
	else 
	{
		cout << RED << "\nError: Please enter a letter" << RESET << endl;
	}
}

int main() 
{
	string option = ""; 
	do
	{
		showMenu();//show menu
		cout << BOLDWHITE << "Please select an option: " << RESET;  
		getline(cin,option); //accept input from the user whole line
		handleOption(option); //pass the option that the user entered to the function
	}while(option != "e" && option != "E"); 
	
	
	return 0;  
}