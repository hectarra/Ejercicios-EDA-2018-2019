// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>



// función que resuelve el problema
// En el caso de que el vector esté vacío devolverá el valor -1 sino, en caso de
// que solo tenga un espacio devolverá dicha posición. En caso de tener dos comprobará
// los dos posibles valores y devolverá el menor de ambos. En el resto de casos
// comprobará anterior y posterior con el valor del medio y elegirá hacia donde debe
// seguir realizando comprobaciones. Si ninguno de los dos valores es menor, el menor será
// el elegido y por tanto devolverá dicho valor;
//
// Eficiencia
// n = fin - ini                  a=1 b=2 k=0
//      | c0 si n = 0, 1, 2       O(n)=(log n)
// T(n) |
//      | T(n/2) + c1 n > 2


int resolver(std::vector<int> const& valores, int ini, int fin) {
	if (ini == fin) return -1;
	else if (ini + 1 == fin) return valores[ini];
	else if (ini + 2 == fin) {
		int m = (ini + fin - 1) / 2;
		if (valores[m] < valores[m + 1]) return valores[m];
		else return valores[m + 1];
	}
	else {
		int m = (ini + fin - 1) / 2;
		if (valores[m - 1] < valores[m]) return resolver(valores, ini, m);
		else if (valores[m + 1] < valores[m]) return resolver(valores, m+1, fin);
    else return valores[m];
	}
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada	int num;
	int num;
	std::cin >> num;
	std::vector<int> valores(num);
	for (int& num : valores) std::cin >> num;

    if (! std::cin)
        return false;

    int sol = resolver(valores, 0, valores.size());

    // escribir sol

	std::cout << sol << '\n';


    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos5.txt");
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
