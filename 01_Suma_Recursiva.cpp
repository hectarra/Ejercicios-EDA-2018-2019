// 2E - Héctor Arranz Torres
// E04

// Para resolver el problema he usado una recursión lineal no final
// Al estar comprendido entre 0 y 10^9 los valores de entrada he comprendido
// la major opción un long int y al estar la solución entre 0 y 10^18
// la función es de tipo long long int

#include <iostream>
#include <iomanip>
#include <fstream>

using lli = long long int;

// función que resuelve el problema
// a = 1, b = 2, k = 0 => n^0*log n => O(log n)
lli resolver(long int a, long int b) {
  if (b == 0) return 0;
  else if (b == 1) return a;
  else if (b%2 == 0) return resolver(2*a , b/2);
  else return resolver(2*a , b/2) + a;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    long int a, b;
    std::cin >> a >> b;
    lli sol = resolver(a, b);
    std::cout << sol << '\n';
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos1.txt");
     auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
     #endif


    int numCasos;
    std::cin >> numCasos;
    for (int i = 0; i < numCasos; ++i)
        resuelveCaso();


    // Para restablecer entrada. Comentar para acepta el reto
     #ifndef DOMJUDGE // para dejar todo como estaba al principio
     std::cin.rdbuf(cinbuf);
    // system("PAUSE");
     #endif

    return 0;
}
