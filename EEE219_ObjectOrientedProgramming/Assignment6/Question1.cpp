// Question 1
public class Circle {
    private int centerp_x;
    private int centerp_y;
    private int radius;

    public Circle (int cp_x, int cp_y, int r) { 
     centerp_x = cp_x;
     centerp_y = cp_y;
     radius = r;
    }

     public double Area(){
       return 3.1416*radius*radius;
    }
        
    public static void main(String args[]) {
        
     Circle[] circle;
     circle = new Circle[3];
   
     circle[0]= new Circle (1,2,3);
     circle[1]= new Circle (2,3,4);
     circle[2]= new Circle (3,4,5);
     
     for (int i=0; i<3; i++)
       System.out.println(circle[i].Area());

    }
}
