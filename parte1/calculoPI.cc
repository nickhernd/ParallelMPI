#include <math.h>
#include "mpi.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

using namespace std;

int main(int argc, char *argv[]) {
    int n, rank, size;
    double PI25DT = 3.141592653589793238462643;
    double mypi, pi, h, sum;

    MPI_Init(&argc, &argv); // Inicializamos los procesos
    MPI_Comm_size(MPI_COMM_WORLD, &size); // Obtenemos el número total de procesos
    MPI_Comm_rank(MPI_COMM_WORLD, &rank); // Obtenemos el identificador de cada proceso

    if (rank == 0) {
        cout << "Introduce la precisión del cálculo (n > 0): ";
        cin >> n;
    }

    // El proceso 0 reparte el valor de n al resto de procesos
    MPI_Bcast(&n, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (n <= 0) {
        if (rank == 0) {
            cerr << "El valor de n debe ser mayor a 0." << endl;
        }
        MPI_Finalize();
        return 1;
    }

    // Inicia la medición de tiempo
    double start_time = MPI_Wtime();

    // Cálculo de PI
    h = 1.0 / (double)n;
    sum = 0.0;
    for (int i = rank + 1; i <= n; i += size) {
        double x = h * ((double)i - 0.5);
        sum += (4.0 / (1.0 + x * x));
    }
    mypi = h * sum;

    // Reducir los valores locales de PI a un valor global en el proceso 0
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Finaliza la medición de tiempo
    double end_time = MPI_Wtime();

    // El proceso 0 imprime el resultado y el tiempo total de ejecución
    if (rank == 0) {
        cout << "El valor aproximado de PI es: " << pi << ", con un error de " << fabs(pi - PI25DT) << endl;
        double totaltime = end_time - start_time;
        cout << "Tiempo de ejecución paralelo: " << totaltime << " segundos." << endl;
        ofstream file("tiempo_output.txt", ios::app);
    	if (file.is_open()) {
        	file << totaltime << endl;
        	file.close();
    	} else {
        	cerr << "Error al abrir el archivo para guardar el tiempo." << endl;
    	} 
    }

    MPI_Finalize();
    return 0;
}
