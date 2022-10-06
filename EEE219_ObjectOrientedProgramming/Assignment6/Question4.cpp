// Question 4
public class Module {
    private String modulecode;
    private String modulename;
    private double creditvalue;
    
    public Module (String code, String name, double credit) { 
     modulecode = code;
     modulename = name;
     creditvalue = credit;
    }
    
    @Override
    public String toString(){
     return modulecode + " " + modulename + " (" + creditvalue + " credits)";
    }
}

// Question 4
public abstract class Student {
   private String name;
   private int ID;
   public Student(String nm, int id) {
      name = nm;
      ID = id;
   }
   void print() {
      System.out.println("Name: " + name + "\nID: " + ID);
   }
}

public class UndergradStudent extends Student {
    private String programme;
    private int nummodules;
    private Module[] modules;
   
    public UndergradStudent(String nm, int id, String prog) { 
       super(nm, id);
       programme = prog;
       nummodules = 0;
    }
       
    void print(){
    super.print();
    System.out.println("Programme: " + programme + "\nRegistered for modules:");
    for(int i=0; i<nummodules; i++)
    System.out.println(modules[i]);
    }
    
    boolean add (Module mod){
    if(nummodules == 10) 
    return false;
    modules[nummodules++] = mod;
    return true;
    }
    
    
    public static void main(String args[]) {
     UndergradStudent s1 = new UndergradStudent("Mary Murphy", 12345678, "ECE");
     s1.add(new Module("EE219", "Object Oriented Programming I", 5.0));
     s1.add(new Module("EE223", "Digital and Analogue Electronics I", 5.0));
     s1.add(new Module("EE202", "Embedded Systems", 5.0));
     s1.print();
  }
}
