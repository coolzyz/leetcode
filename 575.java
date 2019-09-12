package com.leocool.marvel;

import java.util.HashSet;

public class Solution {


	public static int distributeCandies(int[] candies) {
		if (candies.length == 0)
			return 0;

		int targetnum = candies.length / 2;
		HashSet<Integer> kinds = new HashSet<>();
		for (int i = 0; i < candies.length; ++i) {
			kinds.add(candies[i]);
		}
		if (kinds.size() <= targetnum) {
			return kinds.size();
		} else {
			return targetnum;
		}
	}

	public static void test() {
		int []a = new int[] {1,1,2,3};
		System.err.println(distributeCandies(a));
	}
}
