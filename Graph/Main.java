//graph bfs in java

import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int m = sc.nextInt();

        // Adjacency list
        ArrayList<ArrayList<Integer>> adj = new ArrayList<>();

        for(int i = 0; i <= n; i++) {
            adj.add(new ArrayList<>());
        }

        // Take m edges
        for(int i = 0; i < m; i++) {

            int u = sc.nextInt();
            int v = sc.nextInt();

            adj.get(u).add(v);
            adj.get(v).add(u);
        }

        int[] vis = new int[n + 1];

        Queue<Integer> q = new LinkedList<>();

        q.add(1);
        vis[1] = 1;

        while(!q.isEmpty()) {

            int node = q.poll();

            System.out.print(node + " ");

            for(int i = 0; i < adj.get(node).size(); i++) {

                int neighbour = adj.get(node).get(i);

                if(vis[neighbour] == 0) {

                    vis[neighbour] = 1;
                    q.add(neighbour);
                }
            }
        }
    }
}