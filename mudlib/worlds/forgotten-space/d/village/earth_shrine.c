// d/village/earth_shrine.c
// 黑石鋪・村尾破土地廟與山村蒙學隅（非修仙線的平民信仰與識字角）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石鋪・村尾土地廟");
    set_long("藏在村尾幾棵老槐樹根下的小小磚砌土地廟，門楣紅漆早已褪成淡粉。\n"
             "供桌上沒有金香燭，只擺著半碗粗米、三根草香與村婦折的幾枝野白花。\n"
             "廟前兩塊寬大青石板被村裡娃兒拿木炭當寫字板用，歪歪扭扭畫著「山、水、人、米」四字。\n"
             "向北推開低矮竹籬便是【黑石鋪・村尾蒙館】，向東折返【青石暗巷】，向南沿山腳小徑通往【西嶺伐木雜坡】。\n");

    set_exits(([
        "north": "/d/village/village_school.c",
        "east":  "/d/village/dark_alley.c",
        "south": "/d/village/lumber_slope.c",
    ]));

    set("is_outdoor", 1);
    set("no_combat", 1);
    set_touch("default", WHT "矮小的青石供桌與石板桌面被孩童磨得油光發亮，沾著炭灰與草香灰。" NOR);
    set_smell("default", CYN "廉價草香的淡淡艾草焦味、老槐樹葉的苦澀清氣與山野泥土味。" NOR);
    set_listen("default", HIG "老槐樹葉在風裡沙沙響動，不遠處隱約傳來村童照著木炭字描摹的稚嫩唸書聲。" NOR);

    mapping pray_rule = ([
        "targets": ({ "shrine", "altar", "土地", "" }),
        "sp_cost": 3,
        "sensory_msg": CYN "你替歪斜的草香扶正了些許，合十靜立片刻。沒有任何仙光降臨，唯有山風吹過老槐樹葉的平靜安寧。" NOR,
        "train_stat": ([ "spi": 6 ]),
        "exp_gain": 6
    ]);
    add_action_rule("pray", pray_rule);
    add_action_rule("上香", pray_rule);

    mapping rite_rule = ([
        "targets": ({ "grain", "sacrifice", "祭米", "社祭", "" }),
        "sp_cost": 3,
        "sensory_msg": YEL "你隨黑石鋪幾位老村婦將半瓢新篩糙米撒在土地神龕前的青石桌上，口念祈山安歲穩的樸素村謠，感受凡間歲時節慶的溫厚連繫。" NOR,
        "train_stat": ([ "sen": 6 ]),
        "exp_gain": 8
    ]);
    add_action_rule("offer_rite", rite_rule);
    add_action_rule("社祭", rite_rule);
}
