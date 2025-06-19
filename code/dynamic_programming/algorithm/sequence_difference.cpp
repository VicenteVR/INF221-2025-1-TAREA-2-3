#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<pair<string, string>> obtener_diferencias(const string& s, const string& t) {
    int n = s.size(), m = t.size();
    // Paso 1: construir la tabla de LCS
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            if (s[i - 1] == t[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);

    // Paso 2: reconstruir LCS y marcar diferencias
    int i = n, j = m;
    vector<pair<int, int>> lcs_pos;
    while (i > 0 && j > 0) {
        if (s[i - 1] == t[j - 1]) {
            lcs_pos.push_back({i - 1, j - 1});
            --i;
            --j;
        } else if (dp[i - 1][j] >= dp[i][j - 1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs_pos.begin(), lcs_pos.end());

    // Paso 3: extraer las diferencias entre coincidencias
    vector<pair<string, string>> diferencias;
    int si = 0, ti = 0;
    for (auto [s_idx, t_idx] : lcs_pos) {
        if (s_idx > si || t_idx > ti) {
            string sub_s = s.substr(si, s_idx - si);
            string sub_t = t.substr(ti, t_idx - ti);
            if (!sub_s.empty() || !sub_t.empty())
                diferencias.push_back({sub_s, sub_t});
        }
        si = s_idx + 1;
        ti = t_idx + 1;
    }

    // Agregar lo que queda al final
    if (si < n || ti < m) {
        string sub_s = s.substr(si);
        string sub_t = t.substr(ti);
        if (!sub_s.empty() || !sub_t.empty())
            diferencias.push_back({sub_s, sub_t});
    }

    return diferencias;
}
