package leetcode;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
	public static int findShortestSubArray(int[] nums) {

		int ret = 0;
		// num index_begin index_end
		int max = 0;
		HashMap<Integer, Map.Entry<Integer, Integer>> tmp = new HashMap<>();
		// degree
		HashMap<Integer, Integer> n = new HashMap<>();
		for (int i = 0; i < nums.length; ++i) {
			Integer cur = n.get(nums[i]);
			if (cur != null) {
				cur++;
			} else {
				n.put(nums[i], 1);
			}
			
			tmp.get(nums[i]);
		}

		int maxkey = 0;
		for (Map.Entry<Integer, Integer> entry : n.entrySet()) {
			if (max < entry.getValue()) {
				maxkey = entry.getKey();
				max = entry.getValue();
			}
		}

		Map.Entry<Integer, Integer> target = tmp.get(maxkey);
		if (target != null) {
			return target.getValue() - target.getKey();
		}

		return 0;
	}
    
    public static void test() {
    	int []nums = new int[] {1, 2, 3};
    	System.err.println(Solution.findShortestSubArray(nums));
    }
    
    public static void main(String []args) {
    	Solution.test();
    }
}

