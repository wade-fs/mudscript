// /d/counties/liefan/market.c
// 烈礬縣 (Liefan County) 房間 2/14：銅礬硃砂大集

#include "/include/ansi.h"
#include "/include/globals.h"

inherit COUNTY_ROOM_OB;

void create() {
    ::create();
    set_county("liefan");
    set_short("烈礬縣・銅礬硃砂大集");
    set_long("烈礬縣的中央大集地面被長年散落的赤銅礦粉與硃砂染成暗紫紅色。集市\n"
             "兩側店鋪林立，一箱箱結晶透亮的天然明礬、伴生明礬硃砂晶（符道畫符要材）、\n"
             "高純耐火白泥與粗銅錠在此過秤交割。西面回【西迎赤石關門】，北面是【烈礬縣衙】，\n"
             "東面為爐火沖天的【烈礬百工冶煉分舵】，南面是【烈礬護礦武館】，西南與東南分別是\n"
             "【通寶當鋪烈礬分號】與【烈礬縣驛】。\n");

    set_exits(([
        "west":      "/d/counties/liefan/west_gate.c",
        "north":     "/d/counties/liefan/yamen.c",
        "east":      "/d/counties/liefan/smelting_branch.c",
        "south":     "/d/counties/liefan/mine_guard_hall.c",
        "southwest": "/d/counties/liefan/pawnshop.c",
        "southeast": "/d/counties/liefan/post_inn.c",
    ]));

    set_has_shop(1);
    set_coordinate(7, 13, 0);

    mapping credit_rule = ([
        "targets": ({ "grain", "ration", "米糧", "賒糧", "" }),
        "sp_cost": 8,
        "sensory_msg": YEL "你在大集糧鋪替銅駝嶺幾戶斷頓礦工家屬押下名條賒出十斤高粱糙米，糧店掌櫃點頭在帳冊上畫了個記號。" NOR,
        "train_stat": ([ "per": 8, "str": 6 ]),
        "exp_gain": 12,
        "quest_verb": "credit",
        "quest_target": "grain"
    ]);
    add_action_rule("credit", credit_rule);
    add_action_rule("賒糧", credit_rule);
}
