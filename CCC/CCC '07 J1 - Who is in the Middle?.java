import java.io.*;
import java.util.*;

public class Main {
  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    int a[]=new int[3];
    for(int i=0; i<3; i++) {
      a[i]=getInt();
    }
    for(int i=0; i<3; i++) {
      for(int j=i+1; j<3; j++) {
        if(a[i]>a[j]) {
          a[i]=a[i]+a[j];
          a[j]=a[i]-a[j];
          a[i]=a[i]-a[j];
        }
      }
    }
    System.out.println(a[1]);
  }

  public static int getInt() {
    try {
      return Integer.parseInt(br.readLine()); 
    } catch(Exception e) {
      return 0;
    }
  }
}
