impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut tmp = x;
        if x == 0 {
            return x;
        }
        let mut reverse = 0;
        while tmp > 0 {
            let mut modulo = tmp % 10;
            reverse = reverse * 10 + modulo;
            tmp = tmp / 10;
        }
        reverse
    }
    pub fn is_palindrome(x: i32) -> bool {
        let reversed = Self::reverse(x);
        // println!("{}", reversed);
        if reversed == x {
            true
        } else {
            false
        }
    }
}
