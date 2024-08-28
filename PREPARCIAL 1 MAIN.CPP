#include <iostream>
#include "list.h"

// Función para calcular la intersección de dos listas ordenadas L1 y L2
template <typename Object>
List<Object> interseccion(const List<Object> &L1, const List<Object> &L2) {
    List<Object> listaInterseccion; // Inicializa una lista vacía para almacenar la intersección
    typename List<Object>::const_iterator it1 = L1.begin(); // Iterador para la primera lista (L1)
    typename List<Object>::const_iterator it2 = L2.begin(); // Iterador para la segunda lista (L2)

    // Recorre ambas listas simultáneamente
    while (it1 != L1.end() && it2 != L2.end()) {
        if (*it1 == *it2) { // Si los elementos son iguales, agrégalos a la lista de intersección
            listaInterseccion.push_back(*it1);
            ++it1; // Mueve ambos iteradores al siguiente elemento
            ++it2;
        } else if (*it1 < *it2) { // Si el elemento de L1 es menor, mueve el iterador de L1
            ++it1; 
        } else { // Si el elemento de L2 es menor, mueve el iterador de L2
            ++it2;
        }
    }

    return listaInterseccion; // Devuelve la lista que contiene la intersección
}

int main() {
    // Crea dos listas ordenadas de ejemplo
    List<int> L1{1, 2, 3, 4, 5};
    List<int> L2{2, 4, 6, 8};

    // Calcula la intersección de L1 y L2
    List<int> listaInterseccion = interseccion(L1, L2);

    // Imprime los elementos de la lista de intersección
    std::cout << "Intersección de L1 y L2: ";
    for (auto &x : listaInterseccion) {
        std::cout << x << " ";
    }
    std::cout << std::endl;

    return 0;
}
