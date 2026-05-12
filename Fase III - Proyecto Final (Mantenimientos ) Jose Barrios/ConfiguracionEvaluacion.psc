Algoritmo ConfiguracionEvaluacion
    Definir periodo Como Cadena
    Definir n, i Como Entero
    Definir suma Como Real
	
    Dimension criterios[10]  // arreglo de 10 cadenas
    Dimension ponderaciones[10]  // arreglo de 10 reales
	
    Escribir "¿Cuántos criterios de evaluación desea definir?"
    Leer n
	
    Para i <- 1 Hasta n Con Paso 1 Hacer
        Escribir "Ingrese nombre del criterio ", i
        Leer criterios[i]
        Escribir "Ingrese ponderación (%) para ", criterios[i]
        Leer ponderaciones[i]
    FinPara
	
    Escribir "Ingrese el periodo de evaluación (ejemplo: Primer Semestre 2026)"
    Leer periodo
	
    // Validación simple
    suma <- 0
    Para i <- 1 Hasta n Hacer
        suma <- suma + ponderaciones[i]
    FinPara
	
    Si suma <> 100 Entonces
        Escribir "Error: las ponderaciones no suman 100%"
    SiNo
        Escribir "Configuración almacenada correctamente."
        Escribir "=== Configuración Final ==="
        Para i <- 1 Hasta n Hacer
            Escribir criterios[i], " - ", ponderaciones[i], "%"
        FinPara
        Escribir "Periodo: ", periodo
    FinSi
FinAlgoritmo
