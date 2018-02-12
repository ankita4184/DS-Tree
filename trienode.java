import java.lang.Iterable;
public class trienode{
       
        int value = 0;
        trienode[] arr = new trienode[26];
        public void insert(String s){
            trienode p = this;
            int i;
            
            for( i = 0; i < s.length(); i++){
                int x =(int)( s.charAt(i) - 'a' );
                
                if( p.arr[x] == null)
                    p.arr[x] = new trienode();
                p = p.arr[x];
            }
            p.value = 1;
        }
      public boolean search(String s){
            trienode p = this;
            int i;
            
            for(i = 0; i < s.length(); i++){
                int x = (int)( s.charAt(i) - 'a' );
               
                if(p.arr[x] == null)
                    return false;
                p = p.arr[x];
            }
            return p.value == 1;
        }
   
        
               
     public static void main(String[] args){
              trienode root = new trienode();
            String s = new String();
            s = "ankita";
            root.insert(s);
            System.out.println(root.search("ankita"));
            System.out.println(root.search("ankita"));
        
         
        }

}
