// d/yunjin/temple_tea_fair.c
// 雲津城・山神廟會茶市（Tier 2 北境地方廟會與散修商販歇腳茶肆）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("雲津城・山神廟會茶市");
    set_long("夾在三宗交易長街西側的一座古舊山神廟前坪，廟前幾棵老白楊下擺開十幾張\n"
             "草編矮桌與銅皮燒水爐。沒有宗門大殿的森嚴等級，過往挑擔商販、剛下山的散修、\n"
             "馬伕與聽書百姓皆可花兩文錢來喝一碗熱磚茶、聽一段北方皮影鼓詞 (listen_opera)。\n"
             "向東穿過石牌坊即回【三宗物資交易街】。\n");

    set_exits(([
        "east": "/d/yunjin/three_sect_market.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);

    set_touch("default", YEL "粗陶大碗滾燙燙地暖著凍僵的手指，草編矮凳積著北方乾燥黃塵。" NOR);
    set_smell("default", YEL "磚茶熬煮出的微苦濃香、炒黃豆焦香與山神廟飄來的劣質松香味道。" NOR);
    set_listen("default", HIY "說書人醒木「啪」地一拍，夾雜著三弦琴聲與茶客們熱烈捧場的叫好聲。" NOR);

    mapping opera_rule = ([
        "targets": ({ "opera", "story", "聽戲", "皮影", "" }),
        "sp_cost": 0,
        "sensory_msg": HIY "你端起兩文錢的熱磚茶靠在白楊樹旁聽了半段北境古傳奇鼓詞，神思在煙火氣中緩緩舒展。" NOR,
        "train_stat": ([ "sen": 8 ]),
        "exp_gain": 10
    ]);
    add_action_rule("listen_opera", opera_rule);
    add_action_rule("聽戲", opera_rule);

    mapping folk_drum_rule = ([
        "targets": ({ "drum", "festival", "社鼓", "廟會", "" }),
        "sp_cost": 4,
        "sensory_msg": HIY "你隨山神廟會的北境鄉民一道敲起牛皮祈歲社鼓，渾厚鼓聲震落白楊樹梢碎雪，四周茶客齊聲喝采慶祈來年暖春平安。" NOR,
        "train_stat": ([ "sen": 6, "spi": 6 ]),
        "exp_gain": 10
    ]);
    add_action_rule("beat_drum", folk_drum_rule);
    add_action_rule("敲社鼓", folk_drum_rule);

    spawn_npc("/clone/npc/folk/yunjin_tea_vendor.c");
}

void init() {
    ::init();
    add_action("do_tea_gossip", "tea_gossip");
    add_action("do_tea_gossip", "聽茶客");
}

int do_tea_gossip(string arg) {
    object me = this_player();
    if (!me) return 0;
    object rum_d = load_object(RUMOR_D);
    if (!rum_d) return 0;
    string ev = (arg && arg != "") ? arg : "cold_wave";
    mapping *list = rum_d->query_cross_check_rumors(ev);
    write(HIY "\n【山神廟茶攤・四方口徑風聲】\n" NOR);
    foreach (mapping r in list) {
        write(sprintf("  ・[%s｜%s｜可信:%d%%｜%s] %s\n",
            r["source"], r["region"], r["credibility"],
            r["is_stale"] ? WHT "已過時" NOR : HIG "當期實情" NOR, r["text"]));
    }
    write("\n");
    return 1;
}
