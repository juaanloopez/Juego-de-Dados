#include <iostream>
#include<cstdlib>
#include<cstdio>
#include<ctime>

using namespace std;

#include "funciones.h"
#include "menus.h"
#include "juego.h"
#include "rlutil.h"

int main()
{
    srand(time(0)); // Inicializar la semilla para generar números aleatorios
    cout<<endl;
    cout<<"*********************"<<endl;
    cout << "CIEN O ESCALERA" << endl;
    cout<<"*********************"<<endl;
    cout<<endl;
    rlutil::hidecursor();
    system("pause");
    rlutil::showcursor();
    char opc;
    int contadorDePartidas;
    contadorDePartidas = 0;
    while(true){
        system("cls");
        cout<<"********************" << endl;
        cout << "ELIGA LA MODALIDAD QUE DESEA JUGAR" << endl;
        cout<<"1. JUEGO SOLITARIO " << endl;
        cout<<"2. JUEGO DE DOS JUGADORES " << endl;
        //cout<<"3. HISTORIAL DE PARTIDAS " << endl;
        cout<<"0. FIN DEL PROGRAMA " << endl;
        cout<<"********************" << endl;
        cout<<"SELECCIONE UNA OPCION: " << endl;
        rlutil::locate(24,7);
        opc = rlutil::getkey();
        system("cls");
        switch(opc){
            case '1':
                contadorDePartidas++;
                menuSolitario(contadorDePartidas);
                break;
            case '2':
                contadorDePartidas++;
                menuDosJugadores(contadorDePartidas);
                break;
            case '3':
                //historialDePartidas(puntuacionMax);
                break;
            case '0':return 0;
                break;
            default:
                cout<<"OPCION INCORRECTA. INGRESE UN NUEVO VALOR"<<endl;
                system("pause");
                break;

            }
    }
    return 0;
}
