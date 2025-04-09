#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5
struct compu
{
    int velocidad;        // Velocidad de procesamiento en GHz (valor entre 1 y 3)
    int anio;             // Año de fabricación (valor entre 2015 y 2024)
    int cantidad_nucleos; // Cantidad de núcleos (valor entre 1 y 8)
    char *tipo_cpu;       // Tipo de procesador (apuntador a cadena de caracteres)
};
void listarPCs(struct compu pcs[], int cantidad);
void mostrarMasVieja(struct compu pcs[], int cantidad);
void mostrarMasVeloz(struct compu pcs[], int cantidad);
int main()
{
    int numero;
    srand(time(NULL));
    struct compu pc[N];
    char tipos[6][10] = {"Intel", "AMD", "Celeron", "Athlon", "Core", "Pentium"};
    for (int i = 0; i < N; i++)
    {
        pc[i].velocidad = 1 + rand() % 3; // inicio + rand() % (fin - inicio + 1)
        pc[i].anio = 2015 + rand() % 10;
        pc[i].cantidad_nucleos = 1 + rand() % 8;
        numero = rand() % 6;
        pc[i].tipo_cpu = tipos[numero];
    }
    listarPCs(pc, N);
    mostrarMasVieja(pc, N);
    mostrarMasVeloz(pc, N);
    return 0;
}
void listarPCs(struct compu pcs[], int cantidad)
{ // void listarPCs(struct compu pcs[], int N){
    for (int i = 0; i < cantidad; i++)
    {
        printf("\n--- PC %d ---", i + 1);
        printf("\nAnio de fabricacion: %d", pcs[i].anio);
        printf("\nVelocidad de procesamiento en GHz: %d", pcs[i].velocidad);
        printf("\nCantidad de nucleos: %d", pcs[i].cantidad_nucleos);
        printf("\nTipo CPU: %s\n", pcs[i].tipo_cpu);
    }
}
void mostrarMasVieja(struct compu pcs[], int cantidad)
{
    struct compu aux;
    aux.anio = 2025;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].anio < aux.anio)
        {
            aux = pcs[i];
        }
    }
    printf("\n--- PC mas antigua ---");
    printf("\nAnio de fabricacion: %d", aux.anio);
    printf("\nVelocidad de procesamiento en GHz: %d", aux.velocidad);
    printf("\nCantidad de nucleos: %d", aux.cantidad_nucleos);
    printf("\nTipo CPU: %s\n", aux.tipo_cpu);
}
void mostrarMasVeloz(struct compu pcs[], int cantidad){
    struct compu aux;
    aux.velocidad = 0;
    for (int i = 0; i < cantidad; i++)
    {
        if (pcs[i].velocidad > aux.velocidad)
        {
            aux = pcs[i];
        }
    }
    printf("\n--- PC mas veloz ---");
    printf("\nAnio de fabricacion: %d", aux.anio);
    printf("\nVelocidad de procesamiento en GHz: %d", aux.velocidad);
    printf("\nCantidad de nucleos: %d", aux.cantidad_nucleos);
    printf("\nTipo CPU: %s\n", aux.tipo_cpu);
}