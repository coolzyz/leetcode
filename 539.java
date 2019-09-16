package com.leocool.marvel;

import java.util.List;
import java.util.ArrayList;

public class Solution {

	public static void test() {
		List<String> a = new ArrayList<>();
		a.add("23:59");
		a.add("00:00");
		System.err.println(findMinDifference(a));
	}

	public static int findMinDifference(List<String> timePoints) {

		ArrayList<Integer> b = new ArrayList<>();
		timePoints.forEach(one -> {
			b.add(getIntFromString(one));
		});
		b.sort((a,c)->{
			return a - c;
		});

		int min = 3000;
		for (int i = 0; i < b.size() - 1; ++i) {
			int j = i + 1;
			int ti = b.get(i);
			int tj = b.get(j);
			if (tj == ti)
				return 0;
			if (tj - ti < min && tj - ti > 0)
				min = tj - ti;
		}

		int tstart = b.get(0);
		int tend = b.get(b.size() - 1);
		if (tend - tstart < min && tend - tstart > 0) {
			min = tend - tstart;
		}
		if (tstart + 24 * 60 - tend < min) {
			min = tstart + 24 * 60 - tend;
		}
		return min;
	}

	private static int getIntFromString(String b) {
		String[] param = b.trim().split(":");
		return Integer.valueOf(param[0]) * 60 + Integer.valueOf(param[1]);
	}
}
