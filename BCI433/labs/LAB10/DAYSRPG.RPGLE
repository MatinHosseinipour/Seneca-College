000100200402          DCL-f DayDsp Workstn;
000200200726          Dcl-PI  Main  extPgm('DAYSRPG');
000300200726             Solution   char(15);
000400200726         End-PI;
000500200726      // COPY THE PROTOTYPE HERE
000600211209            /COPY LAB10,DAYPROTO
000601211209
000700200402           EXFMT INPUT;
000800170918           DOW NOT(*IN03);
000900211129              // the user defined function
001000211209              DayName = DayNumName(DayIn);
001100190327              *in99 = *on;
001200200402               WRITE INPUT;
001300200402               EXFMT OUTPUT;
001400190327              *in99 = *off;
001500170918               IF *IN03 = '0';
001600200402                 DayIn = 0;
001700200402                 EXFMT INPUT ;
001800170918               ENDIF;
001900170918            ENDDO;
002000170918            *INLR = *ON;
002100170918            RETURN;
002200170918
002300170918
