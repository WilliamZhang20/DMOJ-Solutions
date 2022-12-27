import java.io.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    int low, high, nums=0, count;
    //System.out.printf("Enter lower limit of range\n");
    low = getInt();
    //System.out.printf("Enter upper limit of range\n");
    high = getInt();
    for(int i=low; i<=high; i++) {
      count = 0;
      for(int j=1; j<=high; j++) {
        if(i%j==0) {
          count++;
        }  
      }
      if(count==4) {
        nums++;
      }
    }
    System.out.printf("The number of RSA numbers between %d and %d is %d\n", low, high, nums);
  }
  public static int getInt() {
    try
    {
      return Integer.parseInt(br.readLine());
    }
    catch (Exception e)
    {
      return 0;
    }
  }
}
