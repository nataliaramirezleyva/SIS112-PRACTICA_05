// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva 

// Fecha creación: 25/09/2023

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
    int maxMedallas = 0;
    int indiceMaxMedallas = -1;

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

        // Comprobar si este atleta tiene más medallas que el máximo actual
        if (ats[i].nmedallas > maxMedallas) {
            maxMedallas = ats[i].nmedallas;
            indiceMaxMedallas = i;
        }
    }

    if (indiceMaxMedallas != -1) {
        cout << "El atleta con el mayor número de medallas es: " << ats[indiceMaxMedallas].pers.nombre << " de " << ats[indiceMaxMedallas].pers.pais << " con " << maxMedallas << " medallas." << endl;
    } else {
        cout << "No se encontraron atletas." << endl;
    }

    return 0;
}
