// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin) {
  if (ini == fin) return v[ini];
  else if (ini + 2 == fin) {
    int m = (ini + fin - 1) / 2;
    if (v[m] < v[m + 1]) return v[m];
    else return v[m + 1];
  }
  else {
    int m = (ini + fin - 1) / 2;
    if (v[m - 1] < v[m]) return resolver(v, ini, m);
    else if (v[m + 1] < v[m]) return resolver(v, m+1, fin);
    else return v[m];
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tam;
    std::cin >> tam;

    std::vector<int> v(tam);

    for (int i = 0; i < tam; i++){
      std::cin >> v[i];
    }

    if (! std::cin)
        return false;

    int sol = resolver(v, 0, tam);

    // escribir sol

    std::cout << sol << "\n";


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos8.txt");
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
