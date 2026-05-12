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
#define BOLD_WHT(x) "{w}" + x + "{n}"

/* 常用輔助宏 */
#define RED(x)      CLR_RED + x + CLR_NOR
#define GREEN(x)    CLR_GRN + x + CLR_NOR
#define YELLOW(x)   CLR_YEL + x + CLR_NOR
#define BLUE(x)     CLR_BLU + x + CLR_NOR
#define MAGENTA(x)  CLR_MAG + x + CLR_NOR
#define CYAN(x)     CLR_CYN + x + CLR_NOR
#define WHITE(x)    CLR_WHT + x + CLR_NOR
#define GRAY(x)     CLR_GRA + x + CLR_NOR

#endif
