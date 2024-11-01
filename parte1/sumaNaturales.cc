#include <mpi.h>
#include <iostream>
using namespace std;

int main(int argc, char** argv) {
    int rank, size;
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Rango del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Número total de procesos

    if (size < 2) {
        cout << "Este programa requiere al menos 2 nodos." << endl;
        MPI_Finalize();
        return 1;
    }

    if (rank == 0) {
        // Nodo N1
        int N;
        cout << "Solicitando la longitud del vector al nodo N2..." << endl;

        // Enviar solicitud a N2
        MPI_Send(NULL, 0, MPI_INT, 1, 0, MPI_COMM_WORLD);

        // Recibir el tamaño del vector desde N2
        MPI_Recv(&N, 1, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Nodo N1 ha recibido el tamaño del vector: " << N << endl;

        // Calcular la suma de los N primeros números naturales
        int sum = N * (N + 1) / 2;
        MPI_Send(&sum, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
        
        // Esperar confirmación de finalización de N2
        MPI_Recv(NULL, 0, MPI_INT, 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Nodo N2 ha terminado la tarea. Finalizando el programa." << endl;
    } 
    else if (rank == 1) {
        // Nodo N2
        int N = 10;
        
        // Esperar solicitud de N1
        MPI_Recv(NULL, 0, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        
        // Pedir al usuario que introduzca el tamaño del vector
        cout << "Mensaje desde N1: El tamaño del vector es: ";//<< N << endl;
        cin >> N;

        // Enviar el tamaño del vector a N1
        MPI_Send(&N, 1, MPI_INT, 0, 0, MPI_COMM_WORLD);
        
        // Recibir el resultado de la suma desde N1
        int sum;
        MPI_Recv(&sum, 1, MPI_INT, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "El resultado de la suma de los primeros " << N << " números naturales es: " << sum << endl;

        // Enviar confirmación de finalización a N1
        MPI_Send(NULL, 0, MPI_INT, 0, 0, MPI_COMM_WORLD);
    }

    MPI_Finalize();
    //for(;;); // Para mantener los terminales abiertos con xterm
    return 0;

}
