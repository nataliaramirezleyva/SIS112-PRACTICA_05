// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva 

// Fecha creación: 24/09/2023

// Fecha modificación: 25/09/2023

// Número de ejericio: 2

// Problema planteado: De acuerdo con la siguiente estructura, realice en C++ un programa que lea N atletas y 

// nos devuelva el país que mayor número de medallas ha ganado.

#include <iostream>
#include <cstring>
using namespace std;

struct Datos {
    char nombre[40];
    char pais[25];
};

struct Atleta {
    char deporte[30];
    Datos pers;
    int nmedallas;
};

int main() {
    int N;
    cout << "Ingrese el número de atletas: ";
    cin >> N;

    Atleta ats[30];
    int maxMedallasPorPais = 0;
    char paisMaxMedallas[25] = "";

    for (int i = 0; i < N; i++) {
        cout << "Atleta " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.ignore();
        cin.getline(ats[i].pers.nombre, 40);
        cout << "País: ";
        cin.getline(ats[i].pers.pais, 25);
        cout << "Deporte: ";
        cin.getline(ats[i].deporte, 30);
        cout << "Número de medallas: ";
        cin >> ats[i].nmedallas;

        // Sumar las medallas para el país actual
        if (strcmp(ats[i].pers.pais, paisMaxMedallas) == 0) {
            maxMedallasPorPais += ats[i].nmedallas;
        } else {
            if (ats[i].nmedallas > maxMedallasPorPais) {
                maxMedallasPorPais = ats[i].nmedallas;
                strcpy(paisMaxMedallas, ats[i].pers.pais);
            }
        }
    }

    if (strlen(paisMaxMedallas) > 0) {
        cout << "El país con el mayor número de medallas es: " << paisMaxMedallas << " con un total de " << maxMedallasPorPais << " medallas." << endl;
    } else {
        cout << "No se encontraron atletas." << endl;
    }

    return 0;
}
