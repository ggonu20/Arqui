//#include <stdio.h>
//#include <math.h>

float promedio(int suma,int n)
{
    if(n>0)
    return suma/n;
    else
    return 0;
}
int main()
{
    int totalpersons, edad; 
    float peso, altura, imc;
    int cantidad_n=0, cantidad_j=0, cantidad_adu=0, cantidad_anc=0;
    int suma_n=0, suma_j=0, suma_adu=0, suma_anc=0;
    float promedio_n, promedio_j, promedio_adu, promedio_anc;
    
    printf("Ingrese  cantidad de personas: "); 
    scanf("%d", &totalpersons);  
    
    for(int i = 0; i < totalpersons; i++){ 
        printf("\t\tIngrese edad (en anios): ");
        scanf("%d", &edad);
        printf("\t\tIngrese peso (en kg): ");
        scanf("%f", &peso);
        printf("\t\tIngrese altura (en metro): ");
        scanf("%f", &altura);
        if(edad <= 12 && edad >= 0){
            cantidad_n++;
            suma_n=suma_n+peso;
        }
        if(edad >= 13 && edad <= 29){
            cantidad_j++;
            suma_j=suma_j+peso;
        }
        if(edad >= 30 && edad <= 64){
            cantidad_adu++;
            suma_adu=suma_adu+peso;
        }
        if(edad > 64){
            cantidad_anc++;
            suma_anc=suma_anc+peso;
        }
        imc = peso / pow (altura, 2); 

     
        if (imc < 22 && edad < 45) {  
            printf("\t\t*** IMC = %f >> Riesgo Bajo <<\n\n", imc); 
        }
        if (imc < 22 && edad >= 45){
            printf("\t\t*** IMC = %f >> Riesgo Medio <<\n\n", imc);
        }
        if (imc >= 22 && edad < 45){
            printf("\t\t*** IMC = %f >> Riesgo Medio <<\n\n", imc);
        }
        if (imc > 22 && edad > 45){ 
             printf("\t\t*** IMC = %f >> Riesgo Alto <<\n\n", imc);
        }
     }
     promedio_n=promedio(suma_n,cantidad_n);
     promedio_j=promedio(suma_j,cantidad_j);
     promedio_adu=promedio(suma_adu,cantidad_adu);
     promedio_anc=promedio(suma_anc,cantidad_anc);
     printf("__________________________________________________________\n");
     printf("Categoria      Cantidad      PesoProm      \n");
     printf("  Niños           %d          %f     \n",cantidad_n,promedio_n);
     printf(" Jovenes          %d          %f     \n",cantidad_j,promedio_j);
     printf(" Adultos          %d          %f     \n",cantidad_adu,promedio_adu);
     printf(" Ancianos         %d          %f     \n",cantidad_anc,promedio_anc);
     printf("__________________________________________________________\n");
 
    return 0;
}
