//PT2:MODIFICACIONES DEL CODIGO DE EJEMPLO DE MENU
/*La modificación más significativa fue la de determinar un máximo de 40 caracteres para el nombre del archivo a guardar: como cin no guarda cadenas con espacios,
y la cantidad de caracteres debía determinarse en 40, cambié el tipo de la variable name, de struct FileData, de String a Char. De esta manera utilizando 
la funsión cin.getline() se puede almacenar con tales especificaciones (getline() funciona para strings). 
Esta modificación se encuentra en el case 1 del Switch, en la línea 56.
Otra modificación para case 1 fue agregar cin.ignore ya que de no agregarlo, surgen inconvenientes. En case 4 también aparece por el mismo motivo.
En case 1, también se agrego una salida en pantalla que determina la cantidad de archivos que se encuentran almacenados.

*En los case 2,3, 4, se agrego IF-ELSE para mostrar en pantalla la advertencia de que no hay archivos guardados.
Además en case 3, se agregó un if-else extra en caso de que el tamaño del archivo requerido sea más grande del archivo de mayor tamaño almacenado.*/

//LAS ACLARACIONES SE DESCRIBEN EN LAS LINEAS CORRESPONDIENTES
#include <iostream>
#include <string>
using namespace std;

struct FileData
{
    char name [40]; //CAMBIO DE STRING A CHAR CON ARREGLO
    long size;
};

int numberOfFiles=0;
int i;
int option;

string tempText;
int tempNumber;

int main()
{
    //FileData* files = new FileData[1000];
    FileData files[1000];

    do
    {
        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tamaño" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;

        cin >> option;

        switch(option)
        {
            case 1:
                if (numberOfFiles < 1000)
                {
                    cout << "Introduce el tamaño en KB: ";
                    cin >> files[numberOfFiles].size;
                    cin.ignore(); // PARA LIMPIAR BUFFER Y NO HAYA INCONVENIENTES
                    cout << "Introduce el nombre del archivo: "<< endl;
                    cin.getline(files[numberOfFiles].name, 40, '\n'); //FUNSION PARA GUARDAR NOMBRE DE ARCHIVO
                    numberOfFiles++;
                    cout<< "Espacio Utilizado : "<< numberOfFiles << "/1000";
                    //MUESTRA LA CANTIDAD DE ARCHIVOS HASTA EL MOMENTO
                }
                else
                    {cout << "¡Máximo de archivos alcanzado (1000)!" << endl;}
                break;

            case 2:
                if (numberOfFiles != 0) // ENCASO DE SOLICITAR UN ARCHIVO Y NO HAYA NINGUNO...
                {
                for (i=0; i<numberOfFiles; i++)
                    cout << "Nombre: " << files[i].name
                        << "; Tamaño: " << files[i].size
                        << "Kb" << endl;
                }
                else
                { cout<< "NO EXISTEN ARCHIVOS ALMACENADOS";}
                break;

            case 3:
                if (numberOfFiles != 0) //IDEM CASE2
                {
                    cout << "¿A partir de que tamaño quieres que te muestre? ";
                    cin >> tempNumber;
                    for (i=0; i<numberOfFiles; i++)
                        if (files[i].size >= tempNumber) //IF EXTRA
                          {
                            cout << "Nombre: " << files[i].name
                                << "; Tamaño: " << files[i].size << " Kb" << endl;
                          }
                          else
                          {cout << "NO EXISTE ARCHIVO DE SEMEJANTE TAMAÑO";}
                          //EN CASO DE QUE SE PASE DEL TAMAÑO DEL ARCHIVO MAS GRANDE
                }
                else
                { cout << "NO EXISTE ARCHIVO ALMACENADO";}
                break;

            case 4:
                cin.ignore();//LIMPIA EL BAUFFER
                if (numberOfFiles != 0)     //IDEM CASE 2
                {
                    cout << "¿De qué archivo quieres ver todos los datos?"<< endl;
                    getline(cin,tempText);
                        for (i=0; i<numberOfFiles; i++)
                            if (files[i].name == tempText)
                                cout << "Nombre: " << files[i].name
                                    << "; Tamaño: " << files[i].size << " Kb" << endl;
                }
                else
                {cout << "NO EXISTEN ARCHIVOS ALMACENADOS";}
                break;

            case 5:
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opción: no válida
                cout << "¡Opción desconocida!" << endl;
                break;
        }
    } while (option != 5);// Si la opción es 5, terminamos

    return 0;
}
