package HomeWork_Algorithm;

public class Project_5 {

    static int count_hash_search = 0;
    static int count_sequential_search = 0;

    public static void main(String[] args) {



            /** (A) Create an Array of 4-digits student ID’s of Size 500 using the random generator function. Display the array. */
            int[] a = new int[500];

            for(int i=0; i<a.length; i++){
                a[i] = autoGenerator(1000,9999);
            }

            System.out.println("\n\nGenerating the array: ");
            for(int m : a) System.out.print(m + " ");

            /** (B)  Using division method for a hash function H and a hash table of size m, a prime number, store your data of 4-digits student ID’s  (n=500) to a hash table which       is an array of linked list for collision resolution.
                     H (k) =  k mod m
                     m  : The size of hash table. A prime number larger than and not too larger than 500 / 3  and   2**5   < m <   2**6   and not too close to the  power of 2.
                     ** means power of 2.

             *      here I set m = 59
             * */

            /** (1) Create 500  4-digit student ID’s using random number  generator; And mapped to hash table where each cell is chained to a link list. */
            int[] b = new int[500];

            for(int i=0; i<b.length; i++){
                b[i] = autoGenerator(1000,9999);
            }

            int m = 59;

            MyHashMap X = new MyHashMap(m);

            for(int j = 0; j < 500; j++) {

                X.put_val(b[j]);
            }

            System.out.println("finished");

            /** (2) Print out hash table with contents of each cell (addresses) which are head pointers pointing to a chain of linked list of IDs.  */
            int nodes_NoKey_length = X.nodes_NoKey.length;

            System.out.println("******** Now we print the hash table ********");

            int count = 0 ;
            for(int j = 0; j < nodes_NoKey_length; j++) {

                 ListNode_NoKey aaa = X.nodes_NoKey[j].next;

                System.out.println("\nStart from position " + j );

                 while(aaa != null) {
                     System.out.print(aaa.val + " j = " + j + " | ");
                     aaa = aaa.next;
                     count++;
                 }

            }

            System.out.println(count);

            /** (3) Hash Search: Do 20 searches – 17 with ID found and the other three with ID not found.  */

            int bad_count = 1;
            int good_count = 1;

            int test_num = 0;

            System.out.println("\n\n");

            while( good_count != 18 ) {

                test_num = autoGenerator(1000,9999);

                count_hash_search = 0;

                if( X.hash_search( test_num ) != -1 ) {
                    System.out.println(good_count + " " + test_num + " Search succeed! with computation count: " + count_hash_search);
                    good_count++;
                }

            }

            System.out.println("\n");

            while(bad_count!=4) {

                test_num = autoGenerator(1000,9999);

                count_hash_search = 0;

                if( X.hash_search( test_num ) == -1 ) {
                    System.out.println(bad_count + " " + test_num + "Search failed! with computation count: " + count_hash_search);
                    bad_count++;
                }
            }


        /** (4) Sequential Search: Do 20 searches – 17 with ID found and the other three with ID not found.  */

             System.out.println("\n\n********* Here is the sequential search result*********");
             bad_count = 0;
             good_count = 0;

             test_num = 0;

             System.out.println("\n");

             while( good_count != 17 ) {

                    count_sequential_search = 0;

                    test_num = autoGenerator(1000,9999);

                    for(int i = 0; i<500; i++){

                        if(b[i] !=  test_num) {
                            count_sequential_search++;
                            continue;
                        } else {
                            good_count++;
                            System.out.println(good_count + " " + test_num + " Search succeed!   with computation count: " + count_sequential_search);
                         }
                    }

            }

            System.out.println("\n");

            while( bad_count != 3 ) {

                count_sequential_search = 0;

                test_num = autoGenerator(1000,9999);

                boolean flag = false;

                for(int i = 0; i<500; i++){

                    count_sequential_search++;

                    if(b[i] !=  test_num) continue;

                    flag = true;
                }

                if(flag == false){
                    bad_count++;
                    System.out.println(bad_count + " " + test_num + " Search fail!   with computation count: " + count_sequential_search  );
                }
            }
    }

    public static int autoGenerator(int min, int max){

        return (int)(Math.random() * (max - min + 1) + min);
    }




    /**
     * Definition for singly-linked list.
     * public class ListNode {
     *     int val;
     *     ListNode next;
     *     ListNode(int x) { val = x; }
     * }
     */

    public static class ListNode_NoKey {
        int val;
        ListNode_NoKey next;
        ListNode_NoKey(int x) { val = x; }
    }
    static class SortLinkedList {



        public ListNode_NoKey sortList(ListNode_NoKey head) {

            /** Check corner case**/
            if (head == null || head.next == null) return head;

            /** 1. Define slow & fast pointer */
            ListNode_NoKey slow = head;
            ListNode_NoKey fast = head.next;

            /** 2. Let the pointer stop at correct place */
            while (fast != null && fast.next != null) {
                fast = fast.next.next;
                slow = slow.next;
            }

            /** 3. Get header for 2nd half */
            ListNode_NoKey mid = slow.next;
            slow.next = null;

            /** 4. Start Merge **/
            return merge(sortList(head), sortList(mid));
        }

        /** 4. Start Merge **/
        public ListNode_NoKey merge(ListNode_NoKey l1, ListNode_NoKey l2) {

            /** 4.1 Define Dummy and Tail | Tail就是尾巴，最小的意思 */
            ListNode_NoKey dummy = new ListNode_NoKey(0);
            ListNode_NoKey tail = dummy;

            /** 4.2 Compare two node | until the end */
            while (l1 != null && l2 != null) {

                if(l1.val > l2.val) {
                    tail.next = l2;
                    l2 = l2.next;
                } else {
                    tail.next = l1;
                    l1 = l1.next;
                }

                tail = tail.next;
            }

            /** 4.3 */
            tail.next = (l1 == null) ? l2 : l1;

            /** Dummy is the begining*/
            return dummy.next;

        }



    }



    public static class MyHashMap {

        /* 1. create ListNode structure  */
        class ListNode {

            int key;
            int val;

            ListNode next;

            ListNode(int key, int val) {

                this.key = key;
                this.val = val;
            }
        }
 
        /* 2. create a ListNode array */

        ListNode[] nodes = new ListNode[59];
        ListNode_NoKey[] nodes_NoKey = new ListNode_NoKey[59];

        MyHashMap(int a){
            this.nodes = new ListNode[a];
            this.nodes_NoKey = new ListNode_NoKey[a];
        }

        /* 3. get the MOD key --> PLEASE PAY ATTENTION: Integer.hashcode(int) just return int --> now change! */
        int idx(int key) { return key % nodes.length;}
        int idx_NoKey(int val) { return val % nodes.length;}

        /* 4. find  (CORE FUNCTION)           this is the original key, 从左往右找，从最原始的array上面的点开始找 */
        ListNode find(ListNode bucket, int key) {

            ListNode prev = null;
            /* once the key is not matching */
            while (bucket != null && bucket.key != key) { /* loop until find the key. Find from the last element on the chain */
                /* move forward */
                prev = bucket;
                bucket = bucket.next;
            }

            /* if you find a match, the previous one should be pre. */

            return prev;
        }

        /* 4. find  (CORE FUNCTION)           this is the original key, 从左往右找，从最原始的array上面的点开始找 */
        ListNode_NoKey find_val(ListNode_NoKey bucket, int val) {

            ListNode_NoKey prev = null;
            /* once the key is not matching */
            while (bucket != null && bucket.val != val) { /* loop until find the key. Find from the last element on the chain */
                /* move forward */
                prev = bucket;
                bucket = bucket.next;

                count_hash_search++;

            }

            /* if you find a match, the previous one should be pre. */

            return prev;
        }

        /* 5. put method */
        public void put(int key, int value) {

            int i = idx(key);

            /* if this position is null, give it a ListNode */
            if (nodes[i] == null) nodes[i] = new ListNode(-1, -1);

            ListNode prev = find(nodes[i], key);

            /* 找到最后一个元素，然后加上新的node */
            if (prev.next == null) prev.next = new ListNode(key, value);

                /* 或者，不是最后一个，但可以更新*/
            else prev.next.val = value;
        }

        /* 5. put method */
        public void put_val(int val) {

            int i = idx(val);

            /* if this position is null, give it a ListNode */
            if (nodes_NoKey[i] == null) nodes_NoKey[i] = new ListNode_NoKey(-1);

            ListNode_NoKey prev = find_val(nodes_NoKey[i], val);

            /* 找到最后一个元素，然后加上新的node */
            if (prev.next == null) prev.next = new ListNode_NoKey(val);

                /* 或者，不是最后一个，但可以更新*/
            else prev.next.val = val;
        }


        /* get */
        public int get(int key) {

            int i = idx(key);

            if (nodes[i] == null) return -1;

            /* try to find the matching key*/
            ListNode node = find(nodes[i], key);

            /* 找不到，就返回-1；找到 */
            return node.next == null ? -1 : node.next.val;
        }

        /* search */
        public int hash_search(int val) {

            int i = idx(val);

            if (nodes_NoKey[i] == null) return -1;

            /* try to find the matching key*/
            ListNode_NoKey node = find_val(nodes_NoKey[i], val);

            /* 找不到，就返回-1；找到 */
            return node.next == null ? -1 : node.next.val;
        }


        /* move */
        public void remove(int key) {

            int i = idx(key);

            if (nodes[i] == null) return;

            ListNode prev = find(nodes[i], key);

            if (prev.next == null) return;

            /* remove */
            prev.next = prev.next.next;
        }


    }

}
