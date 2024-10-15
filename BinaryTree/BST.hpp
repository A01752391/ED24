//
//  BST.hpp
//  BinaryTree
//
//  Created by Vicente Cubells on 20/10/20.
//

#ifndef BST_hpp
#define BST_hpp

#include "BinaryTree.hpp"

template <class T>
class BST : public BinaryTree<T>
{
    
public:
    BST() {};
    virtual ~BST() { };
    
    TreeNode<T> * search(const T &) const;
    bool insert(T &);
    bool insert(TreeNode<T> * );
    
    int whatlevelamI(const T &) const;
    
    TreeNode<T> * predecesor(TreeNode<T> * ) const;
    TreeNode<T> * sucesor(TreeNode<T> * ) const;
    TreeNode<T> * remove(T &);
    TreeNode<T> * remove(TreeNode<T> *);
    
    /* BEGIN TODO Actividad 3.1 */
    
    bool isBST(TreeNode<T> * node) const;
    int height(TreeNode<T> * node) const;
    void ancestors(T & value) const;
    int count(TreeNode<T>* node) const;
    
    /* END TODO Actividad 3.1 */
    
    
    
private:
    /* Ocultar algunos métodos heredados */
    //using BinaryTree<T>::insert;
};

/*
 Complejidad: O(log n) si el árbol está balanceado
              O(n) si el árbol está desbalanceado
 */
template <class T>
TreeNode<T> * BST<T>::search(const T & value) const
{
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            return aux;
        }
        else {
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    return nullptr;
}

/*
 Complejidad: O(log n) si el árbol está balanceado
              O(n) si el árbol está desbalanceado
 */
template <class T>
bool BST<T>::insert(T & value)
{
    return this->insert(new TreeNode<T>(value));
}

template <class T>
bool BST<T>::insert(TreeNode<T> * node )
{
    /* No se puede insertar un nodo NULL */
    if (node == nullptr) return false;
    
    /* Obtener la info del nodo a insertar */
    T value = node->getInfo();
    
    /* Establecer un apuntador auxiliar */
    TreeNode<T> * aux = this->root;
    
    /* Estalecer una variable para el padre */
    TreeNode<T> * parent = nullptr;
    
    /* Buscar la posición que le corresponde */
    while (aux != nullptr) {
        if (aux->getInfo() == value) {
            /* Liberar la memoria del nodo porque ya existe */
            delete node;
            
            return false;
        }
        else {
            parent = aux;
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    /* Establecer el parent del nodo a insertar */
    node->setParent(parent);
    
    /* Si el árbol está vacío, se inserta la raiz */
    if (parent == nullptr) {
        this->root = node;
    }
    else {
        /* Si el value a insertar es menor, se inserta a la izquierda */
        if ( parent->getInfo() > value ) {
            parent->setLeft(node);
        }
        /* Si el value a insertar es mayor, se inserta a la derecha */
        else {
            parent->setRight(node);
        }
    }
    
    return true;
}

/*
 Complejidad: O(log n) si el árbol está balanceado
              O(n) si el árbol está desbalanceado
 */
template <class T>
int BST<T>::whatlevelamI(const T & value) const
{
    int level = 0;
    
    TreeNode<T> * aux = this->root;
    
    while (aux != nullptr) {
        level++;
        if (aux->getInfo() == value) {
            return level;
        }
        else {
            aux = aux->getInfo() > value ? aux->getLeft() : aux->getRight();
        }
    }
    
    if (aux == nullptr) {
        level = 0;
    }
    
    return level;
}


/* Encontrar el predecesor de un nodo */
template <class T>
TreeNode<T> * BST<T>::predecesor(TreeNode<T> * actual) const
{
    TreeNode<T> * tmp = actual->getLeft();
    
    while( tmp->getRight() != nullptr) {
        tmp=tmp->getRight();
    }
    
    return tmp;
}

/* Encontrar el sucesor de un nodo */
template <class T>
TreeNode<T> * BST<T>::sucesor(TreeNode<T> * actual) const
{
    TreeNode<T> * tmp = actual->getRight();
    
    while( tmp->getLeft() != nullptr) {
        tmp=tmp->getLeft();
    }
    
    return  tmp;
}

/* Eliminar un nodo del árbol */
template <class T>
TreeNode<T> * BST<T>::remove(T & value)
{
    TreeNode<T> * node = this->search(value);
    
    return this->remove(node);
}

/* Eliminar un nodo del árbol */
template <class T>
TreeNode<T> * BST<T>::remove(TreeNode<T> * node)
{
    if (node != nullptr)
    {
        TreeNode<T> * left = node->getLeft();
        TreeNode<T> * right = node->getRight();
        TreeNode<T> * parent = node->getParent();
        
        // Verificar si tiene dos hijos
        if (left != nullptr && right != nullptr) {
            TreeNode<T> * pred = predecesor(node);
            T info = pred->getInfo();
            node->setInfo(info);
            node = remove(pred);
        }
        // Verificar si tiene un hijo a la izquierda
        else if (left != nullptr) {
            (parent != nullptr && parent->getLeft() == node) ? parent->setLeft(left) : parent->setRight(left);
            node->setLeft(nullptr);
        }
        // Verificar si tiene un hijo a la derecha
        else if (right != nullptr) {
            (parent != nullptr && parent->getLeft() == node) ? parent->setLeft(right) : parent->setRight(right);
            node->setRight(nullptr);
        }
        // No tiene hijos
        else {
            (parent != nullptr && parent->getLeft() == node) ? parent->setLeft(nullptr) : parent->setRight(nullptr);
        }
    }
    
    return node;
}

/* BEGIN TODO Actividad 3.1 */

/* Determinar si un árbol es un BST */
/*
 Complejidad: O(1) si el árbol esta vacío
              O(n) si el árbol está lleno
 */
template <class T>
bool BST<T>::isBST(TreeNode<T> * node) const
{
    if (node == nullptr) {
        return true; // Si el árbol está vacio, se considerará BTS, ya que no hay elementos a evaluar
    }

    std::queue<TreeNode<T> *> nodos; // Inicialización de secuencia para agregar los nodos del árbol
    TreeNode<T>* previo = nullptr; // Para almacenar el nodo previo

    nodos.push(node); // Usar una cola para hacer un recorrido InOrden

    while (!nodos.empty()) {
        int tamano = nodos.size(); // Tamaño de nodos
        
        for (int i = 0; i < tamano; ++i) {
            TreeNode<T> *current = nodos.front(); // Referencia al nodo actual
            nodos.pop(); 
            
            // Recorrido InOrden

            // Insertar en la cola el hijo izquierdo
            if (current->getLeft() != nullptr) {
                nodos.push(current->getLeft());
            }

            nodos.push(current); // Añadir el nodo a la cola
            
            // Insertar en la cola el hijo derecho
            if (current->getRight() != nullptr) {
                nodos.push(current->getRight());
            }
            
            while (!nodos.empty()) {
                TreeNode<T>* siguiente = nodos.front(); // Referencia al nodo siguiente
                nodos.pop();

                // Comprobar el orden de los nodos
                if (previo != nullptr && previo->getInfo() >= siguiente->getInfo()) {
                    return false; // No es un BST, ya que no sigue el orden de valores crecientes
                    // Característica de un árbol BTS con un recorrido InOrden
                }
                previo = siguiente; // Actualizar el nodo anterior
            }
        }
    }
    
    return true; // Si todos los nodos están en orden, es un BST
}

/* Obtener la altura del árbol */
/*
 Complejidad: O(1) si el árbol esta vacío
              O(n) si el árbol está lleno
 */
template <class T>
int BST<T>::height(TreeNode<T> * node) const {
    if (node == nullptr) {
        return 0; // Si el árbol está vacio, la altura es 0
    }

    std::queue<TreeNode<T> *> q; // Inicialización de secuencia para agregar los nodos del árbol
    q.push(node); // Añade el elemento al final de la secuencia
    
    int height = 0; // Contador de altura

    while (!q.empty()) {
        int levelSize = q.size(); // Número de nodos en el nivel actual
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode<T> *aux = q.front(); // Referencia al nodo actual
            q.pop(); // Elimina el elemento de la secuencia
            
            // Insertar en la cola el hijo izquierdo
            if (aux->getLeft() != nullptr) {
                q.push(aux->getLeft());

            }
            
            // Insertar en la cola el hijo derecho
            if (aux->getRight() != nullptr) {
                q.push(aux->getRight());
            }
        }

        height++; // Incrementar la altura conforme pasa cada nivel
    }
    
    return height;
}

/* Visualizar los ancestros de un nodo */
/*
 Complejidad: O(1) si el árbol esta vacío
              O(n) si el árbol está desbalanceado
 */
template <class T>
void BST<T>::ancestors(T& value) const
{
    TreeNode<T> * found = search(value);

    if (found != nullptr){
        TreeNode<T> * parent = found->getParent();
        if (parent != nullptr){
            while (parent != nullptr) {
                std::cout << *parent << " ";
                parent = parent->getParent(); // Recorrer hacia arriba desde el nodo encontrado hasta la raíz
            }
        }
    }
    else { std::cout << "No hay ancestros de este nodo" << std::endl; }
}


/* Obtener la cantidad de nodos del árbol */
/*
 Complejidad: O(log n) si el árbol está balanceado
              O(n) si el árbol está desbalanceado
 */
template <class T>
int BST<T>::count(TreeNode<T>* node) const
{
    if (node == nullptr) {
        return 0; // Si el árbol está vacio, la cantidad de nodos es 0
    }

    std::queue<TreeNode<T>*> nodos; // Inicialización de secuencia para agregar los nodos del árbol
    nodos.push(node); // Añade el elemento al final de la secuencia

    int totalNodos = 0; //  Contador de nodos

    while (!nodos.empty()) {
        TreeNode<T>* aux = nodos.front(); // Referencia al nodo actual
        nodos.pop(); // Elimina el elemento de la secuencia
        totalNodos++; // Sumar nodo actual
        
        // Insertar en la cola el hijo izquierdo
        if (aux->getLeft() != nullptr) {
            nodos.push(aux->getLeft());
        }
        
        // Insertar en la cola el hijo derecho
        if (aux->getRight() != nullptr) {
            nodos.push(aux->getRight());
        }
    }
    
    return totalNodos;
}

/* END TODO Actividad 3.1 */

#endif /* BST_hpp */
