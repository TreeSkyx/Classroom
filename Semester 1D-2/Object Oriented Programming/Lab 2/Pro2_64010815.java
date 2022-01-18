import java.util.Scanner;

public class Pro2_64010815 {
    public static void main(String[] args) {
        int max = 3, min = 0; // Create max-min for random number
        int AI = (int)Math.floor(Math.random()*(max-min+1)+min); // Random number

        /* User Input */
        Scanner input = new Scanner(System.in);
        System.out.print("scissor (0), rock (1), paper (2): " );
        int user  = input.nextInt();
        
        if(user >= 0 && user <= 2 ){ // Checker for error case
        /* Comparison for Win-Lose */
            if(AI == 0){
                if(user == 1) {System.out.println("The computer is scissor. You are rock. You Won");}
                else if(user == 2) {System.out.println("The computer is scissor. You are paper. You Lose");}
                else {System.out.println("The computer is scissor. You are scissor. It is a draw");}
            }
            if(AI == 1){
                if(user == 0) {System.out.println("The computer is rock. You are scissor. You Lose");}
                else if(user == 2) {System.out.println("The computer is rock. You are paper. You Won");}
                else {System.out.println("The computer is rock. You are rock. It is a draw");}
            }
            if(AI == 2){
                if(user == 0) {System.out.println("The computer is paper. You are scissor. You Won");}
                else if(user == 1) {System.out.println("The computer is paper. You are rock. You Lose");}
                else {System.out.println("The computer is paper. You are paper. It is a draw");}
            }
        }
        else {System.out.println("Error!");}
        //Error 1 : User's input number that not in the range 0 to 2

    }
}
