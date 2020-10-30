/* 
problema da mochila 0/1 (knapsack problem)

elementos - cada elemento possui um peso (w) e um valor (v).
objetivo - mximizar o valor dos elementos colocados na mochila.
a mochila tem uma capacidade maxima (wMax).

ex.:
(peso, valor)
elemento 1: (2, 4)
elemento 2: (4, 8)
elemento 3: (3, 6)

um conjunto S de n elementos,
todo elemento tem um peso wi (peso de i) e um valor/beneficio bi (valor/beneficio de i).

-força bruta - fazer todas combinaçoes : 2^n.
    - se n = 2 -> 2^2 = 4 combinaçoes
    - se n = 4 -> 2^4 = 16 combinaçoes
    - se n = 10 -> 2^10 = 1024 combinaçoes

    o valor cresce exponecialmente, na força bruta fica inviavel

-analise assintotica por força bruta : O(2^n)

-na programaçao dinamica fica viavel

 */