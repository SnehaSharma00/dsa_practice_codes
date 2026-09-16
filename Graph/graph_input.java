import java.util.*;

public class graph_input{
    public static void main(String[] args){
        int V =5;
        int [][] edges = {
            {0,1}, 
            {0,2},
            {1,3},
            {2,4}
        };

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i=0; i<V;i++){
            adj.add(new ArrayList<>());

        }
        for(int[] edge : edges){
            int u = edge[0];
            int v = edge[1];

            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        
        for(int i=0; i<V; i++){
            System.out.println(i+ "->" +adj.get(i));
        }
    }
}