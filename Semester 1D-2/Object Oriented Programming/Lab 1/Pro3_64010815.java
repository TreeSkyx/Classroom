import java.util.Scanner;

public class Pro3_64010815 {
    public static void main(String[] args) {
        System.out.print("Enter a number between 0 and  1000: ");
        Scanner input = new Scanner(System.in);
        int num = input.nextInt();

        /*  Split number into digits */
        int th = num/1000; 
        int h = (num/100)%10;   
        int t = (num/10)%10;    
        int u = num%10; 
        
        /* Calculate summation of digits */   
        int sum = th+h+t+u;
        System.out.println(sum);
    }
}
