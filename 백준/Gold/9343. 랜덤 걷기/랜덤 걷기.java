import java.util.Scanner;
import java.util.Arrays;
public class Main { 
    class FirstSort implements Comparable<FirstSort>{
        int[] entry=new int[2];
        public FirstSort() {}
        public FirstSort(int[] a) {
            entry[0]=a[0];
            entry[1]=a[1];
        }
        public int hashCode() {
            return entry[0];
        }
        public int compareTo(FirstSort y) {
            return this.hashCode()-y.hashCode();
        }
    }
    class SecondSort implements Comparable<SecondSort>{
        int[] entry=new int[2];
        public SecondSort() {}
        public SecondSort(int[] a) {
            entry[0]=a[0];
            entry[1]=a[1];
        }
        public SecondSort(FirstSort a) {
            entry[0]=a.entry[0];
            entry[1]=a.entry[1];
        }
        public int hashCode() {
            return entry[1];
        }
        public int compareTo(SecondSort y) {
            return this.hashCode()-y.hashCode();
        }
    }
     
    public long[] getInverseModP(long a, long b) { //return (A,B) such that aA+bB=1 AND the input should a>=b, relatively prime
        long[] rtn=new long[2];
        long[] temp=new long[2];
        if(b==1) {
            rtn[0]=0;
            rtn[1]=1;
        }
        else {
            temp=getInverseModP(b,a%b);
            rtn[0]=temp[1];
            rtn[1]=temp[0]-(a/b)*temp[1]; 
        }
        return rtn;
    }
 
    public static void main(String[] args) {
        Scanner sc=new Scanner(System.in);
        Main main=new Main();
        long divider=1000000007;
         
        int T=sc.nextInt();
         
        FirstSort[] inputs=new FirstSort[T+1];
         
        int[] constructor=new int[2];
        inputs[0]=main.new FirstSort(constructor);
        for(int i=1;i<=T;i++) {
            constructor[0]=sc.nextInt();
            constructor[1]=i;
            inputs[i]=main.new FirstSort(constructor);
        }
        Arrays.sort(inputs);
 
         
        long enumerator=1;
        long denominator=1;
        long denomTemp=1;
         
        for(int i=0;i<T;i++) {
            for(int j=inputs[i].entry[0];j<inputs[i+1].entry[0];j++) {
                enumerator=(enumerator*(2*j+1)%divider)*(2*j+2)%divider;
                denominator=(denominator*(j+1))%divider;
            }
            denomTemp=(((denominator*denominator)%divider)*(inputs[i+1].entry[0]+1))%divider;
            denomTemp=main.getInverseModP(divider,denomTemp)[1]%divider;
            if(denomTemp<0)
                denomTemp+=divider;
            inputs[i].entry[0]=(int)(enumerator*denomTemp%divider);
            inputs[i].entry[1]=inputs[i+1].entry[1];
        }
         
 
        SecondSort[] results=new SecondSort[T];
         
        for(int i=0;i<T;i++) {
            results[i]=main.new SecondSort(inputs[i]);
        }
         
        Arrays.sort(results);
         
        for(int i=0;i<T;i++) {
            System.out.println(results[i].entry[0]);
        }
    }
}