# list of Oracle chracter set names

This list was got by [charset-list.c][charset-list.c] using Oracle instant client 12.2.0.1 on Linux x86_64.
The first and second columns are the Oracle character set id and name.
The third column is the IANA character set name got from the second column by OCINlsNameMap() with `OCI_NLS_CS_ORA_TO_IANA` flag.
The forth column is the Oralce character set name got from the third column by OCINlsNameMap() with `OCI_NLS_CS_IANA_TO_ORA` flag. When the name is same with the second column, it is :+1:. Otherwise, :-1: is prepended.

  ID  |        Oracle name        |      IANA name     | IANA to Oracle
------|---------------------------|--------------------|----------------
   1  | US7ASCII                  | US-ASCII           | :+1:
   2  | WE8DEC                    | DEC-MCS            | :+1:
   3  | WE8HP                     |                    |
   4  | US8PC437                  | CP437              | :+1:
   5  | WE8EBCDIC37               | CP037              | :+1:
   6  | WE8EBCDIC500              | CP500              | :+1:
   7  | WE8EBCDIC1140             | CP01140            | :+1:
   8  | WE8EBCDIC285              | CP285              | :+1:
   9  | WE8EBCDIC1146             | CP01146            | :+1:
   10 | WE8PC850                  | CP850              | :+1:
   11 | D7DEC                     | DIN_66003          | :+1:
   12 | F7DEC                     | NF_Z_62-010_(1973) | :+1:
   13 | S7DEC                     |                    |
   14 | E7DEC                     | ES                 | :+1:
   15 | SF7ASCII                  | SEN_850200_B       | :+1:
   16 | NDK7DEC                   |                    |
   17 | I7DEC                     | IT                 | :+1:
   18 | NL7DEC                    |                    |
   19 | CH7DEC                    |                    |
   20 | YUG7ASCII                 | JUS_I.B1.002       | :+1:
   21 | SF7DEC                    |                    |
   22 | TR7DEC                    |                    |
   23 | IW7IS960                  |                    |
   25 | IN8ISCII                  |                    |
   27 | WE8EBCDIC1148             | CP01148            | :+1:
   28 | WE8PC858                  | CP00858            | :+1:
   31 | WE8ISO8859P1              | ISO-8859-1         | :+1:
   32 | EE8ISO8859P2              | ISO-8859-2         | :+1:
   33 | SE8ISO8859P3              | ISO-8859-3         | :+1:
   34 | NEE8ISO8859P4             | ISO-8859-4         | :+1:
   35 | CL8ISO8859P5              | ISO-8859-5         | :+1:
   36 | AR8ISO8859P6              | ISO-8859-6         | :+1:
   37 | EL8ISO8859P7              | ISO-8859-7         | :+1:
   38 | IW8ISO8859P8              | ISO-8859-8-I       | :+1:
   39 | WE8ISO8859P9              | ISO-8859-9         | :+1:
   40 | NE8ISO8859P10             | ISO-8859-10        | :+1:
   41 | TH8TISASCII               | TIS-620            | :+1:
   42 | TH8TISEBCDIC              |                    |
   43 | BN8BSCII                  |                    |
   44 | VN8VN3                    |                    |
   45 | VN8MSWIN1258              | WINDOWS-1258       | :+1:
   46 | WE8ISO8859P15             | ISO-8859-15        | :+1:
   47 | BLT8ISO8859P13            | ISO-8859-13        | :+1:
   48 | CEL8ISO8859P14            | ISO-8859-14        | :+1:
   49 | CL8ISOIR111               |                    |
   50 | WE8NEXTSTEP               |                    |
   51 | CL8KOI8U                  | KOI8-U             | :+1:
   52 | AZ8ISO8859P9E             |                    |
   61 | AR8ASMO708PLUS            |                    |
   70 | AR8EBCDICX                | CP420              | :-1: AR8EBCDIC420S
   72 | AR8XBASIC                 |                    |
   81 | EL8DEC                    |                    |
   82 | TR8DEC                    |                    |
   90 | WE8EBCDIC37C              | CP037              | :-1: WE8EBCDIC37
   91 | WE8EBCDIC500C             | CP500              | :-1: WE8EBCDIC500
   92 | IW8EBCDIC424              | CP424              | :+1:
   93 | TR8EBCDIC1026             | CP1026             | :+1:
   94 | WE8EBCDIC871              | CP871              | :+1:
   95 | WE8EBCDIC284              | CP284              | :+1:
   96 | WE8EBCDIC1047             | IBM1047            | :+1:
   97 | WE8EBCDIC1140C            | CP01140            | :-1: WE8EBCDIC1140
   98 | WE8EBCDIC1145             | CP01145            | :+1:
   99 | WE8EBCDIC1148C            | CP01148            | :-1: WE8EBCDIC1148
  100 | WE8EBCDIC1047E            | IBM1047            | :-1: WE8EBCDIC1047
  101 | WE8EBCDIC924              | CP00924            | :+1:
  110 | EEC8EUROASCI              |                    |
  113 | EEC8EUROPA3               |                    |
  114 | LA8PASSPORT               |                    |
  140 | BG8PC437S                 |                    |
  150 | EE8PC852                  | CP852              | :+1:
  152 | RU8PC866                  | CP866              | :+1:
  153 | RU8BESTA                  |                    |
  154 | IW8PC1507                 | CP862              | :+1:
  155 | RU8PC855                  | CP855              | :+1:
  156 | TR8PC857                  | CP857              | :+1:
  158 | CL8MACCYRILLIC            |                    |
  159 | CL8MACCYRILLICS           |                    |
  160 | WE8PC860                  | CP860              | :+1:
  161 | IS8PC861                  | CP861              | :+1:
  162 | EE8MACCES                 |                    |
  163 | EE8MACCROATIANS           |                    |
  164 | TR8MACTURKISHS            |                    |
  165 | IS8MACICELANDICS          |                    |
  166 | EL8MACGREEKS              |                    |
  167 | IW8MACHEBREWS             |                    |
  170 | EE8MSWIN1250              | WINDOWS-1250       | :+1:
  171 | CL8MSWIN1251              | WINDOWS-1251       | :+1:
  172 | ET8MSWIN923               |                    |
  173 | BG8MSWIN                  |                    |
  174 | EL8MSWIN1253              | WINDOWS-1253       | :+1:
  175 | IW8MSWIN1255              | WINDOWS-1255       | :+1:
  176 | LT8MSWIN921               |                    |
  177 | TR8MSWIN1254              | WINDOWS-1254       | :+1:
  178 | WE8MSWIN1252              | WINDOWS-1252       | :+1:
  179 | BLT8MSWIN1257             | WINDOWS-1257       | :+1:
  180 | D8EBCDIC273               | CP273              | :+1:
  181 | I8EBCDIC280               | CP280              | :+1:
  182 | DK8EBCDIC277              | IBM277             | :+1:
  183 | S8EBCDIC278               | CP278              | :+1:
  184 | EE8EBCDIC870              | CP870              | :+1:
  185 | CL8EBCDIC1025             |                    |
  186 | F8EBCDIC297               | CP297              | :+1:
  187 | IW8EBCDIC1086             |                    |
  188 | CL8EBCDIC1025X            |                    |
  189 | D8EBCDIC1141              | CP01141            | :+1:
  190 | N8PC865                   | CP865              | :+1:
  191 | BLT8CP921                 |                    |
  192 | LV8PC1117                 |                    |
  193 | LV8PC8LR                  |                    |
  194 | BLT8EBCDIC1112            |                    |
  195 | LV8RST104090              |                    |
  196 | CL8KOI8R                  | KOI8-R             | :+1:
  197 | BLT8PC775                 | CP775              | :+1:
  198 | DK8EBCDIC1142             | CP01142            | :+1:
  199 | S8EBCDIC1143              | CP01143            | :+1:
  200 | I8EBCDIC1144              | CP01144            | :+1:
  201 | F7SIEMENS9780X            |                    |
  202 | E7SIEMENS9780X            |                    |
  203 | S7SIEMENS9780X            | SEN_850200_C       | :+1:
  204 | DK7SIEMENS9780X           | NS_4551-1          | :-1: N7SIEMENS9780X
  205 | N7SIEMENS9780X            | NS_4551-1          | :+1:
  206 | I7SIEMENS9780X            | IT                 | :-1: I7DEC
  207 | D7SIEMENS9780X            | DIN_66003          | :-1: D7DEC
  208 | F8EBCDIC1147              | CP01147            | :+1:
  210 | WE8GCOS7                  |                    |
  211 | EL8GCOS7                  |                    |
  221 | US8BS2000                 |                    |
  222 | D8BS2000                  |                    |
  223 | F8BS2000                  |                    |
  224 | E8BS2000                  |                    |
  225 | DK8BS2000                 |                    |
  226 | S8BS2000                  |                    |
  230 | WE8BS2000E                |                    |
  231 | WE8BS2000                 |                    |
  232 | EE8BS2000                 |                    |
  233 | CE8BS2000                 |                    |
  235 | CL8BS2000                 |                    |
  239 | WE8BS2000L5               |                    |
  241 | WE8DG                     |                    |
  251 | WE8NCR4970                | DEC-MCS            | :-1: WE8DEC
  261 | WE8ROMAN8                 | HP-ROMAN8          | :+1:
  262 | EE8MACCE                  |                    |
  263 | EE8MACCROATIAN            |                    |
  264 | TR8MACTURKISH             |                    |
  265 | IS8MACICELANDIC           |                    |
  266 | EL8MACGREEK               |                    |
  267 | IW8MACHEBREW              |                    |
  277 | US8ICL                    |                    |
  278 | WE8ICL                    |                    |
  279 | WE8ISOICLUK               |                    |
  301 | EE8EBCDIC870C             | CP870              | :-1: EE8EBCDIC870
  311 | EL8EBCDIC875S             |                    |
  312 | TR8EBCDIC1026S            | CP1026             | :-1: TR8EBCDIC1026
  314 | BLT8EBCDIC1112S           |                    |
  315 | IW8EBCDIC424S             | CP424              | :-1: IW8EBCDIC424
  316 | EE8EBCDIC870S             | CP870              | :-1: EE8EBCDIC870
  317 | CL8EBCDIC1025S            |                    |
  319 | TH8TISEBCDICS             |                    |
  320 | AR8EBCDIC420S             | CP420              | :+1:
  322 | CL8EBCDIC1025C            |                    |
  323 | CL8EBCDIC1025R            |                    |
  324 | EL8EBCDIC875R             |                    |
  325 | CL8EBCDIC1158             |                    |
  326 | CL8EBCDIC1158R            |                    |
  327 | EL8EBCDIC423R             | CP423              | :+1:
  351 | WE8MACROMAN8              | MACINTOSH          | :+1:
  352 | WE8MACROMAN8S             | MACINTOSH          | :-1: WE8MACROMAN8
  353 | TH8MACTHAI                |                    |
  354 | TH8MACTHAIS               |                    |
  368 | HU8CWI2                   |                    |
  380 | EL8PC437S                 |                    |
  381 | EL8EBCDIC875              |                    |
  382 | EL8PC737                  |                    |
  383 | LT8PC772                  |                    |
  384 | LT8PC774                  |                    |
  385 | EL8PC869                  | CP869              | :+1:
  386 | EL8PC851                  | CP851              | :+1:
  390 | CDN8PC863                 | CP863              | :+1:
  401 | HU8ABMOD                  |                    |
  500 | AR8ASMO8X                 |                    |
  504 | AR8NAFITHA711T            |                    |
  505 | AR8SAKHR707T              |                    |
  506 | AR8MUSSAD768T             |                    |
  507 | AR8ADOS710T               |                    |
  508 | AR8ADOS720T               |                    |
  509 | AR8APTEC715T              |                    |
  511 | AR8NAFITHA721T            |                    |
  514 | AR8HPARABIC8T             |                    |
  554 | AR8NAFITHA711             |                    |
  555 | AR8SAKHR707               |                    |
  556 | AR8MUSSAD768              |                    |
  557 | AR8ADOS710                |                    |
  558 | AR8ADOS720                |                    |
  559 | AR8APTEC715               |                    |
  560 | AR8MSWIN1256              | WINDOWS-1256       | :+1:
  561 | AR8NAFITHA721             |                    |
  563 | AR8SAKHR706               |                    |
  565 | AR8ARABICMAC              |                    |
  566 | AR8ARABICMACS             |                    |
  567 | AR8ARABICMACT             |                    |
  590 | LA8ISO6937                |                    |
  798 | WE8DECTST                 |                    |
  829 | JA16VMS                   | EUC-JP             | :-1: JA16EUC
  830 | JA16EUC                   | EUC-JP             | :+1:
  831 | JA16EUCYEN                | EUC-JP             | :-1: JA16EUC
  832 | JA16SJIS                  | SHIFT_JIS          | :+1:
  833 | JA16DBCS                  |                    |
  834 | JA16SJISYEN               | SHIFT_JIS          | :-1: JA16SJIS
  835 | JA16EBCDIC930             |                    |
  836 | JA16MACSJIS               |                    |
  837 | JA16EUCTILDE              | EUC-JP             | :-1: JA16EUC
  838 | JA16SJISTILDE             | SHIFT_JIS          | :-1: JA16SJIS
  840 | KO16KSC5601               | EUC-KR             | :-1: KO16MSWIN949
  842 | KO16DBCS                  |                    |
  845 | KO16KSCCS                 |                    |
  846 | KO16MSWIN949              | EUC-KR             | :+1:
  850 | ZHS16CGB231280            | GBK                | :-1: ZHS16GBK
  851 | ZHS16MACCGB231280         |                    |
  852 | ZHS16GBK                  | GBK                | :+1:
  853 | ZHS16DBCS                 |                    |
  854 | ZHS32GB18030              | GB18030            | :+1:
  860 | ZHT32EUC                  |                    |
  861 | ZHT32SOPS                 |                    |
  862 | ZHT16DBT                  |                    |
  863 | ZHT32TRIS                 |                    |
  864 | ZHT16DBCS                 |                    |
  865 | ZHT16BIG5                 | BIG5               | :-1: ZHT16MSWIN950
  866 | ZHT16CCDC                 |                    |
  867 | ZHT16MSWIN950             | BIG5               | :+1:
  868 | ZHT16HKSCS                | BIG5-HKSCS         | :+1:
  870 | AL24UTFFSS                |                    |
  871 | UTF8                      | UTF-8              | :-1: AL32UTF8
  872 | UTFE                      |                    |
  873 | AL32UTF8                  | UTF-8              | :+1:
  992 | ZHT16HKSCS31              | BIG5-HKSCS         | :-1: ZHT16HKSCS
  993 | ZHT32EUCTST               |                    |
  994 | WE16DECTST2               |                    |
  995 | WE16DECTST                |                    |
  996 | KO16TSTSET                |                    |
  997 | JA16TSTSET2               |                    |
  998 | JA16TSTSET                |                    |
 1000 | UTF16                     | UTF-16             | :+1:
 1001 | US16TSTFIXED              |                    |
 1002 | TIMESTEN8                 |                    |
 1830 | JA16EUCFIXED              |                    |
 1832 | JA16SJISFIXED             |                    |
 1833 | JA16DBCSFIXED             |                    |
 1840 | KO16KSC5601FIXED          |                    |
 1842 | KO16DBCSFIXED             |                    |
 1850 | ZHS16CGB231280FIXED       |                    |
 1852 | ZHS16GBKFIXED             |                    |
 1853 | ZHS16DBCSFIXED            |                    |
 1860 | ZHT32EUCFIXED             |                    |
 1863 | ZHT32TRISFIXED            |                    |
 1864 | ZHT16DBCSFIXED            |                    |
 1865 | ZHT16BIG5FIXED            |                    |
 2000 | AL16UTF16                 | UTF-16BE           | :+1:
 2002 | AL16UTF16LE               | UTF-16LE           | :+1:
 9994 | ISO2022-JP-OUTLOOK        | ISO-2022-JP        | :-1: ISO2022-JP
 9995 | ISO2022-JP-OUTLOOK-HWKANA | ISO-2022-JP        | :-1: ISO2022-JP
 9996 | HZ-GB-2312                | HZ-GB-2312         | :+1:
 9997 | ISO2022-KR                | ISO-2022-KR        | :+1:
 9998 | ISO2022-CN                | ISO-2022-CN        | :+1:
 9999 | ISO2022-JP                | ISO-2022-JP        | :+1:

## EUC-JP character sets (Japanese chracter set on Unix)

There are four Oracle character set names whose IANA name is EUC-JP.
One of them, 'JA16VMS', is ancient. The rests are 'JA16EUC', 'JA16EUCTILDE' and 'JA16EUCYEN'.

Mapping form EUC-JP byte sequences to unicode codepoints:

EUC-JP byte sequence | JA16EUC | JA16EUCTILDE | JA16EUCYEN
---|---|---|---
`5C`(&yen;) | U+005C(&#x5C;) | U+005C(&#x5C;) | U+00A5(&#xA5;)
`A1 C1` | U+301C(&#x301C;) | U+FF5E(&#xFF5E;) | U+301C(&#x301C;)
`8F A2 B7` | U+FF5E(&#xFF5E;) | U+FF5E(&#xFF5E;) | U+FF5E(&#xFF5E;)

All other byte sequences are mapped to same codepoints.

Mapping form unicode codepoints to EUC-JP byte sequences:

Unicode codepoint | JA16EUC | JA16EUCTILDE | JA16EUCYEN
---|---|---|---
U+005C(&#x5C;) | `5C`(&yen;) | `5C`(&yen;) | `5C`(&yen;)
U+00A5(&#xA5;) | `5C`(&yen;) | `5C`(&yen;) | `5C`(&yen;)
U+301C(&#x301C;) | `A1 C1` | `A1 C1` | `A1 C1`
U+FF5E(&#xFF5E;) | `8F A2 B7` | `A1 C1` | `8F A2 B7`

All other codepoints are mapped to same byte sequences.

## Shift_JIS character sets (Japanese chracter set on Windows)

There are three Oracle character set names whose IANA name is Shift_JIS.

Mapping form Shift_JIS byte sequences to unicode codepoints:

Shift_JIS byte sequence | JA16SJIS | JA16SJISTILDE | JA16SJISYEN
---|---|---|---
`5C`(&yen;) | U+005C(&#x5C;) | U+005C(&#x5C;) | U+00A5(&#xA5;)
`81 60` | U+301C(&#x301C;) | U+FF5E(&#xFF5E;) | U+301C(&#x301C;)

All other byte sequences are mapped to same codepoints.

Mapping form Shift_JIS byte sequences to unicode codepoints:

Unicode codepoint | JA16SJIS | JA16SJISTILDE | JA16SJISYEN
---|---|---|---
U+005C(&#x5C;) | `5C`(&yen;) | `5C`(&yen;) | `5C`(&yen;)
U+00A5(&#xA5;) | `5C`(&yen;) | `5C`(&yen;) | `5C`(&yen;)
U+301C(&#x301C;) | `81 60` | `81 60` | `81 60`
U+FF5E(&#xFF5E;) | `81 60` | `81 60` | `81 60`

All other codepoints are mapped to same byte sequences about JA16SJIS
and JA16SJISTILDE. However JA16SJISYEN is different.

Unicode codepoints | JA16SJIS, JA16SJISTILDE | JA16SJISYEN
---|---|---
U+00A1(&#xA1;) | 21(!) | FA 55(&#xFFE4;)
U+00A6(&#xA6;) | 7C(\|) | FA 55(&#xFFE4;)
U+00A9(&#xA9;) | 63(c) | ?
U+00AA(&#xAA;) | 61(a) | ?
U+00AB(&#xAB;) | 81 E1(&#xFF3F;) | ?
U+00AD(&#xAD;) | 2D(-) | ?
U+00AE(&#xAE;) | 52(R) | ?
U+00AF(&#xAF;) | 81 50(&#xFFE3;) | ?
... | ... | ...

## Appendix EUC-JP and Shift_JIS mapping in ruby

I checked conversions in ruby as above.

Mapping form EUC-JP byte sequences to unicode codepoints:

EUC-JP byte sequence | EUC-JP | EUC-JIS-2004 | CP51932 | eucJP-ms
---|---|---|---|---
`5C`(&yen;) | U+005C(&#x5C;) | U+005C(&#x5C;) | U+005C(&#x5C;) | U+005C(&#x5C;)
A1 C1 | U+301C(&#x301C;) | U+301C(&#x301C;) | U+FF5E(&#xFF5E;) | U+FF5E(&#xFF5E;)
8F A2 B7 | U+007E(&#x007E) | Error | Error | U+FF5E(&#xFF5E;)

Other bytes sequences were not checked.

Mapping form unicode codepoints to EUC-JP byte sequences:

Unicode codepoint | EUC-JP | EUC-JIS-2004 | CP51932 | eucJP-ms
---|---|---|---|---
U+005C(&#x5C;) | `5C`(&yen;) | `5C`(&yen;) | `5C`(&yen;) | `5C`(&yen;)
U+00A5(&#xA5;) | Error | Error | Error | Error
U+301C(&#x301C;) | A1 C1 | A1 C1 | Error | Error
U+FF5E(&#xFF5E;) | Error | A2 B2 | A1 C1 | A1 C1

Other codepoints were not checked.

Mapping form Shift_JIS byte sequences to unicode codepoints:

Shift_JIS byte sequence | Shift_JIS | Windows-31J
---|---|---
`5C`(&yen;) | U+005C(&#x5C;) | U+005C(&#x5C;)
`81 60` | U+301C(&#x301C;) | U+FF5E(&#xFF5E;)

Other bytes sequences were not checked.

Mapping form unicode codepoints to Shift_JIS byte sequences:

Unicode codepoint | Shift_JIS | Windows-31J
---|---|---
U+005C(&#x5C;) | `5C`(&yen;) | `5C`(&yen;)
U+00A5(&#xA5;) | Error | Error
U+301C(&#x301C;) | `81 60` | Error |
U+FF5E(&#xFF5E;) | Error | `81 60`

Other codepoints were not checked.
