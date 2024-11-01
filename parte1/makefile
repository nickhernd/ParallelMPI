# Compilador y opciones de compilación
MPICXX = mpic++
CXX = g++
CXXFLAGS = 

# Nombres de los ejecutables
SUMA_NATURALES_EXEC = sumaNaturales
CALC_PI_EXEC = calcPI
CARLO_PI_EXEC = carloPI
CALC_PI_SEC_EXEC = calcPIsec
CARLO_PI_SEC_EXEC = monteCarloPIsec
DIFUSION_EXEC = difusion
DISPERSION_EXEC = dispersion
REDUCCION_EXEC = reduccion
ACUMULACION_EXEC = acumulacion
TODOS_DIFUNDEN_EXEC = todosDifunden
TODOS_COMBINAN_EXEC = todosCombinan
SPMD_EXEC = spmd
MAX_EXEC = mpmdMax
MIN_EXEC = mpmdMin
MEDIA_EXEC = mpmdMedia
MAINP2_EXEC = mainP2

# Archivos fuente
SUMA_NATURALES_SRC = sumaNaturales.cc
CALC_PI_SRC = calculoPI.cc
CARLO_PI_SRC = monteCarloPI.cc
CALC_PI_SEC_SRC = calculoPIsec.cc
CARLO_PI_SEC_SRC = monteCarloPIsec.cc
DIFUSION_SRC = difusion.cc
DISPERSION_SRC = dispersion.cc
REDUCCION_SRC = reduccion.cc
ACUMULACION_SRC = acumulacion.cc
TODOS_DIFUNDEN_SRC = todosDifunden.cc
TODOS_COMBINAN_SRC = todosCombinan.cc
SPMD_SRC = spmd.cc
MAX_SRC = mpmdMax.cc
MIN_SRC = mpmdMin.cc
MEDIA_SRC = mpmdMedia.cc
MAINP2_SRC = mainP2.cc

# Objetivo por defecto: compilar todos los ejecutables
all: $(SUMA_NATURALES_EXEC) $(CALC_PI_EXEC) $(CARLO_PI_EXEC) $(CALC_PI_SEC_EXEC) $(CARLO_PI_SEC_EXEC) $(DIFUSION_EXEC) $(DISPERSION_EXEC) $(REDUCCION_EXEC) $(ACUMULACION_EXEC) $(TODOS_DIFUNDEN_EXEC) $(TODOS_COMBINAN_EXEC) $(SPMD_EXEC) $(MAX_EXEC) $(MIN_EXEC) $(MEDIA_EXEC) $(MAINP2_EXEC)

# Compilar el programa sumaNaturales
$(SUMA_NATURALES_EXEC): $(SUMA_NATURALES_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(SUMA_NATURALES_EXEC) $(SUMA_NATURALES_SRC)

# Compilar el programa calculoPI
$(CALC_PI_EXEC): $(CALC_PI_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(CALC_PI_EXEC) $(CALC_PI_SRC)

# Compilar el programa monteCarloPI
$(CARLO_PI_EXEC): $(CARLO_PI_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(CARLO_PI_EXEC) $(CARLO_PI_SRC)

# Compilar el programa calculoPIsec (secuencial)
$(CALC_PI_SEC_EXEC): $(CALC_PI_SEC_SRC)
	$(CXX) $(CXXFLAGS) -o $(CALC_PI_SEC_EXEC) $(CALC_PI_SEC_SRC)

# Compilar el programa monteCarloPIsec (secuencial)
$(CARLO_PI_SEC_EXEC): $(CARLO_PI_SEC_SRC)
	$(CXX) $(CXXFLAGS) -o $(CARLO_PI_SEC_EXEC) $(CARLO_PI_SEC_SRC)

# Compilar el programa difusion
$(DIFUSION_EXEC): $(DIFUSION_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(DIFUSION_EXEC) $(DIFUSION_SRC)

# Compilar el programa dispersion
$(DISPERSION_EXEC): $(DISPERSION_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(DISPERSION_EXEC) $(DISPERSION_SRC)

# Compilar el programa reduccion
$(REDUCCION_EXEC): $(REDUCCION_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(REDUCCION_EXEC) $(REDUCCION_SRC)

# Compilar el programa acumulacion
$(ACUMULACION_EXEC): $(ACUMULACION_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(ACUMULACION_EXEC) $(ACUMULACION_SRC)

# Compilar el programa todosDifunden
$(TODOS_DIFUNDEN_EXEC): $(TODOS_DIFUNDEN_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(TODOS_DIFUNDEN_EXEC) $(TODOS_DIFUNDEN_SRC)

# Compilar el programa todosCombinan
$(TODOS_COMBINAN_EXEC): $(TODOS_COMBINAN_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(TODOS_COMBINAN_EXEC) $(TODOS_COMBINAN_SRC)

# Compilar el programa spmd
$(SPMD_EXEC): $(SPMD_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(SPMD_EXEC) $(SPMD_SRC)

# Compilar el programa mpmd_max
$(MAX_EXEC): $(MAX_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(MAX_EXEC) $(MAX_SRC)

# Compilar el programa mpmd_min
$(MIN_EXEC): $(MIN_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(MIN_EXEC) $(MIN_SRC)

# Compilar el programa mpmd_media
$(MEDIA_EXEC): $(MEDIA_SRC)
	$(MPICXX) $(CXXFLAGS) -o $(MEDIA_EXEC) $(MEDIA_SRC)

# Compilar el mainP2
$(MAINP2_EXEC): $(MAINP2_SRC)
	$(CXX) $(CXXFLAGS) -o $(MAINP2_EXEC) $(MAINP2_SRC)

# Ejecutar el programa sumaNaturales con xterm en dos procesos
run_sumaNaturales: $(SUMA_NATURALES_EXEC)
	mpirun -np 2 xterm -hold -e "./$(SUMA_NATURALES_EXEC)"

# Ejecutar el programa calculoPI con opción de sobresuscripción en dos procesos
run_calcPI2: $(CALC_PI_EXEC)
	mpirun --oversubscribe -np 2 ./$(CALC_PI_EXEC)

# Ejecutar el programa monteCarloPI con opción de sobresuscripción en dos procesos
run_carloPI2: $(CARLO_PI_EXEC)
	mpirun --oversubscribe -np 2 ./$(CARLO_PI_EXEC)

# Ejecutar el programa calculoPI con opción de sobresuscripción en cuatro procesos
run_calcPI4: $(CALC_PI_EXEC)
	mpirun --oversubscribe -np 4 ./$(CALC_PI_EXEC)

# Ejecutar el programa monteCarloPI con opción de sobresuscripción en cuatro procesos
run_carloPI4: $(CARLO_PI_EXEC)
	mpirun --oversubscribe -np 4 ./$(CARLO_PI_EXEC)

# Ejecutar el programa calculoPIsec (secuencial)
run_calcPIsec: $(CALC_PI_SEC_EXEC)
	./$(CALC_PI_SEC_EXEC)

# Ejecutar el programa monteCarloPIsec (secuencial)
run_carloPIsec: $(CARLO_PI_SEC_EXEC)
	./$(CARLO_PI_SEC_EXEC)

# Ejecutar el programa difusion con xterm en cuatro procesos
run_difusion: $(DIFUSION_EXEC)
	mpirun --oversubscribe -np 4 xterm -hold -e "./$(DIFUSION_EXEC)"

# Ejecutar el programa dispersion con xterm en cuatro procesos
run_dispersion: $(DISPERSION_EXEC)
	mpirun --oversubscribe -np 4 xterm -hold -e "./$(DISPERSION_EXEC)"

# Ejecutar el programa reduccion con xterm en cuatro procesos
run_reduccion: $(REDUCCION_EXEC)
	mpirun --oversubscribe -np 4 xterm -hold -e "./$(REDUCCION_EXEC)"

# Ejecutar el programa acumulacion con xterm en cuatro procesos
run_acumulacion: $(ACUMULACION_EXEC)
	mpirun --oversubscribe -np 4 xterm -hold -e "./$(ACUMULACION_EXEC)"

# Ejecutar el programa todosDifunden con xterm en cuatro procesos
run_todosDifunden: $(TODOS_DIFUNDEN_EXEC)
	mpirun --oversubscribe -np 4 xterm -hold -e "./$(TODOS_DIFUNDEN_EXEC)"

# Ejecutar el programa todosCombinan con xterm en cuatro procesos
run_todosCombinan: $(TODOS_COMBINAN_EXEC)
	mpirun --oversubscribe -np 4 xterm -hold -e "./$(TODOS_COMBINAN_EXEC)"

# Ejecutar el programa spmd con opción de sobresuscripción en cuatro procesos
run_spmd: $(SPMD_EXEC)
	mpirun --oversubscribe -np 4 ./$(SPMD_EXEC)

# Ejecutar el conjunto de programas MPMD en modo MPMD con redirección de salida en subshells
run_mpmd: $(MAX_EXEC) $(MIN_EXEC) $(MEDIA_EXEC)
	(mpirun --oversubscribe -np 4 ./$(MAX_EXEC) > max_output.txt) & \
	(mpirun --oversubscribe -np 4 ./$(MIN_EXEC) > min_output.txt) & \
	(mpirun --oversubscribe -np 4 ./$(MEDIA_EXEC) > media_output.txt) & wait
	@echo "\n--- Resultados ---"
	@echo "\nMax Output:" && cat max_output.txt
	@echo "\nMin Output:" && cat min_output.txt
	@echo "\nMedia Output:" && cat media_output.txt

# Ejecutar el main para probar todos los programas
run_main: $(MAINP2_EXEC)
	./$(MAINP2_EXEC)

# Limpiar archivos generados
clean:
	rm -f $(SUMA_NATURALES_EXEC) $(CALC_PI_EXEC) $(CARLO_PI_EXEC) $(CALC_PI_SEC_EXEC) $(CARLO_PI_SEC_EXEC) $(DIFUSION_EXEC) $(DISPERSION_EXEC) $(REDUCCION_EXEC) $(ACUMULACION_EXEC) $(TODOS_DIFUNDEN_EXEC) $(TODOS_COMBINAN_EXEC) $(SPMD_EXEC) $(MAX_EXEC) $(MIN_EXEC) $(MEDIA_EXEC) $(MAINP2_EXEC) max_output.txt min_output.txt media_output.txt tiempo_output.txt output.txt
