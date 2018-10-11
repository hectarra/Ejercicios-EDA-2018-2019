// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
char resolver(std::vector<char> const& v, int ini, int fin) {
  if (ini == fin - 1) return v[ini] - 1;
  else {
    int m = (ini + fin - 1)/2;
    if (fin - 1 - m != v[fin - 1] - v[m]) return resolver(v, m + 1, fin);
    else return resolver(v, ini, m + 1);
  }

}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    char ini, fin, sol;
    int tam;
    std::cin >> ini >> fin;
    tam = fin - ini;

    std::vector<char> presos(tam);

    for (int i = 0; i < tam; i++){
      std::cin >> presos[i];
    }


    if (ini == presos[0] && fin == presos[tam - 1])
      sol = resolver(presos, 0, tam);
    else if (ini == presos[0])
      sol = fin;
    else
      sol = ini;
    // escribir sol*/

    std::cout << sol << '\n';

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos6.txt");
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
