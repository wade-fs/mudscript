// /d/yunjin/mountain_caravan_yard.c
// 雲津仙集・山道車馬行 (Ch.98, Ch.101：雙馬雪橇隊、北荒輜重招標榜與鬼市暗門通道)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津仙集・山道車馬行");
    set_long("停滿北地矮腳駑馬與雙馬木橇的大車院，馬槽旁堆著防寒草料與新上油的鐵爪橇板。\n"
             "木棚牆面上貼著剛由公所統籌頒布的《三宗聯合勘探隊隨軍輜重雪橇招標榜》，引來數家商號爭搶。\n"
             "車行最僻靜西角緊挨著一條臭氣熏天的死巷暗門，門後石階竟直墜峽谷岩石裂縫地下。\n"
             "向北返【三宗物資交易街】，向下掀開暗門走入【雲海鬼市】。\n");

    set_exits(([
        "north": "/d/yunjin/three_sect_market.c",
        "down":  "/d/yunjin/ghost_market.c",
    ]));

    set("is_outdoor", 1);

    set_touch("default", YEL "新上油的鐵爪橇板邊沿油滑冰冷，草料堆乾燥紮手、帶點牲口槽的微溫。" NOR);
    set_smell("default", YEL "濃烈馬廄草料氣、熱橇板桐油味，以及從西角死巷暗門縫裡隱隱滲出的一絲陰溝霉氣。" NOR);
    set_listen("default", WHT "北地矮腳駑馬打響鼻踩地的聲音，夾著各家商號管事圍在《招標榜》前爭論算計的低語。" NOR);

    mapping bid_rule = ([
        "targets": ({ "notice", "sleigh", "招標榜", "雪橇", "" }),
        "sp_cost": 4,
        "sensory_msg": CYN "你細看木棚牆上的《輜重雪橇招標榜》，又瞥了眼西角暗門邊刻意掩飾的泥濘腳印，心裡暗暗留神。" NOR,
        "train_stat": ([ "per": 8 ]),
        "exp_gain": 8
    ]);
    add_action_rule("inspect", bid_rule);
    add_action_rule("看招標", bid_rule);

    spawn_npc("/clone/npc/folk/sun_old_carter.c");
}
