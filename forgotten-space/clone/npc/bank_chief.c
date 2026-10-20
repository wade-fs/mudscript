// clone/npc/bank_chief.c
// 沈萬通・錢莊大朝奉 (bank_chief) - 通寶錢莊總號

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("沈萬通");
    set_short(HIW "通寶錢莊大朝奉" NOR " 沈萬通");
    set_long("一位身穿寶藍緞面長衫、戴著金絲眼鏡的老朝奉，正埋首核對六縣銀票存根。\n"
             "他掌管通寶錢莊總號的高額存取與官商借貸清算，規矩極嚴，非一階合法身分不予開立大額金庫帳戶。\n");
    set_id(({ "bank_chief", "shen wantong", "bank chaofeng", "banker", "沈萬通", "錢莊大朝奉", "錢莊朝奉" }));

    setup_archetype("H", 25);
    set("class", "mortal");
    set("faction", "shanghui");
    set("roles", ({ "service", "shop", "info" }));
    set("rules", ([ "require_legal_status": 1 ]));
    set("schedule", "day");

    add_response(({ "開戶", "銀票", "匯兌", "錢莊", "身分" }),
        "沈萬通扶了扶金絲眼鏡道：「通寶錢莊與全府六縣票號通存通兌。然依府衙防洗錢鐵律，凡開立大額存摺者，須持有宣道司度牒、武館黑鐵牌、百工匠籍或三司緩衝信物等合法身分！」");
}
