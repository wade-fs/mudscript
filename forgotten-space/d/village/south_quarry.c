// d/village/south_quarry.c
// 黑石鋪・南山青石採石場（礦難後自救開採地，與 rumor_d 正典對齊）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南山坡腳・露天青石採石場");
    set_long("被開鑿得如階梯般整齊的南山露天石壁。自從北崖古礦道塌方封井後，\n"
             "許多不願下黑井冒險的礦工便跟著石匠老周來到這裡，靠鐵楔與大錘敲出整塊青石條，\n"
             "既用來修補聚落水渠，也靠賣給修橋行商勉強貼補家用。岩壁旁架著一口烤火取暖的生鐵炭爐 (stove)。\n"
             "向西沿小徑通往【搗衣淺灘】，向北走向【村北舊晾穀場】。\n");

    set_exits(([
        "west":  "/d/village/wash_bank.c",
        "north": "/d/village/old_granary_yard.c",
    ]));

    set("is_outdoor", 1);
    set_touch("default", WHT "青石階梯斷口新鮮銳利，石壁上還插著幾枚待敲的鋼鐵大楔子，指尖滿是粗石粉。" NOR);
    set_smell("default", YEL "新鮮崩開的青石土腥味、汗水味與生鐵炭爐殘留的一點微弱松炭煙氣。" NOR);
    set_listen("default", HIY "「叮！噹！卡！」鐵錘砸進石楔的清脆節拍此起彼落，偶爾伴隨著整塊條石剝離山體的悶響。" NOR);

    mapping quarry_rule = ([
        "targets": ({ "stone", "rock", "青石", "" }),
        "sp_cost": 12,
        "sensory_msg": HIW "你雙手輪圓鐵錘順著青石天然節理砸下鋼楔，「喀嚓」一聲整條方正青石應聲裂開，四濺的石粉裡滿是勞動踏實感。" NOR,
        "train_stat": ([ "str": 12, "con": 10 ]),
        "exp_gain": 12,
        "quest_verb": "quarry",
        "quest_target": "stone"
    ]);
    add_action_rule("quarry", quarry_rule);
    add_action_rule("採石", quarry_rule);

    spawn_npc("/clone/npc/folk/zhou_quarryman.c");
}
