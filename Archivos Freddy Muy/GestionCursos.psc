Proceso GestionCursos
    Dimension cursos[100]
    Dimension catedraticos[100]
    Dimension cupos[100]
    Dimension activo[100]
    Dimension inscripciones[100]
    Dimension cursosInscritos[100]
    Definir opcion Como Cadena
    Definir totalCursos Como Entero
    Definir totalInscripciones Como Entero
    totalCursos <- 0
    totalInscripciones <- 0
	
    Repetir
        Escribir "1. Registrar curso"
        Escribir "2. Asignar catedratico a curso"
        Escribir "3. Inscribirse a curso"
        Escribir "4. Consultar cursos activos"
        Escribir "5. Dar de baja un curso"
        Escribir "6. Salir"
        Leer opcion
		
        Si opcion = "1" Entonces
            RegistrarCurso(cursos, cupos, activo, totalCursos)
        SiNo
            Si opcion = "2" Entonces
                AsignarCatedratico(cursos, catedraticos, activo, totalCursos)
            SiNo
                Si opcion = "3" Entonces
                    InscribirseACurso(cursos, cupos, activo, inscripciones, cursosInscritos, totalCursos, totalInscripciones)
                SiNo
                    Si opcion = "4" Entonces
                        ConsultarCursosActivos(cursos, catedraticos, cupos, activo, totalCursos)
                    SiNo
                        Si opcion = "5" Entonces
                            DarDeBajaUnCurso(cursos, activo, inscripciones, cursosInscritos, totalCursos, totalInscripciones)
                        SiNo
                            Si opcion = "6" Entonces
                                Escribir "Haz salido del sistema"
                            SiNo
                                Escribir "Opcion no valida."
                            FinSi
                        FinSi
                    FinSi
                FinSi
            FinSi
        FinSi
		
    Hasta Que opcion = "6"
FinProceso


SubProceso RegistrarCurso(cursos, cupos, activo, totalCursos Por Referencia)
    Definir nombre Como Cadena
    Definir existe Como Logico
    Definir i Como Entero
    existe <- Falso
	
    Escribir "Ingrese nombre del curso:"
    Leer nombre
	
    Si totalCursos > 0 Entonces
        Para i <- 1 Hasta totalCursos Hacer
            Si cursos[i] = nombre Entonces
                existe <- Verdadero
            FinSi
        FinPara
    FinSi
	
    Si existe Entonces
        Escribir "El curso ya existe."
    SiNo
        totalCursos <- totalCursos + 1
        cursos[totalCursos] <- nombre
        Escribir "Ingrese cupo maximo del curso:"
        Leer cupos[totalCursos]
        activo[totalCursos] <- 1
        Escribir "Curso registrado exitosamente."
    FinSi
FinSubProceso


SubProceso AsignarCatedratico(cursos, catedraticos, activo, totalCursos)
    Definir nombre Como Cadena
    Definir docente Como Cadena
    Definir encontrado Como Logico
    Definir i Como Entero
    encontrado <- Falso
	
    Escribir "Ingrese nombre del curso:"
    Leer nombre
    Escribir "Ingrese nombre del catedratico:"
    Leer docente
	
    Si totalCursos > 0 Entonces
        Para i <- 1 Hasta totalCursos Hacer
            Si cursos[i] = nombre Y activo[i] = 1 Entonces
                catedraticos[i] <- docente
                Escribir "Catedratico asignado correctamente."
                encontrado <- Verdadero
            FinSi
        FinPara
    FinSi
	
    Si No encontrado Entonces
        Escribir "Curso no encontrado o inactivo."
    FinSi
FinSubProceso


SubProceso InscribirseACurso(cursos, cupos, activo, inscripciones, cursosInscritos, totalCursos, totalInscripciones Por Referencia)
    Definir nombreCurso Como Cadena
    Definir nombreEstudiante Como Cadena
    Definir encontrado Como Logico
    Definir i Como Entero
    encontrado <- Falso
	
    Escribir "Ingrese nombre del estudiante:"
    Leer nombreEstudiante
    Escribir "Ingrese nombre del curso:"
    Leer nombreCurso
	
    Si totalCursos > 0 Entonces
        Para i <- 1 Hasta totalCursos Hacer
            Si cursos[i] = nombreCurso Y activo[i] = 1 Entonces
                Si cupos[i] > 0 Entonces
                    cupos[i] <- cupos[i] - 1
                    totalInscripciones <- totalInscripciones + 1
                    inscripciones[totalInscripciones] <- nombreEstudiante
                    cursosInscritos[totalInscripciones] <- nombreCurso
                    Escribir "Inscripcion completada exitosamente."
                    encontrado <- Verdadero
                SiNo
                    Escribir "No hay cupo disponible en este curso."
                    encontrado <- Verdadero
                FinSi
            FinSi
        FinPara
    FinSi
	
    Si No encontrado Entonces
        Escribir "Curso no encontrado o inactivo."
    FinSi
FinSubProceso


SubProceso ConsultarCursosActivos(cursos, catedraticos, cupos, activo, totalCursos)
    Definir i Como Entero
    Definir hayActivos Como Logico
    hayActivos <- Falso
	
    Escribir "===== CURSOS ACTIVOS ====="
	
    Si totalCursos > 0 Entonces
        Para i <- 1 Hasta totalCursos Hacer
            Si activo[i] = 1 Entonces
                Escribir "Curso: ", cursos[i], " | Catedratico: ", catedraticos[i], " | Cupos disponibles: ", cupos[i]
                hayActivos <- Verdadero
            FinSi
        FinPara
    FinSi
	
    Si No hayActivos Entonces
        Escribir "No hay cursos activos."
    FinSi
FinSubProceso


SubProceso DarDeBajaUnCurso(cursos, activo, inscripciones, cursosInscritos, totalCursos, totalInscripciones Por Referencia)
    Definir nombre Como Cadena
    Definir encontrado Como Logico
    Definir i Como Entero
    Definir j Como Entero
    encontrado <- Falso
	
    Escribir "Ingrese nombre del curso a dar de baja:"
    Leer nombre
	
    Si totalCursos > 0 Entonces
        Para i <- 1 Hasta totalCursos Hacer
            Si cursos[i] = nombre Y activo[i] = 1 Entonces
                activo[i] <- 0
                encontrado <- Verdadero
                Escribir "Curso dado de baja."
				
                Si totalInscripciones > 0 Entonces
                    Para j <- 1 Hasta totalInscripciones Hacer
                        Si cursosInscritos[j] = nombre Entonces
                            inscripciones[j] <- ""
                            cursosInscritos[j] <- ""
                        FinSi
                    FinPara
                FinSi
				
                Escribir "Curso dado de baja exitosamente."
            FinSi
        FinPara
    FinSi
	
    Si No encontrado Entonces
        Escribir "Curso no encontrado o inactivo."
    FinSi
FinSubProceso