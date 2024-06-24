#ifndef JUEGO_H_INCLUDED
#define JUEGO_H_INCLUDED
#include "funciones.h"
#include "rlutil.h"


int juegoSolitarioAleatorio(string nombre){
    const int dados = 6;
    int puntuacion, i, a, ronda, vectorDados[dados], suma, tiradas, sumaMayor, rondaMayorPunt, seisRepetidos, repetidos, sumaRepetidos, sexteto1, sexteto2, sexteto3, sexteto4, sexteto5;
    bool escalera;

    puntuacion = 0;
    ronda = 0;

    while(puntuacion < 100){
        bool primerTirada = true;
        tiradas = 0;
        ronda ++;

        cout << "USUARIO: " << nombre << " | " << "RONDA N°: " << ronda << " | " << " PUNTAJE TOTAL: " << puntuacion << endl;
        cout << "***********************************************" << endl;

        for(i=1;i<=3;i++){
            cargarAleatorio(vectorDados, dados, 6);
            tiradas ++;

            cout << endl;
            cout << "LANZAMIENTO N° " << tiradas << endl;
            cout << "***********************************************" << endl;
            cout << endl;

            for(a=0;a<dados;a++){
                cout << "{ "<< vectorDados[a] << " }" << "\t";
            }

            escalera = encontrarEscalera(vectorDados, dados);
            suma = sumarVector(vectorDados, dados);
            sexteto1 = contarNumerosRepetidos(vectorDados, 1, dados);
            cout<< endl;

            if(escalera){
                cout << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                puntuacion = 100;
                suma = 0;
                sumaMayor = 0;
                i=3;
            }

            if(sexteto1==6){
                cout << endl;
                repetidos = 1;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 1 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 1*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto2 = contarNumerosRepetidos(vectorDados, 2, dados);

            if(sexteto2==6){
                cout << endl;
                repetidos = 2;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 2 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 2*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto3 = contarNumerosRepetidos(vectorDados, 3, dados);

            if(sexteto3==6){
                cout << endl;
                repetidos = 3;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 3 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 3*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto4 = contarNumerosRepetidos(vectorDados, 4, dados);

            if(sexteto4==6){
                cout << endl;
                repetidos = 4;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 4 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 4*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto5 = contarNumerosRepetidos(vectorDados, 5, dados);

            if(sexteto5==6){
                cout << endl;
                repetidos = 5;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            seisRepetidos = contarNumerosRepetidos(vectorDados, 6, dados);
            cout << endl;

            if(seisRepetidos==6){
                cout << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "¡QUE MALA SUERTE!  SALIO SEXTETO DE 6 SU PUNTAJE PASA A RESTABLECERSE A 0" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                puntuacion = 0;
                suma=0;
                sumaMayor = 0;
            }

            cout << "LA SUMA DEL LANZAMIENTO N° " << tiradas << " ES " << suma << endl;
            cout << endl;
            system("pause");
            cout << endl;

            if(primerTirada==true||suma>sumaMayor){
                sumaMayor = suma;
                rondaMayorPunt = tiradas;
                primerTirada=false;
            }
        }
        puntuacion += sumaMayor;
        cout << endl;
        cout << "===========================================================================================" << endl;
        cout << "EL LANZAMIENTO MAS ALTO DE LA RONDA " << ronda << " FUE DE " << sumaMayor << " PUNTOS Y SE REGISTRO EN EL LANZAMIENTO N° " << rondaMayorPunt << endl;
        cout << "SU PUNTUACION ACTUAL ES DE: " << puntuacion << endl;
        cout << "===========================================================================================" << endl;
        system("pause");
        system("cls");
    }
    cout<<endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    cout << "FELICIDADES GANASTE CON " << puntuacion <<" PUNTOS" << endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
    system("pause");
    return puntuacion;
}

int juegoSolitarioSimulado(string nombre){

    const int dados = 6;
    int puntuacion , i, a, ronda , vectorDados[dados], suma, tiradas, sumaMayor, rondaMayorPunt, seisRepetidos, repetidos, sumaRepetidos, sexteto1, sexteto2, sexteto3, sexteto4, sexteto5;
    bool escalera;

    puntuacion = 0;
    ronda = 0;

    while(puntuacion < 100){
        bool primerTirada = true;
        tiradas = 0;
        ronda ++;

        cout << "USUARIO: " << nombre << " | " << "RONDA N°: " << ronda << " | " << " PUNTAJE TOTAL: " << puntuacion << endl;
        cout << "***********************************************" << endl;

        for(i=1;i<=3;i++){
            cargarVector(vectorDados, dados);
            tiradas ++;

            cout << endl;
            cout << "LANZAMIENTO N° " << tiradas << endl;
            cout << "********************************************" << endl;
            cout << endl;

            for(a=0;a<dados;a++){
                cout << "{ "<< vectorDados[a] << " }" << "\t";
            }

            escalera = encontrarEscalera(vectorDados, dados);
            suma = sumarVector(vectorDados, dados);
            sexteto1 = contarNumerosRepetidos(vectorDados, 1, dados);
            cout<< endl;

            if(escalera){
                cout << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                puntuacion = 100;
                suma = 0;
                sumaMayor = 0;
                i = 3;
            }

            if(sexteto1==6){
                cout << endl;
                repetidos = 1;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto2 = contarNumerosRepetidos(vectorDados, 2, dados);

            if(sexteto2==6){
                cout << endl;
                repetidos = 2;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto3 = contarNumerosRepetidos(vectorDados, 3, dados);

            if(sexteto3==6){
                cout << endl;
                repetidos = 3;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto4 = contarNumerosRepetidos(vectorDados, 4, dados);

            if(sexteto4==6){
                cout << endl;
                repetidos = 4;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto5 = contarNumerosRepetidos(vectorDados, 5, dados);

            if(sexteto5==6){
                cout << endl;
                repetidos = 5;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            seisRepetidos = contarNumerosRepetidos(vectorDados, 6, dados);
            cout << endl;

            if(seisRepetidos==6){
                cout << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "¡QUE MALA SUERTE!  SALIO SEXTETO DE 6 SU PUNTAJE PASA A RESTABLECERSE A 0" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                puntuacion = 0;
                suma=0;
                sumaMayor = 0;
            }

            cout << "LA SUMA DEL LANZAMIENTO N° " << tiradas << " ES " << suma << endl;
            cout << endl;
            system("pause");
            cout << endl;

            if(primerTirada==true||suma>sumaMayor){
                sumaMayor = suma;
                rondaMayorPunt = tiradas;
                primerTirada=false;
            }
        }
        puntuacion += sumaMayor;
        cout << endl;
        cout << "===========================================================================================" << endl;
        cout << "EL LANZAMIENTO MAS ALTO DE LA RONDA " << ronda << " FUE DE "<< sumaMayor << " PUNTOS Y SE REGISTRO EN EL LANZAMIENTO N° " << rondaMayorPunt << endl;
        cout << "SU PUNTUACION ACTUAL ES DE: " << puntuacion << endl;
        cout << "===========================================================================================" << endl;
        system("pause");
        system("cls");
    }
    cout<<endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<< endl;
    cout << "FELICIDADES GANASTE CON " << puntuacion << " PUNTOS" << endl;
    cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°"<< endl;
    system("pause");
    return puntuacion;
}

string juegoDosJugadoresAleatorio(string nombre1, string nombre2){
    const int dados=6;
    int vectorDados[dados];
    int puntuacion1, puntuacion2, ronda1, ronda2,suma, sumaMayor, tiradas, rondaMayorPunt, escalera;
    int sexteto1,sexteto2,sexteto3,sexteto4,sexteto5,seisRepetidos,repetidos,sumaRepetidos;

    ///pedir nombres de los 2 jugadores
    puntuacion1=0;
    puntuacion2=0;
    ronda1=0;
    ronda2=0;

    /// entra al while y deberia salir cuando una de las 2 puntuaciones llega a 100
    while(puntuacion1<100 && puntuacion2<100){
        system("cls");
        bool primerTiradaUno = true;
        tiradas = 0;
        ronda1 ++;
        sumaMayor = 0; // Inicializar sumaMayor al inicio de cada ronda

        /// inicia la partida el primer jugador con sus respectivas variables
        cout << " ============================" << endl;
        cout << "|" << " TURNO DEL JUGADOR NUMERO 1 " << "|" <<endl;
        cout << " ============================" << endl;
        cout << endl;
        cout << "USUARIO: " << nombre1 << " | " << "RONDA N°: " << ronda1 << " | " << " PUNTAJE TOTAL: " << puntuacion1 << endl;
        cout << "------------------------------------------------" << endl;

        ///cargamos el vector y sumamos la puntuacion
        for(int i=1;i<=3;i++){
            cargarAleatorio(vectorDados, dados, 6);
            suma = sumarVector(vectorDados, dados);
            tiradas ++;

            cout << endl;
            cout << "************************************************" << endl;
            cout << "LANZAMIENTO N° " << tiradas << endl;
            cout << endl;

            /// mostramos el vector de la jugada del primer jugador
            for(int a=0;a<dados;a++){
                cout <<"{ "<< vectorDados[a] <<" }"<< "\t";
            }

            /// ahora se empieza a ver si hay escalera o algun sexteto de numeros en el caso de encontrarse cada uno tiene su propio mensaje
            escalera = encontrarEscalera(vectorDados, dados);
            cout<< endl;
            if(escalera){
                cout << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                puntuacion1 = 100;
                suma = 0;
                sumaMayor = 0;
                i=3;
                break;
            }

            sexteto1 = contarNumerosRepetidos(vectorDados, 1, dados);

            if(sexteto1==6){
                cout << endl;
                repetidos = 1;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 1 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 1*10 = " << sumaRepetidos << "PUNTOS "<< endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto2 = contarNumerosRepetidos(vectorDados, 2, dados);

            if(sexteto2==6){
                cout << endl;
                repetidos = 2;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 2 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 2*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto3 = contarNumerosRepetidos(vectorDados, 3, dados);

            if(sexteto3==6){
                cout << endl;
                repetidos = 3;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 3 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 3*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto4 = contarNumerosRepetidos(vectorDados, 4, dados);

            if(sexteto4==6){
                cout << endl;
                repetidos = 4;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 4 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 4*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto5 = contarNumerosRepetidos(vectorDados, 5, dados);

            if(sexteto5==6){
                cout << endl;
                repetidos = 5;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            seisRepetidos = contarNumerosRepetidos(vectorDados, 6, dados);
            cout << endl;

            if(seisRepetidos==6){
                cout << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "¡QUE MALA SUERTE!  SALIO SEXTETO DE 6 SU PUNTAJE PASA A RESTABLECERSE A 0" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                puntuacion1 = 0;
                suma=0;
                sumaMayor = 0;
            }

            ///se muestra la puntuacion de la tirada
            cout << "LA SUMA DEL LANZAMIENTO N° " << tiradas << " ES " << suma << endl;
            cout << "************************************************" << endl;
            cout << endl;
            system("pause");
            cout << endl;

            /// comprobamos si es la primer tirada o comparamos para sacar la mayor de las 3
            if(primerTiradaUno==true||suma>sumaMayor){
                sumaMayor = suma;
                rondaMayorPunt = tiradas;
                primerTiradaUno=false;
                }


        }

        /// asignamos la mayor tirada a la puntuacion del primer jugador y mostramos por pantalla
        puntuacion1 += sumaMayor;
        cout << endl;
        cout << "===========================================================================================" << endl;
        cout << "LA TIRADA MAS ALTA DE LA RONDA " << ronda1 << " FUE DE "<< sumaMayor << " PUNTOS Y SE REGISTRO EN EL LANZAMIENTO N° " << rondaMayorPunt << endl;
        cout << "LA PUNTUACION DEL JUGADOR 1 "<< nombre1 << " ES DE: " << puntuacion1 <<endl;
        cout << "===========================================================================================" << endl;
        system("pause");
        system("cls");
        ///se indica el cambio de turno y se emiezan a usar las variables del segundo jugador excepto las de suma y sumaMayor al igual que el vector de dados que se pisan cuando le toca al jugador 2
        cout << "¡CAMBIO DE TURNO!" << endl;
        system("pause");

        bool primerTiradaDos = true;
        tiradas = 0;
        ronda2++;
        sumaMayor = 0; // Inicializar sumaMayor al inicio de cada

        /// incia el segundo jugador con sus variables
        cout << " ============================" << endl;
        cout << "|" << " TURNO DEL JUGADOR NUMERO 2 " << "|" << endl;
        cout << " ============================" << endl;
        cout << endl;
        cout << "USUARIO: " << nombre2 << " | " << "RONDA N°: " << ronda2 << " | " << " PUNTAJE TOTAL: " << puntuacion2 << endl;
        cout << "------------------------------------------------" << endl;

        ///se carga y suma el vector
        for(int e=1;e<=3;e++){
            cargarAleatorio(vectorDados, dados, 6);
            suma = sumarVector(vectorDados, dados);
            tiradas ++;

            cout << endl;
            cout << "************************************************" << endl;
            cout << "LANZAMIENTO N° " << tiradas << endl;
            cout << endl;
            ///se muestra el vector
            for(int a=0;a<dados;a++){
                cout << "{ " << vectorDados[a] << " }"<< "\t";
            }

            escalera = encontrarEscalera(vectorDados, dados);
            cout<< endl;

            ///se empieza a analizar si hay escalera o sexteto
            if(escalera){
                cout << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                puntuacion2 = 100;
                suma = 0;
                sumaMayor = 0;
                e=3;
            }

            sexteto1 = contarNumerosRepetidos(vectorDados, 1, dados);

            if(sexteto1==6){
                cout << endl;
                repetidos = 1;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 1 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 1*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto2 = contarNumerosRepetidos(vectorDados, 2, dados);

            if(sexteto2==6){
                cout << endl;
                repetidos = 2;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 2 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 2*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" <<endl;
            }

            sexteto3 = contarNumerosRepetidos(vectorDados, 3, dados);

            if(sexteto3==6){
                cout << endl;
                repetidos = 3;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 3 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 3*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" <<endl;
            }

            sexteto4 = contarNumerosRepetidos(vectorDados, 4, dados);

            if(sexteto4==6){
                cout << endl;
                repetidos = 4;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 4 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 4*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto5 = contarNumerosRepetidos(vectorDados, 5, dados);

            if(sexteto5==6){
                cout << endl;
                repetidos = 5;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            seisRepetidos = contarNumerosRepetidos(vectorDados, 6, dados);
            cout << endl;

            if(seisRepetidos==6){
                cout << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "¡QUE MALA SUERTE!  SALIO SEXTETO DE 6 SU PUNTAJE PASA A RESTABLECERSE A 0" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                puntuacion2 = 0;
                suma=0;
                sumaMayor = 0;
            }

            cout << "LA SUMA DEL LANZAMIENTO N° " << tiradas << " ES " << suma << endl;
            cout << "************************************************" << endl;
            cout << endl;
            system("pause");
            cout << endl;

            ///se verifica si es la primera tirada del segundo jugador o se compara para saber la maxima de las 3
            if(primerTiradaDos==true||suma>sumaMayor){
                sumaMayor = suma;
                rondaMayorPunt = tiradas;
                primerTiradaDos=false;
                }
        }
        ///se asigna la maxima puntuacion a la puntuacion del jugador 2 y se muestra en pantalla
        puntuacion2 += sumaMayor;
        cout << endl;
        cout << "===========================================================================================" << endl;
        cout << "LA TIRADA MAS ALTA DE LA RONDA " << ronda2 << " FUE DE "<< sumaMayor << " PUNTOS Y SE REGISTRO EN EL LANZAMIENTO N° " << rondaMayorPunt << endl;
        cout << "LA PUNTUACION DEL JUGADOR 2 "<< nombre2 << " ES DE: " << puntuacion2 << endl;
        cout << "===========================================================================================" << endl;
        system("pause");
        system("cls");
        ///una vez que pasan las 2 rondas de los jugadores se compara cual es la mayor momentaneamente para mostrar quien es el que va ganando por ahora
        if(puntuacion1>puntuacion2){
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "Por ahora va ganando el jugeador numero 1: " << nombre1 << endl;
                cout << "Con una puntuacion de: " << puntuacion1 << endl;
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                system("pause");
               }
        else{
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "Por ahora va ganando el jugeador numero 2: "<< nombre2 << endl;
                cout << "Con una puntuacion de: "<< puntuacion2 << endl;
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                system("pause");
            }
        }
    ///cuando se encuentra un jugador que supero los 100 sale del while y comparamos cual es mayor para ver quien es el ganador y asi poder retornar esa puntuacion para luego guardarla en el historial
    if(puntuacion1>puntuacion2){
        cout<<endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "FELICIDADES GANO " << nombre1 << " CON UNA PUNTUACION DE " << puntuacion1 << " PUNTOS Y EN " << ronda1 << " RONDAS" << endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        system("pause");
        return nombre1;
    }
    else if(puntuacion1==puntuacion2){
        cout<<endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "OCURRIO UN EMPATE ENTRE ENTRE LOS DOS JUGADORES CON UNA PUNTUACION DE: " << puntuacion1 << endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        system("pause");
        return nombre1;
    }
    else{
        cout<<endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "FELICIDADES GANO " << nombre2 << " CON UNA PUNTUACION DE " << puntuacion2 << " PUNTOS Y EN " << ronda2 << " RONDAS" << endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        system("pause");
        return nombre2;
    }
}

string juegoDosJugadoresSimulado(string nombre1, string nombre2){
    const int dados=6;
    int vectorDados[dados];
    int puntuacion1, puntuacion2, ronda1, ronda2,suma, sumaMayor, tiradas, rondaMayorPunt, escalera;
    int sexteto1,sexteto2,sexteto3,sexteto4,sexteto5,seisRepetidos,repetidos,sumaRepetidos;

    ///pedir nombres de los 2 jugadores
    puntuacion1=0;
    puntuacion2=0;
    ronda1=0;
    ronda2=0;

    /// entra al while y deberia salir cuando una de las 2 puntuaciones llega a 100
    while(puntuacion1<100 && puntuacion2<100){
        system("cls");
        bool primerTiradaUno = true;
        tiradas = 0;
        ronda1 ++;
        sumaMayor = 0; // Inicializar sumaMayor al inicio de cada ronda

        /// inicia la partida el primer jugador con sus respectivas variables
        cout << " ============================" << endl;
        cout << "|" << " TURNO DEL JUGADOR NUMERO 1 " << "|" <<endl;
        cout << " ============================" << endl;
        cout << endl;
        cout << "USUARIO: " << nombre1 << " | " << "RONDA N°: " << ronda1 << " | " << " PUNTAJE TOTAL: " << puntuacion1 << endl;
        cout << "------------------------------------------------" << endl;

        ///cargamos el vector y sumamos la puntuacion
        for(int i=1;i<=3;i++){
            cargarVector(vectorDados, dados);
            suma = sumarVector(vectorDados, dados);
            tiradas ++;

            cout << endl;
            cout << "************************************************" << endl;
            cout << "LANZAMIENTO N° " << tiradas << endl;
            cout << endl;

            /// mostramos el vector de la jugada del primer jugador
            for(int a=0;a<dados;a++){
                cout <<"{ "<< vectorDados[a] <<" }"<< "\t";
            }

            /// ahora se empieza a ver si hay escalera o algun sexteto de numeros en el caso de encontrarse cada uno tiene su propio mensaje
            escalera = encontrarEscalera(vectorDados, dados);
            cout<< endl;
            if(escalera){
                cout << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                puntuacion1 = 100;
                suma = 0;
                sumaMayor = 0;
                i=3;
            }

            sexteto1 = contarNumerosRepetidos(vectorDados, 1, dados);

            if(sexteto1==6){
                cout << endl;
                repetidos = 1;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 1 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 1*10 = " << sumaRepetidos << "PUNTOS "<< endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto2 = contarNumerosRepetidos(vectorDados, 2, dados);

            if(sexteto2==6){
                cout << endl;
                repetidos = 2;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 2 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 2*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto3 = contarNumerosRepetidos(vectorDados, 3, dados);

            if(sexteto3==6){
                cout << endl;
                repetidos = 3;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 3 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 3*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto4 = contarNumerosRepetidos(vectorDados, 4, dados);

            if(sexteto4==6){
                cout << endl;
                repetidos = 4;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 4 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 4*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto5 = contarNumerosRepetidos(vectorDados, 5, dados);

            if(sexteto5==6){
                cout << endl;
                repetidos = 5;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            seisRepetidos = contarNumerosRepetidos(vectorDados, 6, dados);
            cout << endl;

            if(seisRepetidos==6){
                cout << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "¡QUE MALA SUERTE!  SALIO SEXTETO DE 6 SU PUNTAJE PASA A RESTABLECERSE A 0" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                puntuacion1 = 0;
                suma=0;
                sumaMayor = 0;
            }

            ///se muestra la puntuacion de la tirada
            cout << "LA SUMA DEL LANZAMIENTO N° " << tiradas << " ES " << suma << endl;
            cout << "************************************************" << endl;
            cout << endl;
            system("pause");
            cout << endl;

            /// comprobamos si es la primer tirada o comparamos para sacar la mayor de las 3
            if(primerTiradaUno==true||suma>sumaMayor){
                sumaMayor = suma;
                rondaMayorPunt = tiradas;
                primerTiradaUno=false;
                }


        }

        /// asignamos la mayor tirada a la puntuacion del primer jugador y mostramos por pantalla
        puntuacion1 += sumaMayor;
        cout << endl;
        cout << "===========================================================================================" << endl;
        cout << "LA TIRADA MAS ALTA DE LA RONDA " << ronda1 << " FUE DE "<< sumaMayor << " PUNTOS Y SE REGISTRO EN EL LANZAMIENTO N° " << rondaMayorPunt << endl;
        cout << "LA PUNTUACION DEL JUGADOR 1 "<< nombre1 << " ES DE: " << puntuacion1 <<endl;
        cout << "===========================================================================================" << endl;
        system("pause");
        system("cls");
        ///se indica el cambio de turno y se emiezan a usar las variables del segundo jugador excepto las de suma y sumaMayor al igual que el vector de dados que se pisan cuando le toca al jugador 2
        cout << "¡CAMBIO DE TURNO!" << endl;
        system("pause");

        bool primerTiradaDos = true;
        tiradas = 0;
        ronda2++;
        sumaMayor = 0; // Inicializar sumaMayor al inicio de cada

        /// incia el segundo jugador con sus variables
        cout << " ============================" << endl;
        cout << "|" << " TURNO DEL JUGADOR NUMERO 2 " << "|" << endl;
        cout << " ============================" << endl;
        cout << endl;
        cout << "USUARIO: " << nombre2 << " | " << "RONDA N°: " << ronda2 << " | " << " PUNTAJE TOTAL: " << puntuacion2 << endl;
        cout << "------------------------------------------------" << endl;

        ///se carga y suma el vector
        for(int e=1;e<=3;e++){
            cargarVector(vectorDados, dados);
            suma = sumarVector(vectorDados, dados);
            tiradas ++;

            cout << endl;
            cout << "************************************************" << endl;
            cout << "LANZAMIENTO N° " << tiradas << endl;
            cout << endl;
            ///se muestra el vector
            for(int a=0;a<dados;a++){
                cout << "{ " << vectorDados[a] << " }"<< "\t";
            }

            escalera = encontrarEscalera(vectorDados, dados);
            cout<< endl;

            ///se empieza a analizar si hay escalera o sexteto
            if(escalera){
                cout << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                cout << "¡ESCALERA! ¡GANASTE LA PARTIDA!" << endl;
                cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
                puntuacion2 = 100;
                suma = 0;
                sumaMayor = 0;
                e=3;
                break;
            }

            sexteto1 = contarNumerosRepetidos(vectorDados, 1, dados);

            if(sexteto1==6){
                cout << endl;
                repetidos = 1;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 1 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 1*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto2 = contarNumerosRepetidos(vectorDados, 2, dados);

            if(sexteto2==6){
                cout << endl;
                repetidos = 2;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 2 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 2*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" <<endl;
            }

            sexteto3 = contarNumerosRepetidos(vectorDados, 3, dados);

            if(sexteto3==6){
                cout << endl;
                repetidos = 3;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 3 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 3*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" <<endl;
            }

            sexteto4 = contarNumerosRepetidos(vectorDados, 4, dados);

            if(sexteto4==6){
                cout << endl;
                repetidos = 4;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 4 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 4*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            sexteto5 = contarNumerosRepetidos(vectorDados, 5, dados);

            if(sexteto5==6){
                cout << endl;
                repetidos = 5;
                sumaRepetidos = repetidos * 10;
                suma = sumaRepetidos;
                cout << "------------------------------------------------------------------------------------------------" << endl;
                cout << "SALIO SEXTETO DE 5 SU PUNTAJE EN ESTE LANZAMIENTO PASA HACER: 5*10 = " << sumaRepetidos << "PUNTOS " << endl;
                cout << "------------------------------------------------------------------------------------------------" << endl;
            }

            seisRepetidos = contarNumerosRepetidos(vectorDados, 6, dados);
            cout << endl;

            if(seisRepetidos==6){
                cout << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                cout << "¡QUE MALA SUERTE!  SALIO SEXTETO DE 6 SU PUNTAJE PASA A RESTABLECERSE A 0" << endl;
                cout << "--------------------------------------------------------------------------" << endl;
                puntuacion2 = 0;
                suma=0;
                sumaMayor = 0;
            }

            cout << "LA SUMA DEL LANZAMIENTO N° " << tiradas << " ES " << suma << endl;
            cout << "************************************************" << endl;
            cout << endl;
            system("pause");
            cout << endl;

            ///se verifica si es la primera tirada del segundo jugador o se compara para saber la maxima de las 3
            if(primerTiradaDos==true||suma>sumaMayor){
                sumaMayor = suma;
                rondaMayorPunt = tiradas;
                primerTiradaDos=false;
                }
        }
        ///se asigna la maxima puntuacion a la puntuacion del jugador 2 y se muestra en pantalla
        puntuacion2 += sumaMayor;
        cout << endl;
        cout << "===========================================================================================" << endl;
        cout << "LA TIRADA MAS ALTA DE LA RONDA " << ronda2 << " FUE DE "<< sumaMayor << " PUNTOS Y SE REGISTRO EN EL LANZAMIENTO N° " << rondaMayorPunt << endl;
        cout << "LA PUNTUACION DEL JUGADOR 2 "<< nombre2 << " ES DE: " << puntuacion2 << endl;
        cout << "===========================================================================================" << endl;
        system("pause");
        system("cls");
        ///una vez que pasan las 2 rondas de los jugadores se compara cual es la mayor momentaneamente para mostrar quien es el que va ganando por ahora
        if(puntuacion1>puntuacion2){
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "Por ahora va ganando el jugeador numero 1: " << nombre1 << endl;
                cout << "Con una puntuacion de: " << puntuacion1 << endl;
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                system("pause");
               }
        else{
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                cout << "Por ahora va ganando el jugeador numero 2: "<< nombre2 << endl;
                cout << "Con una puntuacion de: "<< puntuacion2 << endl;
                cout << "&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&" << endl;
                system("pause");
            }
        }
    ///cuando se encuentra un jugador que supero los 100 sale del while y comparamos cual es mayor para ver quien es el ganador y asi poder retornar esa puntuacion para luego guardarla en el historial
    if(puntuacion1>puntuacion2){
        cout<<endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "FELICIDADES GANO " << nombre1 << " CON UNA PUNTUACION DE " << puntuacion1 << " PUNTOS Y EN " << ronda1 << " RONDAS" << endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        system("pause");
        return nombre1;
    }
    else if(puntuacion1==puntuacion2){
        cout<<endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "OCURRIO UN EMPATE ENTRE ENTRE LOS DOS JUGADORES CON UNA PUNTUACION DE: " << puntuacion1 << endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        system("pause");
        return nombre1;
    }
    else{
        cout<<endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        cout << "FELICIDADES GANO " << nombre2 << " CON UNA PUNTUACION DE " << puntuacion2 << " PUNTOS Y EN " << ronda2 << " RONDAS" << endl;
        cout << "°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°°" << endl;
        system("pause");
        return nombre2;
    }
}

#endif // JUEGO_H_INCLUDED
