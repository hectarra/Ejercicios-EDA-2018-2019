// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

// He usado un modelo de recursión no final. Realizo
// divisiones entre potencias de 2 hasta llegar al DecimalABinarioFinal
// que sumará los valores obtenidos y los ira concatenando en un string
// He elegido para valores de entrada long int porque los valores que almacena son
// de 2^31 - 1

// función que resuelve el problema
//      | c0 si n = 0, 1          a = 1, b = 2, k = 0
//  T(n)|                               O(logn)
//      | c1 + T(n/2) si n > 1
std::string resolver(long int n) {
  if (n == 0) return "0";
  if (n == 1) return "1";
  else return resolver(n/2) + char('0'+n%2);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    long int n;
    std::cin >> n;
    std::string sol = resolver(n);
    std::cout << sol << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos2.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
     //system("PAUSE");
     #endif

    return 0;
}
