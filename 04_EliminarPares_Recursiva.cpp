// 2E - Héctor Arranz Torres
// E04


#include <iostream>
#include <iomanip>
#include <fstream>

// El programa va dividiendo entre 10 de manera recursiva
// hasta que obtiene un resultado menor que 0 que, en caso
// de que sea impar devolverá el último número y sino un 0.
// Ese resultado se almacenará en la llamada recursiva anterior
// y en caso de ser impar se multiplicará por 10 y se sumará el
// restod de la siguiente llamada recursiva que será el siguiente
// valor de nuestro número, hasta llegar al final.

// función que resuelve el problema
// Eficiencia
//      | c0 si n < 10              a = 1, b = 10, k = 0
// T(n) |                                 O(log n)
//      | T(n/10) + c1 si n >= 10


long long int resuelveCaso(long long int num) {
  if (num / 10 > 0) {
    if ((num % 10) % 2 == 1) return resuelveCaso(num / 10)*10 + num%10;
    else return resuelveCaso(num / 10);
  }
  else { // tienes 1 el modulo de 1 cuanto es muy bien y  ahora tienes dos el modulo de dos cuanto es
    if (num % 2 == 1) return num; // mi no entender como funciona esto
    else return 0;
  }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    long long int num;
    std::cin >> num;
    if (! std::cin)
        return false;

    long long int sol = resuelveCaso(num);

    // escribir sol

    std::cout << sol << '\n';

    return true;

}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
    #ifndef DOMJUDGE
     std::ifstream in("datos4.txt");
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
