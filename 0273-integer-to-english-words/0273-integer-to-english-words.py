class Solution:
    def numberToWords(self, num: int) -> str:
        if num == 0:
            return "Zero"

        units = {
            1: "One", 2: "Two", 3: "Three", 4: "Four", 5: "Five", 
            6: "Six", 7: "Seven", 8: "Eight", 9: "Nine", 10: "Ten",
            11: "Eleven", 12: "Twelve", 13: "Thirteen", 14: "Fourteen",
            15: "Fifteen", 16: "Sixteen", 17: "Seventeen", 18: "Eighteen",
            19: "Nineteen"
        }

        tens = {
            2: "Twenty", 3: "Thirty", 4: "Forty", 5: "Fifty", 
            6: "Sixty", 7: "Seventy", 8: "Eighty", 9: "Ninety"
        }

        def getHundred(num):
            result = []
            if num >= 100:
                n = num // 100
                result.append(units[n] + " Hundred")
                num %= 100
            if num >= 20:
                n = num // 10
                result.append(tens[n])
                num %= 10
            if num > 0:
                result.append(units[num])
            return " ".join(result)

        answer = []
        if num >= 1e9:
            n = num // 1e9
            answer.append(getHundred(n) + " Billion")
            num %= 1e9
        if num >= 1e6:
            n = num // 1e6
            answer.append(getHundred(n) + " Million")
            num %= 1e6
        if num >= 1e3:
            n = num // 1e3
            answer.append(getHundred(n) + " Thousand")
            num %= 1e3
        answer.append(getHundred(num))

        return " ".join(answer).strip()

