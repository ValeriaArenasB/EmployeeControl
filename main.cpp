3
#include <iostream>
#include <fstream>
#include <string.h>

//salario minimo vigente con descuentos de ley aplicados
#define salarioMin 750000;
#define valorHoraM 7197;

using namespace std;

struct Profesor {
  string escalafon;
  //cantidad de asignaturas que dicta 
  int cantidadP;
  //vector de asignaturas
  string asignatura[100];
  //vector de horas por asignatura
  int horas_profesor[100];
  int horasTotales=0;
};

struct Monitor {
  //cantidad de asignaturas que apoya 
  int cantidadM;
  //vector de asignaturas
  string asignatura[100];
  //vector de horas por asignatura
  int horas_monitor[100];
  int horasTotales=0;
};

struct Empleado {
  string nombre;
  string documento;
  string clase;
  string cargo;
  int salarios;
  Profesor profesor;
  Monitor monitor;
  int nomina;
};

ifstream entrada;
int num = 0;
string archivo;

int uno(Empleado empleado[], int num);
int dos(Empleado empleado[], int num);
int tres(Empleado empleado[], int num);
void cuatro(Empleado empleado[], int num);
void cinco(Empleado empleado[], int num);
void seis(Empleado empleado[], int num);
void siete(Empleado empleado[], int num);
void ocho(Empleado empleado[], int num);
//NUEVE

int main() {
  Empleado empleado[50];
  int opcion;

  cout << "Ingrese el nombre del archivo: ";
  cin >> archivo;

  entrada.open(archivo);

  if (entrada.fail()) {
    cout << "No se encontro el archivo";
    exit(1);
  }

  entrada.close();

    do
	{
    cout << "---Nomina de empleados---" << endl;
    cout << "0. Salir" << endl;
    cout << "1. Cargar empleados del archivo .txt" << endl;
    cout << "2. Agregar un empleado" << endl;
    cout << "3. Eliminar un empleado" << endl;
    cout << "4. Agregar asignatura a profesor" << endl;
    cout << "5. Agregar asignatura a monitor" << endl;
    cout << "6. Calcular salario de empleado" << endl;
    cout << "7. Calcular salario de profesor" << endl;
    cout << "8. Calcular salario de monitor" << endl;
    cout << "9. Generar nomina en archivo .txt" << endl;
    cout <<"___________________________" << endl;
    cout << "Digite su opcion: " << endl;
    cin >> opcion;
    fflush(stdin);
    switch (opcion) 
	{
	    case 0:
	    	exit(1);
	      break;
	
	    case 1:
	      num = uno(empleado, num);
	      break;
	
	    case 2:
	      num = dos(empleado, num);
	      break;
	
	    case 3:
	      num = tres(empleado, num);
	      break;
	
	    case 4:
	      cuatro(empleado, num);
	      break;
	
	    case 5:
	      cinco(empleado, num);
	      break;
	
	    case 6:
	      seis(empleado, num);
	      break;
	
	    case 7:
	      siete(empleado, num);
	      break;
	
	    case 8:
	      ocho(empleado, num);
	      break;
	
	    case 9:
	      //funcion
	      break;
	
	    default:
	      cout << "Opcion incorrecta" << endl;
	      break;
    }
  } while (opcion != 0);
}

int uno(Empleado empleado[], int num) {
	  string auxiliar, fin;
	  entrada.open(archivo);
	  int i = 0, profesor = 0, monitor = 0;
	  
	  cout << "Cargando Archivo... " << endl;
	  
  while (fin != "FIN") 
  {
    getline(entrada, empleado[i].nombre);
    getline(entrada, empleado[i].documento);
    getline(entrada, empleado[i].clase);
    if (empleado[i].clase == "Empleado") 
	{
      getline(entrada, empleado[i].cargo);
      getline(entrada, auxiliar);
      empleado[i].salarios = stoi(auxiliar);
    } else if (empleado[i].clase == "Profesor") 
	{
      getline(entrada, empleado[i].profesor.escalafon);
      getline(entrada, auxiliar);
      empleado[i].profesor.cantidadP = stoi(auxiliar);

      for (int b = 0; b < empleado[i].profesor.cantidadP; b++) 
	  {
        getline(entrada, empleado[i].profesor.asignatura[b]);
        getline(entrada, auxiliar);
        empleado[i].profesor.horas_profesor[b] = stoi(auxiliar);
        empleado[i].profesor.horasTotales+=stoi(auxiliar);
      }

    } else if (empleado[i].clase == "Monitor") 
	{
		getline(entrada, auxiliar);
      	empleado[i].monitor.cantidadM = stoi(auxiliar);

     for (int a = 0; i < empleado[i].monitor.cantidadM; a++) 
	  {
        getline(entrada, empleado[i].monitor.asignatura[a]);
    	getline(entrada, auxiliar);
    	empleado[i].monitor.horas_monitor[a]=stoi(auxiliar);
    	empleado[i].monitor.horasTotales+=stoi(auxiliar);
      }
    }
    getline(entrada, fin);
    i++;
    num++;
  }
  
  cout << "Se cargo el archivo..." << endl;
  cout << "Se han leido " << num << " Empleados en total"<< endl;
  return num;
}

int dos(Empleado empleado[], int num) 
{
  empleado[num].clase = "Empleado";
  cout << "--Datos del empleado nuevo--" << endl;
  cout << "Ingrese el nombre: ";
  getline(cin, empleado[num].nombre);

  cout << "Ingrese el ID: ";
  cin >> empleado[num].documento;
  fflush(stdin);
  cout << "Ingrese el tipo de Empleado: ";
  getline(cin, empleado[num].cargo);

  cout << "Ingrese la cantidad de salarios minimos: ";
  cin >> empleado[num].salarios;
  fflush(stdin);
  return ++num;
}

int tres(Empleado empleado[], int num)
{
	cout <<"Num es =" << num << endl;
	
	int ultimo = num-1, elim, pos, b = 1;
	string empleadoF;
	
	cout << "---Lista de Empleados---" << endl;
	for(int i = 0; i < num; i++)
	{
		if(empleado[i].clase == "Empleado")
		{
			cout << "Empleado #" <<b<<": " << empleado[i].nombre << endl;
			cout << "Empleado #" <<b<<": " << empleado[i].documento << endl;
			cout <<"___________________________" << endl;
			b++;
		}
	}
	
	cout << "Ingrese el nombre o codigo del empleado a borrar: ";
	getline(cin, empleadoF);
	
	for(int a = 0; a < num; a++)
	{
		if(empleadoF == empleado[a].nombre || empleadoF == empleado[a].documento)
		{
			pos = a;
			empleado[pos] = empleado[ultimo];
			empleado[ultimo].nombre = " ";
			empleado[ultimo].documento = " ";
			empleado[ultimo].clase = " ";
			empleado[ultimo].cargo = " ";
			empleado[ultimo].salarios = 0;
			num--; 
		}
	}
	
	return num;
}

void cuatro(Empleado empleado[], int num)
{
	int b = 1, h, sumaH = 0, pos;
	bool encontro = false;
	string agregar;
	cout <<"---Lista de Profesores---" << endl;
	for(int i = 0; i < num; i++)
	{
		if(empleado[i].clase == "Profesor")
		{
			cout << "Profesor #" <<b<<": " << empleado[i].nombre << endl;
			cout << "Documento #" <<b<<": " << empleado[i].documento << endl;
			cout <<"___________________________" << endl;
			b++;
		}
	}
	cout <<"Ingrese el nombre del profesor: ";
	getline(cin, agregar);
	cout <<"Cuantas horas trabajo en total: ";
	cin >> h;
	fflush(stdin);
	
	for(int a = 0; a < num && encontro == false; a++)
	{
		if(empleado[a].nombre == agregar && empleado[a].clase == "Profesor"  && empleado[a].profesor.horasTotales == h)
		{
			encontro=true;
			
			cout << "Asignatura a agregar: ";
			cin >> empleado[a].profesor.asignatura[empleado[a].profesor.cantidadP];
			fflush(stdin);
			
			cout << "Horas totales de la asignatura: ";
			cin >> empleado[a].profesor.horas_profesor[empleado[a].profesor.cantidadP];
			fflush(stdin);
			empleado[a].profesor.horasTotales += empleado[a].profesor.horas_profesor[empleado[a].profesor.cantidadP];
			empleado[a].profesor.cantidadP++;
		}
	}
	if(encontro)
	{
		cout << "Registro modificado...." << endl;
	}else{
		cout <<"No se encontro profesor " << agregar << "Con " << h << "asignadas" << endl;
		cout <<"Verifique su informacion" << endl;
	}
}
void cinco(Empleado empleado[], int num)
{
  	int b = 1, h, sumaH = 0, pos;
	bool encontro = false;
	string agregar;
	cout <<"---Lista de Monitores---" << endl;
	for(int i = 0; i < num; i++)
	{
		if(empleado[i].clase == "Monitor")
		{
			cout << "Monitor #" <<b<<": " << empleado[i].nombre << endl;
			cout << "Documento #" <<b<<": " << empleado[i].documento << endl;
			cout <<"___________________________" << endl;
			b++;
		}
	}
	cout <<"Ingrese el nombre del profesor: ";
	getline(cin, agregar);
	cout <<"Cuantas horas trabajo en total: ";
	cin >> h;
	fflush(stdin);
	
	for(int a = 0; a < num && encontro == false; a++)
	{
		if(empleado[a].nombre == agregar && empleado[a].clase == "Monitor"  && empleado[a].monitor.horasTotales == h)
		{
			encontro=true;
			
			cout << "Asignatura a agregar: ";
			cin >> empleado[a].profesor.asignatura[empleado[a].profesor.cantidadP];
			fflush(stdin);
			
			cout << "Horas totales de la asignatura: ";
			cin >> empleado[a].monitor.horas_monitor[empleado[a].monitor.cantidadM];
			fflush(stdin);
			empleado[a].monitor.horasTotales += empleado[a].monitor.horas_monitor[empleado[a].monitor.cantidadM];
			empleado[a].monitor.cantidadM++;
		}
	}
	if(encontro)
	{
		cout << "Registro modificado...." << endl;
	}else{
		cout <<"No se encontro profesor " << agregar << " Con " << h << " asignadas" << endl;
		cout <<"Verifique su informacion" << endl;
	}
}


void seis(Empleado empleado[], int num) 
{
  float nominaE;
  for (int i = 0; i < num; i++) 
  {
    if (empleado[i].clase == "Empleado") 
    {
      empleado[i].nomina = empleado[i].salarios * salarioMin;
    }
  }
  // o return, no se. entonces seria tipo int
  // asumo que eso se mete en algun lado para el reporte pero depende   de lo de agregar/quitar que haces
}

void siete (Empleado empleado[], int num)
{
  int i,j, suma;
  string codigoP;
  float nominaP;
  
  /*cout << "Digite el codigo del profesor ";
  cin >> codigoP;*/
  for(i = 0; i < num; i++)
    {
      if (empleado[i].clase == "Profesor")
      {
        for (j = 0; j < empleado[i].profesor.cantidadP; j++)
          {
            suma = suma + empleado[i].profesor.horas_profesor[j];
          }
 
        if (empleado[i].profesor.escalafon == "Catedra")
          {
            nominaP = 0.5*salarioMin;
            nominaP = nominaP*suma;
            empleado[i].nomina = nominaP/45;
          }
          
        else if (empleado[i].profesor.escalafon == "Instructor")
          {
            nominaP = suma*salarioMin;
            nominaP = nominaP/45;
          }

        else if (empleado[i].profesor.escalafon == "Asistente")
          {
            nominaP = 1.5*salarioMin;
            nominaP = nominaP*suma;
            empleado[i].nomina = nominaP/45;
          }

        else if (empleado[i].profesor.escalafon == "Asociado")
          {
              nominaP = 2*salarioMin;
              nominaP = nominaP*suma;
              empleado[i].nomina = nominaP/45;
          }

        else if (empleado[i].profesor.escalafon == "Titular")
          {
              nominaP = 2.5*salarioMin;
          	  nominaP = nominaP*suma;
              empleado[i].nomina = nominaP/45;
          }

        else
          {
            cout << "No cuenta con un escalafon" << endl;
          }
      }
    }
}

void ocho (Empleado empleado[], int num)
{
  int i,j, suma, nominaM;
  //listop
  for(i = 0; i < 50; i++)
    {
      if (empleado[i].clase == "Monitor")
      {
        for (j = 0; j < empleado[i].monitor.cantidadM; j++)
          {
            suma = suma + empleado[i].monitor.horas_monitor[j];
          }
        empleado[i].nomina = suma * valorHoraM;
      }
    }
  
}

void nueve(Empleado empleado[],int num)
{
  ofstream salida{"Reporte.txt"};
	
	for(int i = 0; i < num; i++)
	{
		salida <<"Empleado #" << i+1 << endl;
		salida << empleado[i].nombre << " ";
		salida << empleado[i].documento << " ";
		salida << empleado[i].nomina << "$"<<endl;
		salida <<"_______________________________" <<endl;
	}
}