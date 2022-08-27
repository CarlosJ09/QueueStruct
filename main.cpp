/*
Estructura de Colas (Queues) Fecha: 26/8/2022

Creado por:

Carlos Jimenez 1105749
Adam Guerrero 1106129
Victor
Alejandro Lara
Mauricio
 */

#include <iostream> //cin & cout
#include <curses.h> //getch()
#include <string>   //Permite utilizar getline en try catch

using namespace std;

struct Queue
{
    int data;
    Queue *next;
};

int menu = 0; // Para manejar el menu

void Menu(); // Menu del programa.
void validarMenu();
void Enqueue(Queue *&head, Queue *&end, int &n);     // inserta datos en la cola.
bool EnqueuePrio(Queue *&cola, int prior, int data); // Inserta datos en la cola con prioridad.
void Dequeue(Queue *&head, Queue *&end, int &n);     // Elimina datos de la cola.
void Display(Queue *&head, Queue *&end, int &n);     // Despliega todos los elementos de la Cola realizando un Dequeue de toda la estructura.
bool IsEmpty(Queue *&head);                          // Verifica si la cola esta vacia, de ser asi manda un mensaje avisando.
void Exit();                                         // Sale del programa.

int main()
{
    Menu();

    return 0;
}

void Menu()
{
    // Frente y Final de la cola
    Queue *head = NULL;
    Queue *end = NULL;

    int dato; // Elemento que introduce el usuario

    while (menu != 5)
    {
        cout << "Elija una opcion: \n \n";

        // Opciones
        cout << "1.Insertar" << endl;
        cout << "2.Insertar con prioridad" << endl;
        cout << "3.Eliminar un elemento" << endl;
        cout << "4.Desplegar" << endl;
        cout << "5.Salir \n"
             << endl;

        cin >> menu;
        switch (menu)
        {
        case 1: // Insertar datos.
            system("clear");
            cout << "Digite el numero que desea ingresar: ";
            cin >> dato;

            Enqueue(head, end, dato);

            cout << "\n"
                 << endl;

            break;

        case 2: // Insertar datos con prioridad en la cola.
            system("clear");
            int prior;

            cout << "Digite el numero que desea insertar \n"
                 << endl;
            cin >> dato;
            cout << "Digite la prioridad del 1 al 16 \n"
                 << endl;
            cin >> prior;

            EnqueuePrio(head, prior, dato);
            cout << "Elemento " << dato << " insertado en la cola correctamente con prioridad " << prior << endl;

            cout << "\n"
                 << endl;
            break;

        case 3: // Eliminando un elemento.
            system("clear");
            cout << "Presione cualquier tecla para eliminar el elemento en frente de la cola" << endl;
            cin >> dato;

            Dequeue(head, end, dato);

            cout << "\n"
                 << endl;

            break;

        case 4: // Desplegando la cola.
            system("clear");
            Display(head, end, dato);

            cout << "\n"
                 << endl;

            break;

        case 5: // Salir
            system("clear");
            Exit();

            cout << "\n"
                 << endl;

            break;
        default: // Cualquier otra opcion.
            cout << "Por favor elija una opcion valida \n"
                 << endl;
            break;
        }
    }
}

void Enqueue(Queue *&head, Queue *&end, int &n)
{
    Queue *nuevo = new Queue();

    nuevo->data = n;
    nuevo->next = NULL;

    if (IsEmpty(head))
    {
        head = nuevo;
    }
    else
    {
        end->next = nuevo;
    }

    end = nuevo;

    cout << "\nElemento " << n << " insertado correctamente!" << endl;
}

bool EnqueuePrio(Queue *&cola, int prior, int data)
{
    int ipc = 0;
    Queue *ant;                       // anterior
    Queue *aux, *nuevo = new Queue(); // Creando espacio en memoria
    bool ip = true;                   // insertarPrioridad = ip
    aux = cola;
    ant = aux;

    while (aux != NULL && ipc < prior)
    {
        ant = aux;
        aux = aux->next;
        ipc++;
    }

    if (prior == ipc)
    {
        nuevo->data = data;
        nuevo->next = aux;

        if (prior != 0)
            ant->next = nuevo;
    }
    else
    {
        ip = false;
    }

    return ip;
}

void Dequeue(Queue *&head, Queue *&end, int &n)
{
    n = head->data;
    Queue *aux = head;

    if (head == end)
    {
        head == NULL;
        end == NULL;
    }
    else
    {
        head = head->next;
    }

    delete aux;

    cout << "El elemento " << n << " ha sido eliminado" << endl;
}

bool IsEmpty(Queue *&head)
{
    return (head == NULL) ? true : false;
}

void Display(Queue *&head, Queue *&end, int &n)
{
    while (head != NULL)
    {
        n = head->data;
        Queue *aux = head;

        if (head == end)
        {
            head == NULL;
            end == NULL;
        }
        else
        {
            head = head->next;
        }

        delete aux;

        cout << "El elemento " << n << " ha sido eliminado" << endl;
    }
}

void Exit()
{
    cout << "Salida de manera exitosa!" << endl;
}