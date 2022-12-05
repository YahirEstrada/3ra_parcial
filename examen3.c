#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
 
typedef struct node{
    int valor;
    struct node *izq, *der;
}node;
 
typedef node *puntero;
 
void insertarArbol (puntero *raiz, int dato);
void imprimirArbol (puntero raiz);
puntero búsqueda (puntero raiz, int dato);
int altura (puntero raiz, int dato);
 

void arbolCompleto (puntero *raiz, int *dato);
 
int main (){
 
    puntero raiz;
    int dato, i=1, aux;
    raiz = NULL;

    insertarArbol (&raiz, 4);
    insertarArbol (&raiz, 1);
    insertarArbol (&raiz, 6);
    insertarArbol (&raiz, 9);
    insertarArbol (&raiz, 5);
 
    //Imprimimos el Arbol en orden de menor a mayor
    printf ("Digitos impresos de menor a mayor ");
    imprimirArbol (raiz);
    printf ("\nEl codigo realiza el arbol segun los numeros ingresados desde el main ");

int t=0;
    printf("\nIngrese el numero que desea buscar: ");
    scanf("%d",&t);


    aux = altura (raiz, t);
    printf ("\nEl nivel de altura del arbol es de : %d\n", aux);
 
system ("PAUSE");
return 0;
}
//Insertamos los numeros//
void insertarArbol (puntero *raiz, int dato){
    if (*raiz == NULL){
        *raiz = malloc(sizeof(node));
        (*raiz)->valor = dato;
        (*raiz)->izq = NULL;
        (*raiz)->der = NULL;
    }else{
        if (dato <= (*raiz)->valor){
            insertarArbol (&(*raiz)->izq, dato);
        }else{
            insertarArbol (&(*raiz)->der, dato);
        }
    }
}
//imprimimos arbol//
void imprimirArbol (puntero raiz){
    if (raiz != NULL){
        imprimirArbol (raiz->izq);
        printf ("%d, ", raiz->valor);
        imprimirArbol (raiz->der);
    }
}
//Busqueda//
puntero búsqueda (puntero raiz, int dato){
    if (raiz == NULL){
        return NULL;
    }else{
        if (dato == raiz->valor){
            return raiz;
        }else{
            if (dato < raiz->valor){
                return búsqueda (raiz->izq, dato);
            }else{
                return búsqueda (raiz->der, dato);
            }
        }
    }
} 
//Altura//
int altura (puntero raiz, int dato){
    int altura=1;
    puntero actual=raiz;
    while (actual!=NULL){
        if (dato == actual->valor){           
            return altura;
        }else{
            altura++;
            if (dato < actual->valor){               
                actual=actual->izq;
            }else{
                if (dato > actual->valor){               
                    actual=actual->der;
                }
            }
        }
    }
printf("\nNo existe ese valor en el arbol.\n");
return 0;
}
