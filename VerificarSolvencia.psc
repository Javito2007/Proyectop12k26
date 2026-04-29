Proceso VerificarSolvencia
    Definir pagos, deuda Como Real
    Definir estadoSolvencia Como Cadena
	
    Escribir "Ingrese total de pagos realizados:"
    Leer pagos
	
    Si pagos >= 0 Entonces
        
        Escribir "Ingrese deuda total:"
        Leer deuda
        
        Si pagos >= deuda Entonces
            deuda <- 0
        Sino
            deuda <- deuda - pagos
        FinSi
        
        Si deuda = 0 Entonces
            estadoSolvencia <- "Solvente"
        Sino
            estadoSolvencia <- "No Solvente"
        FinSi
        
        Escribir "Deuda restante: ", deuda
        Escribir "Estado: ", estadoSolvencia
        
    Sino
        Escribir "Error: Pagos inválidos"
    FinSi
	
FinProceso
