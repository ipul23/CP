#include <bits/stdc++.h>
using namespace std;

#define MAX 240005 // Why? :D
#define inf 0x7fffffff

int arr[240005],arr1[240005];
int tree[MAX],tree1[MAX];
int lazy[MAX],lazy1[MAX];

/**
 * Build and init tree
 */

void build_tree(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree[node] = arr[a]; // Init value
		return;
	}

	build_tree(node*2, a, (a+b)/2); // Init left child
	build_tree(node*2+1, 1+(a+b)/2, b); // Init right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree(int node, int a, int b, int i, int j, int value) {

  	if(lazy[node] != 0) { // This node needs to be updated
   		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
    			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

   		lazy[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree[node] += value;

		if(a != b) { // Not leaf node
			lazy[node*2] += value;
			lazy[node*2+1] += value;
		}

    		return;
	}

	update_tree(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree[node] = max(tree[node*2], tree[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return -inf; // Out of range

	if(lazy[node] != 0) { // This node needs to be updated
		tree[node] += lazy[node]; // Update it

		if(a != b) {
			lazy[node*2] += lazy[node]; // Mark child as lazy
			lazy[node*2+1] += lazy[node]; // Mark child as lazy
		}

		lazy[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree[node];

	int q1 = query_tree(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = max(q1, q2); // Return final result

	return res;
}

/**
 * Build and init tree
 */
void build_tree1(int node, int a, int b) {
  	if(a > b) return; // Out of range

  	if(a == b) { // Leaf node
    		tree1[node] = arr[a]; // Init value
		return;
	}

	build_tree1(node*2, a, (a+b)/2); // Init left child
	build_tree1(node*2+1, 1+(a+b)/2, b); // Init right child

	tree1[node] = min(tree1[node*2], tree1[node*2+1]); // Init root value
}

/**
 * Increment elements within range [i, j] with value value
 */
void update_tree1(int node, int a, int b, int i, int j, int value) {

  	if(lazy1[node] != 0) { // This node needs to be updated
   		tree1[node] += lazy1[node]; // Update it

		if(a != b) {
                lazy1[node*2] += lazy1[node]; // Mark child as lazy
    			lazy1[node*2+1] += lazy1[node]; // Mark child as lazy
		}

   		lazy1[node] = 0; // Reset it
  	}

	if(a > b || a > j || b < i) // Current segment is not within range [i, j]
		return;

  	if(a >= i && b <= j) { // Segment is fully within range
    		tree1[node] += value;

		if(a != b) { // Not leaf node
			lazy1[node*2] += value;
			lazy1[node*2+1] += value;
		}

    		return;
	}

	update_tree1(node*2, a, (a+b)/2, i, j, value); // Updating left child
	update_tree1(1+node*2, 1+(a+b)/2, b, i, j, value); // Updating right child

	tree1[node] = min(tree1[node*2], tree1[node*2+1]); // Updating root with max value
}

/**
 * Query tree to get max element value within range [i, j]
 */
int query_tree1(int node, int a, int b, int i, int j) {

	if(a > b || a > j || b < i) return 2000000000; // Out of range

	if(lazy1[node] != 0) { // This node needs to be updated
		tree1[node] += lazy1[node]; // Update it

		if(a != b) {
			lazy1[node*2] += lazy1[node]; // Mark child as lazy
			lazy1[node*2+1] += lazy1[node]; // Mark child as lazy
		}

		lazy1[node] = 0; // Reset it
	}

	if(a >= i && b <= j) // Current segment is totally within range [i, j]
		return tree1[node];

	int q1 = query_tree1(node*2, a, (a+b)/2, i, j); // Query left child
	int q2 = query_tree1(1+node*2, 1+(a+b)/2, b, i, j); // Query right child

	int res = min(q1, q2); // Return final result

	return res;
}
int main() {
  int testcase,data[60000],q,temp1,temp2,a,b,c,N,i;
  scanf("%d",&testcase);
    for (int j=1; j<=testcase; j++){
    printf("Case #%d:\n",j);
    scanf("%d %d", &N,&q);
    for (int i = 0; i < N; ++i) {
        scanf("%d", &data[i]);
        if (i>0){
            arr[i-1]=data[i]-data[i-1];
        }
    }
    --N;
    build_tree(1,0,N-1);
    build_tree1(1,0,N-1);
    memset(lazy,0,sizeof(lazy));
    memset(lazy1,0,sizeof(lazy1));
    for (int i=0; i<q; i++){
        scanf("%d %d %d",&a,&b,&c);
        if (a==1){
           data[b-1]=c;
           update_tree(1, 0, N-1, b-2, b-2, (data[b-1]-data[b-2])-arr[b-2]);
           update_tree(1, 0, N-1, b-1, b-1, (data[b]-data[b-1])-arr[b-1]);
           update_tree1(1, 0, N-1, b-2, b-2, (data[b-1]-data[b-2])-arr[b-2]);
           update_tree1(1, 0, N-1, b-1, b-1, (data[b]-data[b-1])-arr[b-1]);
           arr[b-2]=(data[b-1]-data[b-2]);
           arr[b-1]=(data[b]-data[b-1]);
        } else{
            int maxz=query_tree(1, 0, N-1, b-1, c-2);
            int minz=query_tree1(1, 0, N-1, b-1, c-2);
            if (b==c) printf("YES\n");
            else
            if (maxz==minz) printf("YES\n");
            else printf("NO\n");
        }
    }
  }
  return 0;
}
