// os problemas knapsack 1 e 2 da pasta questoes ilustram bem como o algoritmo funciona, mas basicamente e:

// estados dp[MAXN][MAXW] ou dp[MAXN][MAXV], basta analisar qual vai dar uma complexidade menor

// transicao, geralmente e algo tipo: dp[i][j] = dp[i - 1][j] e depois voce faz dp[i][j] = max ou min (dp[i][j], dp[i - 1][j - w[i]] + v[i]);