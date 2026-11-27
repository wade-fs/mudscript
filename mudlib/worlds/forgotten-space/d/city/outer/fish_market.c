// d/city/outer/fish_market.c
// 青河入城・外城河埠魚市（Tier 1 漁民水產批發與市井早市）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("青河入城・外城河埠魚市");
    set_long("外城貨運碼頭東側一片坡度平緩的礫石河灘，擺滿了數十個滴著水珠的竹編魚簍\n"
             "與木盆。活蹦亂跳的青魚、河蝦與白條正由剛靠岸的漁婦喊價叫賣，石板上堆著碎冰塊與\n"
             "待刮鱗剖肚的鮮魚 (fish)。\n"
             "向西踏上木板引道即回【青河入城・外城貨運碼頭】。\n");

    set_exits(([
        "west": "/d/city/outer/river_wharf.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", CYN "濕滑石板濺滿魚腥水漬，浸過冰冷青河水的竹編魚簍邊沿又涼又紮手。" NOR);
    set_smell("default", CYN "濃烈鮮活的河魚水腥氣、河泥草香與早市竹筐裡的潮濕柳條味道。" NOR);
    set_listen("default", HIY "漁婦劉三娘脆亮的報價吆喝聲、魚尾拍打木盆的「啪啪」聲與刀背刮鱗聲。" NOR);

    mapping gut_rule = ([
        "targets": ({ "fish", "魚", "剖魚", "" }),
        "sp_cost": 6,
        "sensory_msg": CYN "你蹲在木盆邊學著熟練漁婦下刀刮鱗去鰓，三兩下便把一條大青魚收拾得乾乾淨淨。" NOR,
        "train_stat": ([ "dex": 8 ]),
        "exp_gain": 9
    ]);
    add_action_rule("gut", gut_rule);
    add_action_rule("理魚", gut_rule);

    spawn_npc("/clone/npc/folk/fishmonger_liu.c");
}
