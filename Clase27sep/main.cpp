//
//  main.cpp
//  ejercicio_1
//
//  Created by Vicente Cubells on 09/10/20.
//

#include <iostream>
#include <sstream>
#include <string>
#include "/workspaces/ED24/Clase27sep/Queue.cpp"
#include "/workspaces/ED24/Clase27sep/Stack.cpp"

int main(int argc, const char * argv[]) {
    
    /* Crear una cola vacía */
    Queue<int> * queue = new Queue<int>();
    std::cout << "(C) Se crea una cola  vacía" << std::endl;
    
    /* Ingresar la frase*/
    std::istringstream frase("Me gustan las donas");
    std::string palabra;

    // Extraer palabras del string y almacenarlas en la pila
    while (frase >> palabra) {
        queue->enqueue(palabra); // Agregar la palabra a la pila
    }
    
    /* Visualizar el contenido de la cola */
    std::cout << "(L) La cola tiene los siguientes elementos:" << std::endl;
    std::cout << *queue << std::endl;
    
    /*
     * Invertir el contenido de la cola utilizando
     * una estructura auxilia pila
     */
    
    /* Crear una estructura auxiliar pila */
    Stack<int> * stack = new Stack<int>();
    
    /* Pasar los elementos de la cola a la pila */
    while ( !queue->empty() )
    {
        stack->push( queue->dequeue() );
    }
    
    /* Pasar los elementos de la pila a la cola */
    while ( !stack->empty() )
    {
        queue->enqueue( stack->pop() );
    }
    
    /* Liberar la memoria de la pila */
    delete stack;
    
    /* Visualizar el contenido de la cola invertida */
    std::cout << "(L) La cola invertida tiene los siguientes elementos:" << std::endl;
    std::cout << *queue << std::endl;
    
    /*
     * Invertir el contenido de la cola utilizando
     * el método reverse()
     */
    
    queue->reverse();
    
    /* Visualizar el contenido de la cola invertida */
    std::cout << "(L) La cola invertida tiene los siguientes elementos:" << std::endl;
    std::cout << *queue << std::endl;
    
    /* Liberar la memoria ocupada */
    delete queue;
    std::cout << "(D) Se liberó la memoria de la cola" << std::endl;
    
    return 0;
}
