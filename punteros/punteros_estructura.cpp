#include <iostream>
#include <string>

using namespace std;

struct Estudiante {
    int id;
    string nombre;
    string apellido;
    float nota1;
    float nota2;
    float nota3;
    float nota4;
};

int main() {
    int numEstudiantes;
    cout << "Ingrese la cantidad de estudiantes: ";
    cin >> numEstudiantes;

    Estudiante* estudiantes = new Estudiante[numEstudiantes];

    for (int i = 0; i < numEstudiantes; i++) {
        cout << "Ingrese los datos del estudiante " << i + 1 << ":" << endl;
        cout << "ID: ";
        cin >> estudiantes[i].id;
        cout << "Nombre: ";
        cin >> estudiantes[i].nombre;
        cout << "Apellido: ";
        cin >> estudiantes[i].apellido;
        cout << "Nota 1: ";
        cin >> estudiantes[i].nota1;
        cout << "Nota 2: ";
        cin >> estudiantes[i].nota2;
        cout << "Nota 3: ";
        cin >> estudiantes[i].nota3;
        cout << "Nota 4: ";
        cin >> estudiantes[i].nota4;
    }

    for (int i = 0; i < numEstudiantes; i++) {
        float promedio = (estudiantes[i].nota1 + estudiantes[i].nota2 + estudiantes[i].nota3 + estudiantes[i].nota4) / 4.0;
        cout << "Estudiante " << estudiantes[i].id << ": " << endl;
        cout << "Nombre: " << estudiantes[i].nombre << " " << estudiantes[i].apellido << endl;
        cout << "Nota 1: " << estudiantes[i].nota1 << endl;
        cout << "Nota 2: " << estudiantes[i].nota2 << endl;
        cout << "Nota 3: " << estudiantes[i].nota3 << endl;
        cout << "Nota 4: " << estudiantes[i].nota4 << endl;
        cout << "Promedio: " << promedio << endl;
        if (promedio > 60) {
            cout << "Aprobado" << endl;
        } else {
            cout << "Reprobado" << endl;
        }
        cout << endl;
    }

    delete[] estudiantes;

    return 0;
}