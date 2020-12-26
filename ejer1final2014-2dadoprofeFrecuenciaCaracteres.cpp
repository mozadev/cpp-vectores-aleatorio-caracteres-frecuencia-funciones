// ConsoleApplication5.cpp : main project file.
#include "stdafx.h"
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include<conio.h>
#include <Windows.h>
#include <iomanip>
#include<string.h>


using namespace std;
using namespace System;

int cant_carac_cadena()
{
	int n;
	do {
		cout << "ingrese numero de caracteres de la cadena: "; cin >> n;
	} while (n > 50);
	return n;
}



void generar_cadena(char *vcadena, int cantidad_caracteres)
{
	srand(time(NULL));
	for (int i = 0; i < cantidad_caracteres; i++)
	{
		vcadena[i] = char(65) + rand() % ((char(122) + 1) - char(65));
		if (vcadena[i] >= char(91) && vcadena[i] <= char(96))
			vcadena[i] = char(32);
	}
}

void imprimir_cadena(char *vcadena, int cantidad_caracteres)
{
	for (int i = 0; i < cantidad_caracteres; i++)
		cout << vcadena[i] << " ";
	cout << endl;
}

void frecuencia_vocales(char *vcadena, int cantidad_caracteres)
{

	int vocal_a = 0, vocal_e = 0, vocal_i = 0, vocal_o = 0, vocal_u = 0;
	for (int i = 0; i < cantidad_caracteres; i++)

		switch (vcadena[i])
		{
		case 'a':case 'A':vocal_a++; break;
		case 'e':case 'E':vocal_e++; break;
		case 'i':case 'I':vocal_i++; break;
		case 'o':case 'O':vocal_o++; break;
		case 'u':case 'U':vocal_u++; break;

		}if (vocal_a > 0)cout << "vocal a: " << vocal_a << endl;
		if (vocal_e > 0)	cout << "vocal e: " << vocal_e << endl;
		if (vocal_i > 0)	cout << "vocal i: " << vocal_i << endl;
		if (vocal_o > 0)	cout << "vocal o: " << vocal_o << endl;
		if (vocal_u > 0)	cout << "vocal u: " << vocal_u << endl;
}

void mayor_longitud(char *vcadena, int cantidad_caracteres)
{
	int longitud = 0, posicion = 0, mayor = 0, posmayor=0;
	for (int i = 0; i < cantidad_caracteres; i++)
	{
		while (vcadena[i] == char(32) && i + 1 < cantidad_caracteres)
			i++;
		posicion = i;
		longitud = 0;
		while (((vcadena[i]>=char(65)&&vcadena[i] <= char(90)) ||( vcadena[i] >= char(97)&& vcadena[i] <= char(122))) && (i + 1 < cantidad_caracteres))
		{
			longitud++;
			i++;
		}
		if (longitud > mayor)
		{
			mayor = longitud;
			posmayor = posicion;
		}
	}
	cout << "la longitud de palabra de mayor tamaño es: " << mayor << " y la palabra es: " << endl;
		
	for (int i = posmayor; i <= posmayor + mayor; i++)
		cout << vcadena[i];
	cout << endl;

}


int main()
{
	int cantidad_caracteres = cant_carac_cadena();
	char*vcadena = new char[cantidad_caracteres];
	generar_cadena(vcadena, cantidad_caracteres);
	imprimir_cadena(vcadena, cantidad_caracteres);
	frecuencia_vocales(vcadena, cantidad_caracteres);
	mayor_longitud(vcadena, cantidad_caracteres);
	system("pause");

}