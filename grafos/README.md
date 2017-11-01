# Grafos

1.1 Faça uma lista de todos os grafos que tenham {a, b, c} por conjunto de vértices. 
4 Faça a lista de modo que cada grafo apareça ao lado do seu complemento


```diagram
vazio
a--b 
a--c
b--c
a--b--c
a--b
|
c
a--b
   |
   c

```

E 1.2 Faça uma figura de um K5 e outra de um ¬K5. Quantas arestas tem
um Kn? E um ¬Kn

> Um k5 é um grafo com 5 arestas e todas ligadas entre sí
-------------------
                    a -----
                  / | \   |
                 b--c--d  |
                  \ | /   |
                    e -----

        O complementar é o contrário dele é

        a
      b c d
        e
------------


Um gráfo completo tem 2 números
K23 significa que o primiero número são os vertices de cima o segundo é o vertice de baixo, porém nimguém de cima é ligado e nunuém de baixo é ligado as ligações são apenas de cima pçara baixo

# Representação no programa

* Você pode definir em uma matriz, mas é muito ruim, uma representação melhor éde um dicionário

```python
d['a'] = ['c', 'b', 'e']
```


# Grafos importantes
1. Cavalo 3x3: desenhar no tabuleiro 3x3

|   |  |   |
|---|--|---|
| * |  |   |
|   |  | * |
| * |  |   |

-----------------

|   |  |   |
|---|--|---|
| 1 | 4 | 7 |
| 6 |   | 2 |
| 3 | 8 | 5 |


## Por que ele é importante?

é um grafo planar
e ele tem um circuito __circuito hamilton lane__, posso passar por todos os vertices e voltar para o primeiro sem repetir
a-->3-->b-->4-->d-->1-->e-->2-->a

## emparelhamento máximo 
quando consegue combinar todos os vertices e não sobra nenhum vertice sem conexão


## Cubo

O cubo com números de gray também é importante
      101----------110
    /   |        /  |
000-----|---010     |
 |      |    |      |
 |     111---|----011
 |   /       |    /
100----------001


* O cubo também tem um circuito Hamiltoniano


# Grafo bi partido não pode ter conexao entre os de cima e os de baixo
