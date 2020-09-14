#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct FileData
{
    string nombre;// Nombre del archivo
    int tamanio;// El tamaño en bytes
};
FileData files[1000];

int numberOfFiles;// Número de archivos que ya tenemos
int contador=0;
int i;// Para bucles
int op;// La option del menu que elija el usuario

string tempText;// Para pedir datos al usuario
int tempNumber;

 void openFile();
 void caso1();
 void caso2();
 void caso3();
 void caso4();

int main()
{
    do
    {
        numberOfFiles = 0; //inicializamos siempre nuestra numberofiles en 0 para actualizar constantemente los datos

        openFile();

        cout << endl;
        cout << "Escoja una opción:" << endl;
        cout << "1.- Añadir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tamaño" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;

        cin >> op;
        cin.ignore();

        // llamamos funsion opc y hacemos una cosa u otra según la opción escogida
        switch(op)
        {
            case 1: caso1();  //agregar archivo
                    break;
            case 2: caso2();
                    break;
            case 3: caso3();// Mostrar según el tamaño
                    break;
            case 4: caso4(); // Ver todos los datos del archivo
                    break;
            case 5: cout << "Fin del programa" << endl;     // Salir: avisamos de que salimos
                    break;
            default: cout << "¡Opción desconocida!" << endl;    // Otra opción: no válida
                     break;
        }
    }
            while(op != 5);// Si la opción es 5, terminamos

    return 0;
}

void openFile()
{
    ifstream OpenFile; //abrimos el archivo y se sacan los datos...
        OpenFile.open("Registros.txt", ios::in);
        if(OpenFile.is_open())
        {
            while(!OpenFile.eof())
            {
                OpenFile >> files[numberOfFiles].tamanio;
                OpenFile.get( );
                getline(OpenFile, files[numberOfFiles].nombre);

                if((!files[numberOfFiles].nombre.empty())&&(files[numberOfFiles].tamanio != 0)) //si el renglon no esta vacio...
                {
                    numberOfFiles++;
                }
            }
            contador= numberOfFiles;
            cout << "CANTIDAD DE ARCHIVOS ALMACENADOS: "<<numberOfFiles<< endl;
        }
        OpenFile.close();
}

void caso1()
{
    if (numberOfFiles < 1000)   // Si queda hueco
            {
                cout << "Introduce el nombre del archivo" << endl;
                getline(cin, files[numberOfFiles].nombre);
                cout << "Introduce el tamaño en KB"<< endl;
                cin >> files[numberOfFiles].tamanio;

                ofstream esc_file; //guardamos los nuevos datos en el archivo y creamos uno si el archivo no existe...
                esc_file.open("Registros.txt", ios::app);
                if(esc_file.is_open())
                {
                    esc_file << files[numberOfFiles].tamanio << " " << files[numberOfFiles].nombre << endl;
                }
                esc_file.close();

                numberOfFiles++;  // suma un archivo
            }
            else   // Si no hay hueco para más archivos, avisamos
            {
                cout << "¡Máximo de archivos alcanzado (1000)!" << endl;
            }
}
void caso2()
{
    for (i = 0; i < numberOfFiles; i++) // Mostrar todos los archivos
    {cout << "Nombre: " << files[i].nombre << endl <<
            "Tamaño: " << files[i].tamanio << "Kb" << endl;}
}

void caso3()
{
    cout << "¿A partir de que tamaño de archivo quieres que le muestre? ";
            cin >> tempNumber;
            for (i=0; i<numberOfFiles; i++)
            {
                if (files[i].tamanio >= tempNumber)
                { cout << "Nombre: " << files[i].nombre << endl<<
                "Tamaño: " << files[i].tamanio << " Kb" << endl;}
            }
}
void caso4()
{
     cout << "¿De qué archivo quieres ver todos los datos?";
            cin >> tempText;
            for (i=0; i<numberOfFiles; i++)
            {
                if (files[i].nombre == tempText)
                { cout << "Nombre: " << files[i].nombre << endl<<
                        "Tamaño: " << files[i].tamanio << " Kb" << endl;}
            }
}

