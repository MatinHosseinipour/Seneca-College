000100211213       dcl-f Partreport printer oflind(*in01);
000101211213       Dcl-f Parts disk(*ext) keyed usage(*input) rename(Parts:partr);
000105211213       dcl-s PartCode Char(9);
000106211213
000107211213       dcl-s PartsTotal zoned(3);
000108211213       dcl-s Dummy zoned(1);
000109211213
000110211213       Exsr SummaryInfo;
000111211213
000112211213
000113211213
000114211213
000115211213
000116211213
000117211213
000118211213
000119211213       Begsr SummaryInfo;
000120211213       EXEC SQL
000121211213	     Select Count(*) Into :PartsTotal
000122211213            From SENECACORP/Parts;
000123211213       ENDSR;
