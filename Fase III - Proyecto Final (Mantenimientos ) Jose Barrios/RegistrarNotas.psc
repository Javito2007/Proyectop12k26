Algoritmo RegistrarNotas
    Definir n, i Como Entero
    Definir nota Como Real
    Definir valido Como Logico
	
    Dimension alumnos[10]   // lista de alumnos inscritos
    Dimension notas[10]     // notas ingresadas
	
    Escribir "¿Cuántos alumnos desea registrar?"
    Leer n
	
    // 4.1 Consultar criterios y alumnos
    Para i <- 1 Hasta n Hacer
        Escribir "Ingrese nombre del alumno ", i
        Leer alumnos[i]
    FinPara
	
    // 4.2 Ingresar notas
    Para i <- 1 Hasta n Hacer
        Escribir "Ingrese nota para ", alumnos[i]
        Leer nota
		
        // 4.3 Validar notas
        Si nota >= 0 Y nota <= 100 Entonces
            notas[i] <- nota
            valido <- Verdadero
        SiNo
            Escribir "Error: nota inválida. Debe estar entre 0 y 100."
            valido <- Falso
        FinSi
    FinPara
	
    // 4.4 Almacenar notas
    Si valido = Verdadero Entonces
        Escribir "Notas almacenadas correctamente."
        Para i <- 1 Hasta n Hacer
            Escribir alumnos[i], " - ", notas[i]
        FinPara
    SiNo
        Escribir "No se almacenaron todas las notas por errores de validación."
    FinSi
FinAlgoritmo
