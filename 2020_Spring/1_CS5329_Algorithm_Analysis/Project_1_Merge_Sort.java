import java.util.Arrays; 
import java.util.Random; 

public class myMergeSort {
 
    static int count;
    
    public static void main(String[] args) {
        
        int[] a = {26, 5, 98, 108, 28, 99, 100, 56, 34, 1 };
               
        Random rand = new Random();
 
        int N = 90; 
  
        a = new int[N]; 
        
        for(int i = 0; i<N; i++) a[i]  = rand.nextInt(100);
     
        System.out.println("N = " + N);

        System.out.println(" Original array: " + Arrays.toString(a)); 

        count = 0; 
        MergeSort(a);

        System.out.println("   Sorted array: " + Arrays.toString(a));
        System.out.println("Count: " + count);
    
        
        int[] worst_case  = new int[]{90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,37,36,35,34,33,32,31,30, 29,28,27,26,25,24,23,22,21,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1}; 
 
        System.out.println("Worst_case" + "   Sorted array: " + Arrays.toString(worst_case));
        
        count = 0; 
        MergeSort(worst_case); 
        
        System.out.println("Worst_Case" + "   Sorted array: " + Arrays.toString(worst_case));
        System.out.println(" ---- Count: " + count);
    
     
    }
    
    private static void MergeSort(int[] a) {
        Sort(a, 0, a.length - 1); count++;
    }

    private static void Sort(int[] a, int left, int right) {
        if(left>=right){
            count++;
                        return;
        }

    
        int mid = (left + right) / 2; count++;
 
        Sort(a, left, mid);count++;
        Sort(a, mid + 1, right);count++;
        merge(a, left, mid, right);count++;
    }

    private static void merge(int[] a, int left, int mid, int right) {
    
        int[] tmp = new int[a.length]; count++;
        int r1 = mid + 1;count++;
        int tIndex = left;count++;
        int cIndex=left;count++;
   
        while(left <=mid && r1 <= right) {count++;
            if (a[left] <= a[r1]) {
                count++;
                tmp[tIndex++] = a[left++];
            }
                
            else {
                count++;
                tmp[tIndex++] = a[r1++];
            }
                
        }
        
            while (left <=mid) {
                tmp[tIndex++] = a[left++]; count++;
            }
   
            while ( r1 <= right ) {
                tmp[tIndex++] = a[r1++]; count++;
            }
   
             while(cIndex<=right){
                    a[cIndex]=tmp[cIndex];count++;
   
                    cIndex++;
                }
        }
    }