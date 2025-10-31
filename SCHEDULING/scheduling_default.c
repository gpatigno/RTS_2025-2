#define _GNU_SOURCE
#include <sched.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

/* Hilo simple que imprime en qué CPU está corriendo */
void * task(void *unused) {
    printf("\nThis thread is running on CPU %d\n\n", sched_getcpu());
    pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
    pthread_t tid;
    pthread_attr_t attr;

    int scope, policy, detachstate, inheritsched;
    struct sched_param schedparam;
    size_t stacksize;

    /* Inicializar atributos con los valores por defecto */
    pthread_attr_init(&attr);

    /* Obtener y mostrar scope */
    if (pthread_attr_getscope(&attr, &scope) == 0) {
        if (scope == PTHREAD_SCOPE_SYSTEM)
            printf("Scope           : PTHREAD_SCOPE_SYSTEM\n");
        else if (scope == PTHREAD_SCOPE_PROCESS)
            printf("Scope           : PTHREAD_SCOPE_PROCESS\n");
        else
            printf("Scope           : Unknown (%d)\n", scope);
    }

    /* Obtener y mostrar política de planificación */
    if (pthread_attr_getschedpolicy(&attr, &policy) == 0) {
        printf("Policy          : ");
        switch (policy) {
            case SCHED_OTHER:  printf("SCHED_OTHER\n"); break;
            case SCHED_FIFO:   printf("SCHED_FIFO\n"); break;
            case SCHED_RR:     printf("SCHED_RR\n"); break;
            default:           printf("Unknown (%d)\n", policy); break;
        }
    }

    /* Obtener y mostrar prioridad */
    if (pthread_attr_getschedparam(&attr, &schedparam) == 0) {
        printf("Priority        : %d\n", schedparam.sched_priority);
    }

    /* Obtener y mostrar detach state */
    if (pthread_attr_getdetachstate(&attr, &detachstate) == 0) {
        printf("Detach state    : %s\n", 
               (detachstate == PTHREAD_CREATE_JOINABLE) ? "JOINABLE" :
               (detachstate == PTHREAD_CREATE_DETACHED) ? "DETACHED" :
               "UNKNOWN");
    }

    /* Obtener y mostrar inherit scheduler */
    if (pthread_attr_getinheritsched(&attr, &inheritsched) == 0) {
        printf("Inherit sched   : %s\n",
               (inheritsched == PTHREAD_INHERIT_SCHED) ? "INHERIT_SCHED" :
               (inheritsched == PTHREAD_EXPLICIT_SCHED) ? "EXPLICIT_SCHED" :
               "UNKNOWN");
    }

    /* Obtener y mostrar tamaño del stack */
    if (pthread_attr_getstacksize(&attr, &stacksize) == 0) {
        printf("Stack size      : %zu bytes\n", stacksize);
    }

    /* Crear hilo */
    if (pthread_create(&tid, &attr, task, NULL) != 0) {
        perror("pthread_create");
        exit(EXIT_FAILURE);
    }

    /* Esperar al hilo */
    pthread_join(tid, NULL);

    /* Liberar atributos */
    pthread_attr_destroy(&attr);
    return 0;
}
