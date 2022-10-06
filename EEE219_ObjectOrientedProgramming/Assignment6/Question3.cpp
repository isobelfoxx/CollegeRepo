// Question 3
public class Complex {
    private double real;
    private double imag;
    
    public Complex (double r, double im) { 
     real = r;
     imag = im;
    } 
    
    public Complex add (Complex c1){
        Complex c2 = this;
        double r = c1.real + c2.real;
        double im = c1.imag + c2.imag;
        return new Complex(r, im);
    }
    
    public Complex subtract (Complex c1){
        Complex c2 = this;
        double r = c2.real - c1.real;
        double im = c2.imag - c1.imag;
        return new Complex(r, im);
    }
    

    public Complex multiply (Complex c1){
        Complex c2 = this;
        double r = c2.real * c1.real - c2.imag * c1.imag;
        double im = c2.real * c1.imag + c2.imag * c1.real;
        return new Complex(r, im);
    }
		    
    public Complex divide (Complex c1){
        Complex c2 = this;
        double r = (c2.real * c1.real + c2.imag * c1.imag)/ (c1.real * c1.real + c1.imag * c1.imag);
        double im = (c2.imag * c1.real - c2.real * c1.imag) / (c1.real * c1.real + c1.imag * c1.imag);
        return new Complex(r, im);
    }
    
    @Override
    public String toString(){
        if (imag < 0)
             return real + imag + "j";
        else
             return real + "+" + imag + "j";
    }

    public static void main(String args[]) {
      Complex c1 = new Complex(1,-2);
      Complex c2 = new Complex(3,-4);
      Complex c3 = new Complex(-3,2);
      System.out.println(c1.add(c2).subtract(c2).subtract(c1));
      System.out.println(c1.subtract(c2).divide(c3).add(c1.multiply(c3)));
   }
}
