#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <fstream>
#include <chrono>
#include <sstream>
#include "algorithm/sequence_difference.cpp"

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    cin >> K;
    cout << K << '\n';

    // Abrimos archivo para guardar mediciones
    ofstream fout("data/measurements/a.txt"); // append

    string linea;
    getline(cin, linea); // limpiar salto pendiente

    for (int i = 0; i < K; ++i) {
        int n, m;
        string s, t;

        // Leer línea 1
        getline(cin, linea);
        stringstream ss1(linea);
        ss1 >> n;
        s = linea.substr(linea.find(' ') + 1);

        // Leer línea 2
        getline(cin, linea);
        stringstream ss2(linea);
        ss2 >> m;
        t = linea.substr(linea.find(' ') + 1);

        // Medición de tiempo individual
        auto inicio = chrono::high_resolution_clock::now();

        auto diferencias = obtener_diferencias(s, t);

        auto fin = chrono::high_resolution_clock::now();
        auto duracion = chrono::duration_cast<chrono::microseconds>(fin - inicio).count();

        size_t memoria_kb = sizeof(string) * 2 + sizeof(diferencias) + 100;

        cout << diferencias.size() << '\n';
        for (const auto& par : diferencias) {
            cout << par.first << ' ' << par.second << '\n';
        }

        fout << (s.size() + t.size()) << " " << (duracion / 1000.0) << " " << memoria_kb << "\n";
    }


    fout.close();
    return 0;
}
