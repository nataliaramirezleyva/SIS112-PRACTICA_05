// Materia: Programación I, Paralelo 4

// Autor: Natalia Nicole Ramirez Leyva 

// Fecha creación: 24/09/2023

// Fecha modificación: 24/09/2023

// Número de ejericio: 1

// Problema planteado:La información de todos los empleados de la UCB se almacena en una variable tipo 

// struct llamada “empleado”.

// La información con que se cuenta es: nombre, ci, departamento y salario.
// Realizar un programa en C++ que lea un array de estructura de los datos de N 
// empleados e imprima los siguiente:
// • Empleado con mayor salario
// • Empleado con menor salario
// • Promedio salarial
// • Promedio por departamento
// • Departamento con mayor salario en promedio
// • Departamento con menor salario en promedio

#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura empleado
struct Empleado {
    string nombre;
    int ci;
    string departamento;
    double salario;
};

int main() {
    int N;
    cout << "Ingrese el número de empleados: ";
    cin >> N;

    // Declarar un array de estructuras para almacenar los datos de los empleados
    Empleado empleados[N];

    // Leer los datos de los empleados
    for (int i = 0; i < N; i++) {
        cout << "Empleado " << i + 1 << ":" << endl;
        cout << "Nombre: ";
        cin.ignore();
        getline(cin, empleados[i].nombre);
        cout << "CI: ";
        cin >> empleados[i].ci;
        cout << "Departamento: ";
        cin.ignore();
        getline(cin, empleados[i].departamento);
        cout << "Salario: ";
        cin >> empleados[i].salario;
    }

    // Inicializar las variables para realizar cálculos
    Empleado empleadoMayorSalario = empleados[0];
    Empleado empleadoMenorSalario = empleados[0];
    double sumaSalarios = 0;
    double promedioSalarial;
    double sumaSalariosPorDepartamento = 0;
    int contadorPorDepartamento = 0;
    double promedioPorDepartamento;
    string departamentoMayorPromedio;
    double mayorPromedio = 0;
    string departamentoMenorPromedio;
    double menorPromedio = empleados[0].salario;

    // Calcular el empleado con mayor y menor salario, y la suma de salarios
    for (int i = 0; i < N; i++) {
        if (empleados[i].salario > empleadoMayorSalario.salario) {
            empleadoMayorSalario = empleados[i];
        }
        if (empleados[i].salario < empleadoMenorSalario.salario) {
            empleadoMenorSalario = empleados[i];
        }
        sumaSalarios += empleados[i].salario;
    }

    // Calcular el promedio salarial
    promedioSalarial = sumaSalarios / N;

    // Calcular el promedio por departamento y encontrar el departamento con mayor y menor promedio
    for (int i = 0; i < N; i++) {
        sumaSalariosPorDepartamento = 0;
        contadorPorDepartamento = 0;
        for (int j = 0; j < N; j++) {
            if (empleados[j].departamento == empleados[i].departamento) {
                sumaSalariosPorDepartamento += empleados[j].salario;
                contadorPorDepartamento++;
            }
        }
        promedioPorDepartamento = sumaSalariosPorDepartamento / contadorPorDepartamento;
        if (promedioPorDepartamento > mayorPromedio) {
            mayorPromedio = promedioPorDepartamento;
            departamentoMayorPromedio = empleados[i].departamento;
        }
        if (promedioPorDepartamento < menorPromedio) {
            menorPromedio = promedioPorDepartamento;
            departamentoMenorPromedio = empleados[i].departamento;
        }
    }

    // Imprimir los resultados
    cout << "Empleado con mayor salario: " << empleadoMayorSalario.nombre << " (CI: " << empleadoMayorSalario.ci << ") - Salario: " << empleadoMayorSalario.salario << endl;
    cout << "Empleado con menor salario: " << empleadoMenorSalario.nombre << " (CI: " << empleadoMenorSalario.ci << ") - Salario: " << empleadoMenorSalario.salario << endl;
    cout << "Promedio salarial: " << promedioSalarial << endl;
    cout << "Promedio por departamento:" << endl;
    cout << "Departamento con mayor salario en promedio: " << departamentoMayorPromedio << " - Promedio: " << mayorPromedio << endl;
    cout << "Departamento con menor salario en promedio: " << departamentoMenorPromedio << " - Promedio: " << menorPromedio << endl;

    return 0;
}
