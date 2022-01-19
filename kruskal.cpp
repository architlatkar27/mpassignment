/**
 *    author:  abhishekvtangod
 *    created:        
**/

#include<bits/stdc++.h>
#include<chrono>
using namespace std; 

#define mod 1000000007
#define gcd(a,b) __gcd(a,b)
#define lcm(a,b) (a*b)/gcd(a,b)
#define bits(x) __builtin_popcountll(x)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl "\n"

typedef long long int ll;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using oset=tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// oset<pair<ll,ll>> indexed_set;

// struct HASH{
//   size_t operator()(const pair<int,int>&x)const{
//     return hash<long long>()(((long long)x.first)^(((long long)x.second)<<32));
//   }
// };

int n;
vector<tuple<int , int ,int>> tp;
vector<tuple<int , int ,int>> result;
//w,u,v}
vector<int> tree_id;




void solve()
{
	int n,e;cin>>n>>e;	//total vertices and edges
	tree_id.resize(n);
	for(int i=0;i<n;i++){
		tree_id[i]=i;
	}

	for(int i=0;i<e;i++){
		int u,v,w;
		cin>>u>>v>>w;
		tp.push_back({w,u,v});
	}
	sort(tp.begin(),tp.end());

	// for(auto i:tp){
	// 	int u,v,w;
	// 	tie(w,u,v) = i;
	// 	cout<<u<<" "<<v<<" "<<w<<" "<<endl;
	// }
    auto start = chrono::high_resolution_clock::now();
	int cost = 0;
	for(auto it:tp){
		int u,v,w;
		tie(w,u,v) = it;
		if(tree_id[u] == tree_id[v]){
			continue;
		}
		cost += w;
		result.push_back(it);

		int old_id = u,new_id = v;
		for(int i =0;i<n;i++){
			if(tree_id[i]==old_id){
				tree_id[i]=new_id;
			}
		}
	}
    auto stop = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start);
	cout<<"execution time in microseconds: "<<duration.count()<<endl;
    cout<<"Cost : "<<cost<<endl;
	cout<<"Tree : "<< endl;
	for(auto it:result){
		int u,v,w;
		tie(w,u,v) = it;
		cout<<u<<" "<<v<<" "<<w<<endl;
	}

}


int main()
{   
    IOS;

	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif



		solve();

	

    return 0;
}