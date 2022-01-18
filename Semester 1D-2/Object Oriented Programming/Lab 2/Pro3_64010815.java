import java.util.Scanner;

public class Pro3_64010815 {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter Year: ");
        int year = input.nextInt();
        System.out.print("Enter month: ");
        int month = input.nextInt();
        System.out.print("Enter day of the month: ");
        int day = input.nextInt();
        if(month == 1){
            month = 13;
            year--;
        }
        if(month == 2){
            month = 14;
            year--;
        }
        int j = year/100;
        int k = year%100;
        int h = day + 13*(month + 1) / 5 + k + k / 4 + j / 4 + 5 * j;
        h = h % 7;
        if(h == 0){System.out.print("Saturday");}
        else if(h == 1){System.out.print("Sunday");}
        else if(h == 2){System.out.print("Monday");}
        else if(h == 3){System.out.print("Tuesday");}
        else if(h == 4){System.out.print("Wednesday");}
        else if(h == 5){System.out.print("Thursday");}
        else if(h == 6){System.out.print("Friday");}
    }
}
