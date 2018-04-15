//Michal J
//Sieve Of Eratosthenes

#include <stdio.h>
#include <stdlib.h>
#include <math.h>


struct elementOfList{
    int number;
    struct elementOfList *next;
};
struct elementOfList *firstElement = NULL, *lastElement = NULL;
struct elementOfList *marked = NULL, *current = NULL, *prev = NULL;

void addElementToList(int number);
void showList();
int main()
{
    int n;
    int squareRoot, biggestDiscoveredPrime = 2;

    printf("Algorytm - Sito Erytostanesa\n\n");

    do{
        printf("Podaj gorna granice przedzialu, wieksza/rowna 2:\n");
        scanf("%d", &n);
    }while(n<2);

    //Tworzenie listy
    int i=2;
    for(i; i<=n; i++) addElementToList(i);

    //   showList();
    marked = firstElement;
    prev = firstElement;
    //Implementacja sita
    squareRoot = sqrt(n);
    printf("\nLiczby pierwsze w zakresie <2;%d> zapisano w pliku SE.txt\n\n", n);
    while(biggestDiscoveredPrime <= squareRoot)   //sprawdzamy tylko w ograniczonym zakresie
    {
        current=marked->next;
        while(current != NULL)
        {
            if(current->number % marked->number == 0){   //czyli znaleziono wielokrotność
                prev->next = current->next;
                free(current);
                current = prev->next;
            }
            else
            {
                prev = current;
                current = current->next;
            }
        }
        marked = marked->next;
        biggestDiscoveredPrime = marked->number;


    }

    //Zapis do pliku

    FILE* plik;
    plik = fopen("SE.txt", "w");
    current = firstElement;
    while(current != NULL)
    {
        fprintf(plik, "%d\n", current->number);
        current=current->next;
        free(firstElement);
        firstElement=current;
    }
    fclose(plik);

    return 0;
}


void addElementToList(int number){
    struct elementOfList *tran = malloc(sizeof(struct elementOfList));
    tran->number=number;
    tran->next=NULL;
    if(firstElement != NULL)
    {
        lastElement->next=tran;
        lastElement=tran;
    }
    else
    {
        firstElement = tran;
        lastElement = tran;
    }
}

void showList(){
    struct elementOfList *tran = firstElement;
    do{
        printf("%d ", tran->number);
        tran = tran->next;
    }
    while(tran != NULL);
}
