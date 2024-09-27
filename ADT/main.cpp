//  main.cpp

#include <iostream>
#include "Node.hpp"
#include "LinkedList.hpp"


int main(int argc, const char * argv[]) {
    
    /* Trabajo con una LinkedList */
    std::cout << std::endl;
    std::cout << "---  Actividad 2.1 - Demostración de funciones de la LinkedList  ---" << std::endl;
    std::cout << std::endl;
    
    /* Crear una lista */
    std::cout << "(C) Se crea una lista vacía" << std::endl;
    LinkedList<int> * list_task = new LinkedList<int>();
    
    /* Insertar elementos en la lista */
    std::cout << "(I) Insertar elementos en la lista" << std::endl;
    for (int i=0; i < 15; ++i) {
        list_task->insert(i+1, i);
        //list_task->insert(i, rand() % 10);
    }
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *list_task << std::endl;
    std::cout  << std::endl;

    /* Eliminar un rango de elementos de la lista */
    std::cout << "(R) Se eliminaron los elementos del 1 al 4" << std::endl;
    list_task->deleteRange(1, 4);
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista tiene los siguientes elementos: " << std::endl;
    std::cout << *list_task << std::endl;
    std::cout  << std::endl;
    
    /* Obtener una sublist */
    std::cout << "(S) Se crea una sublista con los elementos del 1 al 4" << std::endl;
    LinkedList<int> * sublist = list_task->subList(1, 4);
    
    /* Mostrar el contenido de la lista */
    std::cout << "(L) La lista original tiene los siguientes elementos: " << std::endl;
    std::cout << *list_task << std::endl;
    
    /* Mostrar el contenido de la lista */
    std::cout << "(S) La sublista tiene los siguientes elementos: " << std::endl;
    std::cout << *sublist << std::endl;
    std::cout << std::endl;
    
    /* Obtener la union de dos listas */
    std::cout << "(U) Se crea la unión de dos listas" << std::endl;
    LinkedList<int> * union_list = list_task->Union(sublist);
    
    /* Mostrar el contenido de la lista union */
    std::cout << "(U) La lista Union tiene los siguientes elementos: " << std::endl;
    std::cout << *union_list << std::endl;
    std::cout << std::endl;
    
    /* Obtener la diferencia de dos listas */
    std::cout << "(E) Se crea la diferencia de dos listas" << std::endl;
    LinkedList<int> * except = list_task->Except(sublist);

    /* Mostrar el contenido de la lista except */
    std::cout << "(E) La lista Except tiene los siguientes elementos: " << std::endl;
    std::cout << *except << std::endl;
    std::cout << std::endl;

    /* Obtener la intersección de dos listas */
    std::cout << "(I) Se crea la intersección de dos listas" << std::endl;
    LinkedList<int> * intersection = list_task->Intersection(sublist);
    
    /* Mostrar el contenido de la lista intersection */
    std::cout << "(I) La lista Intersection tiene los siguientes elementos: " << std::endl;
    std::cout << *intersection << std::endl;
    
   /* Liberar la memoria de las listas */
    delete list_task;
    delete sublist;
    delete union_list;
    delete except;
    delete intersection;
    
    return 0;
};