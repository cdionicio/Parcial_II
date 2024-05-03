#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Estructura para almacenar la información de cada estudiante
struct Estudiante {
    int id;
    string nombres;
    string apellidos;
    float nota1, nota2, nota3, nota4;
    float promedio;
    string resultado;
};

// Función para calcular el promedio y determinar si el estudiante aprobó o reprobó
void calcularPromedio(Estudiante* estudiante) {
    estudiante->promedio = (estudiante->nota1 + estudiante->nota2 + estudiante->nota3 + estudiante->nota4) / 4;
    if (estudiante->promedio >= 60) {
        estudiante->resultado = "Aprobado";
    } else {
        estudiante->resultado = "Reprobado";
    }
}

// Función para crear un nuevo estudiante
void crearEstudiante(Estudiante* estudiantes, int& numEstudiantes) {
    cout << "Ingrese la información del estudiante " << numEstudiantes + 1 << ":" << endl;
    cout << "ID: ";
    cin >> estudiantes[numEstudiantes].id;
    cout << "Nombres: ";
    cin.ignore();
    getline(cin, estudiantes[numEstudiantes].nombres);
    cout << "Apellidos: ";
    getline(cin, estudiantes[numEstudiantes].apellidos);
    cout << "Nota 1: ";
    cin >> estudiantes[numEstudiantes].nota1;
    cout << "Nota 2: ";
    cin >> estudiantes[numEstudiantes].nota2;
    cout << "Nota 3: ";
    cin >> estudiantes[numEstudiantes].nota3;
    cout << "Nota 4: ";
    cin >> estudiantes[numEstudiantes].nota4;
    calcularPromedio(&estudiantes[numEstudiantes]);
    numEstudiantes++;
}

// Función para leer los estudiantes desde el archivo binario
void leerEstudiantes(Estudiante* estudiantes, int& numEstudiantes) {
    ifstream archivo("notas.dat", ios::binary);
    if (archivo.is_open()) {
        archivo.read(reinterpret_cast<char*>(&numEstudiantes), sizeof(int));
        for (int i = 0; i < numEstudiantes; i++) {
            archivo.read(reinterpret_cast<char*>(&estudiantes[i]), sizeof(Estudiante));
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Función para escribir los estudiantes en el archivo binario
void escribirEstudiantes(Estudiante* estudiantes, int numEstudiantes) {
    ofstream archivo("notas.dat", ios::binary | ios::trunc);
    if (archivo.is_open()) {
        archivo.write(reinterpret_cast<char*>(&numEstudiantes), sizeof(int));
        for (int i = 0; i < numEstudiantes; i++) {
            archivo.write(reinterpret_cast<char*>(&estudiantes[i]), sizeof(Estudiante));
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo." << endl;
    }
}

// Función para mostrar la información de un estudiante
void mostrarEstudiante(Estudiante* estudiante) {
    cout << "ID: " << estudiante->id << endl;
    cout << "Nombres: " << estudiante->nombres << endl;
    cout << "Apellidos: " << estudiante->apellidos << endl;
    cout << "Nota 1: " << estudiante->nota1 << endl;
    cout << "Nota 2: " << estudiante->nota2 << endl;
    cout << "Nota 3: " << estudiante->nota3 << endl;
    cout << "Nota 4: " << estudiante->nota4 << endl;
    cout << "Promedio: " << estudiante->promedio << endl;
    cout << "Resultado: " << estudiante->resultado << endl;
}

// Función para mostrar el menú y ejecutar las opciones
void menu(Estudiante* estudiantes, int& numEstudiantes) {
    int opcion;
    do {
        cout << "Menú:" << endl;
        cout << "1. Crear estudiante" << endl;
        cout << "2. Leer estudiantes" << endl;
        cout << "3. Actualizar estudiante" << endl;
        cout << "4. Eliminar estudiante" << endl;
        cout << "5. Salir" << endl;
        cout << "Ingrese una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                crearEstudiante(estudiantes, numEstudiantes);
                escribirEstudiantes(estudiantes, numEstudiantes);
                break;
            case 2:
                leerEstudiantes(estudiantes, numEstudiantes);
                for (int i = 0; i < numEstudiantes; i++) {
                    mostrarEstudiante(&estudiantes[i]);
                    cout << endl;
                }
                break;
            case 3:
                // Implementar la función para actualizar un estudiante
                break;
            case 4:
                // Implementar la función para eliminar un estudiante
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                break;
            default:
                cout << "Opción inválida. Intente de nuevo." << endl;
                break;
        }
    } while (opcion != 5);
}

int main() {
    const int MAX_ESTUDIANTES = 100;
    Estudiante estudiantes[MAX_ESTUDIANTES];
    int numEstudiantes = 0;

    menu(estudiantes, numEstudiantes);

    return 0;
}