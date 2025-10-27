Algoritmo "semnome"

Var
 a, b, x: logico

Inicio

escreva ("Fui na aula as 18h? (V/F)")
leia (a)

escreva ("Fui na monitoria as 18h? (V/F)")
leia (b)

x <- a ou b

 se (a = verdadeiro) então
escreva("Foi somente na aula")
fimse

 se (b = verdadeiro) então
escreva("Foi somente na monitoria")
fimse

 se (x = falso) então
escreva("Não foi nem na aula nem na monitoria")
fimse

Fimalgoritmo