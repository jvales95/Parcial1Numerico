rm (list=ls())

Fx <- function(x) log(x+2)+sin(x)
#Se tiene f= ln(x+2) + sin x, ya que es la interseccion de las dos funciones solicitados
F1x <- function(x) log(x+2)+sin(x) 
#Metodo de la Secante
#Halla la raiz de Fx

error <- 1E-7
   
secante <- function(x0,x1) {
    x<-(Fx(x1)*x0-Fx(x0)*x1)/(Fx(x1)-Fx(x0))
    error <- 1
    while (error > 1.e-4) {
        x0<-x1
        x1<-x
        x<-(Fx(x1)*x0-Fx(x0)*x1)/(Fx(x1)-Fx(x0))
        if (Fx(x) == 0) break
        error<-abs(Fx(x)/F1x(x))
        cat("X=",x,"\t","E=",error,"\n")
    }
}
secante(0,3)