#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fr(i,k,n) for(ll i = k;i<n;i++)
#define mo map<ll,ll> 
vector<ll> ms[2*100000+2];
ll above[2*100000+1][20];
ll level[2*100000+1];
ll as = 0;
 
void dfs(ll src ,ll parent,ll as){
	level[src] = as;
	if(above[src][0] == -1){
		above[src][0] = parent;
	}
	
	ll q = above[src][0];
	for(ll i = 1;i<=19;i++){
		if(q != -1){
			q = above[q][i-1];
		}
		if(above[src][i] == -1){
			above[src][i] = q;
		}
		
	}
	for(ll j = 0;j<=19;j++){
		if(above[src][j] == 0){
			above[src][j] = -1;
		}
	}
	above[src][0] = parent;
	for(ll child:ms[src]){
		if(child != parent){
			dfs(child,src,as+1);
		}
	}
}
 
pair<ll,ll> lift(ll nodea,ll nodeb){
	
	for(ll i = 19;i>=0;i--){
		if(above[nodea][i] != above[nodeb][i]){
			nodea = above[nodea][i];
			nodeb = above[nodeb][i];
		}
	}
	return {nodea,nodeb};
}
 
ll search(ll src,ll no){
	if(no<0){
		return -1;
	}
	if(no == 0){
		return (src == 0)?-1:src;
	}
	if(src <=0){
		return -1;
	}
//	cout<<src<<" "<<no<<"\n";
	ll ns;
	ll uo;
	for(ll i = 19;i>=0;i--){
		 uo = (1<<i);
		
		if(uo<=no){
			
				 ns = no - uo;
				 uo = i;
				return  search(above[src][uo],ns);
				 
		}
	
		
		
		
	}
	return 0;
//	cout<<ns<<"\n";
	
}
 
int main(){
	 ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,q;
    cin>>n>>q;
    ll x;
    fr(i,2,n+1){
    	cin>>x;
    	ms[i].push_back(x);
    	ms[x].push_back(i);
    }    
    
    ll a,b;
    for(ll i = 0;i<=n;i++){
    	for(ll j = 0;j<=19;j++){
    		above[i][j] = -1;
    	}
    }
    dfs(1,0,as);
  //  cout<<above[4][1]<<"\n";
//    cout<<level[4]<<" "<<level[5]<<"\n";
    fr(i,0,q){
    	cin>>a>>b;
    	if(level[a]>level[b]){
    		swap(a,b);
    		
    	}
//    	cout<<level[a]<<" "<<level[b]<<" "<<a<<" "<<b<<"\n";
    	if(level[a] == level[b]){
    		if(a == b){
    			cout<<a<<"\n";
    		}
    		else{
    			pair<ll,ll> pe = lift(a,b);
    					cout<<above[pe.first][0]<<"\n";
    		}
    		//
    	//	cout<<a<<" "<<b<<"\n";
    
    	}
    	
    	else{
    		ll k = level[b]-level[a];
    		 b = search(b,k);
    		
    		 if(b == a){
    		 	cout<<b<<"\n";
    		 }
    		 else{
    		 	pair<ll,ll> pe = lift(a,b);
    		 	cout<<above[pe.first][0]<<"\n";
    		 }
    		
    	}
    	
    }
}