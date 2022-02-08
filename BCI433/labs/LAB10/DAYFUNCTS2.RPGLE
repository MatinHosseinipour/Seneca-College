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
001100211209         DCL-DS DayData;
001102211209              *N CHAR(9) INZ('Monday');
001104211209              *N CHAR(9) INZ ('Tuesday');
001106211209              *N CHAR(9) INZ ('Wednesday');
001108211209              *N CHAR(9) INZ ('Thursday');
001110211209              *N CHAR(9) INZ ('Fiday');
001112211209              *N CHAR(9) INZ ('Saturday');
001114211209              *N CHAR(9) INZ ('Sunday');
001116211209              DayArray Char(9) Dim(7) POS(1);
001117211209         END-DS;
003200200406
003201211209
003202211209           RETURN DayArray(Number);
003400190327        End-Proc;
