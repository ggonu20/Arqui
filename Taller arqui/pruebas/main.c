int esPalindromoRecursivo(char * cadena, int indiceInicio, int indiceFin) {

    // Si llegamos hasta aquí es porque ya sólo queda un carácter,
    // y por lo tanto no se puede comparar con otro
    // Esto también comprueba si la cadena tiene uno o menos caracteres
    if (indiceInicio >= indiceFin) return 1;

    // Sólo para explicar la comparación que se hace
    printf("Comparando %c con %c\n", cadena[indiceInicio], cadena[indiceFin]);

    // Si no, entonces comparamos el primer y último carácter
    if (cadena[indiceInicio] == cadena[indiceFin]) {
        // En caso de que sí, vamos por buen camino. Ahora cortamos la cadena desde inicio + 1 hasta fin - 1
        return esPalindromoRecursivo(cadena, indiceInicio + 1, indiceFin - 1);
    } else {
        // Si no eran iguales los carácteres al inicio y fin, entonces desde ahí se termina la recursión
        // y se regresa 0
        return 0;
    }
}

int esPalindromoConWhile(char * cadena) {

    int longitud = strlen(cadena);

    // Cadenas de 1 o menos son, por definición, recursivas
    if (longitud <= 1) return 1;

    // Comenzamos en el inicio y fin de la cadena
    int inicio = 0, fin = longitud - 1;


    // Mientras el primer y último carácter sean iguales
    while (cadena[inicio] == cadena[fin]){
        // Aquí sólo resta un carácter por comparar, eso indica que SÍ es palíndroma
        if (inicio >= fin) return 1;
        // Vamos acortando la cadena
        inicio++;
        fin--;
    }
    // Si termina el ciclo y no se rompió, entonces no es palíndroma
    return 0;
}

int main() {
    // Una cadena para probar, la cual la da el usuario
    char cadena[50];
    printf("Escribe una cadena (de menos de 50 caracteres) y te voy a decir si es palindroma o no\n\t");
    scanf("%s", &cadena);

    // La recursiva necesita saber el inicio y fin al inicio
    int longitudDeCadena = strlen(cadena);
    int resultadoRecursivo = esPalindromoRecursivo(cadena, 0, longitudDeCadena - 1);
    if (resultadoRecursivo) {
        printf("De manera recursiva, '%s' es palindroma\n", cadena);
    } else {
        printf("De manera recursiva, '%s' NO es palindroma\n", cadena);
    }

    int resultadoConWhile = esPalindromoConWhile(cadena);
    if (resultadoConWhile) {
        printf("Usando while, '%s' es palindroma\n", cadena);
    } else {
        printf("Usando while, '%s' NO es palindroma\n", cadena);
    }
}
