#include <stdio.h>
#include <stdlib.h>

//Declaración de funciones 
int  Registro_Num_Al();
void Print_cal(float cal_gen, int n_2);
void Print_cal_2(float cal_gen_2, int n_4);
void Registro_Prom_Al(int n);
void Verif_malloc(float *comprobacion); 
void Verif_realloc(float **comprobacion_1);
void Redefinicion_Arreglo();

//Declaración global
int Num_al=0;
float *calificaciones_Alumnos=NULL; 

int main ()
{
    //Declaración de variables locales 
  
    int opcion=0;
    
    //Comienzo del algoritmo 
    printf("#####Bienvenido al sistema de registro de calificaciones#####\n");
    printf("%cCu%cntos estudiantes se requieren registrar?\n",168, 160); //Uso de codigo ASCII
    Num_al=Registro_Num_Al();//Guardo los datos de la funcion en la variable Num_al
    Registro_Prom_Al(Num_al); //Registra las calificaciones de los alumnos uno por uno y obtiene el promedio 
    do 
    {
        do 
        {
            printf("%cDesea ingresar mas calificaciones de estudiantes?\n",168);
            printf("Presione  1, si desea agregar mas alumnos\n");
            printf("Presione  2, si desea salir del programa\n");
            scanf("%d", &opcion);
            if (opcion!=1 && opcion!=2)
            {
                printf("El valor ingresado no se encuentra en los valores permitidos\n");
                printf("Vuelva a ingresar su valor\n");
            }
        } while (opcion!=1 && opcion!=2);
        

        switch (opcion)//Seleccionador que permite preguntar al usuario si desa sseguir añadiendo calificaciones 
        {
            case 1: 
            Redefinicion_Arreglo(); //redimensiona el arreglo con arreglo
            break; 

            case 2: 
            printf("Terminando ejecucion del programa");
            break; 
        }

    }while (opcion!=2);
    free(calificaciones_Alumnos);//Se libera la memoria del arreglo 
    
    return 0; 
}



int Registro_Num_Al() //Se define la función para registrar el promedio de los estudiantes 
{
    //Variables locales 
    int Num_Registro= 0;
    //Algoritmo
    do 
    {
    scanf("%d", &Num_Registro); //Se registra el número de alumnos que se quiere ingresar
    if(Num_Registro<=0) //Mensaje de salida en caso que se hubiesen ingresado valores negativos o el valor cero
    {
    printf("No se aceptan numeros negativos o el numero cero\n");
    printf("Vuelva a ingresar el numero de alumnos que desea registrar\n");
    }

    }while (Num_Registro<=0); //Ciclo que evalua y permite reingresar los datos en caso que se hubise seleccionado números negativos o el número cero. 
    return Num_Registro;
}

void Verif_malloc(float *comprobacion) //se define funcion que comprueba que haya espacio en la memoría
{
    if(comprobacion==NULL)
    {
    printf("No hay suficiente espacio en la memoria\n");
    exit(1);
    }
}

void Print_cal(float cal_gen, int n_2) //Se define función para imprimir las calificaciones
{
    //Declaración de variables locales
    int k=0; //Indica a utilizar en el for 
    //Algoritmo
    printf("\n----Calificaciones registradas ----\n");
    for (k=0; k<n_2; k++) //Se imprime la calificación individual de los estudiantes y su promedio general 
    {   
        printf("\nLa calificacion del alumno %d: %.2f ", k+1, calificaciones_Alumnos[k]);
    }
    printf(" \nEl promedio general de los alumnos es: %.3f \n", cal_gen); //Se imprime la calificación general de todos los alumnos. 
}

void Print_cal_2(float cal_gen_2, int n_4) //Se define función para imprimir las calificaciones
{
    //Declaración de variables locales
    int k=0; //Indica a utilizar en el for 
    //Algoritmo
    printf("\n----Calificaciones registradas ----\n");
    for (k=0; k<n_4; k++) //Se imprime la calificación individual de los estudiantes y su promedio general 
    {   
        printf("\nLa calificacion del alumno %d: %.3f ", k+1, calificaciones_Alumnos[k]);
    }
    printf(" \nEl promedio general de los alumnos es: %.3f \n", cal_gen_2); //Se imprime la calificación general de todos los alumnos. 
}

void Registro_Prom_Al(int n)
{
    //Declaración de vriables locales 
    float suma_cal=0;
    float Promedio = 0;

    int i=0;// Se declara el indice a utilizar 

    //Algoritmo 
    calificaciones_Alumnos=(float*) malloc(n * sizeof(float));//Reservo memoria dinámica del arreglo calificaciones
    Verif_malloc(calificaciones_Alumnos);  //Verifica si se reservo la memoria con malloc

    for (i=0; i<n; i++)  //Se registran las calificiaciones de los alumnos 
    {   
        printf("\nRegistre la calificacion del alumno %d: ", i+1);  
        scanf("%f", &calificaciones_Alumnos[i]);
    }

    for (i=0; i<n; i++) //Se realiza la suma de las calificaciones de los alumnos 
    {   
        suma_cal += calificaciones_Alumnos[i]; 
    }
    
    Promedio=suma_cal/n; //Se obtiene el promedio de todos los estudiantes
        
    Print_cal(Promedio, n);
}


void Verif_realloc(float **comprobacion_1) //Se comprueba que haya espacio en la memoría
{
    if(*comprobacion_1==NULL)
    {
    printf("No hay suficiente espacio en la memoria\n");
    exit(1);
    }    
}

void Redefinicion_Arreglo() //Funcion para redimensionar el arreglo 
{
    //Declaracion de variables 
    int l=0; //Indice de for 
    float suma_cal_2=0;
    float Promedio_2=0;
    int nuevo_tam=0; 
    int tam_total=0;

    //Algoritmo
    printf("%cCu%cntos estudiantes desea agregar?\n",168, 160); 
    scanf("%d", &nuevo_tam);
    int viejo_tam = Num_al;
    tam_total= nuevo_tam+Num_al;
    float *temporal=realloc(calificaciones_Alumnos, tam_total * sizeof(float)); //Se redimeniona el arreglo con realloc  
    Verif_realloc(&temporal);//Se verifica que haya espacio en la memoria
    Num_al=tam_total; 
    calificaciones_Alumnos=temporal; 

    for (l = viejo_tam; l < tam_total; l++)  //Se registran las calificiaciones de los alumnos  agregados
    {   
        printf("\nRegistre la calificacion del alumno %d: ", l+1);  
        scanf("%f", &calificaciones_Alumnos[l]);
    }

    for (l=0; l< tam_total; l++) //Se realiza la suma de las calificaciones de los alumnos 
    {   
        suma_cal_2 += calificaciones_Alumnos[l]; 
    }
    
    
    Promedio_2=suma_cal_2/tam_total; //Se obtiene el promedio del total de los estudiantes

    Print_cal_2(Promedio_2, tam_total);
}
