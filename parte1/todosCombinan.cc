#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    int local_value, total_sum;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtener el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtener el número total de procesos

    // Cada proceso asigna un valor local (por ejemplo, rank * 2)
    local_value = rank * 2;
    cout << "Proceso " << rank << " tiene el valor local: " << local_value << endl;

    // Todos combinan: calcular la suma de todos los valores locales y almacenar el resultado en cada proceso
    MPI_Allreduce(&local_value, &total_sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    // Cada proceso imprime el resultado total de la suma
    cout << "Proceso " << rank << " tiene el resultado de la suma total: " << total_sum << endl;

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
