library(utils)
library(datasets)
library(ggplot2)
data("")
setwd("D:/Documentos/proyecto")  
df1=read.table("CLineal.txt", header = TRUE)
df2=read.table("CCuadratica.txt", header = TRUE)
df3=read.table("CExponencial.txt", header = TRUE)
df4=read.table("CLinealLogaritmica.txt", header = TRUE)
df5=read.table("CContinua.txt", header = TRUE)
ggplot()+
  geom_line(data=(df1*10000), mapping = aes(x=x, y = y),color="blue")+
  geom_line(data=(df2*10000), mapping = aes(x=x, y = y),color="red")+
  geom_line(data=(df3*9500), mapping = aes(x=x, y = y),color="yellow")+
  geom_line(data=(df4*9300), mapping = aes(x=x, y = y),color="green")+
  geom_line(data=(df5), mapping = aes(x=x, y = y),color="pink")+
  labs(x="N de datos", y="Tiempo de Ejecucion")


