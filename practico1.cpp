//Escriba una estructura que almacene datos de una canción en formato MP3:
//Artista, Título, Duración (en segundos), Tamaño del fichero (en KB).
//Un programa debe pedir los datos de una canción al usuario, almacenarlos
//en dicha estructura y después mostrarlos en pantalla.
//Use los ejemplos visto en clase como base para resolver este práctico.
//Puede adjuntar la solución directamente cómo entrega de esta actividad.
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
    cout << "TAMAÑO EN KB" << endl;
    cin >> cancion.kb;

   cout << endl;
    cout << "NOMBRE DE LA CANCION: "<<(cancion.titulo)<< endl
         << "ARTISTA: " << cancion.artista<< endl
         << "DURACION EN SEGUNDOS: " << cancion.duracion << endl
         << "TAMAÑO EN KB: " << cancion.kb << endl;

    return 0;
}
