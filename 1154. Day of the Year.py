class Solution:
    months = (31,28,31,30,31,30,31,31,30,31,30,31)
    def dayOfYear(self, date: str) -> int:
        year, month, day, res = int(date[:4]), int(date[5:7]), int(date[8:]), 0
        for m in range(month-1):  # exclude current month
            res += self.months[m]
        res += day
        if (year % 400 == 0 or year % 4 == 0 and year % 100 != 0) and month > 2:
            res += 1    # in case of leap year
        # print(year, month, day)
        return res
