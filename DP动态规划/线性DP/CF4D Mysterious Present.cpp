#include<bits/stdc++.h>
using namespace std;
const int MAX=5005;
int n,w,h;
int f[MAX];
int back[MAX];

struct Node{
    int w,h,x;
    #define w(i)    a[i].w
    #define h(i)    a[i].h
    bool operator < ( const Node & a ) const{
       if ( w == a.w ) return h < a.h;
        return w < a.w;
    }
}a[MAX];

void print ( int x ){
    if ( a[x]. w <= w || a[x].h <= h ) return;
    print ( back[x] );
    printf ( "%d " , a[x].x );
}

int main ( ){
    while ( ~scanf ( "%d%d%d" , &n , &w , &h )){
        for ( int i = 1 ; i <= n ; i++ ){
            scanf ( "%d%d" , &w(i) , &h(i) );
            a[i].x = i;
        }
        f[0] = -1;
        sort ( a+1 , a+n+1 );
        for ( int i = 1 ; i <= n ; i++ ){
            int tmp = -1,id = 0;
            for ( int j = 0 ; j < i ; j++ )
                if ( w(j) < w(i) && h(j) < h(i) && w(j) > w && h(j) > h )
                    if ( tmp < f[j] ){
                        tmp = f[j];
                        id = j;
                    }
            if ( w(i) > w && h(i) > h ) f[i] = 1 , back[i] = 0;
            else f[i] = -1;
            if ( tmp+1 > f[i] ){
                f[i] = tmp+1;
                back[i] = id;
            }
        }
        int maxn = 0;
        for ( int i = 1 ; i <= n ; i++ )
            maxn = max ( maxn , f[i] );
        if ( maxn == 0 ){
            puts ( "0" );
            continue;
        }
        printf ( "%d\n" , maxn );
        for ( int i = 1 ; i <= n ; i++ )
            if ( maxn == f[i] ){
                print ( i );
                puts ("");
                break;
            }
    }
}
