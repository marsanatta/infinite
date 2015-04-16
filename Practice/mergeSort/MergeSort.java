import java.util.Random;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class MergeSort {
	private static int[] arr;
	private static int[] tmp;
	private static int len;

	public static void main(String args[]) {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		try {	
			len = Integer.parseInt(br.readLine());
		}catch(IOException e) {
			System.err.println("readLine Error!");
		}
		arr = new int[len];
		Random rand = new Random();
		for (int i = 0; i < len; i++) {
			arr[i] = rand.nextInt(100);
		}
		printArray();
		System.out.println("sorting...");
		MergeSort ms = new MergeSort();
		ms.sort(0, len - 1);
		printArray();
	}


	public static void printArray() {
		System.out.println("array:");
		for (int i = 0; i < len; i++) {
			System.out.println(arr[i]);
		}
	}

	public void sort(int low, int high) {
		if (low < high) {
			int mid = low + (high - low) / 2;
			sort(low, mid);
			sort(mid + 1, high);
			merge(low, mid, high);
		}
	}

	public void merge(int low, int mid, int high) {
		int[] tmp = new int[high - low + 1];
		int l = low, h = mid+1, tmpLen = 0;
		while (l <= mid && h <= high) {
			if (arr[l] <= arr[h]) {
				tmp[tmpLen] = arr[l];
				l++;
			}
			else {
				tmp[tmpLen] = arr[h];
				h++;
			}
			tmpLen++;
		}
		if (l <= mid) {
			for (; l <= mid; l++, tmpLen++) {
				tmp[tmpLen] = arr[l];
			}
		}
		else if (h <= high) {
			for (; h <= high; h++, tmpLen++) {
				tmp[tmpLen] = arr[h];
			}
		}
		for (int i = low, j = 0; i <= high; i++, j++) {
			arr[i] = tmp[j];
		}
	}

}
