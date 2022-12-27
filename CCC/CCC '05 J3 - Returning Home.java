import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    String[] out = new String[10];
    String[] turns1 = new String[10];
    String[] turns2 = new String[10];
    String[] spots = new String[10];
    String input1, input2;
    int ind=0;
    while(true) {
      input1 = getString(); 
      input2 = getString();
      turns1[ind] = input1;
      spots[ind] = input2;
      ind++;
      if(input2.equals("SCHOOL")) {
        break;
      }
    }
    for(int i=ind-1; i>=0; i--) {
      if(turns1[i].equals("L")) {
        turns2[ind-i-1] = "RIGHT";
      } else if(turns1[i].equals("R")) {
        turns2[ind-i-1] = "LEFT";
      }
    }
    for(int i=ind-2; i>=0; i--) {
      out[ind-i-2] = String.format("onto %s street.", spots[i]);
    }
    out[ind-1]="into your HOME.";
    for(int i=0; i<ind; i++) {
      out[i] = String.format("Turn %s %s", turns2[i], out[i]);
      System.out.println(out[i]);
    }
  }

  public static String getString() {
    try {
      return br.readLine();
    }
    catch(Exception e) {
      return "";
    }
  }
}
