// /clone/item/cyan_crystal_filament_vial.c
// 淡青道化晶絲剝離樣本管（第三卷 Ch.100 三元互濟手術實證樣本）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("淡青晶絲樣本管", ({ "cyan_crystal_filament_vial", "crystal filament", "filament vial", "淡青晶絲樣本管", "道化晶絲" }));
    set_short(HIC "三元剝離・淡青道化晶絲樣本" NOR);
    set_long("一支封存著半寸長、細如髮絲的半透明淡青色晶體細絲與一滴暗紅淤血的特製小玻璃管。\n"
             "這是五位主角在泥途商棧地窖以九轉銀針、雪線苔液、黑鐵齒輪微震、三分陽剛氣血、沙漏控溫\n"
             "與周天星算五方協作自柳清虛手太陰肺經剝出的第一例標本。病案嚴格標註：此法僅對單根初生晶絲有效。\n");
    set_weight(45);
    set_value(0);
    set("is_evidence", 1);
    set("evidence_grade", "corroborative");
}
