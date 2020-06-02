package HomeWork_Algorithm;

import java.util.Arrays;
import java.util.Iterator;
import java.util.LinkedList;

public class Project_8 {

    private int V;
    private LinkedList<Integer> adj[];
    private String[] colors = new String[]{"Blue", "Brown", "Green", "Lavander", "Orange", "Pink", "Red", "Yellow", "Violet", "Gold", "Gray", "Indigo", "Silver"};

    private String[] countries = new String[]{"DDD", "Ecuador", "Columbia", "Peru", "Venezuela", "Bolivia", "Chile", "Guyana", "Brazil", "Paraguay", "Argetina", "Suriname", "French", "Urugway"};



    Project_8(int v) {
        V = v;
        adj = new LinkedList[v];
        for (int i = 0; i < v; ++i)
            adj[i] = new LinkedList();
    }

    void addEdge(int v, int w) {
        adj[v].add(w);
        adj[w].add(v); // 无向图（ undirected）
    }

    void BFSColoring() {

        int result[] = new int[V];

        Arrays.fill(result, -1);

        result[0] = 0;

        boolean available[] = new boolean[V];

        Arrays.fill(available, true);

        for (int u = 1; u < V; u++) {

            Iterator<Integer> it = adj[u].iterator();

            while (it.hasNext()) {

                int i = it.next();

                if (result[i] != -1) available[result[i]] = false;
            }

            int cr;
            for (cr = 0; cr < V; cr++) {
                if (available[cr])
                    break;
            }

            result[u] = cr;

            Arrays.fill(available, true);
        }

        String nodeColor[] = new String[V];

        Arrays.fill(nodeColor, "DDD");

        for(int k=0; k < V; k++){

            nodeColor[k] = colors[result[k]];

            System.out.println("result[k] = " + colors[result[k]]);
        }

        System.out.println("The color sequence: ");
        for(String i : colors){

            System.out.print(i + "");
        }

        for (int u = 1; u < V; u++) {

            System.out.println(u);
            System.out.println("Vertex " + countries[u] + " --->  Color " + nodeColor[u]);
        }
    }

    public static void main(String args[]) {

        int[][] adjenctList = new int[14][];

        adjenctList[1] = new int[]{2,3};
        adjenctList[2] = new int[]{1,3,4,8};
        adjenctList[3] = new int[]{1,2,8,6};
        adjenctList[4] = new int[]{2,7,8};
        adjenctList[5] = new int[]{3,8,9,10,6};
        adjenctList[6] = new int[]{3,5,10};
        adjenctList[7] = new int[]{4,11,8};
        adjenctList[8] = new int[]{12,11,7,4,2,3,5,9,10,13};
        adjenctList[9] = new int[]{8,5,11};
        adjenctList[10] = new int[]{6,5,9,8,13};
        adjenctList[11] = new int[]{7,12,8};
        adjenctList[12] = new int[]{11,8};
        adjenctList[13] = new int[]{8,10};



        for(int i = 1; i < adjenctList.length; i++){

            System.out.print("Node " + i + " and its neighbors are:  " );

            for(int j:adjenctList[i]) System.out.print(j+"  ");

            System.out.println("");
        }

        Project_8 graph = new Project_8(adjenctList.length);


        for(int i = 1; i < adjenctList.length; i++){

            for(int k : adjenctList[i]){
                graph.addEdge(i,k);
            }

        }


        graph.BFSColoring();
    }

}