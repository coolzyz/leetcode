import java.util.AbstractMap;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

class Solution {
	public static int findShortestSubArray(int[] nums) {
		if (nums.length == 0) {
			return 0;
		}
		// num index_begin index_end
		HashMap<Integer, Map.Entry<Integer, Integer>> tmp = new HashMap<>();
		// degree
		HashMap<Integer, Integer> n = new HashMap<>();
		for (int i = 0; i < nums.length; ++i) {
			Integer cur = n.get(nums[i]);
			if (cur != null) {
				n.put(nums[i], cur + 1);
			} else {
				n.put(nums[i], 1);
			}

			Map.Entry<Integer, Integer> target = tmp.get(nums[i]);
			if (target != null) {
				target.setValue(i);
			} else {
				Map.Entry<Integer, Integer> entry = new AbstractMap.SimpleEntry<Integer, Integer>(i, i);
				tmp.put(nums[i], entry);
			}
		}

		int max = 0;
		// 计算最大度
		ArrayList<Integer> finals = new ArrayList<>();
		for (Map.Entry<Integer, Integer> entry : n.entrySet()) {
			if (max <= entry.getValue()) {
				max = entry.getValue();
			}
		}
		// 过滤所有度是max的数字
		for (Map.Entry<Integer, Integer> entry : n.entrySet()) {
			if (entry.getValue() == max)
				finals.add(entry.getKey());
		}

		// 度是max中取最小长度
		int ret = 60000;
		for (Integer v : finals) {
			Map.Entry<Integer, Integer> target = tmp.get(v);
			int cur = target.getValue() - target.getKey() + 1;
			if (ret > cur) {
				ret = cur;
			}
		}

		return ret;
	}

	public static void test() {
		int []nums = new int[] {1,2,2,3,1,4,2};
		System.err.println(Solution.findShortestSubArray(nums));
	}
}

