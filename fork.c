#include <stdio.h>      
#include <stdlib.h>     
#include <unistd.h>     
#include <sys/wait.h>   

int main() {

    pid_t pid;  // Variable para almacenar el resultado de fork()
    int i, j;   // Variables contadoras

    
    for (i = 0; i < 3; i++) {           //crear 3 hijos

        pid = fork();  // Se crea un nuevo proceso

        
        if (pid < 0) {      // Si fork falla
            perror("Error en fork");
            exit(1);
        }

        if (pid == 0) {     //Proceso hijo

            
            for (j = 0; j < 5; j++) {           // Cada hijo ejecuta este ciclo 5 veces

                printf("Hijo[%d] --> pid = %d y ppid = %d  i = %d\n", i + 1, getpid(),getppid(),j); //Número del hijo, PID del hijo, PID del padre, contador i
            }

            exit(0); // El hijo termina aquí
        }
    }

    for (i = 0; i < 3; i++) {       // El padre espera que los 3 hijos terminen
        wait(NULL);         // Espera a que un hijo finalice
    }

    
    for (i = 0; i < 5; i++) {       // Una vez terminan los hijos, el padre ejecuta su rutina
        printf("Rutina del proceso padre valor de i: %d\n", i);
    }

    return 0;  // Fin del programa
}
