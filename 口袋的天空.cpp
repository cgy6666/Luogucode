#include <bits/stdc++.h>
using namespace std;
struct node{
	int u,v,w;
}a[200005];
int fa[5005],n,m,cnt,ans,k;
inline int find(int x){return x == fa[x] ? x : fa[x] = find(fa[x]);}
inline bool cmp(node x,node y){return x.w < y.w;}
int main(){
	cin >> n >> m >> k;
	for (register int i = 1;i <= n;i++) fa[i] = i;
	int u,v,w;
	for (register int i = 1;i <= m;i++){
		cin >> u >> v >> w;
		a[i].u = u,a[i].v = v,a[i].w = w;
	}
	sort(a+1,a+m+1,cmp);
	for (register int i = 1;i <= m;i++){
		int nu = find(a[i].u),nv = find(a[i].v);
		if (nu == nv) continue;
		cnt++,fa[nu] = nv,ans += a[i].w;
		if (cnt >= (n-k)) break;
	}
	if (cnt >= (n-k)) cout << ans;
	else cout << "No Answer";
	return 0;
}
