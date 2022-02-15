import java.util.Scanner;

public class Pro4_64010815 {
    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        // Tax rates
        double[] rates = {0.10, 0.15, 0.25, 0.28, 0.33, 0.35};

        // The brackets for each rate for all the filing statuses
        int[][] brackets = {
            {8350, 33950, 82250, 171550, 372950}, // Single filer
            {16700, 67900, 137050, 20885, 372950}, // Married jointly
                                                    // -or qualifying widow(er)
            {8350, 33950, 68525, 104425, 186475}, // Married separately
            {11950, 45500, 117450, 190200, 372950} // Head of household
        };

        /* User Input */
        System.out.println("Filing Status");
        System.out.println("[0]-Single filer");
        System.out.println("[1]-Married jointly or qualifying widow(er)");
        System.out.println("[2]-Married separately");
        System.out.println("[3]-Head of household");
        System.out.print("Enter the filing status: ");
        int status = getStatus();
		System.out.print("Enter the taxable income: ");
		double income = in.nextDouble();

        /* Display the result*/
        System.out.print("Tax is " + computeTax(brackets, rates, status, income)); 
    }

    /* Computes and returns the total tax for the filing status brackets */
    public static double computeTax(int[][] brackets, double[] rates, int status, double income) {
        double tax = 0, incomeTaxed = 0;
        for (int i = 4; i >= 0; i--) {
            if (income > brackets[status][i])
                 tax += (incomeTaxed = income - brackets[status][i]) * rates[i + 1];
                income -= incomeTaxed;
    }    
        return tax += brackets[status][0] * rates[0];
    }

	/* Returns a valid status */
	public static int getStatus(){
		Scanner in = new Scanner(System.in);
		int status;
		do {
			status = in.nextInt();
			if (status < 0 || status > 3)
				System.out.println("Error: invalid status!!!");
		} while (status < 0 || status > 3);
		return status;
	}
    

}
