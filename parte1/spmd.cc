#include <mpi.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>  // Para std::min y std::max
#include <numeric>  // Para accumulate()

using namespace std;

int main(int argc, char* argv[]) {
    int rank, size, N = 100;  // Tamaño del vector
    double local_min, local_max, local_sum, global_min, global_max, global_sum;
    
    // Inicializar MPI
    MPI_Init(&argc, &argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);  // Obtener el identificador del proceso
    MPI_Comm_size(MPI_COMM_WORLD, &size);  // Obtener el número total de procesos

    // Definir el tamaño local de cada subvector
    int local_N = N / size;

    // Generar datos en el proceso 0 y distribuirlos
    vector<double> data;
    if (rank == 0) {
        data.resize(N);
        srand(time(0));
        for (int i = 0; i < N; ++i) {
            data[i] = static_cast<double>(rand()) / RAND_MAX * 100.0;  // Genera números entre 0 y 100
        }
    }

    // Cada proceso recibe su subvector
    vector<double> local_data(local_N);
    MPI_Scatter(data.data(), local_N, MPI_DOUBLE, local_data.data(), local_N, MPI_DOUBLE, 0, MPI_COMM_WORLD);

    // Calcular mínimo, máximo y suma local en cada proceso
    local_min = *min_element(local_data.begin(), local_data.end());
    local_max = *max_element(local_data.begin(), local_data.end());
    local_sum = accumulate(local_data.begin(), local_data.end(), 0.0);

    // Reducir los valores mínimos, máximos y de suma en el proceso 0
    MPI_Reduce(&local_min, &global_min, 1, MPI_DOUBLE, MPI_MIN, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_max, &global_max, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
    MPI_Reduce(&local_sum, &global_sum, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    // Calcular y mostrar los resultados finales en el proceso 0
    if (rank == 0) {
        double global_avg = global_sum / N;
        cout << "Máximo global: " << global_max << endl;
        cout << "Mínimo global: " << global_min << endl;
        cout << "Media global: " << global_avg << endl;
    }

    // Finalizar MPI
    MPI_Finalize();
    return 0;
}
