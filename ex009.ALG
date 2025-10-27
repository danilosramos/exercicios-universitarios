Algoritmo "semnome"

Var

c, v, a, b, L: real
q: inteiro

Inicio

escreva ("Digite o valor da compra unitária:")
leia (c)

escreva ("Digite o valor de venda unitária:")
leia(v)

escreva ("Digite a quantidade de produtos:")
leia(q)

a <- c * q
b <- v * q
L <- b - a

se l > 0 entao
escreva ("Seu lucro foi de R$", L)

senão
escreva ("Seu prejuízo foi de R$", L)


fimse
Fimalgoritmo