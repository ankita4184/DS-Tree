import java.io.*;
import java.util.*;
import java.lang.*;

public class avl{
    public static void main(String[] args){
        int size, temp;
        Scanner scan = new Scanner(System.in);
        size = scan.nextInt();
        Node root = new Node();
        while(size > 0){
            size--;
            temp = scan.nextInt(); 
            root = insert(root, temp);
            System.out.println(root.Height(root,left) - root.Height(root->right));
        }
    }
}

class Node{
    int data;
    Node left;
    Node right;
    public Node(){
      }
    public Node insert(Node root, int temp){
        if(root == null){
            Node t = new Node();
            t.data = temp;
            t.left = null;
            t.right = null;
            return t;
        }
        else if(root.data < temp){
            root.right = insert(root.right, temp);
            if(Height(root.right) - Height(root.left) == 2){
                if(root.right.data < temp)
                    root = SingleRotateR(root);  
                else
                    root = DoubleRotateR(root;
            }
        }
        else if(root.data > temp){
            root.left = insert(root.left, temp)
            if(Height(root.left) - Height(root.right) == 2){
                if(root.left.data 
       
