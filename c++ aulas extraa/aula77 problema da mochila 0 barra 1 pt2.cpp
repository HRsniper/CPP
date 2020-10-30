/* 
temos 1, 2, 3, ..., n elementos 
o subproblema sera encontrar a soluçao otim para Sk = {elementos 1, 2, 3, ..., k}

pergunta: podemos escrever a soluçao Sn em termos dos subproblemas?

ex.:
    elemento    peso    valor/benefico
        1         2          3
        2         4          5
        3         5          8
        4         3          4
        5         9          10

capacidade maxima da mochila: 20
S4 = {1,2,3,4} - peso total: 14, benefico maximo: 20
S5 = {1,2,3,5} - peso total: 20, benefico maximo: 26

resposta: nao , justificativa: s4 nao é parte da soluçao S5. a soluçao otima para S5 nao é formada
pela soluçao otima de S4, ou seja nao podemos passar de s4 para s5.isso viola o principio da otimalidade
onde a soluçao otima do problema deve incluir as soluçoes otimas dos seus subproblemas.

o parametro (w) - representa o peso maximo de cada subconjunto de elementos

o sub problema sera calcular V[k,w] para encontrar a soluçao otima para Sk
     Sk = {elementos 1, 2, 3, ..., k}

se tormarmos  V[i,j]
i = 0, ..., k-1
j = 0, ..., w
como derivar V[k,w]

forma recurssiva para os subproblemas
     V[k,w] = 
                V[k-1,w] se wk > w
                max { V[k-1, w], V[k-1, w-wk] + bk }
                
o subconjunto Sk que tem peso total w:
1) o melhor subconjunto s(k-1) que tem um peso total <= w
1) o melhor subconjunto s(k-1) que tem um peso total <= w - wk + elemento k

o melhor subsonjunto Sk que tem peso total <= w  contem o elemento k ou nao 

wk > w  elemento k nmao pode ser parte do solçuçao senao o peso total seria maior do que w


wk <= w o elemento k podw fazer parte da soluçao e escolhemos o caso com o maior valor


 */