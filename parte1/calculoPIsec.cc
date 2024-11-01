#include <iostream>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;

int main() {
    int n; // Número de iteraciones
    double PI25DT = 3.141592653589793238462643;
    double pi, h, sum;

    cout << "Introduce la precisión del cálculo (n > 0): ";
    cin >> n;

    if (n <= 0) {
        cerr << "El valor de n debe ser mayor a 0." << endl;
        return 1;
    }

    // Inicia la medición de tiempo
    auto start_time = chrono::high_resolution_clock::now();

    // Calculo de PI
    h = 1.0 / (double)n;
    sum = 0.0;
    for (int i = 1; i <= n; ++i) {
        double x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x * x));
    }
    pi = h * sum;

    // Finaliza la medición de tiempo
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_time - start_time;

    // Imprime el resultado
    cout << "El valor aproximado de PI es: " << pi << ", con un error de " << fabs(pi - PI25DT) << endl;
    double totalTime = duration.count();
    cout << "Tiempo de ejecución secuencial: " << totalTime << " segundos." << endl;

    ofstream file("tiempo_output.txt", ios::app);
    if (file.is_open()) {
        file << totalTime << endl;
        file.close();
    } else {
        cerr << "Error al abrir el archivo para guardar el tiempo." << endl;
    } 

    return 0;
}
