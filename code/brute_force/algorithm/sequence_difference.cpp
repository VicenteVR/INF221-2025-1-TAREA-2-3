#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

string mejor_subsecuencia = "";

void generar_subsecuencias(const string& s, const string& t, int i, int j, string actual) {
    if (i == s.size() || j == t.size()) {
        if (actual.size() > mejor_subsecuencia.size())
            mejor_subsecuencia = actual;
        return;
    }

    if (s[i] == t[j]) {
        generar_subsecuencias(s, t, i + 1, j + 1, actual + s[i]);
    }
    generar_subsecuencias(s, t, i + 1, j, actual);
    generar_subsecuencias(s, t, i, j + 1, actual);
}

vector<pair<string, string>> obtener_diferencias(const string& s, const string& t) {
    mejor_subsecuencia = "";
    generar_subsecuencias(s, t, 0, 0, "");
    string lcs = mejor_subsecuencia;

    vector<pair<string, string>> diferencias;
    int si = 0, ti = 0;

    for (char c : lcs) {
        int ns = si;
        int nt = ti;
        while (s[si] != c) ++si;
        while (t[ti] != c) ++ti;

        string sub_s = s.substr(ns, si - ns);
        string sub_t = t.substr(nt, ti - nt);
        if (!sub_s.empty() || !sub_t.empty())
            diferencias.emplace_back(sub_s, sub_t);

        ++si;
        ++ti;
    }

    if (si < s.size() || ti < t.size()) {
        string sub_s = s.substr(si);
        string sub_t = t.substr(ti);
        if (!sub_s.empty() || !sub_t.empty())
            diferencias.emplace_back(sub_s, sub_t);
    }

    return diferencias;
}
