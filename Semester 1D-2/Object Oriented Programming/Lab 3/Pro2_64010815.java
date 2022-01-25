import java.util.Arrays;
import java.util.Scanner;

public class Pro2_64010815 {
     /* Merge Function*/
    public static int[] merge(int[] list1, int[] list2) {
        int[] mergeList = new int[list1.length+list2.length];
        for(int i=0;i<list1.length;i++){
            mergeList[i] = list1[i];
        }
        for(int i=0;i<list2.length;i++){
            mergeList[i+list1.length]=list2[i];
        }
        Arrays.sort(mergeList);
        return mergeList;
    }
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter list1: ");
        String list1txt[] = input.nextLine().split(" ");
        int list1[] = new int[list1txt.length];

        /* List 1 Transform to int*/
        for(int i=0;i<list1txt.length;i++){
            try {
                list1[i] = Integer.parseInt(list1txt[i]);
            } catch (Exception e) {
                System.out.println("Error! : Please enter the number");
                return;
            }
        }
        System.out.print("Enter list2: ");
        String list2txt[] = input.nextLine().split(" ");
        int list2[] = new int[list2txt.length];

        /* List 2 Transform tp int*/
        for(int i=0;i<list2txt.length;i++){
            try {
                list2[i] = Integer.parseInt(list2txt[i]);
            } catch (Exception e) {
                System.out.println("Error! : Please enter the number");
                return;
            }
        }
        /* Merged List Print out */
        int[] finalList = merge(list1, list2);
            System.out.print("The merged list is ");
        for(int i=0;i<finalList.length;i++){
            System.out.print(finalList[i]+" ");
        }
        //Error1 : User don't input any number
    }
}
