#include <mpi.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    int local_value, sum;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtener el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtener el número total de procesos

    // Semilla para la generación aleatoria de cada proceso
    srand(time(0) + rank);
    local_value = rand() % 100;  // Cada proceso genera un número aleatorio entre 0 y 99

    cout << "Proceso " << rank << " generó el valor: " << local_value << endl;

    // Reducción: Sumar los valores de todos los procesos en el proceso 0
    MPI_Reduce(&local_value, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    // Solo el proceso 0 imprime el resultado de la reducción
    if (rank == 0) {
        cout << "La suma de todos los valores es: " << sum << endl;
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
