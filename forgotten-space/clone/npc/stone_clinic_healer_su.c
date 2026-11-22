// /clone/npc/stone_clinic_healer_su.c
// 蘇青竹（灰燼石堡・邊緣醫棚醫女）(Ch.130)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("蘇青竹");
    set_short(CYN "邊緣緩衝醫站" NOR " 蘇青竹");
    set_long("一位二十出頭的石堡遺民醫女，指縫與粗布圍裙上沾滿苦苔藥汁，眼神卻冷靜堅韌。\n"
             "她在半塌石窯裡照護吸入幾何晶塵而發病的鹽夫，並細心保存著石堡三百年的病例簿。\n");
    set_id(({ "stone_clinic_healer_su", "healer su", "su", "蘇青竹", "醫女" }));

    setup_archetype("A", 65);
    set("class", "mortal");
    set("faction", "edge_bastion");
    set("roles", ({ "healer", "quest", "info" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/edge/edge_clinic.c");

    add_response(({ "排異", "律令排異症", "晶塵", "病患" }),
        "蘇青竹眉頭深鎖：「那位太清老前輩左半身已經透出半透明玉色硬稜，按老法子灌溫補湯藥\n"
        "反而催發晶稜暴漲！顧大夫說這叫『律令排異症』——快來幫忙冷敷隔離查診（diagnose patient）。」");

    add_response(({ "病例", "苦苔", "樣本" }),
        "蘇青竹從暗格抱出一疊厚厚發黃的獸皮醫案：「這三百年病例簿都留著呢，只是欠缺正北、\n"
        "西南、正東三處極地的異質樣本對照，才配不出真正穩妥的緩衝方。」");
}
