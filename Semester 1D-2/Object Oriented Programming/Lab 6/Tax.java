public class Tax {
    /* Data field */
    private int filingStatus;
	public static final int SINGLE_FILER = 0;
	public static final int MARRIED_JOINTLY_OR_QUALIFYING_WIDOWER = 1;
	public static final int MARRIED_SEPARATELY = 2;
	public static final int HEAD_OF_HOUSEHOLD = 3;
	private int[][] brackets;
	private double[] rates;
	private double taxableIncome;

    Tax(){
        filingStatus = SINGLE_FILER; //default filing status

        double[] Rates = {0.10, 0.15, 0.25, 0.28, 0.33, 0.35};
		setRates(Rates);

		// Default brackets for each rate for all the filing statuses
		int[][] Brackets = {
			{8350, 33950, 82250, 171550, 372950},  // Single filer
			{16700, 67900, 137050, 20885, 372950}, // Married jointly
																// -or qualifying widow(er)
			{8350, 33950, 68525, 104425, 186475},  // Married separately
			{11950, 45500, 117450, 190200, 372950} // Head of household
        };
        setBrackets(Brackets);

        
		// Default taxable income
		taxableIncome = 0;
    }

        // Construct a tax with specified data
        Tax(int filingStatus, int[][] brackets, double[] rates, double taxableIncome){
            setFilingStatus(filingStatus);
            setBrackets(brackets);
            setRates(rates);
            setTaxableIncome(taxableIncome);
        }

        /* Setting new filing status */
        public void setFilingStatus(int filingStatus) {
            this.filingStatus = filingStatus;
        }

        /** Return filingStatus */
	    public int getFilingStatus() {
		return filingStatus;
	    }

        /** set new brackets */
	    public void setBrackets(int[][] brackets) {
		this.brackets = new int[brackets.length][brackets[0].length];
		for (int i = 0; i < brackets.length; i++) {
			for (int j = 0; j < brackets[i].length; j++)
				this.brackets[i][j] = brackets[i][j];
		}
    }

        /** Return brackets */
	public int[][] getBrackets() {
		return brackets;
	}

	/** Set new rates */
	public void setRates(double[] rates) {
		this.rates = new double[rates.length];
		for (int i = 0; i < rates.length; i++)
			this.rates[i] = rates[i];
	}

	/** Return rates */
	public double[] getRates() {
		return rates;
	}

	/** Set new taxableIncome */
	public void setTaxableIncome(double taxableIncome) {
		this.taxableIncome = taxableIncome;
	}

    /* Return tax */
    public double getTax() {
		double tax = 0, incomeTaxed = 0;
		double income = taxableIncome; 
		if (rates.length >= 2) {
			for (int i = rates.length - 2; i >= 0; i--) {
				if (income > brackets[filingStatus][i]) {
 					tax += (incomeTaxed = income - brackets[filingStatus][i]) 
 								* rates[i + 1];
					income -= incomeTaxed;
 				}
			} 
		}
		return tax += brackets[filingStatus][0] * rates[0];
	}
    
}
