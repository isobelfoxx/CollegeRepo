public class ApplicationChallenge {

	//Task 1: Most frequent
	public static String mostFreq (int [] array) {
		int count = 0;
		int maxcount = 0;
		int mostfreq = 0; 
		int mostfreq2 = 0; 
		String output = null;
				
		if(array.length == 0)
			output = "The Array is null";
		
		for(int i = 0; i < array.length; i++) {
			for(int j = 0; j < array.length; j++) {
				if(array[i] == array[j]) 
					count++;
			}
			if(count > maxcount) {
				maxcount = count;
				mostfreq = array[i];				
			}
			
			if(count == maxcount) {
				mostfreq2 = array[i];
				if (mostfreq == mostfreq2)
					output = "The most frequent value is: " + Integer.toString(mostfreq);
				else
					output = "There are two most frequent values: " + Integer.toString(mostfreq) + ", " + Integer.toString(mostfreq2);
			}
			System.out.println(count);
			count = 0;
		}
		
		if(maxcount == 1) 
			output = "There is no most frequent value, each value occurs the same time";
		return output;

	}
	
	//Task 2: Reverse string iteratively
    public static String reverseStringIteratively (String string) {
    	char []charArray = string.toCharArray();
    	char temp;
    	int length = string.length();
    	
    	if (string == null || string.equals("")) {
            return string;
        }
    	
		for(int i = 0; i < length/2; i++ ) {
			temp = charArray[i];
			charArray[i] = charArray[length-1-i];
			charArray[length-1-i] = temp;
		}
       return String.valueOf(charArray);
	}
    
    //Task 2: Reverse string Recursively
    public static String reverseStringRecursively (String string) {
    	
    	if (string == null || string.equals("")) {
            return string;
        }
    	
    	return reverseStringRecursively(string.substring(1)) + string.charAt(0);

	}

	public static void main(String args[]) {
		//Most frequent
		System.out.println("Task 1: ");
		int testArray [] = {1,1,2,1,3};
		
		System.out.print("Test Array = [ ");
		
		for(int i = 0; i < testArray.length - 1; i++) {
			if(i < testArray.length-1)
				System.out.print(testArray[i] + ", ");
			else
				System.out.print(testArray[i]);
		}
		System.out.print(" ]");
		
		System.out.println();
		System.out.println( mostFreq(testArray));
	
		System.out.println();
		
		System.out.println("Task 2: ");
		String testString = "Isobel";
		System.out.println("Original String: " + testString);
		
		System.out.println();
		System.out.println("Reversed Iteratively:  " + reverseStringIteratively(testString));
		
		System.out.println();
		System.out.println("Reversed Recursively:  " + reverseStringRecursively(testString));
		
	}
}
