#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    int rank, size, n_points, points_in_circle = 0, total_in_circle;
    double pi_estimate;

    MPI_Init(&argc, &argv);                  // Inicializamos MPI
    MPI_Comm_size(MPI_COMM_WORLD, &size);    // Obtenemos el número total de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);    // Obtenemos el identificador del proceso

    if (rank == 0) {
        // Proceso principal pide el número de puntos
        cout << "Introduce el número de puntos para el cálculo de PI: ";
        cin >> n_points;

        // Repartir el número de puntos entre los procesos
        MPI_Bcast(&n_points, 1, MPI_INT, 0, MPI_COMM_WORLD);
    } else {
        // Procesos que no son rank 0 reciben n_points
        MPI_Bcast(&n_points, 1, MPI_INT, 0, MPI_COMM_WORLD);
    }

    // Inicia la medición de tiempo
    double start_time = MPI_Wtime();

    // Semilla para cada proceso diferente
    srand(time(0) + rank);

    // Cada proceso calcula su parte de puntos
    int local_count = 0;
    for (int i = rank; i < n_points; i += size) {
        double x = static_cast<double>(rand()) / RAND_MAX;
        double y = static_cast<double>(rand()) / RAND_MAX;
        
        if ((x * x + y * y) <= 1.0) {
            local_count++;
        }
    }

    // Reducir los resultados de todos los procesos en el proceso 0
    MPI_Reduce(&local_count, &total_in_circle, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Finaliza la medición de tiempo
    double end_time = MPI_Wtime();

    // Calcular e imprimir el valor de pi solo en el proceso 0
    if (rank == 0) {
        pi_estimate = 4.0 * static_cast<double>(total_in_circle) / n_points;
        cout << "El valor estimado de PI es: " << pi_estimate << endl;
        double totalTime = end_time - start_time;
        cout << "Tiempo de ejecución paralelo: " << totalTime << " segundos." << endl;
        ofstream file("tiempo_output.txt", ios::app);
        if (file.is_open()) {
            file << totalTime << endl;
            file.close();
        } else {
            cerr << "Error al abrir el archivo para guardar el tiempo." << endl;
        }
    }

    MPI_Finalize();  // Finalizamos MPI
    return 0;
}
