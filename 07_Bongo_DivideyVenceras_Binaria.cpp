// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


// función que resuelve el problema
int resolver(std::vector<int> const& v, int ini, int fin, int num) {
    int m = (ini + fin - 1)/2;
    if (ini == fin - 1 && v[ini] != m + num) return 0;
    else if (v[m] == m + num) return v[m];
    else if (v[m] < num) return resolver(v, m + 1, fin, num);
    else return resolver(v, ini, m, num);
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
void resuelveCaso() {
    // leer los datos de la entrada
    int tam, num;
    std::cin >> tam;
    std::cin >> num;

    std::vector<int> v(tam);

    for (int i = 0; i < tam; i++){
      std::cin >> v[i];
    }

    int sol = resolver(v, 0, tam, num);
    // escribir sol

    std::cout << sol << '\n';


}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos7.txt");
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
