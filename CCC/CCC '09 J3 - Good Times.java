import java.io.*;
import java.lang.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    int[] ott = new int[4]; // Ottawa Time
    int[] pct = new int[4]; // Pacific Time
    int[] mot = new int[4]; // Mountain Time
    int[] cet = new int[4]; // Central Time
    int[] est = new int[4]; // Eastern Time
    int[] alt = new int[4]; // Atlantic Time
    int[] nlt = new int[4]; // Newfoundland Time

    // Fill Ottawa time array with zeros for addition and subtraction when accounting time zones
    for (int i = 0; i < 4; i++) {
      ott[i] = 0;
    }

    // Take Input of Ottawa Time
    String lines = getLine();

    for (int i = 0; i < lines.length(); i++) {
      ott[3-i] = Character.getNumericValue(lines.charAt(lines.length()-1-i));
    }

        // Assigning and adjusting times for time zones
    est = copyArray(ott);
    est = adjustment(est);
    cet = copyArray(ott);
    cet[1]--;
    cet = adjustment(cet);

    mot = copyArray(ott);
    mot[1] -= 2;
    mot = adjustment(mot);

    pct = copyArray(ott);
    pct[1] -= 3;
    pct = adjustment(pct);

    alt = copyArray(ott);
    alt[1]++;
    alt = adjustment(alt);

    nlt = copyArray(ott);
    nlt[1]++;
    nlt[2] += 3;
    nlt = adjustment(nlt);

    ott = est; // adjust Ottawa time to remove extra zeros

    // Print out times for different time zones
    printArray(ott); 
    System.out.println(" in Ottawa");
    printArray(pct); 
    System.out.println(" in Victoria");
    printArray(mot); 
    System.out.println(" in Edmonton");
    printArray(cet); 
    System.out.println(" in Winnipeg");
    printArray(est); 
    System.out.println(" in Toronto");
    printArray(alt);
    System.out.println(" in Halifax");
    printArray(nlt);
    System.out.println(" in St. John's");
  }

  public static int[] adjustment(int[] time) {
    int adjustedTime[] = time;
    int numPair=adjustedTime[0]*10+adjustedTime[1];
    for(int i=0; i<3; i++) {
      // If second index is beyond 9 (when going to 10 or 20 hours), replace with 10-b and add 1 to previous digit
      if(adjustedTime[1]>9) {
        adjustedTime[1]=10-adjustedTime[1];
        adjustedTime[0]++;
      }
      //If the second index is below 0, subtract one from previous digit and replace second index with the amount that it is below zero
      if(adjustedTime[1]<0 && adjustedTime[0]!=0) {
        adjustedTime[1]=10-Math.abs(adjustedTime[1]);
        adjustedTime[0]--;
      }

      // If the the desired time zone is in the previous day, adjust to 2400-(time surpassed)
      if(numPair<0) {
        int x = 24-Math.abs(numPair);
        adjustedTime[0]=(int) Math.floor(x/10.0);
        adjustedTime[1]=x%10;
      }

      // If the time is beyond 2400, adjust to next day
      if(numPair>24) {
        adjustedTime[1] = numPair-24;
      }

      numPair=adjustedTime[0]*10+adjustedTime[1]; // reassign value
    }
    // When adding 30 mins, adjust if it goes over the hour
    numPair = adjustedTime[2]*10+adjustedTime[3];
    if(numPair>60) {
      numPair = numPair-60;
      adjustedTime[2]=(int) Math.floor(numPair/10.0);
      adjustedTime[3]=numPair % 10;
      adjustedTime[1]++;
    }
    // If there are unecessary zeros, delete them
    if(adjustedTime[0]==0 && adjustedTime[1]==0) {
      adjustedTime[0]=-1;
      adjustedTime[1]=-1;
    } else if(adjustedTime[0]==0) {
      adjustedTime[0]=-1;
    }
    return adjustedTime;
  }

  public static int[] copyArray(int[] arr) {
    int filled[]=new int[arr.length];
    for(int i=0; i<arr.length; i++) {
      filled[i]=arr[i];
    }
    return filled;
  }

  public static void printArray(int[] arr) {
    for (int i = 0; i < arr.length; i++) {
      if(arr[i] > -1) {
        System.out.print(arr[i]);
      }
    }
  }

  public static String getLine() {
    try {
      return br.readLine();
    } catch (Exception e) {
      return "";
    }
  }
}
