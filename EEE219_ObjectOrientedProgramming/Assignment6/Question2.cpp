// Question 2
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

     public static void main(String args[]) {
      Module m1 = new Module("EE219", "Object Oriented Programming I", 5.0);
      System.out.println(m1);
   }
}
