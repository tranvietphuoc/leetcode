impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut res = Vec::<i32>::new();
        for i in 0..(nums.len() - 1) {
            for j in (i + 1)..nums.len() {
                if nums[i] + nums[j] == target {
                    res.push(i as i32);
                    res.push(j as i32);
                }
            }
        }
        res
    }
}
