Funcion valorCarta <- obtenerCarta (mazo, mano, turno_j, suma_m, blackjack)
	Definir carta, valorCarta, valorAs como Entero
	
	Repetir
		carta := Aleatorio(1,52)
	Mientras Que mazo[carta,2] = mano[carta,2]

	mano[carta,2] := mazo[carta,2]
		
	Segun mazo[carta,1] Hacer
		1: Escribir "Saco un ", mazo[carta,2] ," de diamante."
		2: Escribir "Saco un ", mazo[carta,2] ," de corazon."
		3: Escribir "Saco un ", mazo[carta,2] ," de trebol."
		4: Escribir "Saco un ", mazo[carta,2] ," de picas."
			Si mazo[carta,2] = 39 o mazo[carta,2] = 49 o mazo[carta,2] = 50 o mazo[carta,2] = 51 o mazo[carta,2] = 52 Entonces
				blackjack := blackjack + 1
			FinSi
	FinSegun
		
	Si mazo[carta,2] = 1 Entonces
		
		Si turno_j = Verdadero Entonces
			Repetir
				Escribir "Como quieres usar el AS? Escribe 1 o 11."
				Leer valorAs
			Hasta Que valorAs = 1 o valorAs = 11
			valorCarta := valorAs
		SiNo
			Si suma_m + 11 > 21 Entonces
				valorCarta:= 1
			SiNo
				valorCarta:= 11
			FinSi
		FinSi
	
	SiNo
		Si mazo[carta,2] = 11 o mazo[carta,2] = 12 o mazo[carta,2] = 13 Entonces
			valorCarta := 10
		SiNo
			valorCarta := mazo[carta,2]
		FinSi
	FinSi
	
FinFuncion


Proceso blackjackGame
	
	Definir valorCarta, mazo, mano, i, j, k, turno, suma_m, suma_j, blackjack, capital, apuesta  Como Entero
	Definir respuesta_1, respuesta_2 Como Caracter
	Definir turno_j,victoria_j Como Logico
	Dimension mazo[52,2]
	Dimension mano[52,2]
	capital := 0
	
	k:= 1
	Para i desde 1 hasta 4 Hacer
		Para j desde 1 hasta 13 Hacer
			mazo[ k ,1] := i
			mazo[ k ,2] := j
			k:= k+1
		FinPara
	FinPara
	
	// Inicio del juego
	
	Escribir "==== BLACKJACK ===="
	Escribir "Bienvenido al juego de BLACKJACK o el 21, desea iniciar una partida?"
	
	Repetir
		Escribir "S = Si, N = No"
		Leer respuesta_2
		respuesta_2 := Mayusculas(respuesta_2)
	Hasta Que respuesta_2 = "S" o respuesta_2 = "N"
	
	Si respuesta_2 = "S" Entonces
	Repetir
			suma_m := 0
			suma_j := 0
			blackjack := 0
			turno_j := Falso
			turno := 1
			respuesta_1 := ""
			
		Si capital = 0 Entonces
			Repetir
				Escribir ""
				Escribir "Cual es tu capital?"
				Leer capital
			Mientras Que capital <=0
		FinSi
		
		Repetir
			Escribir "Cuanto apuestas?"
			Leer apuesta
		Mientras Que apuesta <=0 o capital < apuesta 
		
		k:= 1
		Para i desde 1 hasta 4 Hacer
			Para j desde 1 hasta 13 Hacer
				mano[ k ,1] := 0
				mano[ k ,2] := 0
				k:= k+1
			FinPara
		FinPara
		
		Limpiar Pantalla
		Escribir "|| Turno ", turno
		Escribir "Capital: ", capital
		Escribir "Apuesta: ", apuesta
		victoria_j := Falso
		
		turno_j := Verdadero
		Escribir ""
		Escribir "JUGADOR: "
		Para i desde 1 hasta 2 Hacer
			valorCarta := obtenerCarta(mazo, mano, turno_j, suma_m, blackjack)
			suma_j := suma_j + valorCarta
		FinPara
		
		Si blackjack = 2 Entonces
			victoria_j := Verdadero
		FinSi
		
		Si suma_j = 21 o blackjack = 2 Entonces
			victoria_j := Verdadero
		SiNo
			Escribir "-----------------------------------"
			
			turno_j := Falso
			Escribir "MESA: "
			valorCarta := obtenerCarta(mazo, mano, turno_j, suma_m, blackjack)
			suma_m := suma_m + valorCarta
			
			Escribir ""
			Escribir "Tu suma : ", suma_j
			Escribir "Suma de la mesa : ", suma_m
			
			Escribir ""
			
			Repetir
				Escribir "Desea sacar otra carta? S = Si , N = No"
				Leer respuesta_1
				respuesta_1:= mayusculas(respuesta_1)
			Hasta Que respuesta_1 = "S" o respuesta_1 = "N"
		FinSi
		
		turno:= turno + 1
		
		Mientras respuesta_1 = "S" y victoria_j = Falso Hacer
			Limpiar Pantalla
			
			Escribir "|| Turno ", turno
			Escribir "Capital: ", capital
			Escribir "Apuesta: ", apuesta
			turno_j := Verdadero
			
			Escribir "JUGADOR: "
			valorCarta := obtenerCarta(mazo, mano, turno_j, suma_m, blackjack)
			suma_j := suma_j + valorCarta
			
			Escribir ""
			Escribir "Tu suma : ", suma_j
			Escribir "Suma de la mesa : ", suma_m
			
			Si suma_j=21 Entonces
				victoria_j:=Verdadero
			SiNo					
				Si suma_j>21 Entonces
					respuesta_1:='N'
				SiNo
					Escribir ""
					Repetir
						Escribir "Desea sacar otra carta? S = Si , N = No"
						Leer respuesta_1
						respuesta_1:= mayusculas(respuesta_1)
					Hasta Que respuesta_1 = "S" o respuesta_1 = "N"
				FinSi
			FinSi
		FinMientras
		
		Si victoria_j = Verdadero Entonces
			
			Si blackjack = 2 Entonces
				Escribir "GANASTE!"
				Escribir "Ganaste el TRIPLE de tu apuesta: ", apuesta*3
				capital := capital + apuesta*3
				Escribir "Tu capital ahora: ", capital
			SiNo
				Escribir "GANASTE!"
				capital := capital + apuesta
				Escribir "Tu capital ahora: ", capital
			FinSi
			
		SiNo
			Si suma_j > 21 Entonces
				Escribir "PERDISTE!"
				capital:= capital - apuesta
				Escribir "Tu capital ahora: ", capital
			SiNo
				Escribir ""
				Escribir "MESA: "
				turno_j := Falso
				
				Mientras suma_m < 21 Hacer
					valorCarta := obtenerCarta(mazo, mano, turno_j, suma_m, blackjack)
					suma_m := suma_m + valorCarta
				FinMientras
				
				Escribir ""
				Escribir "Tu suma : ", suma_j
				Escribir "Suma de la mesa : ", suma_m
				Escribir ""
				
				Si suma_j > suma_m y suma_j < 21 o suma_m > 21 Entonces
					Escribir "GANASTE!"
					capital := capital + apuesta
					Escribir "Tu capital ahora: ", capital
				SiNo
					Escribir "PERDISTE!"
					capital:= capital - apuesta
					Escribir "Tu capital ahora: ", capital
				FinSi
			FinSi
		FinSi
		
		Escribir ""
		Escribir "********************************"
		Repetir
			Escribir "Deseas jugar otra vez? S = Si , N = No"
			Leer respuesta_2
			respuesta_2 := mayusculas(respuesta_2)
		Hasta Que respuesta_2 = "S" o respuesta_2 = "N"
		
	Mientras Que respuesta_2 = "S" y capital <> 0
		
	FinSi
FinProceso
