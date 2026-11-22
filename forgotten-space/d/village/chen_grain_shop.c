// d/village/chen_grain_shop.c
// 黑石鋪・陳記雜糧鋪（生活支翼：市井買糧、過秤與鄰里日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・陳記雜糧鋪");
    set_long("一間低矮卻收拾得極為整齊的木板糧鋪，門檻被挑夫的草鞋磨得圓潤光亮。\n"
             "牆邊一排十幾口大敞口粗陶米缸，分別盛著糙米、燕麥麵、高粱與所剩無幾的粗鹽；\n"
             "樑上垂著一桿老舊烏木桿秤 (weigh grain)，陳老漢正戴著袖套在櫃後撥算盤。\n"
             "向東推開後門通往【舊晾穀場與牛棚】，出門 (out) 即回【青石街市】。\n");

    set_exits(([
        "out":  "/d/village/square.c",
        "east": "/d/village/old_granary_yard.c",
    ]));

    set("is_outdoor", 0);
    set("no_combat", 1);

    set_touch("default", YEL "粗陶米缸沿口乾爽微糙，指腹沾著淡淡的陳年穀糠灰與乾燥麻布袋觸感。" NOR);
    set_smell("default", HIG "乾燥的陳米、燕麥粉與新劈松木桶的樸實氣味令人安心，壓過了山風裡的寒意。" NOR);
    set_listen("default", WHT "烏木算盤偶爾清脆一響，夾雜著婦人挑撿穀粒時麻袋發出的沙沙聲。" NOR);

    mapping weigh_rule = ([
        "targets": ({ "grain", "rice", "糙米", "雜糧", "" }),
        "sp_cost": 5,
        "sensory_msg": HIG "你拎起麻繩將粗布米袋掛上烏木桿秤，移動銅秤砣直到秤桿平平穩住——剛好五升見方的飽滿糙米，陳老漢連連點頭稱讚手腳穩當。" NOR,
        "train_stat": ([ "per": 8, "str": 6 ]),
        "exp_gain": 8,
        "quest_verb": "weigh",
        "quest_target": "grain"
    ]);
    add_action_rule("weigh", weigh_rule);
    add_action_rule("秤米", weigh_rule);

    spawn_npc("/clone/npc/folk/chen_grain_owner.c");
}

string query_long() {
    string res = ::query_long();
    object ws = find_object(WORLD_STATE_D);
    if (ws && ws->is_caravan_blocked()) {
        res += YEL "【糧鋪近況】牆角粗鹽木桶已經見底，幾名村婦正低聲央求陳老漢多勻半勺糙米應急。\n" NOR;
    } else if (ws && ws->is_caravan_arrived()) {
        res += HIG "【補貨喜訊】櫃旁新堆起十幾袋商隊運來的飽滿冬麥與粗鹽，陳老漢臉上的愁容散去不少。\n" NOR;
    }
    return res;
}
