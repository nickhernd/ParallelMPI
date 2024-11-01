#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <numeric>

using namespace std;

int main(int argc, char* argv[]) {
    int rank, size, N = 100;
    double local_sum, global_sum;

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

    // Calcular la suma local
    local_sum = accumulate(local_data.begin(), local_data.end(), 0.0);
    // Reducir los valores de la suma al proceso 0
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calcular y mostrar la media en el proceso 0
    if (rank == 0) {
        double global_avg = global_sum / N;
        cout << "Media global: " << global_avg << endl;
    }

    MPI_Finalize();
    return 0;
}
