// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>

struct sol {
  int numero;
  int pot;
};

// El programa va dividiendo entre 10 todos los numeros hasta
// llegar a un valor menor que 10. Devolvemos el struct con
// un valor de potencia = 1 que será recibido por las llamadas
// anteriores. Después calcularemos las potencias de 10 por las
// que debemos multiplicar al resto de la division sumado con el
// valor anterior del numero. Finalmente retornamos el numero
// invertido.

// función que resuelve el problema
// Eficiencia
//      | c0 si n < 10              a = 1, b = 10, k = 0
// T(n) |                                 O(log n)
//      | T(n/10) + c1 si n >= 10

sol invertir(int n) {
  sol sol;
  if (n < 10) {
    sol.pot = 1;
    sol.numero = n//%10;
  }
  else {
    sol = invertir(n/10);
    sol.pot*=10;
    sol.numero+=n%10 * sol.pot;
  }
  return sol;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int num;
    std::cin >> num;
    if (! std::cin)
        return false;

    sol sol = invertir(num);

    // escribir sol
    std::cout << sol.numero << '\n';


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos3.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    while (resuelveCaso())
        ;


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     //system("PAUSE");
     #endif

    return 0;
}
