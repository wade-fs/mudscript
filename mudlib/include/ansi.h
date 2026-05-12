#ifndef ANSI_H
#define ANSI_H

/* 顏色標記定義 */
#define CLR_RED     "{r}"
#define CLR_GRN     "{g}"
#define CLR_YEL     "{y}"
#define CLR_BLU     "{b}"
#define CLR_MAG     "{m}"
#define CLR_CYN     "{c}"
#define CLR_WHT     "{w}"
#define CLR_GRA     "{gr}"
#define CLR_NOR     "{n}"

/* 常用輔助宏 (全名 - 供 login.c 等舊程式碼使用) */
#define RED(x)      CLR_RED + x + CLR_NOR
#define GREEN(x)    CLR_GRN + x + CLR_NOR
#define YELLOW(x)   CLR_YEL + x + CLR_NOR
#define BLUE(x)     CLR_BLU + x + CLR_NOR
#define MAGENTA(x)  CLR_MAG + x + CLR_NOR
#define CYAN(x)     CLR_CYN + x + CLR_NOR
#define WHITE(x)    CLR_WHT + x + CLR_NOR
#define GRAY(x)     CLR_GRA + x + CLR_NOR

/* 常用縮寫 (3字母) */
#define RED(x)      CLR_RED + x + CLR_NOR
#define GRN(x)      CLR_GRN + x + CLR_NOR
#define YEL(x)      CLR_YEL + x + CLR_NOR
#define BLU(x)      CLR_BLU + x + CLR_NOR
#define MAG(x)      CLR_MAG + x + CLR_NOR
#define CYN(x)      CLR_CYN + x + CLR_NOR
#define WHT(x)      CLR_WHT + x + CLR_NOR
#define GRA(x)      CLR_GRA + x + CLR_NOR

/* 高亮度系列 (HI* 系列) */
#define HIR(x)      CLR_RED + x + CLR_NOR
#define HIG(x)      CLR_GRN + x + CLR_NOR
#define HIY(x)      CLR_YEL + x + CLR_NOR
#define HIB(x)      CLR_BLU + x + CLR_NOR
#define HIM(x)      CLR_MAG + x + CLR_NOR
#define HIC(x)      CLR_CYN + x + CLR_NOR
#define HIW(x)      CLR_WHT + x + CLR_NOR

/* 其他輔助功能 */
#define BOLD_WHT(x) CLR_WHT + x + CLR_NOR

#endif
