#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "rlutil.h"

// Poner el archivo en la misma carpeta que el cpp
/// DECLARACIÓN/PROTOTIPO DE FUNCIONES
void cargarVector(int v[], int tam);///asigna valores a cada una de las posiciones del vector

void mostrarVector(int v[], int tam);/// muestra lo que contiene cada una de las posiciones del vector

void ponerCero(int v[], int tam);/// pone en 0 todas las posiciones del vector

int posicionNumeroEnVector(int v[],int tam, int numero);/// devuelve la posición que ocupa un número que se //envía como parámetro. Devuelve la primera posición que encuentra el número. Si no lo encuentra devuelve -1
int contarNumerosRepetidos(int v[], int numero, int tam);///cuenta la cantidad de veces que se repite un //número en el vector

int maximoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el máximo en el vector

int minimoVector(int v[], int tam);///devuelve  la posición (primera) que ocupa el mínimo en el vector


void cargarAleatorio(int v[], int tam, int limite);///asigna valores aleatorios a cada al vector

void ordenarVector(int v[], int tam );/// ordena de menor a mayor un vector

int sumarVector(int v[], int tam ); /// suma los valores contenidos en el vector

void copiarVector(int v[], int v2[],int tam ); ///copia el vector v en v2

bool compararVectores(int v[], int v2[],int tam );// compara los dos vectores que recibe. Si son iguales ///devuelve true, si no devuelve false

/// Desarrollo de funciones / Definiciones
int posicionNumeroEnVector(int v[],int tam, int numero){
    int i;
    for(i=0;i<tam;i++){
        if(v[i]==numero) return i;
        }
    return -1;
}
int minimoVector(int v[], int tam){
    int i, posMin=0;
    for(i=1;i<tam;i++){
        if(v[i]<v[posMin]) {
                posMin=i;
        }
    }
    return posMin;
}
void ordenarVector(int v[], int tam ){
    int i,j, posmin, aux;
    for(i=0;i<tam-1;i++){
        posmin=i;
        for(j=i+1;j<tam;j++){
            if(v[j]<v[posmin]) posmin=j;
        }
        aux=v[i];
        v[i]=v[posmin];
        v[posmin]=aux;
    }
}

int maximoVector(int v[], int tam){
    int i, posMax=0;
    for(i=1;i<tam;i++){
        if(v[i]>v[posMax]) {
                posMax=i;
        }
    }
    return posMax;
}

void cargarAleatorio(int v[], int tam, int limite){
  int i;
  srand(time(NULL));
  for( i=0; i<tam; i++ ){
        v[i]=(rand()%limite)+1;
  }
}

void mostrarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<v[i]<<"\t";
    }
}


int contarNumerosRepetidos(int v[], int numero, int tam){
    int i, cant=0;
    for(i=0;i<tam;i++){
        if(v[i]==numero) cant++;
        }
    return cant;
}


void ponerCero(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        v[i]=0;
    }
}


int sumarVector(int v[], int tam ){
    int i, suma=0;
    for(i=0;i<tam;i++){
        suma+=v[i];
    }
    return suma;
}


void copiarVector(int v[], int v2[],int tam ){
    int i;
    for(i=0;i<tam;i++){
        v2[i]=v[i];
    }
}

bool compararVectores(int v[], int v2[],int tam ){
   int i;
    for(i=0;i<tam;i++){
        if(v2[i]!=v[i]) return false;
    }
    return true;
}

void cargarVector(int v[], int tam){
    int i;
    for(i=0;i<tam;i++){
        cout<<"INGRESE UN NUMERO: ";
        cin>>v[i];

        while(v[i]<1||v[i]>6){
            cout<<"TIRADA INCORRECTA - INGRESE UN NUMERO DEL 1 AL 6: ";
            cin>>v[i];
        }
    }
}

bool encontrarEscalera(int v[], int tam){
    int i, c1,c2, c3, c4, c5, c6;

    c1=c2=c3=c4=c5=c6= 0;

    for(i=0; i<tam; i++)
    {
        switch (v[i]) {
    case 1:
        c1++;
        break;
    case 2:
        c2++;
        break;
    case 3:
        c3++;
        break;
    case 4:
        c4++;
        break;
    case 5:
        c5++;
        break;
    case 6:
        c6++;
        break;
    default:
        break;
        }
    }

    if(c1&&c2&&c3&&c4&&c5&&c6==1){
        return true;
    }
    else{
        return false;
    }

}

int encontrarRepetidos(int v[], int tam){
    int i, c1,c2, c3, c4, c5, c6;

    c1=c2=c3=c4=c5=c6= 0;

    for(i=0; i<tam; i++)
    {
        switch (v[i]) {
    case 1:
        c1++;
        if(c1==6){
            return 1;
        }
        break;
    case 2:
        c2++;
        if(c2==6){
            return 2;
        }
        break;
    case 3:
        c3++;
        if(c3==6){
            return 3;
        }
        break;
    case 4:
        c4++;
        if(c4==6){
            return 4;
        }
        break;
    case 5:
        c5++;
        if(c5==6){
            return 5;
        }
        break;
    default:
        return 0;
        break;
        }
    }
}

#endif // FUNCIONES_H_INCLUDED
