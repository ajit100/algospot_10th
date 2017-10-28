#include <stdio.h>
#include <stdlib.h>

int check();
int charToInt(char c);
int charToDate(char*);

int main() {
   if (check()) printf("YES\n");
   else printf("NO\n");
}

int check() {
   //int input;
   char temp[9];
   


   //printf("연도 입력 (YYYYMMDD): ");
   while(1){
   scanf("%s", temp);
   
   if (charToDate(temp))
     break;
    
  }

    for (int i = 0; i < 7; i++) {
         for (int j = i; j > 0; j--) {
            if (charToInt(temp[i + 1]) + charToInt(temp[j]) == 10) return 1;
         }
      
      
   }
   
   //printf("날짜가 맞지 않음.\n");
   return 0;
}

int charToInt(char c) {
   switch (c) {
   case '1':return 1;
      break;
   case '2':return 2;
      break;
   case '3':return 3;
      break;
   case '4':return 4;
      break;
   case '5':return 5;
      break;
   case '6':return 6;
      break;
   case '7':return 7;
      break;
   case '8':return 8;
      break;
   case '9':return 9;
      break;
   case '0':return 0;
      break;
   default:return -1;
      break;
   }
}

int charToDate(char* temp) {
   int year = charToInt(temp[0]) * 1000 + charToInt(temp[1]) * 100 + charToInt(temp[2]) * 10 + charToInt(temp[3]);
   int month = charToInt(temp[4]) * 10 + charToInt(temp[5]);
   int day = charToInt(temp[6]) * 10 + charToInt(temp[7]);

   int lastDay[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };

   switch (month) {
   case 2: if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
      lastDay[1] = 29;
   case 1:
   case 3:
   case 4:
   case 5:
   case 6:
   case 7:
   case 8:
   case 9:
   case 10:
   case 11:
   case 12:
      if (0 < day || day < lastDay[month - 1]) return 1;
   default:
      return 0;
   }
}
