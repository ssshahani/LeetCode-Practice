# -*- coding: utf-8 -*-
"""
Created on Thu Aug 30 00:18:12 2018

@author: Sahil S
"""

#Integer to English Words

#Encapsulation

class IntegerToWords:
    def convertIntToWords(self,num):
        word_dict = {1000000000 : 'Billion', 
                     1000000 : 'Million', 
                     1000 : 'Thousand', 
                     100 : 'Hundred', 
                     90: 'Ninety', 
                     80: 'Eighty',
                     70: 'Seventy',
                     60: 'Sixty',
                     50: 'Fifty',
                     40: 'Forty',
                     30: 'Thirty',
                     20: 'Twenty',
                     19: 'Nineteen',
                     18: 'Eighteen',
                     17: 'Thirteen',
                     16: 'Fourteen',
                     15: 'Fifteen',
                     14: 'Foureen',
                     13: 'Thirteen',
                     12: 'Twelve',
                     11: 'Eleven',
                     9: 'Nine',
                     8: 'Eight',
                     7: 'Seven',
                     6: 'Six',
                     5: 'Five',
                     4: 'Four',
                     3: 'Three',
                     2: 'Two',
                     1: 'One',
                     0: 'Zero',
                     10: 'Ten' }
        keys = [1000000000,1000000,1000,100,90,80,70,60,50,40,30,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1,0]
        
        def internal_func(n):
            for div in keys:
                q,r = divmod(n,div)
                if not q: continue
                s1 = internal_func(q) + " " if div >= 100 else ""
                s2 = " " + internal_func(r) if r else ""
                return s1 + word_dict[div] + s2
                    
        return internal_func(num)
        
cnvt = IntegerToWords()
print(cnvt.convertIntToWords(910))