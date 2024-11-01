#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;
    int data;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtener el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtener el número total de procesos

    if (rank == 0) {
        // Solo el proceso 0 inicializa el valor de 'data'
        cout << "Proceso 0: Introduce un número para difundir: ";
        cin >> data;
    }

    // Difundir el valor de 'data' desde el proceso 0 a todos los procesos
    MPI_Bcast(&data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    // Todos los procesos imprimen el valor recibido
    cout << "Proceso " << rank << " recibió el valor: " << data << endl;

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
