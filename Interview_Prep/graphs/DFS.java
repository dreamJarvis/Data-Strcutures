import java.io.*;
import java.util.*;

public class DFS {
    private int V;                          // number  of vertices
    private LinkedList<Integer> adj[];       // Array of lists for adjacency list representation

    // Constructor
    DFS(int v){
        V = v;
        adj = new LinkedList[v];
        for(int i=0; i < v; i++)
            adj[i] = new LinkedList();
    }


    // to add edge in the graph
    void addEdge(int v, int w){
        adj[v].add(w);
    }

    // a function used by DFS
    void DFSUtil(int v, boolean visited[]){
        // Mark the current node as visited and print it
        visited[v] = true;

        Iterator<Integer> i = adj[v].listIterator();
        while(i.hasNext()){
            int n = i.next();
            if(!visited[n])
                DFSUtil(n, visited);
        }
    }

    // to do DFS traversal. uses recursive DFSUtil
    void DFSTraversal(int v){
        boolean visited[] = new boolean[V];     // mark all the vertices not visited(set as false by default)
        DFSUtil(v, visited);                    // call the recursion helper to print DFS traversal
    }

    public static void main(String[] args) {
        DFS g = new DFS(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 21);
        g.addEdge(2, 0);
        g.addEdge(2, 3);
        g.addEdge(3, 3);

        System.out.println("DFS traversal : ");

        g.DFSTraversal(2);
    }
}
