package test;

import java.util.Arrays;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);

			int r = in.nextInt();
			int c = in.nextInt();
			Point[] points = new Point[r * c];
			int k = 0;
			for (int i = 0; i < r; i++) {
				for (int j = 0; j < c; j++) {
					points[k] = new Point(in.nextInt());
					points[k].row = i;
					points[k].column = j;
					k++;
				}
			}
			in.close();

			Arrays.sort(points);

			 int maxLength = 0;
			int[] path = new int[points.length];
			for (int i = 0; i < points.length; i++) {
				int j = i - 1;
				while (j >= 0) {
					// if is neighbour point
					if (((points[i].column == points[j].column && Math.abs(points[i].row - points[j].row) == 1)
							|| (points[i].row == points[j].row && Math.abs(points[i].column - points[j].column) == 1))
							&& (points[i].height != points[j].height)) {
						path[i] = max(path[i], path[j]);
					}
					j--;
				}

				path[i] += 1;

				if (path[i] > maxLength) {
					maxLength = path[i];
				}
			}


		System.out.println(maxLength);
	}

	public static int max(int a, int b) {
		return a > b ? a : b;
	}
}

class Point implements Comparable<Point> {
	int height;
	int row;
	int column;

	public Point(int height) {
		this.height = height;
	}

	@Override
	public int compareTo(Point o) {
		if (this.height > o.height) {
			return 1;
		} else if (this.height == o.height) {
			return 0;
		} else {
			return -1;
		}

	}
}