000100191105       //***********************************************************************
000200191105       //* THIS PROGRAM USES A CURSOR TO LOAD A TEMPORARY RESULT TABLE FROM 3
000300191105       //* SEPARATE TABLES, ONTARIO, QUEBEC AND MANITOBA. A NUMBER IS PASSED
000400191105       //* TO THE PROGRAM TO DETERMINE WHICH RECORDS ARE INLCUDED FROM THE 3 TAB
000500191105       //***********************************************************************
000600190313           DCL-F PROVREPORT PRINTER OFLIND(*IN01) ;
000700190313           DCL-S ProvinceH    Char(10);
000800190313           DCL-S EndOfFile    IND;
000900190313           DCL-S TotalRecords PACKED(5:0) ;
001000211104       // LowLimit is passed to the program
001001211201           DCL-PI MAIN EXTPGM('PROVSQL');
001002211201             LowLimitIn Packed(15:5);
001003211201           END-PI;
001006211104       // All Host Variables available under a single name
001100211201           DCL-DS CustomerRecord;
001101211201             CustId    Char(6);
001102211201             FullName  Char(31);
001103211201             City      Char(20);
001104211201             Purchase  Packed(7:2);
001105211201             PDate     Date;
001106211201             Province  Char(10);
001108211201           END-DS;
002300070123     C/EJECT
002400070123     C**************************************************************************
002500070123     C*                        ***   M A I N   R O U T I N E   ***
002600070123     C**************************************************************************
002700070118      /FREE
002800191105                LowLimit = LowLimitIn;
002900100309                EXSR PrepareFiles;
003000211104                Write StartOfRpt;
003100211104                Write ColHeading;
003200100309                EXSR GetRow;
003300190313                Write NewProv;
003400070209                ProvinceH = Province;
003500070202                DOW NOT EndOfFile;
003600190313                    IF *IN01 = *ON;
003700211104                        Write StartOfRpt;
003800211104                        Write ColHeading;
003900190313                       *IN01 = *OFF;
004000070209                    ENDIF;
004001211104           // Province may change
004101211201                    IF ProvinceH = Province;
004102211201                      Write CustDetail;
004103211201                    ELSE;
004104211201                      ProvinceH = Province;
004105211201                      Write TotalPurch;
004106211201                      TotalAmt = 0;
004107211201                      Write NewProv;
004108211201                      Write CustDetail;
004109211201                    ENDIF;
005000211201                    TotalAmt = TotalAmt + Purchase;
005100070202                    TotalRecords= TotalRecords + 1;
005200100309                    EXSR GetRow;
005300070119                ENDDO;
005400211104                Write TotalPurch;
005500070202                EXSR   WRAPUP;
005600211104                Write LessThan;
005700070119                *INLR = *ON;
005800070119                RETURN;
005900100309        //**********************************************************************
006000100309        // O P E N F I L E S   S U B R O U T I N E
006100100309        //**********************************************************************
006200211201           BEGSR  PrepareFiles;
006300100309        // S E T   U P   T H E   T E M P O R A R Y   R E S U L T  S T R U C T U
006400211201           EXEC SQL
006401211201             DECLARE ALLPROVCURSOR CURSOR
006402211201               FOR
006403211201             SELECT CUSTID,
006404211201                    TRIM(FNAME) || ' ' || LNAME,
006405211201                    CITY,
006406211201                    PURCHASE,
006407211201                    PDATE,
006408211201                    'Ontario' AS PROVINCE
006409211201             FROM BCI433LIB/ONTARIO
006410211201             WHERE PURCHASE >= :LowLimitIn
006411211201             UNION ALL
006412211201             SELECT CUSTID,
006413211201                    TRIM(FNAME) || ' ' || LNAME,
006414211201                    CITY,
006415211201                    PURCHASE,
006416211201                    PDATE,
006417211201                    'Quebec' AS PROVINCE
006418211201             FROM BCI433LIB/QUEBEC
006419211201             WHERE PURCHASE >= :LowLimitIn
006420211201             UNION ALL
006421211201             SELECT CUSTID,
006422211201                    TRIM(FNAME) || ' ' || LNAME,
006423211201                    CITY,
006424211201                    PURCHASE,
006425211201                    PDATE,
006426211201                    'MANITOBA' AS PROVINCE
006427211201             FROM BCI433LIB/MANITOBA
006428211201             WHERE PURCHASE >= :LowLimitIn
006429211201             FOR READ ONLY;
006432211201             EXEC SQL
006433211201               SELECT COUNT(*)
006434211201               INTO :ONTTOTAL
006435211201               FROM BCI433LIB/ONTARIO
006436211201             WHERE PURCHASE < :LowLimitIn;
006437211201             EXEC SQL
006438211201               SELECT COUNT(*)
006439211201               INTO :QUETOTAL
006440211201               FROM BCI433LIB/QUEBEC
006441211201             WHERE PURCHASE < :LowLimitIn;
006442211201             EXEC SQL
006443211201               SELECT COUNT(*)
006444211201               INTO :MANTOTAL
006445211201               FROM BCI433LIB/MANITOBA
006446211201             WHERE PURCHASE < :LowLimitIn;
008600211201          // A   T E M P O R A R Y   R E S U L T   T A B L E   I S   C R E A T E D
008700211201              EXEC SQL
008701211201               OPEN ALLPROVCURSOR;
008702211201
008703211201              If (SQLCODE <> 0) or (SQLWN0 = 'w');
008704211201	          EndOfFile = *ON;
008705211201            ENDIF;
009500100309            ENDSR;
009600100309        //**********************************************************************
009700100309        //   G E T     R O W    S U B R O U T I N E
009800100309        //**********************************************************************
009900100309            BEGSR     GETROW;
010000211104
010001211201              EXEC SQL
010002211201               FETCH NEXT
010003211201                 FROM ALLPROVCURSOR
010004211201                 INTO :CustomerRecord;
010005211201
010006211201              IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
010007211201                 EndOfFile = *ON;
010008211201              ENDIF;
011000100309             ENDSR;
011100100309        //**********************************************************************
011200100309        // W R A P U P     S U B R O U T I N E
011300100309        //**********************************************************************
011400100309           BEGSR WRAPUP;
011500211201             EXEC SQL
011501211201               CLOSE ALLPROVCURSOR;
011502211201
011503211201             IF (SQLCODE <> 0) OR (SQLWN0 = 'W');
011504211201               DSPLY 'PROBLEM CLOSING THE CURSOR';
011505211201             ENDIF;
014700100309          ENDSR;
