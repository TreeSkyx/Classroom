import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;

public class Pro4_64010815 {
    public static void main(String[] args) {
        ArrayList<Double> assistant = new ArrayList<>();
        ArrayList<Double> associate = new ArrayList<>();
        ArrayList<Double> full = new ArrayList<>();

        try {
            File file = new File("Salary.txt");
            Scanner readFile = new Scanner(file);
            while (readFile.hasNext()){
                String[] line = (readFile.nextLine().split(" "));
                processData(assistant,associate,full,line[2],Double.parseDouble(line[3]));
            }
        } catch (FileNotFoundException ex) {
            System.out.println("File not found!");
            System.exit(0);
        }

        
    double totalAssiantant = getTotal(assistant);
    double totalAssociate = getTotal(associate);
    double totalFull = getTotal(full);
    double totalFaculty = (totalAssiantant + totalAssociate + totalFull);


    System.out.printf("Total salary for assiantant professor is : %.2f\n ",totalAssiantant);
    System.out.printf("Total salary for associate professor is : %.2f\n ",totalAssociate);
    System.out.printf("Total salary for full professor is : %.2f\n ",totalFull);
    System.out.printf("Total salary for all professor is : %.2f\n ",totalFaculty);


    System.out.printf("Average salary for assiantant professor is : %.2f\n ", (totalAssiantant/ assistant.size()));
    System.out.printf("Average salary for associate professor is : %.2f\n ",(totalAssociate / associate.size()));
    System.out.printf("Average salary for full professor is : %.2f\n ",(totalFull / full.size()));
    System.out.printf("Average salary for all professor is : %.2f\n ",(totalFaculty / (assistant.size() + associate.size() + full.size())));

    }
    public static double getTotal(ArrayList<Double> list){
        double total = 0;
        for(int i=0; i < list.size(); i++){
            total += list.get(i);
        }
        return total;
    }
    public static void processData(ArrayList<Double> assist, ArrayList<Double> assoc, ArrayList<Double> full, String rank , double salary) {
        if(rank.equals("assistant"))
            assist.add(salary);
        else if(rank.equals("associate"))
            assoc.add(salary);
        else
            full.add(salary);
    }
}
