// d/village/mine.c
// 黑石鋪・北面黑石斷崖與古礦坑 (重勞動與打熬區)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("黑石斷崖・古礦道口");
    set_long("此處高懸於聚落北側，山風凜冽，寸草不生。黑色的怪石嶙峋突兀，宛如\n"
             "猙獰的獸齒。面前立著一個半塌陷的古老礦洞，四周散落著廢棄的鐵鎬與\n"
             "碎石渣，幾道烏黑的軌道延伸進幽暗深處，隱約能聽見洞穴內部傳來的滴水\n"
             "聲與微弱的金屬摩擦聲。幾名皮膚黝黑的老礦工正倚著石壁歇息喘氣。\n");

    set_exits(([
        "south": "/d/village/square.c",
    ]));

    set("is_outdoor", 1);
}

void init() {
    ::init();
    add_action("do_mine", "mine");
    add_action("do_mine", "採礦");
}

int do_mine(string arg) {
    object me = this_player();

    if (me->query(VITAL_KEE) < 15) {
        write(HIR "你氣血衰竭，手臂酸麻，連鐵鎬都提不起來了！\n" NOR);
        return 1;
    }

    me->add(VITAL_KEE, -15);
    write("你掄起鐵鎬，狠狠砸向堅硬的黑石礦脈，火星四濺！\n");

    // 鍛鍊臂力 str
    me->add(STAT_STR, 1);
    write(HIG "【在沉重的揮鎬勞動中，你的雙臂肌肉緊繃，臂力微幅提升！】\n" NOR);

    if (random(100) < 40) {
        write(HIY "只聽『叮』的一聲脆響，你從碎石中撬出了一塊【粗鐵礦石】！\n" NOR);
        object ore = clone_object("/std/item.c");
        if (ore) {
            ore->set_name("粗鐵礦石", ({ "iron ore", "ore", "礦石" }));
            ore->set_short("粗鐵礦石");
            ore->set_long("一塊剛從黑石斷崖開採出來的未精煉粗鐵礦，質地堅硬厚重。\n");
            ore->set_weight(2000);
            ore->move(me);
        }
    } else {
        write("碎石崩落一地，只可惜這處岩層盡是雜質廢土。\n");
    }
    return 1;
}
