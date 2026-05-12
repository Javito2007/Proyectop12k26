Proceso GestionUsuarios
    Dimension usuarios[100]
    Dimension claves[100]
    Dimension roles[100]
    Dimension activo[100]
    Definir opcion Como Cadena
    Definir totalUsuarios Como Entero
    totalUsuarios <- 0
	
    Repetir
        Escribir "1. Registrar usuario"
        Escribir "2. Autenticar usuario"
        Escribir "3. Asignar rol"
        Escribir "4. Modificar/Desactivar/Reactivar usuario"
        Escribir "5. Mostrar usuarios"
        Escribir "6. Salir"
        Leer opcion
		
        Si opcion = "1" Entonces
            RegistrarUsuario(usuarios, claves, roles, activo, totalUsuarios)
        SiNo
            Si opcion = "2" Entonces
                AutenticarUsuario(usuarios, claves, activo, totalUsuarios)
            SiNo
                Si opcion = "3" Entonces
                    AsignarRol(usuarios, roles, totalUsuarios)
                SiNo
                    Si opcion = "4" Entonces
                        ModificarUsuario(usuarios, claves, activo, totalUsuarios)
                    SiNo
                        Si opcion = "5" Entonces
                            MostrarUsuarios(usuarios, roles, activo, totalUsuarios)
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


SubProceso RegistrarUsuario(usuarios, claves, roles, activo, totalUsuarios Por Referencia)
    totalUsuarios <- totalUsuarios + 1
    Escribir "Ingrese nombre de usuario:"
    Leer usuarios[totalUsuarios]
    Escribir "Ingrese clave:"
    Leer claves[totalUsuarios]
    roles[totalUsuarios] <- "usuario"
    activo[totalUsuarios] <- 1
    Escribir "Usuario registrado exitosamente."
FinSubProceso


SubProceso AutenticarUsuario(usuarios, claves, activo, totalUsuarios)
    Definir nombre Como Cadena
    Definir clave Como Cadena
    Definir encontrado Como Logico
    Definir i Como Entero
    encontrado <- Falso
	
    Escribir "Ingrese nombre de usuario:"
    Leer nombre
    Escribir "Ingrese clave:"
    Leer clave
	
    Para i <- 1 Hasta totalUsuarios Hacer
        Si usuarios[i] = nombre Y claves[i] = clave Y activo[i] = 1 Entonces
            Escribir "Autenticacion exitosa."
            encontrado <- Verdadero
        FinSi
    FinPara
	
    Si No encontrado Entonces
        Escribir "Usuario/clave incorrectos o usuario desactivado."
    FinSi
FinSubProceso


SubProceso AsignarRol(usuarios, roles, totalUsuarios)
    Definir nombre Como Cadena
    Definir nuevoRol Como Cadena
    Definir encontrado Como Logico
    Definir i Como Entero
    encontrado <- Falso
	
    Escribir "Ingrese nombre de usuario:"
    Leer nombre
    Escribir "Ingrese nuevo rol (admin/usuario):"
    Leer nuevoRol
	
    Para i <- 1 Hasta totalUsuarios Hacer
        Si usuarios[i] = nombre Entonces
            roles[i] <- nuevoRol
            Escribir "Rol asignado correctamente."
            encontrado <- Verdadero
        FinSi
    FinPara
	
    Si No encontrado Entonces
        Escribir "Usuario no encontrado."
    FinSi
FinSubProceso


SubProceso ModificarUsuario(usuarios, claves, activo, totalUsuarios)
    Definir nombre Como Cadena
    Definir nuevaClave Como Cadena
    Definir opcion Como Entero
    Definir encontrado Como Logico
    Definir i Como Entero
    encontrado <- Falso
	
    Escribir "Ingrese nombre de usuario a modificar:"
    Leer nombre
	
    Para i <- 1 Hasta totalUsuarios Hacer
        Si usuarios[i] = nombre Entonces
            encontrado <- Verdadero
            Escribir "1. Cambiar clave"
            Escribir "2. Desactivar usuario"
            Escribir "3. Reactivar usuario"
            Leer opcion
			
            Si opcion = 1 Entonces
                Escribir "Ingrese nueva clave:"
                Leer nuevaClave
                claves[i] <- nuevaClave
                Escribir "Clave actualizada."
            SiNo
                Si opcion = 2 Entonces
                    activo[i] <- 0
                    Escribir "Usuario desactivado."
                SiNo
                    Si opcion = 3 Entonces
                        activo[i] <- 1
                        Escribir "Usuario reactivado."
                    SiNo
                        Escribir "Opcion no valida."
                    FinSi
                FinSi
            FinSi
        FinSi
    FinPara
	
    Si No encontrado Entonces
        Escribir "Usuario no encontrado."
    FinSi
FinSubProceso


SubProceso MostrarUsuarios(usuarios, roles, activo, totalUsuarios)
    Definir estado Como Cadena
    Definir i Como Entero
    Escribir "----- LISTA DE USUARIOS -----"
    Para i <- 1 Hasta totalUsuarios Hacer
        Si activo[i] = 1 Entonces
            estado <- "Activo"
        SiNo
            estado <- "Desactivado"
        FinSi
        Escribir "Usuario: ", usuarios[i], " | Rol: ", roles[i], " | Estado: ", estado
    FinPara
FinSubProceso