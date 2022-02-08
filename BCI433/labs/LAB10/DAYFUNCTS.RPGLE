000100181112
000200181112
000300200406        Ctl-Opt NoMain  ;
000400200406
000500200726      // COPY THE PROTOTYPE HERE
000600211209         /COPY LAB10,DAYPROTO
000601211209
000700190327       Dcl-Proc DayNumName  EXPORT;
000800190327         Dcl-Pi *N CHAR(9) ;
000900200402           Number  Packed(1);
001000200406         End-PI;
001100200406
001200200406          DCL-s DayName Char(9);
001300200406
001400101103                 SELECT;
001500190327                     WHEN NUMBER = 1;
001600101103                     DAYNAME = 'Monday';
001700190327                     WHEN NUMBER = 2;
001800101103                     DAYNAME = 'Tuesday';
001900190327                     WHEN NUMBER = 3;
002000101103                     DAYNAME = 'Wednesday';
002100190327                     WHEN NUMBER = 4;
002200101103                     DAYNAME = 'Thursday';
002300190327                     WHEN NUMBER = 5;
002400101103                     DAYNAME = 'FRIDAY';
002500190327                     WHEN NUMBER = 6;
002600101103                     DAYNAME = 'Saturday';
002700190327                     WHEN NUMBER = 7;
002800101103                     DAYNAME = 'Sunday';
002900101103                     OTHER;
003000101103                     DAYNAME = 'Unknown';
003100101103                 ENDSL;
003200200406
003300101103                 Return Dayname;
003400190327        End-Proc;
