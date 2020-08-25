---Instructivo para el uso del programa de Serpientes y Escaleras con excepciones----Sebastian Rojas A01637557
-Instrucciones para el uso de mi programa de snakes and ladders. La codificiación esta organizada en 5 clases y un archivo snakes.cpp donde en su método main
se ejecuta un simple codigo que manda a llamar a un objeto de tipo myGame donde se encuentra toda la lógica del juego. 
-Las clases usadas en el código son MyGame, Player, Board, Dado y Case. Decidí que estas fueran las clases por la forma en que se organiza mi juego. 
-Al crear un objeto myGame este solo posee un atributo de tipo turno el cual se va actualizando conforme pasan los turnos dentro de su método start. 
-En el método start se incluyen el resto de las clases. Se generan 2 objetos jugadores para iniciar el juego, luego se crea un objeto de tipo tablero el cual tiene un arreglo 
de objetos tipo casilla. Este arreglo en su constructor se genera con casillas normales y aleatoriamente pone 6 casillas especiales, 3 escaleras y 3 serpientes. 
-Con lo anterior predefinido empieza el juego pidiendole al usuario que ingrese la tecla 'c' para continuar y si desea terminar el juego antes que presione 'e'. Se definio un numero máximo de 
turnos como 25 pero es posible modificarlo con el metodo setTurnMAX(int) perteneciente a myGame. 
-El jugador que llega a la casilla 30 antes gana el juego. Igualmente el jugador 1 siempre inicia primero el juego y además los inputs de los jugadores se verifican para que si ingresan algo que no sea 'c' o 'e' se repita la instrucción y no se consuma un turno. 
-Los archivos necesarios para correr el programa son: serpientesEscaleras, MyGame.cpp, MyGame.h, Player.cpp, Player.h, Board.cpp, Board.h, Case.cpp, Case.h, dado.cpp, dado.h, snakes.cpp.
-En el caso de compilar dentro de Clion se necesita un cmake List donde se define que archivos se usaran para compilar. 

----Update exceptions-----
El programa evolucionó en algunos detalles desde la última entrega haciendo que el usuario no termine el programa con un error
y limitandolo a poner valores razonables en la configuración del juego. Se validan todas las entradas del usuario con excepciones
generadas por una clase llamada MyException e implementando dos de sus métodos en el método start() de MyGame donde se encuentra
toda la lógica del juego. Primero tenemos el método que valida las entradas al configurar las dimensiones del tablero, su número de 
casillas especiales y sus bonificaciones o penalizaciones por caer en ellas. En esta caso, al ingresar un dato no válido el programa se
termina. La otra excepción presente es dentro del modo de juego manual donde se valida que solo pueda el usuario ingresar el input
"c" para pasar al siguiente turno o el input "e" para terminar el juego. A diferencia del primer método este da 5 intentos de 
equivocarse y no consume ningún turno solo le pide que ingrese un input válido al usuario. 
-------------------------------------------------------------------------------------------