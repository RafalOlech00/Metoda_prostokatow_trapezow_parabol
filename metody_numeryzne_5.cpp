#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// przedział całkowania
double a = 0.5;
double b = 5;

double CalkowanaFunkcja(double x) // funkcja zwracająca funkcję do całkowania
{
	// w zależności od potrzebnej funkcji należy odkomentować 
	//return sin(x);
	//return (x * x) + (2 * x) + 5;
	return exp(x);
	
	
}


// funkcja która całkuje metodą prostokątów
double MetodaProstokatow(int n, double a, double b)
{
	double s = (b - a) / n;
	double x = a;
	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += CalkowanaFunkcja(x + 0.5 * s);
		x += s;
	}
	return suma * s;
}

// funkcja, która całkuje metodą trapezów
double MetodaTrapezow(int n, double a, double b)
{
	double s = (b - a) / n;
	double x1 = a; 
	double x2 = a + s;
	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += s * ((CalkowanaFunkcja(x1) + CalkowanaFunkcja(x2))) * 0.5;
		x1 += s;
		x2 += s;
	}
	return suma;
}

// funkcja, która całkuje metodą Simpsona
double MetodaSimpsona(int n, double a, double b)
{
	double s = (b - a) / n;
	double x1 = a; 
	double x2 = a + s;
	double suma = 0;
	for (int i = 0; i < n; i++)
	{
		suma += (s / 6) * (CalkowanaFunkcja(x1) + 4 * CalkowanaFunkcja((x1 + x2) / 2) + CalkowanaFunkcja(x2));

		x1 += s;
		x2 += s;
	}
	return suma;
}

void Zbieznosc()
{
	for (int i = 1; i <= 20; i++) // zwiększamy liczbę przedziałów aż do 20, aby uzyskać potem dokładniejszy wykres 
	{
		int n = i; // liczba przedziałów 
		cout << "Liczba przedzialow: " << n << endl;
		cout << "Wynik obliczony metoda prostokatow: ";
		cout << MetodaProstokatow(n, a, b) << endl;
		cout << "Wynik obliczony metoda trapezow: ";
		cout << MetodaTrapezow(n, a, b) << endl;
		cout << "Wynik obliczony metoda Simpsona: ";
		cout << MetodaSimpsona(n, a, b) << endl<<endl;

	}
}



int main()
{
	int n = 4;  // liczba przediałów

	if (CalkowanaFunkcja(b) == sin(b))
	{
		cout << "Wzor calkowanej funkcji: sin(x)"<<endl<<endl;
	}
	else if (CalkowanaFunkcja(b) == exp(b))
	{
		cout << "Wzor calkowanej funkcji: exp(x)" << endl<<endl;

	}
	else if (CalkowanaFunkcja(b) == (b * b + 2*b + 5))
	{
		cout << "Wzor calkowanej funkcji: x^2 + 2*x + 5" << endl<<endl;
	}
	

	cout << "Liczba przedzialow: " << n << endl<<endl;
	cout << "Przedzial calkowania: <" << a << " , " << b <<">"<< endl<<endl;
	
	cout << "Wynik obliczony metoda prostokatow: ";
	cout << MetodaProstokatow(n, a, b) << endl<<endl;
	cout << "Wynik obliczony metoda trapezow: ";
	cout << MetodaTrapezow(n, a, b) << endl<<endl;
	cout << "Wynik obliczony metoda Simpsona: ";
	cout << MetodaSimpsona(n, a, b) << endl<<endl;

	Zbieznosc();

	return 0;
}