#include<bits/stdc++.h>
using namespace std;
const double eps=1e-8;
double ax,ay,bx,by,cx,cy,dx,dy,p,q,r;
double Getdis(double _x1,double _y1,double _x2,double _y2){
    double dx=_x1-_x2,dy=_y1-_y2;
    return sqrt(dx*dx+dy*dy);
}

double Ans(double _x1,double _y1,double _x2,double _y2){
    return Getdis(_x1,_y1,_x2,_y2)/r+Getdis(_x2,_y2,dx,dy)/q;
}
double Calc1(double ex,double ey){
    double nowlx=cx,nowly=cy,nowrx=dx,nowry=dy;
    while(Getdis(nowlx,nowly,nowrx,nowry)>eps){
        double lenx=(nowrx-nowlx)/3,leny=(nowry-nowly)/3;
        double lmidx=nowlx+lenx,rmidx=nowrx-lenx,lmidy=nowly+leny,rmidy=nowry-leny;
        double ans1=Ans(ex,ey,lmidx,lmidy),ans2=Ans(ex,ey,rmidx,rmidy);
        if(ans2-ans1>eps) nowrx=rmidx,nowry=rmidy;
        else nowlx=lmidx,nowly=lmidy;
    }
    return Ans(ex,ey,nowlx,nowly);
}
double Calc(){
    double nowlx=ax,nowly=ay,nowrx=bx,nowry=by;
    while(Getdis(nowlx,nowly,nowrx,nowry)>eps){
        double lenx=(nowrx-nowlx)/3,leny=(nowry-nowly)/3;
        double lmidx=nowlx+lenx,rmidx=nowrx-lenx,lmidy=nowly+leny,rmidy=nowry-leny;
        double ans1=Calc1(lmidx,lmidy)+Getdis(lmidx,lmidy,ax,ay)/p,ans2=Calc1(rmidx,rmidy)+Getdis(rmidx,rmidy,ax,ay)/p;
        if(ans2-ans1>eps)   nowrx=rmidx,nowry=rmidy;
        else nowlx=lmidx,nowly=lmidy;
    }
    return Calc1(nowlx,nowly)+Getdis(nowlx,nowly,ax,ay)/p;
}
int main(){
    scanf("%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf%lf",&ax,&ay,&bx,&by,&cx,&cy,&dx,&dy,&p,&q,&r);
    // puts("????");
    printf("%.2lf\n",Calc());
    return 0;
}
