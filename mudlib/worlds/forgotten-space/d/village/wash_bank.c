// d/village/wash_bank.c
// 黑石鋪・碎石溪下游・婦女搗衣淺灘（日常生活空間）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("碎石溪下游・搗衣淺灘");
    set_long("溪流流到此處變得平緩開闊，陽光穿過竹梢灑在淺淺的卵石水灣上。\n"
             "岸邊排著幾塊尋常灰青溪石，幾只竹籃裡放著浸濕的粗布短褂與皂角碎末；\n"
             "水邊蘆葦叢裡偶爾能見小銀魚穿梭。這裡沒有上游斷碑的刺骨詭譎，唯有柴米油鹽的人間聲氣。\n"
             "向西溯溪返回【幽霧水谷・碎石溪灘】，往東沿石坡小徑赴【南山青石採石場】。\n");

    set_exits(([
        "west": "/d/village/stream.c",
        "east": "/d/village/south_quarry.c",
    ]));

    set("is_outdoor", 1);
    set_touch("default", CYN "下游淺灘水流平緩，鵝卵石被陽光曬得微溫，溪水裡飄著滑膩的天然皂角沫。" NOR);
    set_smell("default", HIG "濕潤水草、陽光曬乾的粗布衣香與淡淡野薑花氣息柔和地散在風裡。" NOR);
    set_listen("default", WHT "木槌敲打濕布的「啪啪」聲與王大嬸和鄰居婦女說笑的聲音清脆傳開。" NOR);

    mapping wash_rule = ([
        "targets": ({ "clothes", "basket", "衣物", "" }),
        "sp_cost": 5,
        "sensory_msg": CYN "你幫王大嬸撈起泡在木盆裡的厚布被面，順著水流輕搓擰乾，指尖在水波陽光裡透著清爽。" NOR,
        "train_stat": ([ "dex": 6 ]),
        "exp_gain": 6,
        "quest_verb": "help_wash",
        "quest_target": "clothes"
    ]);
    add_action_rule("rinse", wash_rule);
    add_action_rule("漂洗", wash_rule);

    spawn_npc("/clone/npc/folk/wang_washerwoman.c");
}
