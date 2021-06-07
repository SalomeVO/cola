/*Ingenieria en Sistemas 
  Mercy Salome Vasquez Otiz
  Carnet: 0909-20-5202
  Tercer Semestre*/

//Declaracion de libreras 
#include <iostream>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

using namespace std;

//Estructura de la cola
struct Cola{
  int inicio;
  int max;
  int capacidad;
  char *arreglo;
};

struct Cola* crearCola(int capacidad){
  
  struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola)); //Guarda un espacio en memoria
  cola->capacidad   = capacidad; //Tamaño de la cola
  cola->inicio      = -1; //Inicializamos 
  cola->max       = 0;//Inicialiazamos 
  cola->arreglo     = (char*)malloc(cola->capacidad*sizeof(char)); //Creamos el array
  return cola;
}

//Para determinar si la cola esta vacia
int vacia(Cola q){
  
  if (q.max==0) 
    return (1);
  
 return(0);
}

//Para determinar si la esta llena
int llena(Cola *q){
  if (q->max==q->capacidad) return (1);
  
 return(0);
}

//funcion para ingresar datos
void QUEUE(Cola *q, char *dato){

  q->arreglo[q->max]=*dato;
   q->max++;
}//fin de funcion QUEUE

//funcion para eliminar datos
string ENQUEUE(Cola *cola){
  
  //declaracion de variable 
  string x;
  
  x = cola-> arreglo[0];
  
  for(int i; i<cola->max-1; i++)
  
    cola->arreglo[i] = cola-> arreglo[i+1];
    
    cola->max--;
  
  return(x);
}//fin de funcion ENQUEUE

//funcion para imprimir datos
void visualizar(struct Cola* q){
  
  struct Cola p=*q;
    
    //dondicional para mostrar los clientes
  if(!vacia(p)){
      
      cout<<"\n\tLos nombres de los clientes son: ";
      
      for(int i; i<q->max; i++)
        cout<<q->arreglo<<endl;
        _getch();
  }
  else
    cout<<"\n\t No se encuentran clientes";//mensaje si la cola esta vacia 
    _getch();
}//fin de la funcion visualizar


int main() {
  //inicializar variables
  int op;
  int tamanio;
  char *nombre;
  struct Cola* cola;
  
  do{ system("color B0");//color de la pantalla
    system("cls"); //limpiar pantalla
    
                  //Visalizar menu
    cout<<"\n\t*************************************";
    cout<<"\n\t*           MENU PRINCIPAL          *";
    cout<<"\n\t*************************************";
    cout<<"\n\t* 1. Establecer tamanio del arreglo *";
    cout<<"\n\t* 2. Funcion QUEUE                  *";
    cout<<"\n\t* 3. Funcion ENQUEUE                *";
    cout<<"\n\t* 4. Mostrar Cola                   *";
    cout<<"\n\t* 5. Finalizar programa             *";
    cout<<"\n\t*************************************";
    cout<<"\n\n\tEliga una opcion: ";
    cin>>op; //leer opcion de usuario
    
    switch(op){
    	
      case 1: system("cls"); //limpiar pantalla
      	  
	      cout<<"\n\tIngrese el tamaño del array: ";
          cin>>tamanio;
          cola=crearCola(tamanio); //Creamos la cola
          break;
        
      case 2: system("cls"); //limpiar pantalla
	      
	      cout<<"\n\tIngrese el nombre del cliente: ";
          nombre = (char*)malloc(sizeof(char)); //Creamos un arreglo que almacenara los datos
          cin>>nombre;
          QUEUE(cola, nombre);//invocacion de funcion QUEUE
          break;
      
      case 3: system("cls"); //limpiar pantalla
      
	      cout<<"\n\tEliminamos un cliente";
          ENQUEUE(cola);//invocacion de funcion 
          _getch();
          break;
      
      case 4: system("cls"); //limpiar pantalla
          visualizar(cola);//invocacion de funcion
          _getch();
          break;
      
      case 5: break; //para que no ingrese a default
      
      default: { system("color C0");//color de pantalla
      
		cout<<"\tERROR: El numero que ingreso es incorrecto!"; //Mensaje de error 
		_getch();//detener el porgrama para leer
		 break; }//mensaje de error
      }
   }while(op!=5);
  return 0;
}
  
/*Ingenieria en Sistemas 
  Mercy Salome Vasquez Otiz
  Carnet: 0909-20-5202
  Tercer Semestre*/
