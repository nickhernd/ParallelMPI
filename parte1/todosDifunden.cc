#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    int local_value;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtener el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtener el número total de procesos

    // Cada proceso asigna un valor local (por ejemplo, rank * 2)
    local_value = rank * 2;
    cout << "Proceso " << rank << " tiene el valor: " << local_value << endl;

    // Vector para almacenar los datos recibidos de todos los procesos
    vector<int> gathered_data(size);

    // Todos los procesos recopilan los valores de cada proceso
    MPI_Allgather(&local_value, 1, MPI_INT, gathered_data.data(), 1, MPI_INT, MPI_COMM_WORLD);

    // Cada proceso imprime el resultado de la acumulación
    cout << "Proceso " << rank << " tiene los datos recopilados: ";
    for (int i = 0; i < size; i++) {
        cout << gathered_data[i] << " ";
    }
    cout << endl;

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
