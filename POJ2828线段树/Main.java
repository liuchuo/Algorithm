package test;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		
		Node[] nodes = new Node[200100 * 3];
		while (in.hasNext()) {
			int n = in.nextInt();
			int[] pos = new int[n];
			int[] val = new int[n];
			
			for (int i = 0; i < n; i++) {
				pos[i] = in.nextInt();
				val[i] = in.nextInt();
			}
			buildTree(nodes, 1, 1, n);
			
			int[] leave = new int[n+1];
			for (int i = n-1; i >= 0; i--) {
				memory(nodes, 1, leave, pos[i]+1, val[i]);
			}
			
			for (int i = 1; i < leave.length - 1; i++) {
				System.out.print(leave[i] + " ");
			}
			System.out.println(leave[leave.length-1]);
		}
		in.close();
	}
	
	public static void memory(Node[] nodes, int i, int[] leave, int pos, int val) {
		int leftChild = i + i;
		int rightChild = leftChild + 1;
		
		if (nodes[i].left == nodes[i].right) {
			leave[nodes[i].left] = val;
		} else if (nodes[leftChild].emptySize >= pos) {
			nodes[leftChild].emptySize--;
			memory(nodes, leftChild, leave, pos, val);
			
		} else {
			nodes[rightChild].emptySize--;
			memory(nodes, rightChild, leave, pos - nodes[leftChild].emptySize, val);
			
		}
	}
	
	public static void buildTree(Node[] nodes, int i, int left, int right) {
		nodes[i] = new Node(left, right);
		if (nodes[i].emptySize > 1) {
			int mid = (left + right) / 2;
			buildTree(nodes, i + i, left, mid);
			buildTree(nodes, i + i + 1, mid + 1, right);
		}
	}
}

class Node {
	int emptySize;
	int left;
	int right;
	
	public Node(int left, int right) {
		this.left = left;
		this.right = right;
		this.emptySize = right - left + 1;
	}
}