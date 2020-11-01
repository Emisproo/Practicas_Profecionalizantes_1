#include <iostream>
#include <string>
#include <fstream>
using namespace std;

 const int DIM = 1000;
 typedef struct
 {
   string fecha;
   string alumno;
   string carrera;
   string curso;
   string materia;
 } tAlumnos;


typedef tAlumnos tArray[DIM];

typedef struct {
   tArray elementos;
   int contador=0;
} tLista;
tLista lista;

 void openFile(tLista &lista);
 void asistencia(tLista &lista, bool &ok);
 void up_date_file (tLista &lista);
 void ordenar(tLista &lista);


 char op;
 bool ok;
 int i, j, pos;
 int main()
 {
     openFile(lista);
     asistencia (lista, ok);
     cin.ignore();
     ordenar(lista);
     up_date_file(lista);

        cout << "NO SE OLVIDE DE LAVAR SUS MANOS CON ABUNDANTE JABON Y USE TAPA-BOCA."<< endl
                << "QUE TENGA BUEN DÍA ;)";
 }

 void openFile(tLista &lista)
 {
      ifstream OpenFile; //abrimos el archivo y se sacan los datos...
        OpenFile.open("Asistencias.txt", ios::in);
        if(OpenFile.is_open())
        {
            while(!OpenFile.eof())
               {
                OpenFile >> lista.elementos[lista.contador].fecha;
                OpenFile.get( );
                OpenFile >> lista.elementos[lista.contador].alumno;
                OpenFile.get( );
                OpenFile >> lista.elementos[lista.contador].carrera;
                OpenFile.get( );
                OpenFile >> lista.elementos[lista.contador].curso;
                OpenFile.get( );
                OpenFile >> lista.elementos[lista.contador].materia;
                OpenFile.get( );

                if((!lista.elementos[i].fecha.empty())
                   && (!lista.elementos[i].alumno.empty())
                   && (!lista.elementos[i].carrera.empty())
                   && (!lista.elementos[i].curso.empty())
                   && (!lista.elementos[i].materia.empty())) //si el renglon no esta vacio...
                {
                    lista.contador++;
                }
              }
        }
            OpenFile.close();
 }
void asistencia(tLista &lista, bool &ok)
{
    tAlumnos alumno;
    ok = true;
     if(lista.contador < DIM)
    {
         cout << endl;
        cout << "***REGISTRO DE ASISTENCIAS***"<< endl;
        cout << "Ingrese la fecha del día (dd/mm/aaaa): ";
        getline(cin,alumno.fecha);
        cout << "Ingrese su nombre y apellido: ";
        getline(cin,alumno.alumno);
        cout << "Ingrese la carrera que cursa: ";
        getline(cin,alumno.carrera);
        cout << "Ingrese el curso: ";
        getline(cin,alumno.curso);
        cout << "Ingrese la materia que va a presenciar: ";
        getline(cin,alumno.materia);

         if (lista.contador == DIM)
        {
            ok = false;

        }
        else
        {
            int i=0;
            while  (i < lista.contador)
            {
                i++;
            }
                // Insertamos en la posición i (primer mayor o igual)
            for (int j = lista.contador; j > i; j--)
            {
                // Desplazamos una posición a la derecha
                lista.elementos[j] = lista.elementos[j-1];
            }
            lista.elementos[i] = alumno;
            lista.contador++;
        }
    }
        else
            cout << "Maximo de alumnos cargados (1000)!" << endl;

}

void ordenar(tLista &lista)
{
    for (i = 1; i < lista.contador; i++) // Desde el segundo elemento hasta el último
        {
         for(int j = 0; j < lista.contador - 1; j++)
            {
              tAlumnos temp;
              temp = lista.elementos[j];
              lista.elementos[j] = lista.elementos[j+1];
              lista.elementos[j+1] = temp;
            }
    }
}

void up_date_file (tLista &lista)
{
     ofstream Archivo;
    Archivo.open("Asistencias.txt", ios::out);
    if(Archivo.is_open())
    {
        for(i = 0; i < lista.contador; i++)
        {
             Archivo <<lista.elementos[i].fecha<< " "
             << lista.elementos[i].alumno<< " "
             << lista.elementos[i].carrera << " "
             <<lista.elementos[i].curso << " "
             << lista.elementos[i].materia << endl;
        }
    }
    Archivo.close();
}
