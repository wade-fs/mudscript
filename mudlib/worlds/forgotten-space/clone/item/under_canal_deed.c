// clone/item/under_canal_deed.c
// 總堂血精交割正底單 - 卷二第四幕核心定罪鐵證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("總堂血精交割正底單", ({ "under canal deed", "under_canal_deed", "zhengdidan", "正底單", "交割底單" }));
    set_short(HIR "【總堂血精交割正底單】" NOR);
    set_long("自金石商會總堂地下「天字一號密室」外層鐵櫃中起獲的原始紫檀木匣長卷。\n"
             "卷首赫然加蓋著錢百川內堂專用「金蓮環刀印」，詳細載明過去三年黑石嶺北崖私礦盜採的三萬斤地煞血精流水。\n"
             "匣口與卷軸邊緣有府衙案牘主簿文承敬親手滴下的通紅硃砂火漆與案牘正堂公印，\n"
             "在西水門大水倒灌滅跡前搶出，法定保管鏈（chain of custody）100% 完整，為關鍵定罪鐵證（conclusive）。\n");
    set_weight(60);
    set_value(2000);
    set("is_evidence", 1);
    set("evidence_type", "under_canal_deed");
    set("evidence_level", "conclusive");
}
