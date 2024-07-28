class Solution:
    def nonSpecialCount(self, left: int, right: int) -> int:
        import math

        max_root = int(math.sqrt(right)) + 1

        is_prime = [True] * (max_root + 1)
        is_prime[0] = is_prime[1] = False  

        for i in range(2, int(math.sqrt(max_root)) + 1):
            if is_prime[i]:
                for j in range(i * i, max_root + 1, i):
                    is_prime[j] = False

        spl_nums = set()
        for i in range(2, max_root + 1):
            if is_prime[i]:
                spl_num = i * i
                if left <= spl_num <= right:
                    spl_nums.add(spl_num)

        total_count = right - left + 1

        spl_count = sum(1 for num in spl_nums if left <= num <= right)

        return total_count - spl_count
