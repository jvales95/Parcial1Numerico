rm (list=ls())

Fx <- function(x) log(x+2) - sin(x)
F1x <- function(x) (1/(x+2)) + cos(x)
F2x <- function(x) -1/(2 + x)^2 - sin(x)
newton <- function(x0,E) {
	
	x <- x0
	while (abs(Fx(x)) > E) {
        
		x <- x - Fx(x)*F1x(x)/(F2x(x)^2 - Fx(x)*F2x(x))
        cat("X=",x,"\t","E=",E,"\n")
	}
	
}
newton(2,10e-5)