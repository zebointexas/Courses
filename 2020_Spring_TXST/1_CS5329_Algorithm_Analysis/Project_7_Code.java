package HomeWork_Algorithm;

public class Project_7 {

    static int count_DP;
    static int count_noDP;

    public static void main(String args[]) {

        int arr_0[] = new int[] {30, 35, 15, 5, 10, 20, 25};
        int arr_1[] = new int[] {11, 21, 31, 41, 13};

        int arr_2[] = new int[] {30, 335, 155, 5, 150, 270, 25};
        int arr_3[] = new int[] {145, 2, 378, 4, 35};

        int arr_4[] = new int[] {3, 5, 15, 5, 1, 20, 5};
        int arr_5[] = new int[] {14, 42, 53, 34, 13,1,5,3,6,7};

        int[][] a = {arr_0, arr_1, arr_2, arr_3, arr_4, arr_5};

        for(int[] aa:a){

            System.out.print("The input is [");

            for(int aaa:aa) System.out.print(aaa + " ");

            System.out.println("]");


            System.out.println("With DP (Minimum number of multiplications) " +  Project_7_DP(aa));
            System.out.println("No DP (Minimum number of multiplications)   " + Project_7(aa, 1, aa.length-1));

            System.out.println("\n");


            System.out.println("(a) With DP, the calculation times: " +  count_DP);count_DP = 0;

            System.out.println("(b) No DP, the calculation times:   " +  count_noDP);count_noDP = 0;

            System.out.println("\n");
            System.out.println("\n");

        }
    }

    //****** No DP | Matrix Ai has dimension p[i-1] x p[i] for i = 1..n
    static int Project_7(int p[], int i, int j)
    {
        if (i == j)
            return 0;

        int min = Integer.MAX_VALUE;

        // place parenthesis at different places between first
        // and last matrix, recursively calculate count of
        // multiplications for each parenthesis placement and
        // return the minimum count
        for (int k=i; k<j; k++)
        {
            int count = Project_7(p, i, k) + Project_7(p, k+1, j) + p[i-1]*p[k]*p[j];

            count_noDP++;count_noDP++;

            if (count < min) min = count;
        }

        // Return minimum count
        return min;
    }

    //************ with DP
    static int Project_7_DP(int p[] /* array */) {

        int n = p.length;
        /* 为了简化问题，第一行第一列无用。*/
        int m[][] = new int[n][n];

        int s[][] = new int[n][n];

        int i, j, k, L, q;

        // m[i,j] --> refer to "introduction to algorithm - version 3" page 376

        // 当L长度为一: 自己跟自己，不用相乘，为0
        for (i = 1; i < n; i++) m[i][i] = 0;

        // 当L长度为二或以上: 自己跟自己，不用相乘，为0
        for (L=2; L<n; L++)
        {
            for (i=1; i<n-L+1; i++)
            {
                j = i+L-1;

                if(j == n) continue;

                m[i][j] = Integer.MAX_VALUE;

                for (k=i; k<=j-1; k++)
                {
                    // q = cost/scalar multiplications
                    q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];count_DP++;count_DP++;

                    if (q < m[i][j]) {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }

        System.out.println("*********** Upper Triangular Matrices m[i,j]");

        int g_l = getFirstRowLength(m[1]);

        for(int a = 0; a < m.length; a ++) {

            int diff = g_l - getFirstRowLength(m[a]);

            while(diff-- > 0) {

                System.out.print(" ");

            }
            for (int b = 0; b < m.length; b ++)
                System.out.print(m[a][b] + " ");

            System.out.println("\n");
        }
        System.out.println("*********** Upper Triangular Matrices m[i,j]");


        System.out.println("\n");

        System.out.println("*********** Upper Triangular Matrices s[i,j]");

        g_l = getFirstRowLength(s[1]);
        for(int a = 0; a < s.length; a ++) {

            int diff = g_l - getFirstRowLength(s[a]);

            while(diff-- > 0) {

                System.out.print(" ");

            }

            for (int b = 0; b < s.length; b ++)
                System.out.print(s[a][b] + " ");

            System.out.println("\n");
        }

        return m[1][n-1];
    }


    public static int getFirstRowLength(int[] m){

        String g_l = "";

        for(int g:m) g_l = g_l + g;

        return g_l.length();

    }
}
