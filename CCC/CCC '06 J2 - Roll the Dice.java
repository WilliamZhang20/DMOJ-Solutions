import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    int m, n, ways=0;
    //System.out.print("Enter m: ");
    m = getInt();
    //System.out.print("Enter n: ");
    n = getInt();
    
    for(int i=1; i<=m; i++) {
      for(int j=1; j<=n; j++) {
        if(i+j==10) {
          ways++;
        }
      }
    }
    if(ways>1 || ways<1) {
      System.out.printf("There are %d ways to get the sum 10.\n", ways);
    }
    else if(ways==1) {
      System.out.printf("There is 1 way to get the sum 10.\n");
    }
  }

  public static int getInt() {
    try {
      return Integer.parseInt(br.readLine()); 
    } catch(Exception e) {
      return 0;
    }
  }
}
