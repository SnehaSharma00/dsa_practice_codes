import java.util.*;

public class Main {

    static void dfs(ArrayList<ArrayList<Integer>> adj,
                    int[] vis, int node) {

        vis[node] = 1;
        System.out.print(node + " ");

        for(int neighbour : adj.get(node)) {

            if(vis[neighbour] == 0) {
                dfs(adj, vis, neighbour);
            }
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        for(int i = 0; i < m; i++) {

            int u = sc.nextInt();
            int v = sc.nextInt();

            adj.get(u).add(v);
            adj.get(v).add(u);
        }
        int[] vis = new int[n + 1];

        dfs(adj, vis, 1);
    }
}