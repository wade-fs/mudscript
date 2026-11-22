// /d/yunjin/western_warehouse_street.c
// 雲津仙集・西街貨棧區 (Ch.84, Ch.90)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・西街貨棧區");
    set_long("條石鋪成的貨運長街，兩旁林立著掛滿商號木牌的大小石砌貨棧，不時可見\n"
             "披著霜雪的雪橇車隊卸下來自金石府六縣的耐火炭袋、乾草與生鐵軸。\n"
             "街尾那座原本漏風、如今修葺整齊的小型石砌舊貨棧掛著一塊黑墨寫成的【泥途商棧】木牌。\n"
             "向北往萬寶重整空倉暨【無毒炭料回收廠】，往東返回【萬山廣場】，向西步入【泥途商棧】，向南拐入繁鬧的【三宗物資交易街】。\n");

    set_exits(([
        "north": "/d/yunjin/west_street_recycling.c",
        "east":  "/d/yunjin/wanshan_square.c",
        "west":  "/d/yunjin/mudway_store.c",
        "south": "/d/yunjin/three_sect_market.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", WHT "條石街面沾著融雪水漬與耐火炭黑灰，石砌貨棧厚木門上的鐵環冷硬沉實。" NOR);
    set_smell("default", YEL "濕羊皮、耐火炭末、乾草垛與各家商號油布防水帳篷的味道。" NOR);
    set_listen("default", WHT "卸貨木箱砸落的「咚咚」聲、管事唱報貨單數目的喊聲與雪橇鈴聲。" NOR);

    mapping tally_rule = ([
        "targets": ({ "crates", "cargo", "貨箱", "貨棧", "" }),
        "sp_cost": 5,
        "sensory_msg": YEL "你沿著長街看過各商號卸下的耐火炭袋與鐵軸標記，認出泥途商棧門前那排貨碼放得最整齊紮實。" NOR,
        "train_stat": ([ "per": 6 ]),
        "exp_gain": 8
    ]);
    add_action_rule("inspect", tally_rule);
    add_action_rule("看貨棧", tally_rule);

    spawn_npc("/clone/npc/folk/county_worker.c");
}
