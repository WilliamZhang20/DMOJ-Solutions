import java.io.*;

public class Main {

  static InputStreamReader r = new InputStreamReader(System.in);
  static BufferedReader br = new BufferedReader(r);

  public static void main(String[] args) {
    int b, n;
    char[] list={'A', 'B', 'C', 'D', 'E'};
    char temp;
    while(true) {
      //System.out.print("Button number: ");
      b=getInt();
      //System.out.print("Number of presses: ");
      n=getInt();
      if(b==4 && n==1) {
        break;
      }
      for(int i=0; i<n; i++) {
        switch(b) {
          case 1:
            temp=list[0];
            for(int j=0; j<4; j++) {
              list[j]=list[j+1];
            }
            list[4]=temp;
            break;
          case 2:
            temp=list[4];
            for(int j=4; j>0; j--) {
              list[j]=list[j-1];
            }
            list[0]=temp;
            break;
          case 3:
            temp=list[0];
            list[0]=list[1];
            list[1]=temp;
            break;
          default:
            System.out.println("Invalid button");
            break;
        }
      }
    }
    for(int i=0; i<5; i++) {
      System.out.print(list[i]+" ");
    }
    System.out.println();
  }

  public static int getInt() {
    try {
      return Integer.parseInt(br.readLine());
    } catch (Exception e) {
      return 0;
    }
  }
}
