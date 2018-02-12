public class bst_generic<K extends Comparable<K>, V>
{

    private Node root;
    public void Insert(K key, V value){
        root = insert(root, key, value);
    }
    public Node insert(Node root, K key, V value){
        if(root == null) return new Node(key, value);
        int cmp = key.compareTo(root.key);
        if(cmp == 0) root.value = value; //updation
        if(cmp == 1) root.right = insert(root.right, key, value);
        if(cmp == -1) root.left = insert(root.left, key, value);
        return root;
    }
    public void inOrder(){
        Inorder(root);
    }
    public void Inorder(Node root){
        if(root == null) return;
        Inorder(root.left);
        System.out.println(root.key+" "+root.value);
        Inorder(root.right);
    }
    private class Node{
        private K key;
        private V value;
        private Node left;
        private Node right;
        
        public Node(K key, V value){
            this.key = key;
            this.value = value;
        }
    }
    public static void main(String[] args){
        bst_generic<Integer, String> bst = new bst_generic<>(); 
        bst.Insert(50, "Ankita");
        bst.Insert(20, "Anki");
        bst.Insert(30, "Ank");
        bst.Insert(40, "Ankit");
        bst.inOrder();
    }
}
