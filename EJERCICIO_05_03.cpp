// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva 

// Fecha creacion: 25/09/2023

// Fecha modificación: 25/09/2023

// Número de ejericio: 3

// Problema planteado:Realice un programa en C++ con funciones y estructuras para el estacionamiento del 

// Multicine.

// Este estacionamiento cuenta con 4 pisos, cada piso tiene distintas capacidades de 
// autos
// Piso 1 – 50 autos
// Piso 2 – 40 autos
// Piso 3 – 30 autos
// Piso 4 – 45 autos
// El estacionamiento debe recibir varios tipos de autos (vagoneta, camionetas, 
// automóviles, minivans y motocicletas), marca del auto, modelo del auto y color del 
// auto.
// Escribir un programa en C++ utilizando funciones y estructuras para:
// • Simular la entrada de vehículos, el programa debe pedir la cantidad de 
// vehículos ingresados y el programa debe simular los tipos de vehículo, la 
// marca, el modelo, el color y en que piso se han estacionado.
// • La simulación puede repetirse varias veces hasta que el usuario ingrese el valor
// de 0 (cero) en la cantidad de vehículos. La cantidad de vehículos debe se 
// incremental.
// • Luego de cada ingreso de vehículos se desea saber cuantos hay estacionado en 
// cada piso.
// • Cuantos son vagoneta, camionetas, automóviles, minivans y motocicletas.
// • Hacer un reporte por colores de autos, modelo y marca. 
// • La simulación debe determinar cuando el parqueo se ha llenado.
// • La simulación debe determinar cuántos espacios libres queda.


#include <iostream>
#include <string>
using namespace std;

// Estructura para representar un vehículo
struct Vehiculo {
    string tipo;
    string marca;
    string modelo;
    string color;
};

int main() {
    const int capacidadPisos[] = {50, 40, 30, 45};
    int ocupacionPisos[] = {0, 0, 0, 0};
    Vehiculo vehiculos[200];  // Suponemos un máximo de 200 vehículos en el estacionamiento
    int cantidadVehiculos = 0;

    while (true) {
        cout << "Ingrese la cantidad de vehículos a estacionar (0 para salir): ";
        int cantidad;
        cin >> cantidad;

        if (cantidad == 0) {
            cout << "Saliendo del programa..." << endl;
            break;
        }

        for (int i = 0; i < cantidad; i++) {
            if (cantidadVehiculos >= (capacidadPisos[0] + capacidadPisos[1] + capacidadPisos[2] + capacidadPisos[3])) {
                cout << "El estacionamiento está lleno. No se pueden ingresar más vehículos." << endl;
                break;
            }

            Vehiculo vehiculo;
            cout << "Tipo de vehículo (vagoneta, camioneta, automóvil, minivan, motocicleta): ";
            cin >> vehiculo.tipo;
            cout << "Marca: ";
            cin >> vehiculo.marca;
            cout << "Modelo: ";
            cin >> vehiculo.modelo;
            cout << "Color: ";
            cin >> vehiculo.color;

            // Incrementar la ocupación en el piso correspondiente
            if (vehiculo.tipo == "vagoneta") {
                ocupacionPisos[0]++;
            } else if (vehiculo.tipo == "camioneta") {
                ocupacionPisos[1]++;
            } else if (vehiculo.tipo == "automóvil") {
                ocupacionPisos[2]++;
            } else if (vehiculo.tipo == "minivan") {
                ocupacionPisos[3]++;
            } else if (vehiculo.tipo == "motocicleta") {
                ocupacionPisos[3]++;
            }

            // Incrementar la cantidad total de vehículos
            cantidadVehiculos++;
        }

        // Mostrar la ocupación en cada piso
        for (int i = 0; i < 4; i++) {
            cout << "Piso " << i + 1 << ": " << ocupacionPisos[i] << " vehículos ocupados de " << capacidadPisos[i] << " disponibles." << endl;
        }
    }

    return 0;
}