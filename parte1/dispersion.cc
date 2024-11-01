#include <mpi.h>
#include <iostream>
#include <vector>
using namespace std;

int main(int argc, char* argv[]) {
    int rank, size;

    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtener el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtener el número total de procesos

    const int elements_per_proc = 4;  // Número de elementos que recibirá cada proceso
    vector<int> data;

    if (rank == 0) {
        // Solo el proceso 0 inicializa el array de datos
        data.resize(size * elements_per_proc);
        cout << "Proceso 0 inicializando el array: ";
        for (int i = 0; i < size * elements_per_proc; i++) {
            data[i] = i + 1;  // Inicializar el array con valores del 1 al size*elements_per_proc
            cout << data[i] << " ";
        }
        cout << endl;
    }

    // Cada proceso recibirá un buffer para su porción de datos
    vector<int> recv_data(elements_per_proc);

    // Scatter: el proceso 0 distribuye partes iguales del array a cada proceso
    MPI_Scatter(data.data(), elements_per_proc, MPI_INT, recv_data.data(), elements_per_proc, MPI_INT, 0, MPI_COMM_WORLD);

    // Cada proceso imprime los datos que ha recibido
    cout << "Proceso " << rank << " recibió los datos: ";
    for (int i = 0; i < elements_per_proc; i++) {
        cout << recv_data[i] << " ";
    }
    cout << endl;

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
