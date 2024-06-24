#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED
#include "juego.h"
#include "rlutil.h"

void historialDePartidas(int puntajeMayor, string nombre){
    if(puntajeMayor==0){
        cout << "******************************************" << endl;
        cout << "----NO SE REGISTRARON PARTIDAS JUGADAS----" << endl;
        cout << "******************************************" << endl;
    }
    else{
        cout << "*******************************" << endl;
        cout << "----RANKIN MAYOR PUNTUACION----" << endl;
        cout << "#1 - " << nombre << " - " << puntajeMayor << endl;
        cout << "*******************************" << endl;
    }
    system("pause");
}

void historialDePartidasDosJugadores(string nombre, int contadorpartidas){
        if(contadorpartidas==1){
            cout << "******************************************" << endl;
            cout << "----NO SE REGISTRARON PARTIDAS JUGADAS----" << endl;
            cout << "******************************************" << endl;
            system("pause");

        }
        else{
            cout << "*******************************" << endl;
            cout << "----RANKIN MAYOR PUNTUACION----" << endl;
            cout << "#1 - " << nombre << endl;
            cout << "*******************************" << endl;
            system("pause");

        }
}

void menuSolitario(int contadorPartidas){
    char opc;
    int puntuacionMax, contadorPuntaje, puntuacionAnt;
    string nombreDeUsuario1;
    string nombreDeUsuario;
    contadorPuntaje = 0;
    while(true){
        system("cls");
        cout<<"********************" << endl;
        cout<<"MODO SOLITARIO" << endl;
        cout << endl;
        cout<<"INGRESE EL MODO DE JUEGO QUE DESEA JUGAR " << endl;
        cout<<"1. MODO SIMULADO " << endl;
        cout<<"2. MODO ALEATORIO " << endl;
        cout<<"3. INGRESE AL HISTORIAL DE PARTIDAS SOLITARIO " << endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL " << endl;
        cout<<"********************" << endl;
        cout<<"SELECCIONE UNA OPCION: " << endl;
        rlutil::locate(24, 10);
        opc = rlutil::getkey();
        system("cls");
        switch(opc){
            case '1':
                cout << "INGRESE SU NOMBRE DE USUARIO: " << endl;
                rlutil::locate(31, 1);
                cin >> nombreDeUsuario1;
                system("cls");
                if(contadorPartidas==1){
                    puntuacionMax = juegoSolitarioSimulado(nombreDeUsuario1);
                    contadorPartidas ++;
                }
                else{
                    puntuacionAnt = juegoSolitarioSimulado(nombreDeUsuario1);
                    if(puntuacionMax<puntuacionAnt){
                        puntuacionMax = puntuacionAnt;
                    }
                }
                break;
            case '2':
                cout << "INGRESE SU NOMBRE DE USUARIO: "<< endl;
                rlutil::locate(31, 1);
                cin >>nombreDeUsuario1;
                system("cls");
                if(contadorPartidas==1){
                    puntuacionMax = juegoSolitarioAleatorio(nombreDeUsuario1);
                    contadorPartidas ++;
                }
                else{
                    puntuacionAnt = juegoSolitarioAleatorio(nombreDeUsuario1);
                    if(puntuacionMax<puntuacionAnt){
                        puntuacionMax = puntuacionAnt;
                    }
                }
                break;
            case '3':
                historialDePartidas(puntuacionMax, nombreDeUsuario1);
                break;
            case '0':
                return;
                break;
            default:
                cout<<"OPCION INCORRECTA. INGRESE UN NUEVO VALOR"<<endl;
                system("pause");
                break;

            }
    }
}

int menuDosJugadores(int contadorPartidas){
    //int opc;
    char opc;
    int contadorPuntaje;
    string nombreMax, nombreAnt;
    string nombreDeUsuario1;
    string nombreDeUsuario2;
    contadorPuntaje = 0;
    while(true){
        system("cls");
        cout << "********************" << endl;
        cout << "MODO DOS JUGADORES " << endl;
        cout << endl;
        cout << "INGRESE EL MODO DE JUEGO QUE DESEA JUGAR " << endl;
        cout << "1. MODO SIMULADO " << endl;
        cout << "2. MODO ALEATORIO " << endl;
        cout << "3. INGRESE AL HISTORIAL DE PARTIDAS DOS JUGADORES " << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL " << endl;
        cout << "********************" << endl;
        cout << "SELECCIONE UNA OPCION: " << endl;
        rlutil::locate(24, 10);
        opc = rlutil::getkey();
        //cin >> opc;
        system("cls");
        switch(opc){
            case '1':
                cout << "INGRESE EL NOMBRE DEL USUARIO 1: " << endl;
                rlutil::locate(34, 1);
                cin >> nombreDeUsuario1;
                cout << "INGRESE EL NOMBRE DEL USUARIO 2: " << endl;
                rlutil::locate(34, 2);
                cin >> nombreDeUsuario2;
                system("cls");
                if(contadorPartidas==1){
                    nombreMax = juegoDosJugadoresSimulado(nombreDeUsuario1, nombreDeUsuario2);
                    contadorPartidas ++;
                }
                else{
                    nombreAnt = juegoDosJugadoresSimulado(nombreDeUsuario1, nombreDeUsuario2);
                    if(nombreMax<nombreAnt){
                        nombreMax = nombreAnt;
                    }
                }
                break;
            case '2':
                cout << "INGRESE EL NOMBRE DEL USUARIO 1: " << endl;
                rlutil::locate(34, 1);
                cin >> nombreDeUsuario1;
                cout << "INGRESE EL NOMBRE DEL USUARIO 2: " << endl;
                rlutil::locate(34, 2);
                cin >> nombreDeUsuario2;
                system("cls");
                if(contadorPartidas==1){
                    nombreMax = juegoDosJugadoresAleatorio(nombreDeUsuario1, nombreDeUsuario2);
                    contadorPartidas ++;
                }
                else{
                    nombreAnt = juegoDosJugadoresAleatorio(nombreDeUsuario1, nombreDeUsuario2);
                    if(nombreMax<nombreAnt){
                        nombreMax = nombreAnt;
                    }
                }
                break;
            case '3':
                 historialDePartidasDosJugadores(nombreMax,contadorPartidas);
                break;
            case '0':
                return 0;
                break;
            default:
                cout<<"OPCION INCORRECTA. INGRESE UN NUEVO VALOR"<<endl;
                system("pause");
                break;
            }
    }
}

#endif // MENUS_H_INCLUDED
