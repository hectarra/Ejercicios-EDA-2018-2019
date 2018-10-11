// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin) {
      int m = (ini + fin - 1)/2;
      if (v[m] % 2 == 1) return v[m];
      else if ((v[m] - v[ini]) / 2 == m - ini) return resolver(v, m+1, fin);
      else return resolver(v, ini, m);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada

    int tam;
    std::cin >> tam;

    if (tam == 0)
        return false;

    std::vector<int> v(tam);
    for (int i = 0; i < tam; i++){
      std::cin >> v[i];
    }

    int sol = resolver(v, 0, tam);

    // escribir sol

    std::cout << sol << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos10.txt");
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
