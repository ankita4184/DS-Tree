import java.lang.*;
import java.util.*;
public class ifaword {
        int value = 0;
        ifaword[] arr = new ifaword[26];
        public boolean check(String s){
            ifaword p = this;
            for(int i = 0; i < s.length(); i++){
                int x = (int)(s.charAt(i) - 'a');
                if(p.arr[x] == null)
                    return false;
                p = p.arr[x];
            }
            return p.value == 1;
        }
        public void insert(String s){
            ifaword p = this;
            for(int i = 0; i < s.length(); i++){
                int x = (int)(s.charAt(i) - 'a');
                if(p.arr[x] == null)
                    p.arr[x] = new ifaword();
                p = p.arr[x];
            }
            p.value = 1;
        }
        public int permute(String s){
            String che = s;
            int count = 0;
            do{
                if(check(che))
                    count++;
                che = nextPermutation(che);
              }while(che != null);
            return count;
        }
        public static void main(String[] args){
            ifaword root = new ifaword();
            root.insert("ankita");
            root.permute("aaiknt");
        }
}
