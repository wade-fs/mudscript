// clone/tool/gong_ebony_ruler.c
// 天工烏木尺 - 百工總會正式學徒信物

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("天工烏木尺", ({ "ebony ruler", "ruler", "tool", "烏木尺", "天工烏木尺", "量尺" }));
    set_short(CYN "天工烏木尺" NOR);
    set_long("府城百工總會匠首歐陽大師親自審定頒發的正式匠籍信物。\n"
             "以盤木縣百年油性陰沉烏木精製，尺身打磨如鏡，正反面刻有極其精密的百工榫卯刻度\n"
             "與金石應力分界線。不僅是測繪造器的必備工具，亦能用作精準打擊結構薄弱點的奇門器械。\n");
    set_weight(800);
    set_value(1600);
    set("is_tool", 1);
    set("tool_type", "smith_ruler");
    set("is_class_badge", 1);
    set("class_req", "gong_initiate");
}
