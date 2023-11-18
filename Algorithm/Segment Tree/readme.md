## 세그트리 0인덱스와 1인덱스 다른점

- seg.update() 부분
```c++
// 0-index
void update(int idx, ll x) {
  tree[idx += sz] = x;
  while (idx /= 2) tree[idx] = merge(tree[2*idx], tree[2*idx+1]);
}

// 1-index
void update(int idx, ll x) {
  tree[idx += sz-1] = x;
  while (idx /= 2) tree[idx] = merge(tree[2*idx], tree[2*idx+1]);
}
``` 
seg.tree[sz]에 0-인덱스는 인덱스 0에 해당하는 원소가 들어가야 함.  
seg.tree[sz]에 1-인덱스는 인덱스 1에 해당하는 원소가 들어가야 함.  

<br>

- seg.query() 부분
```c++
// 0-index
ll query(int l, int r, int n=1, int nl=0, int nr=sz-1) {
  if (nr<l || r<nl) return 0;
  if (l<=nl && nr<=r) return tree[n];
  
  int mid = (nl + nr) / 2;
  return merge(query(l, r, 2*n, nl, mid), query(l, r, 2*n+1, mid+1, nr));
}

// 1-index
ll query(int l, int r, int n=1, int nl=1, int nr=sz) {
  if (nr<l || r<nl) return 0;
  if (l<=nl && nr<=r) return tree[n];
  
  int mid = (nl + nr) / 2;
  return merge(query(l, r, 2*n, nl, mid), query(l, r, 2*n+1, mid+1, nr));
}
```
0-인덱스는 n=1인 루트노드에 해당하는 구간이 [0, n-1]으로 대응함.  
1-인덱스는 n=1인 루트노드에 해당하는 구간이 [1, n]으로 대응함.  

