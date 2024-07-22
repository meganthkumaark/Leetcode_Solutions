class Solution:
    def minimumCost(self, m, n, horizontalCut, verticalCut):
        horizontalCut.sort(reverse=True)
        verticalCut.sort(reverse=True)

        hm, vm = 0, 0
        horizontalPieces, verticalPieces = 1, 1
        totalCost = 0

        while hm < len(horizontalCut) and vm < len(verticalCut):
            if horizontalCut[hm] > verticalCut[vm]:
                totalCost += horizontalCut[hm] * verticalPieces
                horizontalPieces += 1
                hm += 1
            else:
                totalCost += verticalCut[vm] * horizontalPieces
                verticalPieces += 1
                vm += 1

        while hm < len(horizontalCut):
            totalCost += horizontalCut[hm] * verticalPieces
            hm += 1

        while vm < len(verticalCut):
            totalCost += verticalCut[vm] * horizontalPieces
            vm += 1

        return totalCost