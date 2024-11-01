#include <iostream>
#include <cstdlib> 
#include <fstream>
#include <string>

using namespace std;

void printMenu(){
	cout << endl << "===========================" << endl;
	cout << "Menú de opciones" << endl;
	cout << "1 - Tarea 2.1.2" << endl;
	cout << "2 - Tarea 2.1.3 v1" << endl;
	cout << "3 - Tarea 2.1.3 v2" << endl;
	cout << "4 - Tarea 2.1.4" << endl;
	cout << "q - Salir" <<  endl;
	cout << "===========================" << endl;
}

void tarea3v1(){
	// Integral --> para apreciar diferencias usar 300000000
	ofstream file("tiempo_output.txt", ios::app);
    if (file.is_open()) {
        file << "1 ";
        file.close();
    } else {
            cerr << "Error al abrir el archivo" << endl;
    }
    system("make run_calcPIsec");
    file.open("tiempo_output.txt", std::ios::app);
    if (file.is_open()) {
        file << "2 ";
        file.close();
    } else {
            cerr << "Error al abrir el archivo" << endl;
    }
    system("make run_calcPI2");
    file.open("tiempo_output.txt", std::ios::app);
    if (file.is_open()) {
        file << "4 ";
        file.close();
    } else {
            cerr << "Error al abrir el archivo" << endl;
    }
    system("make run_calcPI4");
    system("gnuplot -p -e \""
    	"set terminal png size 800,600; "
       	"set output 'grafico_integral.png'; "
      	"set title 'Comparación de Tiempos de Cálculo de PI (Integral)'; "
       	"set xlabel 'Número de Procesos'; "
    	"set ylabel 'Tiempo (s)'; "
        "set style data histogram; "
        "set style histogram cluster gap 1; "
        "set style fill solid border -1; "
        "set boxwidth 0.9; "
        "plot 'tiempo_output.txt' using 2:xtic(1) title 'Tiempo'\"");
    system("rm -f tiempo_output.txt");

    // Monte Carlo --> para apreciar diferencias usar 50000000
    file.open("tiempo_output.txt", ios::app);
    if (file.is_open()) {
        file << "1 ";
        file.close();
    } else {
            cerr << "Error al abrir el archivo" << endl;
    }
    system("make run_carloPIsec");
    file.open("tiempo_output.txt", std::ios::app);
    if (file.is_open()) {
        file << "2 ";
        file.close();
    } else {
            cerr << "Error al abrir el archivo" << endl;
    }
    system("make run_carloPI2");
    file.open("tiempo_output.txt", std::ios::app);
    if (file.is_open()) {
        file << "4 ";
        file.close();
    } else {
            cerr << "Error al abrir el archivo" << endl;
    }
    system("make run_carloPI4");
    system("gnuplot -p -e \""
    	"set terminal png size 800,600; "
       	"set output 'grafico_monte_carlo.png'; "
        "set title 'Comparación de Tiempos de Cálculo de PI (Monte Carlo)'; "
        "set xlabel 'Número de Procesos'; "
        "set ylabel 'Tiempo (s)'; "
        "set style data histogram; "
        "set style histogram cluster gap 1; "
        "set style fill solid border -1; "
        "set boxwidth 0.9; "
        "plot 'tiempo_output.txt' using 2:xtic(1) title 'Tiempo'\"");
}

void tarea3v2(){
	system("make run_difusion");
	system("make run_dispersion");
	system("make run_reduccion");
	system("make run_acumulacion");
	system("make run_todosDifunden");
	system("make run_todosCombinan");
}

void tarea4(){
	cout << "PROGRAMA SPMD" << endl << endl;
	system("make run_spmd");
	cout << endl;
	cout << "PROGRAMA MPMD" << endl << endl;
	system("make run_mpmd");
}

char menu(){
	char opt;
	char seguir;
	do{	
		printMenu();
		cin >> opt;
		switch(opt){
		case '1':
			cout << "Elijo la Tarea 2.1.2" << endl;
			system("make run_sumaNaturales");
			break;
		case '2':
			cout << "Elijo la Tarea 2.1.3 v1" << endl;
			tarea3v1();
			break;
		case '3':
			cout << "Elijo la Tarea 2.1.3 v2" << endl;
			tarea3v2();
			break;
		case '4':
			cout << "Elijo la Tarea 2.1.4" << endl;
			tarea4();
			cout << endl << "Pulsa cualquier tecla para finalizar" << endl;
			cin >> seguir;
			break;
		case 'q':
			cout << "Elijo salir" << endl;
			break;
		case 'Q':
			cout << "Elijo salir" << endl;
			break;
		default:
			cout << "Opción no válida (1, 2, 3, 4, q)" << endl;
		}
		system("clear");
	}
	while(opt != 'q' && opt != 'Q');
	return opt;
}

int main() {
	system("make clean");
	system("make");
	menu();
	
	return 0;
}