# PilasDinamicas_Excep

UEA: Estructuras de Datos Lineales.

Notación infija es la notación "tradicional":
b x c
Se llama infija debido a que el operador se encuentra "entre" los dos operandos.

a + b x c

Cada operador tiene un nivel de precedencia.
() Mayor precedencia
Potencia
Multiplicación/División
Suma y Resta


Se puede hacer explícita la precedencia a través del úso de paréntesis:
De la expresión original se van asociando:
a + b x c + d

a + (b x c) + d
(a+ (b x c) )+d

((a+ (b x c) )+d )

Notación posfija
Los operadores van después de los operandos
a + b x c (Notación infija)
a b c x + (Notación posfija)

Algoritmo para convertir de notación infija a posfija

Partimos de un cojunto de elementos o tokens.
Tenemos tokens de tipo operador: 
+,-, x, / ( )
Tenemos tokens de tipo operandos:
Letras o símbolos de un sólo caracter
a,b,c, etc.

Para convertir de notación infija a posfija usando una pila. Hay que seguir los siguientes pasos:

1) Crear una pila vacía llamada pilaoperadores. Asimismo crear una variable de tipo string para guardar la expresión de salida (notación posfija)

2) Procesar los tokens de izquierda a derecha y tomar las siguientes decisiones:
a) Si el token es un operando, lo agregamos al string de la expresión de salida.
b) Si el token es un paréntesis izquierdo, hacer un push del paréntesis en la pilaoperadores.
c) Si el token es un paréntesis derecho, hacer pop de la pilaoperadores hasta encontrar el paréntesis izquierdo. Agregar cada operador al final del string de salida.
d) Si el token es un operador, se realiza un push en la pilaoperadores. Sin embargo, en este paso es necesario hacer pop a todos los operadores que ya están en la pilaoperadores que tienen igual o mayor precedencia y agregarlos al final del string de salida.
e) Una vez que se haya procesado totalmente la expresión infija, hay que verificar si aún hay elementos en la pila de operadores, y si es así hay que agregarlos al string de salida.

Ejemplo: 

A la entrada tengo la siguiente expresión:
a x b + c x d

I)

//Pila vacía
pilaoperadores =[]
//Variabledesalida
salida =""
II)
Agregamos el operando a a la variable de salida
salida ="a"
pilaoperadores =[]
III)
salida ="a"
pilaoperadores =[*]
IV)
salida= "a b"
pilaoperadores =[*]
V)
hago pop a la pilaoperadores.
salida= "a b *"
hago push a la pilaoperadores con +
pilaoperadores =[+]
VI)
salida = "a b * c"
pilaoperadores =[+]
VII)
salida= "a b x c"
pilaoperadores =[* +]

VII)
salida = "a b * c d"

VII) 
pilaoperadores =[* +]
pop pilaoperadores
pilaoperadores =[+]

salida="a b * c d *"
pop pilaoperadores
pilaoperadores =[]
salida="a b * c d * +"
