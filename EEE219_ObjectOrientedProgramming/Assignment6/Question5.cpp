// Question 5
public class MirrorString {
   static int j = 0;
   public static void mirrorString(String str) {
      if (str.equals(""))
      return str;
      
      char[] A = str.tocharArray();
     
      mirrorString(A, 0);
      
     return String.copyValueOf(A);
   }
   
   private static void mirrorString(String str, int i) {
     if ( i == str.length())
      return str;
      
    mirrorString(str, i + 1);
    
    if (i <= j){
    char temp = str[i];
    str[i] = str[j];
    str[j++] = temp;
    }
   }
   
   public static void main(String args[]) {
      mirrorString("Hello World!");
      System.out.println("Reversed string is: " + str);
      
   }
}
