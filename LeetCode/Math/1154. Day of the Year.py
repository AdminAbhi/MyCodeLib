class Solution:
    def dayOfYear(self, date: str) -> int:
        y,m,d = map(int,date.split('-'))
        
        if m == 1: return d
        
        days_month = {1:31, 2:28, 3:31, 4:30, 5:31, 6:30, 7:31, 8:31, 9:30, 10:31, 11:30, 12:31}
        if ((y%4 == 0) and (y%100) != 0) or (y%400 == 0):
            days_month[2] = 29
        dayz = 0
        for i in range(1,m):
            dayz += days_month[i]
        dayz += d
        return dayz
