import java.util.Scanner;

public class Pro3_64010815 {
    public static void main(String[] args) {
        /* User Input */
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Year: ");
        int year = input.nextInt();
        System.out.println("Enter month: (1:Jan, 2:Feb ,3:Mar ,4:Apr, 5:May, 6:Jun, 7:Jul, 8:Aug, 9:Sep, 10:Oct, 11:Nov, 12:Dec)");
        int month = input.nextInt();
        System.out.print("Enter day of the month (1-31): ");
        int day = input.nextInt();

        /* Leap Year Check */
        boolean leap = false;
        // if the year is divided by 4
        if(year % 4 == 0) {
            // if the year is century
            if(year % 100 == 0) {
                // if the year divided by 400
                if(year % 400 == 0)
                    leap = true;
                else leap = false;
            }
            // if the year isn't century
            else leap = true;
        } 
        else leap = false;

        
        if(month>=1  && month<=12 && day>=1 && day <=31){
        /* 1st and 2nd month change for Zeller’s congruence */
        if(month == 1){
            month = 13;
            year--;
        }
        if(month == 2){
            month = 14;
            year--;
        }
        /* Zeller’s congruence */
        int j = year/100;
        int k = year%100;
        int h = day + 13*(month + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
        h = h % 7;

        if(day == 29 && month == 14 && !leap) h = 29; // leap year error

        /* Print the day of the week from Zeller’s congruence */
        if(h == 0){System.out.print("Saturday");}
        else if(h == 1){System.out.print("Sunday");}
        else if(h == 2){System.out.print("Monday");}
        else if(h == 3){System.out.print("Tuesday");}
        else if(h == 4){System.out.print("Wednesday");}
        else if(h == 5){System.out.print("Thursday");}
        else if(h == 6){System.out.print("Friday");}
        else {System.out.print("Error!");}
    }
    else {System.out.println("Error!");}
    //Error 1: User's month input is unreal month
    //Error 2: User's day input is unreal day
    //Error 3: User try to put 29 Feb in the year that not a Leap year
}
}
