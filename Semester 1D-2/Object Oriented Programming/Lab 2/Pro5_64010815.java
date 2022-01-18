import java.util.Scanner;

public class Pro5_64010815 {
    public static void main(String[] args) {
        /* User Input */
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of lines: ");
        int num = input.nextInt();
        if(num>=1 && num <=15){
        /* Create Pyramid of Number */
        for (int i=1; i<=num; i++){
            for (int j=1; j<=(num-i)*2; j++){
            System.out.print(" ");      // Create space for pyramid shape
            }
          for (int k=i; k>=1; k--){
            System.out.print(" "+k);    //  Create left side of pyramid            
          }                                        
          for (int l=2; l<=i; l++){
            System.out.print(" "+l);    //  Create right side of pyramid
          }
          System.out.println();
        }
        }
        else {System.out.println("Error!");}
        //Error 1 : User's input number that not in the range 1 to 15
    }
}
