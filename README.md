# Introdução 

Isto é um programa que conta a **quantidade de tempo média** necessária para realizar as seguintes operações:

- Busca sequencial
- Busca binária iterativa
- Busca binária recursiva

A variável `iterations` pode ser alterada para aumentar/diminuir a precisão do medida de tempo.

Após a contagem, o programa gerará relatórios csv contendo o melhor caso, pior caso e casos aleatórios.

## Inicialização

Para iniciar o programa e gerar os relatórios, apenas faça o seguinte comando:

```bash
make build && make run
```
ou
```bash
make all
```

Caso queira uma opção mais visual para análise, você pode também usar:

```bash
make bench
```

que roda o programa, gera os relatórios e cria gráficos sobre cada um deles