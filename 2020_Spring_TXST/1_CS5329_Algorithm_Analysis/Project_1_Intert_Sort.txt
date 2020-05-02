import java.util.Arrays; 
import java.util.Random; 

public class InsertionSort {

    public static void main(String[] args) {
        
        Random rand = new Random();
 
        int N = 12;  int M = 0; 
       
        int[] a; 
        
        int count = 0; 
 
        while(M < 10){
            
            a = new int[10]; 
            
            for(int i = 0; i<10; i++){
                
                a[i]  = rand.nextInt(100);
            }
            
            System.out.println(M + " Original array: " + Arrays.toString(a)); 
            
            count = sort(a);
            
            System.out.println(M+ "   Sorted array: " + Arrays.toString(a));
            
            System.out.println("Count: " + count);
            
            M++; 
        }
        
        int[] worst_case  = new int[]{10,9,8,7,6,5,4,3,2,1}; 
        
        System.out.println("Worst_case" + "   Sorted array: " + Arrays.toString(worst_case));
        
        count = sort(worst_case); 
        
        System.out.println("Worst_Case" + "   Sorted array: " + Arrays.toString(worst_case));
        
        System.out.println(" ---- Count: " + count);
    }

    private static int sort(int[] arr) {
        
        int count = 0; 
        
        for (int j = 1; j < arr.length; j++) {
        
            int key = arr[j];
            int i = j - 1;
        
            while (i >= 0 && key < arr[i]) {
                
                arr[i + 1] = arr[i];
                i--;
            
                count++;
                
            }
            arr[i + 1] = key;
        }
        
        return count; 
    }
} 