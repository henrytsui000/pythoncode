#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<((int)n);i++)
#define IOS ios_base::sync_with_stdio(0); cin.tie(0)
#define endl '\n'
#define sz(n) ((int)n.size())
#define int long long

const int N = 2000010;
const int sw = 100000;
const int maxn = 1e5+5;
const double pi=acos(-1.0);
struct node{
    double x,y;
    node (double xx=0,double yy=0){
        x=xx;y=yy;
    }
};
node a[N],b[N],omega[N],a_omega[N];
int n,m,fn,num[N];
int al[maxn],ar[maxn],amid[maxn],tar[maxn];

node operator +(const node &a,const node &b){return node (a.x+b.x,a.y+b.y);}
node operator -(const node &a,const node &b){return node (a.x-b.x,a.y-b.y);}
node operator *(const node &a,const node &b){return node (a.x*b.x-a.y*b.y,a.x*b.y+a.y*b.x);}

void init(int n){
    rep(i,n){
        omega[i]=node(cos(2.0*pi*i/n),sin(2.0*pi*i/n));
        a_omega[i]=node(cos(2.0*pi*i/n),-sin(2.0*pi*i/n));
    }
}

void gogo_power_ranger(){
    memset(al,0,sizeof(al));
    rep(i,sw)
        ar[i]=9;
    tar[sw*2]=2;
}

void fndmid(){
    rep(i,maxn)
        amid[i] = ar[i]+al[i];
    for(int i=maxn-1;i>=0;i++){
        if(amid[i]%2&&i!=0)
            amid[i-1]+=10;
        amid[i]/=2;
    }
}

void FFT(int n,node *a,node *w){
    int i,j=0,k;
    rep(i,n){
        if (i>j) swap(a[i],a[j]);
        for (int l=n>>1;(j^=l)<l;l>>=1);
    }
    for (i=2;i<=n;i<<=1){
        int m=i>>1;
        for (j=0;j<n;j+=i)
            rep(k,m){
                node z=a[j+k+m]*w[n/i*k];
                a[j+k+m]=a[j+k]-z;
                a[j+k]=a[j+k]+z;
            }
    }
}

void check_omega(){
	cout<<"---line---"<<endl;
	cout<<"omega:"<<endl;
	rep(i,fn){
	   	if(omega[i].x<0.00001&&omega[i].x>-0.00001)
	   		cout<<"("<<0<<',';
	    else cout<<"("<<omega[i].x<<',';
		if(omega[i].y<0.00001&&omega[i].y>-0.00001)
			cout<<0<<"),";
		else cout<<omega[i].y<<"),"; 
	}
	cout<<endl<<"END_omega"<<endl<<"a_omega:"<<endl;
	rep(i,fn){
	   	if(a_omega[i].x<0.00001&&a_omega[i].x>-0.00001)
	   		cout<<"("<<0<<',';
	    else cout<<"("<<a_omega[i].x<<',';
		if(a_omega[i].y<0.00001&&a_omega[i].y>-0.00001)
			cout<<0<<"),";
		else cout<<a_omega[i].y<<"),"; 
	}
    cout<<endl;
	cout<<"END a_omega"<<endl;
	cout<<"---line---"<<endl;
}

int cal(){

    memset(a,0,sizeof(a));
    memset(num,0,sizeof(num));
    memset(omega,0,sizeof(omega));
    memset(a_omega,0,sizeof(a_omega));

    n=sw;
    rep(i,n)
        a[i].x=(double)(amid[i]);
    fn=1;
    while(fn<=2*n) fn<<=1;
    init(fn);
    cout<<fn<<endl;
    FFT(fn,a,omega);
    rep(i,fn+1)
        a[i]=a[i]*a[i];    
    FFT(fn,a,a_omega);
    rep(i,fn+1)
        num[i]=(int)(a[i].x/fn+0.5);
    rep(i,fn+1){
        num[i+1]+=num[i]/10;
        num[i]%=10;
    }
    // int len=2*sw+1;
    // while (num[len]==0)
    //     len--;
    // for(int i=len;i>=0;i--)
    //     cout<<num[i];
    // cout<<endl;
    return 0;
}

bool count(){
    for(int i=sw;i>=0;i--)
        if(num[i]>tar[i])
            return false;
    return true;
}

bool escape(){
    rep(i,maxn-1)
        if(al[i+1]!=ar[i+1])
            return false;
    if(al[0]!=ar[0]+1)
        return false;
    return true;
}

void solve(){
    amid[sw-1]=1;
    while(!escape()){
        fndmid();
        cal();  
        if(count())
            rep(i,sw) al[i]=amid[i];
        else
            rep(i,sw) al[i]=amid[i];
    }
    for(int i=sw-1;i>=0;i--) 
        cout<<amid[i];
    cout<<endl;
}

int32_t main(){
    solve();
    return 0;
}

/*
123 * 45

fn = 4

04000
01300
00220
00015
-----
05535
*/