// clone/item/relay_poison_sample.c
// 黑水埗毒囊提純交割單 - 卷二第三幕關鍵物證

#include "/include/ansi.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("黑水埗毒囊提純交割單", ({ "relay poison sample", "relay_poison_sample", "jiaogedan", "交割單", "毒囊單據" }));
    set_short(MAG "【黑水埗毒囊提純交割單】" NOR);
    set_long("一本自濁水縣黑水埗地下毒囊提純作坊密櫃中起獲的原始交割手抄流水帳。\n"
             "帳頁被水銀與綠礬毒汁浸染得微泛幽紫，上面赫然有已故副總管趙德貴的親筆代簽與商會後勤專用戳記。\n"
             "特別備註載明：六十斤高純度地陰腐骨散專供黑石關犒軍乾肉與醃菜混用，\n"
             "與松崖驛趙德貴毒案、蘇遠山大掌櫃慢性毒殺之毒理特徵三方互鎖，證明力逼近關鍵定罪鐵證（conclusive）。\n");
    set_weight(60);
    set_value(800);
    set("is_evidence", 1);
    set("evidence_type", "relay_poison");
    set("evidence_level", "conclusive_pending");
}
