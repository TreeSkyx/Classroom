import java.util.Date;

public class Employee extends Person {
    private int office;
    private double salary;
    private java.util.Date dateHired;

    public Employee(String name, String address, String phone, 
		String email, int office, double salary) {
		super(name, address, phone, email);
		this.office = office;
		this.salary = salary;
		this.dateHired = new Date();
	}

	public void setOffice(int office) {
		this.office = office;
	}

	public void setSalary(double salary) {
		this.salary = salary;
	}

	public void setDateHired() {
		dateHired = new Date();
	}

	public int getOffice() {
		return office;
	}

	public String getSalary() {
		return String.format("%.2f", salary);
	}

	public Date getDateHired() {
		return dateHired;
	}

    public String toString() {
		return super.toString() + "\nOffice: " + office + 
        "\nSalary: " + getSalary() +
         "\nDate hired: " + getDateHired();
    }

}
