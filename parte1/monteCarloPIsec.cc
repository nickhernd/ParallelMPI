#include <iostream>
#include <cstdlib>
#include <cmath>
#include <chrono>
#include <fstream>

using namespace std;

int main() {
    int n_points, points_in_circle = 0;
    double pi_estimate;

    cout << "Introduce el número de puntos para el cálculo de PI: ";
    cin >> n_points;

    // Inicia la medición de tiempo
    auto start_time = chrono::high_resolution_clock::now();

    srand(time(0));  // Semilla para generación aleatoria

    for (int i = 0; i < n_points; ++i) {
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;
        
        if ((x * x + y * y) <= 1.0) {
            points_in_circle++;
        }
    }

    // Cálculo de PI
    pi_estimate = 4.0 * static_cast<double>(points_in_circle) / n_points;

    // Finaliza la medición de tiempo
    auto end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> duration = end_time - start_time;
    double totalTime = duration.count();
    cout << "El valor estimado de PI es: " << pi_estimate << endl;
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
