########################################################################
# Material fornecido pela Profª. Dra. Flávia Cristina Martins Queiroz Mariano
########################################################################

#### Manipulacao de objetos e funcoes
#Instalacao do R
require(grid)
########################################################################
# pagina do R, onde estao os pacotes, tutoriais e arquivos de instalacao
browseURL(URLencode("http://www.r-project.org/"))
#
########################################################################
# link direto para a pagina de download da versao para Windows
browseURL(URLencode("http://cran.stat.ucla.edu/bin/windows/base/"))
#
#########################################################
# documento com instrucoes de intalacao e primeiros passos
browseURL(URLencode("http://cran.r-project.org/doc/contrib/Itano-installation.pdf"))
#
#########################################################
# pagina do R Studio, a interface do momento
browseURL(URLencode("http://www.rstudio.org/"))
#
########################################################################
# pagina da [R-br], a lista Brasileira oficial de usuarios do programa R
browseURL(URLencode("http://www.leg.ufpr.br/rbr"))
#
########################################################################
# lista de abreviacoes das funcoes
browseURL(URLencode("http://jeromyanglim.blogspot.com/2010/05/abbreviations-of-r-commands-explained.html"))
#
########################################################################
# blogs/site para consulta sobre R
browseURL(URLencode("http://www.r-bloggers.com/"))


#### Primeiros passos no R: como pedir ajuda
########################################################################
# fazendo a busca do termo
help(mean) # documentacao e apresentada no editor
help(mean, help_type="html") # documentacao e apresentada no navegador de internet
?mean # e o mesmo que help(mean)
########################################################################
# buscando em pacotes o termo
help.search("mean") # faz uma busca ampla do termo, inclusive em pacotes nao carregados
??mean # o mesmo que help.search("mean")

###### Como o R funciona: criacao, atribuicao, acesso e modificacao de objetos

##### Operacoes matematicas fundamentais e mais
########################################################################
1+100 # soma
3-5 # subtracao
2*8 # produto
3/4 # divisao
2^3 # potenciacao, tambem vale 2**3
sqrt(4) # raiz quadrada
log(10) # logartimo natural ln (base e)
log10(3) #log base 10
log2(3) #log base-2
log(30, base=2.2) # logartimo base qualquer
sin(pi)
exp(2)
factorial(3) #fatorial (n!)
choose(3,2) #numero de combinacoes ( n!/x!(n-x)! )
combn(letters[1:4], 2)#todas conjuntos gerados pela combinacoes de certo numero de elementos
#
########################################################################
# criacao de vetores, sequencias logicas e numeros aleatorios
flavia<-c(2,4,7,3,8,9) # um vetor, fun??o c de "concatenar" 
1:7 # uma sequencia regular de passo 1
seq(0, 20, by=2.4) # uma sequencia regular de passo 2.4
seq(0, 20, length=5) # uma sequencia regular de 4 elementos
?seq
help(seq, help_type="html")
rep(1:3, times=3) # repete o vetor todo 3 vezes
rep(1:3, each=3) # repete cada elemento 3 vezes

?rnorm
rnorm(5)
rnorm(5, 3, 2) # numeros aletorios normais media=3 desvio=2
round(rnorm(5, sd=2, mean=3), 2) # o mesmo arredondando com 2 casas
rnorm(5, mean=3, sd=2) # o mesmo
runif(5) # numero aletorios uniformes min=0, max=1
# as operacoes em vetores 
x <- 1:3
x-1
an<-5:7
x+an 
x/3

#O R e uma linguagem orientada a objetos: variaveis, dados, matrizes, funcoes, etc sao armazenados
#na memoria ativa do computador na forma de objetos. Por exemplo, se um objeto x tem o valor 10,
#ao digitarmos o seu nome, o programa exibe o valor do objeto:
x <- 10
x = 10
x

x/c(1:2)
x^2
log(x)

x3<-seq(0,1,by=0.1)
x3

batata<-rep(2,5)
batata
x5<-rep(c("a","b"),each=3)
x5


########################################################################
# matrizes
matrix(c(1,5,38,400), 2, 2) # matriz 2x2
matrix(1:6, 2, 3) # matriz 2x3
matrix(rnorm(9), 3, 3) # matriz 3x3
matrix(c("a","c","b","j"), 2, 2) # matriz 2x2
#
########################################################################
###  estrutura de dados (planilha)

# Um data.frame e semelhante a uma matriz em que as colunas podem ser de tipos 
# diferentes. Os data frames sao objectos usados para guardar tabelas ... Um data.frame e algo 
# muito parecido com uma tabela do Access.
data.frame(A=1:4, B=runif(4), C=letters[1:4])
data.frame(trat=c(1:2,1:2), bloc=rep(1:2, each=2))
expand.grid(cult=c("A","B"), bloc=c("I","II","III"), dose=1:3)


#
########################################################################
# as operacoes com matrizes
m1 <- matrix(1:4, ncol = 2)
m1
m4 <- matrix(1:4, nc = 2)

x <- matrix(1:4, 2, 2)
y <- matrix(4:1, 2, 2)
z <- matrix(1:6, 3, 2)
x*10 # produto por constante
x-4 # subtra??o por uma contante
x+y # soma de matrizes (elementwise)
x*y # produto de elementos (elementwise)
x%*%y # produto de matrizes
x+z
z%*%x
det(x) # determinante
diag(x) # elementos da diagonal
solve(x) # inversa
t(z) # transposta
#
########################################################################
# exemplo de operacoes com matrizes
x <- 0:12 # valores da variavel indendente
y <- x+rnorm(x,0,1) # valores da variavel aleatoria dependente
plot(x, y) # diagrama de dispersao de y em funcao de x
X <- cbind(b0=1, b1=x) # matriz do modelo de regressao linear E(Y|x) = b0+b1*x
X
########################################################################
# Criando listas
list(A=rnorm(4),
     B=matrix(1:4,2,2),
     C=data.frame(a=1:4, b=runif(4), c=letters[1:4]),
     D="Flavia Cristina")

#
########################################################################
#### Atribuicao, acesso e modificacao de tipos de objetos 
########################################################################
# vetores
x <- seq(12, 18, 2); 
x
x[1]
x[2:3]
x<-x[-1]
x[3:4] <- c(20,22);
x
x <- c(x, 40, 89, 132)
x
#
########################################################################
# matrizes
x <- matrix(rnorm(9), 3, 3); 
x
x[1,]
x[,1]
x[2,2]
x[-3,-3]
x[3,1] <- 19; 
x
#
########################################################################
# tabelas de dados
x <- data.frame(A=1:4, B=runif(4), C=letters[1:4]); 
x
x[,1]
x[,"A"]
x[1,2]
x[-3,-3]
x[1,"A"] <- "200"
x$A
#
########################################################################
# digitando dados com edit()
x <- edit(data.frame())
x
#
########################################################################
#### Informacoes sobre objetos (atributos)
########################################################################
# para vetores
v <- c(a=1, b=2, c=3)
v
length(v) # dimensao/comprimento/numero e elementos
class(v) # classe do objeto
names(v) # nome dos elementos
#
########################################################################
# para matrizes
m <- matrix(1:4,2,2)
m
dim(m) # dimensoes
nrow(m) # numero de linhas
ncol(m) # numero de colunas
class(m) # classe do objeto
colnames(m) # nome das colunas
rownames(m) # nome das linhas
colnames(m) <- c("prod","peso") # modifica o nome das colunas
rownames(m) <- c("M","F") # modifica o nome das linhas
colnames(m)
m

########################################################################
# para data.frames 
d <- expand.grid(A=1:2, B=c("A","B"))
dim(d) # dimensoes
nrow(d) # numero de linhas
ncol(d) # numero de colunas
names(d) # nome das colunas
names(d) <- c("trat", "bloc") # modifica o nome das colunas
d
#
########################################################################
# para listas
l <- list(A=rnorm(4), B=matrix(1:4,2,2))
length(l) # numero de elementos/numero de slots/numero de "abas"
class(l) # classe do objeto
names(l) # nome dos elementos/nome dos slots/nome das "abas"
l
#
########################################################################
# como saber praticamente tudo sobre um objeto?
str(v)
str(m)
str(d)
str(l)
ls() # lista os objetos da memoria
#
########################################################################

########################################################################
##### Operacoes estatisticas
########################################################################
# em vetores
x <- rnorm(1000, 80, 3) # valores realizados de uma distribuicao normal
mean(x) # media (average)
sum(x) # soma
var(x) # variancia amostral (denominador n-1)
sd(x) # desvio padrao amostral (denominador n-1)
median(x) # mediana
max(x) # maximo
min(x) # minimo
range(x) # extremos
diff(range(x)) # amplitude
summary(x) # resumo: extremos, media, q1, q2 e q3 (quartis) 
IQR(x) # distancia interquatilica
quantile(x) # quantis/percentis
plot(x) # diagrama de dispersao, valores ~ ordem
hist(x) # histograma/distribuicao de frequencias
# ver pacote fBasics para mais funcoes de analise descritiva
#
########################################################################
# operacoes em matrizes para obter quantidades marginais em linhas e colunas
x <- matrix(rnorm(20), 4, 5)
mean(x) # media entre todos os elementos
sd(x) # desvio-padrao entre todos os elementos
colSums(x) # soma por colunas
rowMeans(x) # media por linhas
apply(x, MARGIN=1, FUN=var) # variancia marginal nas linhas
apply(x, 2, median) # mediana marginal nas colunas
apply(x,2, FUN=sd) # vetor de desvios-padroes amostrais por coluna
var(x) # matriz de covariancia amostral 
cor(x) # matriz de correlacao amostral

#
########################################################################
#Entrando com dados diretamente no R
########################################################################

#Tipos de variaveis
#Qualitativa
Est_Civil<-c("casado","solteiro","casado","casado","solteiro","casado","solteiro","casado","casado","solteiro")
Est_Civil

#Quantitativa discreta
quantd<-c(2,2,3,4,5,4,5,6,5,4)
quantd

# funcao scan() ? conveniente para digitar vetores longos
y <- scan() #usuario digita cada dado seguido de enter
y

#Quantitativa continua
Salario<-c(4.00, 4.56, 5.25, 5.73, 6.26, 6.66, 6.86, 7.39, 7.59, 7.44, 8.12, 8.46, 8.74, 8.95, 9.13, 9.35, 9.77, 9.80, 10.53,
           10.76, 11.06, 11.59, 12.00, 12.79, 13.23, 13.60, 13.85, 14.69, 14.71, 15.99, 16.22, 16.61, 17.26, 18.75, 19.40, 23.30)
Salario

###### Importando dados
########################################################################
# como importar/ler dados?
apropos("read") # retorna as funcoes que possuem o termo "read" no nome
#
########################################################################
# onde os dados devem estar?
getwd() # o seu diretorio de trabalho atual
setwd("E:/Aula6e7_IntroducaoR/aula1_Fla") # alterar o seu diretorio de trabalho
#
########################################################################
# importando dados
ex01 <- read.table("empresaMB.txt") #Lendo dados de um arquivo texto
ex02<-read.csv("C:/Users/jonatas/Desktop/PROB_e_EST_Flavia/Aula6e7_IntroducaoR/aula_Fla/empresaMB.csv",header=T, sep=",")  #Separa??o decimal com ponto
ex02
ex03<-read.csv2("C:/Users/jonatas/Desktop/PROB_e_EST_Flavia/Aula6e7_IntroducaoR/aula_Fla/empresaMB.csv",header=T,sep=";") #Separa??o decimal com v?rgula
ex03

class(ex03) # classe do objeto
names(ex03) # nomes das colunas
dim(ex03) # dimensoes
str(ex03) # estrutura
head(ex03) # cabecalho, o default mostra as 6 primeiras linhas
ex03 # todos os registros (ter cuidado quando a base for grande)


#Analise descritiva
# Distribuicao de frequencias - Variavel Qualitativa
ex03$est_civil
names(ex03)
colnames(ex03)<-c("n","est_civil","instrucao","filhos","salario", "ano","mes","regiao")
names(ex03)
ex03$est_civil

#Frequencia absoluta
fabs<-table(ex03$est_civil)
fabs
#Frequencia relativa
fr<-prop.table(fabs)
fr
#Frequencia acumulada
facum<-cumsum(fr)
facum
#Montando a tabela
Tabela<-cbind(fabs,fr,facum,por=100*fr)
Tabela

#######
#Distribuicao de frequencias - Variavel quantitativa discreta
#Frequencia absoluta
fa<-table(ex03$filhos)
fa

#Frequencia relativa
fr<-prop.table(table(ex03$filhos))
fr

#Frequencia acumulada
fac<-cumsum(prop.table(table(ex03$filhos)))

#Montando a tabela
Tabela<-cbind(fa,fr,fac,por=100*fr)
Tabela

########
#Distribuicao de frequencia - Variavel quantitativa continua
#Frequencia absoluta
fabs2<-table(ex03$salario)
fabs2

#Frequencia relativa
fr2<-prop.table(table(ex03$salario))

#Frequencia acumulada
facum2<-cumsum(prop.table(table(ex03$salario)))

#Montando a tabela
Tabela<-cbind(fabs2,fr2,facum2,por=100*fr2)
Tabela

range(ex03$salario)
nclass.Sturges(ex03$salario) # k = 1 + 3,322(log10 n) - Sturges'formula
fa.classe <- table(cut(ex03$salario, seq(4, 23.30, l = 7)))
fa.classe
fa.classe <- table(cut(ex03$salario, seq(3.9, 23.30, l = 7)))
fa.classe
fr.classe<- prop.table(fa.classe)
Tabela<-cbind(fa.classe,fr.classe)
Tabela

#Tabelas de contingencia
table(ex03$est_civil,ex03$filho)

#########################
#Graficos
demo(graphics)

#Grafico em barras
par(mfrow=c(1,2))
barplot(table(ex03$filho),main="Numero de filhos")
?barplot
barplot(table(ex03$filho),main="Numero de filhos", col="red",
xlab="Numero de filhos", ylab="Frequencia absoluta")
box()

#Grafico Composicao em setores (pizza)
pie(table(ex03$instrucao), main="Pizza")
pie(table(ex03$instrucao), main="Pizza",
    col = c("purple", "violetred1", "green3",
         "cornsilk", "cyan", "white"))
pie(table(ex03$instrucao), main="Pizza",
        col = c("cornsilk", "cyan", "white"))
legend("topleft", legend=names(table(ex03$instrucao)), fill = c("cornsilk", "cyan", "white"))        

par(mfrow=c(1,1))
Pizza=pie(table(ex03$instrucao), main="Pizza",
    col = c("cornsilk", "cyan", "white"))
legend("topleft", legend=names(table(ex03$instrucao)), fill = c("cornsilk", "cyan", "white"))        
box()
?pie

#Ramo e folhas
stem(ex03$salario)
stem(ex03$salario,2)

#Histograma
hist(ex03$salario)
hist(ex03$salario,nclass=5)
hist(ex03$salario,nclass=5, col="orange", main="Tempo de atendimento", freq=F)

#Grafico de quantis
boxplot(ex03$salario)

####### Medidas resumo
mean(ex03$salario)
median(ex03$salario)
quantile(ex03$salario)
var(ex03$salario)
sd(ex03$salario)
summary(ex03$salario)
IQR(ex03$salario)


## Variancia populacional
varp<-sum((ex03$salario - mean(ex03$salario))^2/(length(ex03$salario)))
varp

mean(ex03$filho, na.rm = T)


###Salvando arquivos no R
write.table(Tabela, file="Tabela.txt")

##
pdf(file="mygraph.pdf")
barplot(table(ex03$filho),main="Numero de filhos", col="red",
        xlab="Numero de filhos", ylab="Frequencia absoluta")
box()
dev.off()
##
