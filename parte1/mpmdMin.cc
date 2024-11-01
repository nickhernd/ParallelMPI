#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[]) {
    int rank, size, N = 100;
    double local_min, global_min;

    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int local_N = N / size;
    vector<double> data;

    // Generar datos en el proceso 0 y distribuirlos
    if (rank == 0) {
        data.resize(N);
        srand(time(0) + rank);
        for (int i = 0; i < N; ++i) {
            data[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;
        }
    }

    vector<double> local_data(local_N);
    MPI_Scatter(data.data(), local_N, MPI_DOUBLE, local_data.data(), local_N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Calcular el mínimo local
    local_min = *min_element(local_data.begin(), local_data.end());

    // Reducir los valores al mínimo global en el proceso 0
    MPI_Reduce(&local_min, &global_min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);

    // Imprimir el resultado en el proceso 0
    if (rank == 0) {
        cout << "Mínimo global: " << global_min << endl;
    }

    MPI_Finalize();
    return 0;
}
