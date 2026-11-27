// /clone/npc/wanwu_arbiter_core.c
// 萬物仲裁子機（離艦總約法廳無念裁決傀儡）(Ch.152, 163)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("萬物仲裁子機");
    set_short(HIW "鋼鐵仲裁橋・" NOR "萬物仲裁子機");
    set_long("一尊懸浮於青金石柱上方、由三環同心銅輪與無念法印構成的古機關裁決中樞。\n"
             "它不講人情亦無私利，只核驗【天門引】、【九城總契銅版】與離艦總約條文的法理優先序。\n");
    set_id(({ "wanwu_arbiter_core", "arbiter core", "arbiter", "萬物仲裁子機", "仲裁子機" }));

    setup_archetype("G", 99);
    set("class", "construct");
    set("faction", "wanwu_core");
    set("roles", ({ "arbiter", "quest" }));
    set("no_combat", 1);
    set("home_room", "/d/realm/wanwu/arbitration_bridge.c");

    add_response(({ "火種", "離艦總約", "第七條", "沈雲妮" }),
        "仲裁子機銅輪緩緩轉動，傳出低沉金石聲響：「核驗《平民避難配額總帳》暨『沈雲妮』總調度權限：\n"
        "凡完成逐戶登記與工時抵扣之避難區，優先適用第一優先序『保全人類火種』條款（invoke treaty / equalize charter）。」");
}
