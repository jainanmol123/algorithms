/**
* Quick-union (lazy approach) class for dealing with dynamic connectivity. 
* Array indexes represent objects. 
*/

public class QuickUnionUF{
    
    /**
    * Index represents object, value represents root.
    * If two objects share root (directly or indirectly, they don't need to have 
    * the same value), they are connected.
    */
    private int[] id;
    
    /**
    * Creates the array and sets ID of each object to itself (N array accesses).
    * @param N Number of objects to be created. 
    */
    public QuickUnionUF(int N){
        id = new int[N];
        for (int i = 0; i < N; i++){
            id[i] = i;
        }
    }
    
    /**
    * Chase parent pointers until reach root (depth of i array accesses).
    * @param i Object that will be searched for its root.
    */
    private int root(int i){
        while (i != id[i]){
            i = id[i];
        }
        return i;
    }
    
    /**
    * Check if p and q have same root (depth of p and q array accesses).
    * @param p An object (array index).
    * @param q An object (array index).
    * @return True of objects are connected, false if they aren't.
    */
    public boolean connected(int p, int q){
        return root(p) == root(q);
    }
    
    /**
    * Change root of p to point to root of 1 (depth of p and q array accesses).
    * @param p The object that will change its root to q's root.
    * @param q The object that will share its root with p.
    */
    public void void union(int p, int q){
        int i = root(p);
        int j = root(q);
        id[i] = j;
    }
}