rm(list=ls())

Fx <- function(x) exp(x)

# Halla la raiz de Fx

Aitken <- function(a,b,c) {

    x<-1
    error<-1
    while (error > 1.e-4) {
        #if (Fx(x) == 0) break
        i<-x
        x<-(b-a)^2/(c-2*b+a)
        a<-b
        b<-c
        c<-x
        error<-abs(i-x)
        cat("X=",x,"\tE=",error,"\n")

    }

}

Aitken(0.6,0.85,0.725)