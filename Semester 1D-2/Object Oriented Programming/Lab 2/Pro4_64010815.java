import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

public class Pro4_64010815 {
    public static void main(String[] args) {
        /* User Input */
        String[] city = new String[3]; // Create Array for Cities
        Scanner input = new Scanner(System.in);
        System.out.print("Enter th first city: ");
        city[0] = input.nextLine();
        System.out.print("Enter th second city: ");
        city[1] = input.nextLine();
        System.out.print("Enter th third city: ");
        city[2] = input.nextLine();
        /* Cities Name Sort */
        List<String> list = new ArrayList<>(); // Create List for Cities Array
        // Add City name to the list
        for(String lang:city){
            list.add(lang);
        }
        Collections.sort(list);  // Sort the name (A-Z)
        System.out.print("The three cities in alphabetical order are ");
        for(String lang:list) 
        System.out.print(lang+" ");  
    }
}
