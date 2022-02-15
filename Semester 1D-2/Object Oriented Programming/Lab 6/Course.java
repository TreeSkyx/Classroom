public class Course {
    private String courseName;
    private String[] students = new String[1];
    private int numberOfstudents;

    public Course(String courseName){
        this.courseName = courseName;
    }

    /* Auto-increase the array size */
    public void addStudent(String student){
        if(numberOfstudents == students.length){
            String[] a = new String[students.length + 1];
            for(int i=0; i < numberOfstudents; i++){
                a[i] = students[i];
            }
            students = a;
        }
        students[numberOfstudents] = student;
        numberOfstudents++;
    }
    
    public String[] getStudents(){
        return students;
    }

    public int getNumberOfStudents(){
        return numberOfstudents;
    }

    public String getCourseName(){
        return courseName;
    }

    /* Remove student from a course */
    public void dropStudent(String student){
        int index = findStudent(student);
        if(index >= 0){
            dropStudent(index);
        }
        else{
            System.out.println(student + " is not in the course");
        }
    }

    /* Delete a student */
    private void dropStudent(int index){
        String[] std = new String[students.length - 1];
        for(int i=0, j=0; i < std.length; i++ , j++){
            if(i == index){
                j++;
            }
            std[i] = students[j];
        }
        this.students = std;
        numberOfstudents--;
    }
    
    /* removes all students from the course */
	public void clear() {
		students = new String[1];
		numberOfstudents = 0;
	}

	/* Returns the index if student is found. Otherwise returns -1 */
	private int findStudent(String student) {
		for (int i = 0; i < numberOfstudents; i++) {
			if (students[i].equals(student)) {
				return i;
			}
		}
		return -1;
	}
}
