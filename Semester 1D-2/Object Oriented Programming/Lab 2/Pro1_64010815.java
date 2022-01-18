import java.util.Scanner;

public class Pro1_64010815 {
    public static void main(String[] args) {
        /* Input Date */
        Scanner input = new Scanner(System.in);
        System.out.print("Enter today's day: ");
        int today = input.nextInt();
        System.out.print("Enter the number of days elapsed since today: ");
        int future = input.nextInt();

        if(today>=0 && today<=6 && future>=1){ // Checker for some error case
        System.out.print("Today is ");
        
        /* Today's day print in the days of the week format */
        int num = today;
        if(num == 0) {System.out.print("Sunday");}
        else if(num == 1) {System.out.print("Monday");}
        else if(num == 2) {System.out.print("Tuesday");}
        else if(num == 3) {System.out.print("Wednesday");}
        else if(num == 4) {System.out.print("Thursday");}
        else if(num == 5) {System.out.print("Friday");}
        else if(num == 6) {System.out.print("Saturday");}
        System.out.print(" and the future day is ");
        
        /* Calculate for the days of the week in the future */
        num = (today + future)%7;
        if(num == 0) {System.out.print("Sunday");}
        else if(num == 1) {System.out.print("Monday");}
        else if(num == 2) {System.out.print("Tuesday");}
        else if(num == 3) {System.out.print("Wednesday");}
        else if(num == 4) {System.out.print("Thursday");}
        else if(num == 5) {System.out.print("Friday");}
        else if(num == 6) {System.out.print("Saturday");}
        }
        else{
            System.out.println("Error!");
            //Error 1 : User's input today's day that less than 0 or more than 6
            //Error 2 : User's input the number of days elapsed since today less than 1 (0 is today)
        }
    }
}
