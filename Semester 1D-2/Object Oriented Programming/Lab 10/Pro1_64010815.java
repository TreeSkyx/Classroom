import java.util.Scanner;

public class Pro1_64010815 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int[] array = randArray();
        
        System.out.print("Enter the index fo the array: ");
        try {
            System.out.println("The corresponding element value is " + array[input.nextInt()]);
        } catch (ArrayIndexOutOfBoundsException ex) {
            System.out.println("Out of Bonds.");
        }
    }
    public static int[] randArray(){
        int[] array = new int[100];
        for (int i = 0; i < array.length; i++){
            array[i] = (int)(Math.random()*100) + 1;
        }
        return  array;
    }
}