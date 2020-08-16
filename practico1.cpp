//Escriba una estructura que almacene datos de una canci�n en formato MP3:
//Artista, T�tulo, Duraci�n (en segundos), Tama�o del fichero (en KB).
//Un programa debe pedir los datos de una canci�n al usuario, almacenarlos
//en dicha estructura y despu�s mostrarlos en pantalla.
//Use los ejemplos visto en clase como base para resolver este pr�ctico.
//Puede adjuntar la soluci�n directamente c�mo entrega de esta actividad.
#include <iostream>
#include <string>
using namespace std;

struct
{
    string titulo;
    string artista;
    int duracion;
    float kb;
} cancion;

int main()
{
    //Carga de datos
    cout << "NOMBRE DE LA CANCION"<< endl;
    getline(cin, cancion.titulo);
    cout << "ARTISTA" << endl;
    getline(cin, cancion.artista);
    cout << "DURACION EN SEGUNDOS" << endl;
    cin >> cancion.duracion;
    cout << "TAMA�O EN KB" << endl;
    cin >> cancion.kb;

   cout << endl;
    cout << "NOMBRE DE LA CANCION: "<<(cancion.titulo)<< endl
         << "ARTISTA: " << cancion.artista<< endl
         << "DURACION EN SEGUNDOS: " << cancion.duracion << endl
         << "TAMA�O EN KB: " << cancion.kb << endl;

    return 0;
}
