class Solution:
    def minimumCost(self, m, n, horizontalCut, verticalCut):
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)

        hm_segments = 1
        vm_segments = 1

        total_cost = 0
        hm_pointer = 0
        vm_pointer = 0

        while hm_pointer < len(horizontalCut) and vm_pointer < len(verticalCut):
            if horizontalCut[hm_pointer] > verticalCut[vm_pointer]:
                total_cost += horizontalCut[hm_pointer] * vm_segments
                hm_segments += 1
                hm_pointer += 1
            else:
                total_cost += verticalCut[vm_pointer] * hm_segments
                vm_segments += 1
                vm_pointer += 1

        while hm_pointer < len(horizontalCut):
            total_cost += horizontalCut[hm_pointer] * vm_segments
            hm_segments += 1
            hm_pointer += 1

        while vm_pointer < len(verticalCut):
            total_cost += verticalCut[vm_pointer] * hm_segments
            vm_segments += 1
            vm_pointer += 1

        return total_cost