Algoritmo calculoNotaFinal
	Definir nota1, nota2, nota3, nota4 Como Real
	Definir estado como cadena
	
	Escribir "Ingrese nota 1: "
	Leer nota1
	Escribir "Ingrese nota 2: "
	Leer nota2
	Escribir "Ingrese nota 3: "
	Leer  nota3
	Escribir "Ingrese nota 4: "
	Leer nota4
	
	Si (nota1 >= 0 y nota1 <= 100) y (nota2 >= 0 y nota2 <= 100) y (nota3 >= 0 y nota3 <= 100) y (nota4 >= 0 y nota4 <= 100) Entonces
		
		promedio <- (nota1 + nota2 + nota3 + nota4) / 4
		
		si promedio >= 61 Entonces 
			estado <- "Aprobado"
		SiNo
			estado <- "Reprobado"
			
		FinSi
		
		Escribir "Estado: ", estado
		
	SiNo
		escribir "Error: notas invalidas"
		
	FinSi
	
FinAlgoritmo
