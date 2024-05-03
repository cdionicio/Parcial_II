#include <iostream>
#include <string>
using namespace std;

int main() {
    int numEstudiantes;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> numEstudiantes;

    // Crear arreglos para almacenar la información de los estudiantes
    int id[numEstudiantes];
    string nombres[numEstudiantes];
    string apellidos[numEstudiantes];
    float nota1[numEstudiantes], nota2[numEstudiantes], nota3[numEstudiantes], nota4[numEstudiantes];
    float promedios[numEstudiantes];
    string resultados[numEstudiantes];

    // Pedir al usuario que ingrese los datos de cada estudiante
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "\nEstudiante " << i + 1 << ":\n";
        cout << "ID: ";
        cin >> id[i];
        cout << "Nombres: ";
        cin.ignore();
        getline(cin, nombres[i]);
        cout << "Apellidos: ";
        getline(cin, apellidos[i]);
        cout << "Nota 1: ";
        cin >> nota1[i];
        cout << "Nota 2: ";
        cin >> nota2[i];
        cout << "Nota 3: ";
        cin >> nota3[i];
        cout << "Nota 4: ";
        cin >> nota4[i];
    }

    // Calcular el promedio y determinar si el estudiante aprobó o reprobó
    for (int i = 0; i < numEstudiantes; i++) {
        promedios[i] = (nota1[i] + nota2[i] + nota3[i] + nota4[i]) / 4;
        if (promedios[i] >= 60) {
            resultados[i] = "Aprobado";
        } else {
            resultados[i] = "Reprobado";
        }
    }

    // Mostrar los resultados
    cout << "\nResultados:\n";
    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Estudiante " << i + 1 << ":\n";
        cout << "ID: " << id[i] << "\n";
        cout << "Nombres: " << nombres[i] << "\n";
        cout << "Apellidos: " << apellidos[i] << "\n";
        cout << "Promedio: " << promedios[i] << "\n";
        cout << "Resultado: " << resultados[i] << "\n";
    }

    return 0;
}