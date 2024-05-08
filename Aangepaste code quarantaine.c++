% infectiemodel Voit met quarantaine van 10% van de mensen

function infectie = f(c,t);

% parameters

rb = 3;

rs = 0.01;

ri = 0.0005;

rr = 0.05;

rd = 0.02;

rq = 0.1;

% gezonde mensen

infectie(1) = rb+rs*c(3)-ri*c(1)*c(2);

%geinfecteerde mensen

infectie(2) = ri*c(1)*c(2)-rr*c(2)-rd*c(2)-rq*c(2);

%resistente mensen

infectie(3) = rr*c(2)-rs*c(3);

endfunction

stap = 200

eind = 100

t = linspace(0,eind,stap);

c0=[450;10;500]; % S,I,R

y = lsode("f",c0,t);

plot(t,y);

plot(t,y(1: 200),"b-",t,y(1: 200,2),"r--",t,y(1: 200,3),"g-.")

xlabel ("tijd")

ylabel("aantal")

legend("Susceptible","Infected","Resistent")
