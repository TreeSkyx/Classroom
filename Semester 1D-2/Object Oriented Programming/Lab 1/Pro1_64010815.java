public class Pro1_64010815 {
    public static void main(String[] args) {
        int population =  312032486; // Base population at start of the 1st-year
        for(int i=1;i<=5;i++){
            int second = 31536000; // Second in one year

            /* Population Change */
            int newBorn = second/7;
            int death = second/13;
            int immigrant = second/45;

            int yearPopulation =  (population+newBorn+immigrant)-death; // New population at the end of the year
            System.out.println("Year "+i+" population is : "+yearPopulation);
            population = yearPopulation; // Update new population for next year
        }
    }
}
