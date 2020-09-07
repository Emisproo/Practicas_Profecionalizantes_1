//MODIFICACIONES DEL CODIGO DE EJEMPLO DE MENU
//LAS ACLARACIONES SE DESCRIBEN EN LAS LINEAS CORRESPONDIENTES
#include <iostream>
#include <string>
using namespace std;

struct FileData
{
    string name;
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
        cout << "Escoja una opci�n:" << endl;
        cout << "1.- A�adir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tama�o" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;

        cin >> option;

        switch(option)
        {
            case 1:
                if (numberOfFiles < 1000)
                {
                    cout << "Introduce el tama�o en KB: ";
                    cin >> files[numberOfFiles].size;
                    cin.ignore(); // PARA LIMPIAR BUFFER Y NO HAYA INCONVENIENTES
                    cout << "Introduce el nombre del archivo: "<< endl;
                    getline(cin,files[numberOfFiles].name);
                    numberOfFiles++;
                    cout<< "Espacio Utilizado : "<< numberOfFiles << "/1000";
                    //MUESTRA LA CANTIDAD DE ARCHIVOS HASTA EL MOMENTO
                }
                else
                    {cout << "�M�ximo de archivos alcanzado (1000)!" << endl;}
                break;

            case 2:
                if (numberOfFiles != 0) // ENCASO DE SOLICITAR UN ARCHIVO Y NO HAYA NINGUNO...
                {
                for (i=0; i<numberOfFiles; i++)
                    cout << "Nombre: " << files[i].name
                        << "; Tama�o: " << files[i].size
                        << "Kb" << endl;
                }
                else
                { cout<< "NO EXISTEN ARCHIVOS ALMACENADOS";}
                break;

            case 3:
                if (numberOfFiles != 0) //IDEM CASE2
                {
                    cout << "�A partir de que tama�o quieres que te muestre? ";
                    cin >> tempNumber;
                    for (i=0; i<numberOfFiles; i++)
                        if (files[i].size >= tempNumber)
                          {
                            cout << "Nombre: " << files[i].name
                                << "; Tama�o: " << files[i].size << " Kb" << endl;
                          }
                          else
                          {cout << "NO EXISTE ARCHIVO DE SEMEJANTE TAMA�O";}
                          //EN CASO DE QUE SE PASE DEL TAMA�O DEL ARCHIVO MAS GRANDE
                }
                else
                { cout << "NO EXISTE ARCHIVO ALMACENADO";}
                break;

            case 4:
                cin.ignore();//LIMPIA EL BAUFFER
                if (numberOfFiles != 0)//IDEM CASE 2
                {
                    cout << "�De qu� archivo quieres ver todos los datos?"<< endl;
                    getline(cin,tempText);
                        for (i=0; i<numberOfFiles; i++)
                            if (files[i].name == tempText)
                                cout << "Nombre: " << files[i].name
                                    << "; Tama�o: " << files[i].size << " Kb" << endl;
                }
                else
                {cout << "NO EXISTEN ARCHIVOS ALMACENADOS";}
                break;

            case 5:
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opci�n: no v�lida
                cout << "�Opci�n desconocida!" << endl;
                break;
        }
    } while (option != 5);// Si la opci�n es 5, terminamos

    return 0;
}
