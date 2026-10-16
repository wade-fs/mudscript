// d/village/falls.c
// 黑石鋪・南谷寒澗・墜龍瀑布 (小說第8章場景)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("南谷寒澗・墜龍瀑布");
    set_long("兩側黑褐色的絕壁高達三十丈，筆直如削，崖壁上覆蓋著一層滑膩的深黑\n"
             "苔蘚。一道丈許寬的瀑布 (falls) 宛如狂暴白龍自崖頂砸落，狠狠撞入墨綠\n"
             "深不見底的寒潭之中，轟鳴之聲震耳欲聾，水汽瀰漫成一片白茫茫的迷霧。\n"
             "瀑布正下方橫亙著幾方被水浪抽打得光滑如鏡的巨型黑石 (rock)，岩壁背面\n"
             "幽暗潮濕處生長著泛著暗青油光的生石膽苔 (moss)。\n"
             "（可在此瀑布鍛體 train_falls，或採集生石膽苔 gather moss）\n");

    set_exits(([
        "north": "/d/village/stream.c",
    ]));

    set("is_outdoor", 1);
    set("can_train_falls", 1);
    set("can_gather_moss", 1);
    set("moss_stock", 5);
    spawn_npc("/clone/npc/zhao_si.c");
}

void init() {
    ::init();
    add_action("do_train_falls", "train_falls");
    add_action("do_train_falls", "鍛體");
    add_action("do_train_falls", "瀑布鍛體");
}

int do_train_falls(string arg) {
    object me = this_player();

    if (me->query(VITAL_SP) < 25) {
        write(HIR "你此刻精疲力竭，若貿然跳入千鈞狂瀑之中，恐有筋骨折斷、被急流捲入潭底之險！\n" NOR);
        return 1;
    }

    write(CYN "你深吸一口氣，赤身躍上瀑布下方冰冷滑膩的黑石，雙足死死扣進石縫之中！\n" NOR);
    write("十丈高的萬鈞急流如狂暴鈍錘般一次又一次砸在你的頭頂、脊椎與雙肩之上——\n");

    me->add(VITAL_SP, -25);
    me->add(VITAL_KEE, -15);

    int con = me->query(STAT_CON);
    int str = me->query(STAT_STR);

    if (random(100) < 40) {
        write(HIY "在冰冷刺骨的重水轟擊下，你體內氣血逆衝如爐，骨節爆發出一陣炒豆般的脆響！\n" NOR);
        write(HIG "【極限鍛體！你頂住了千鈞瀑布的衝擊，肉身韌性與氣血上限獲得提升！】\n" NOR);
        me->add_max_vital(VITAL_KEE, 5);
        me->add_exp(35);
    } else {
        write(YEL "水浪沉重如鐵，你咬緊牙關苦苦支撐了半柱香，周身皮膚泛起一片血紅，體魄更加凝實。\n" NOR);
        me->add_exp(15);
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "train_falls",
            "target": "falls"
        ]));
    }
    return 1;
}

int do_gather(object me, string arg) {
    if (!arg || (arg != "moss" && arg != "石膽苔" && arg != "生石膽苔" && arg != "藥")) {
        return 0;
    }

    if (query("moss_stock") <= 0) {
        write("岩壁陰暗處的生石膽苔已被採集一空，需等待地煞陰濕水汽重新滋生。\n");
        return 1;
    }

    if (me->query(VITAL_SP) < 15) {
        write("你手腳發軟，無法在濕滑絕壁上攀爬採藥。\n");
        return 1;
    }

    write(CYN "你攀上濕滑峭壁背面，小心翼翼地從岩石縫隙中剝離下一把泛著暗青油光的生石膽苔。\n" NOR);
    me->add(VITAL_SP, -15);
    add("moss_stock", -1);

    object moss = new("/clone/item/stone_moss.c");
    if (moss) {
        moss->move(me);
        write(HIG "你獲得了一份【生石膽苔】！\n" NOR);
    }

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "gather",
            "target": "moss"
        ]));
    }
    return 1;
}
