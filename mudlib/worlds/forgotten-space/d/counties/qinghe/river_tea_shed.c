// /d/counties/qinghe/river_tea_shed.c
// 青河縣 (Qinghe County) 擴展生活翼：蘆花渡・河鮮粗茶棚

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("qinghe");
    set_short("蘆花渡・河鮮粗茶棚");
    set_long("搭在蘆花渡西岸堤壩柳蔭下的半敞開竹棚，棚下支著三口泥灶與幾張長條竹凳。\n"
             "剛靠岸的漁夫與採藥散戶總愛來此花兩文錢喝一碗現泡的洗靈草葉粗茶 (tea)，\n"
             "配著烤得酥脆的小河蝦乾與糙米熱粥。向東踏上木棧即回【蘆花渡・漁農草集】。\n");

    set_exits(([
        "east": "/d/counties/qinghe/luhuadu_dock.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set_touch("default", CYN "長條竹凳被河風與衣衫磨得光滑微涼，泥灶邊陶壺摸起來溫熱紮實。" NOR);
    set_smell("default", HIG "現泡洗靈草茶的微苦清香、河蝦乾的鹹鮮味與岸邊白蘆花水汽揉成水鄉氣息。" NOR);
    set_listen("default", CYN "青河水輕拍木樁的嘩啦聲裡，夾著撐篙船老大估算水勢與價錢的扯嗓談笑。" NOR);

    mapping brew_rule = ([
        "targets": ({ "tea", "herb", "茶", "粗茶", "" }),
        "sp_cost": 6,
        "sensory_msg": HIG "你舀起清冽青河活水澆進陶壺滾煮，待茶葉舒展後端起粗瓷碗淺飲一口，喉間清潤回甘。" NOR,
        "train_stat": ([ "sen": 6, "per": 6 ]),
        "exp_gain": 10
    ]);
    add_action_rule("brew_tea", brew_rule);
    add_action_rule("煮茶", brew_rule);

    spawn_npc("/clone/npc/folk/qinghe_boatman.c");
}
