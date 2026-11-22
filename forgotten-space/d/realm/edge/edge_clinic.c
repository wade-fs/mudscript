// /d/realm/edge/edge_clinic.c
// 第四卷 Act 1：邊緣礦棚・排異緩衝醫站 (Ch.130)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("邊緣礦棚・排異緩衝醫站");
    set_long("由半截塌頂石窯改建而成的簡陋醫棚，矮木榻上躺著左半身浮出半透明玉色硬稜的失明鹽夫，\n"
             "石案上擺著苦苔冷敷藥盆、細礦灰粉罐與三百年發黃的獸皮病例簿；醫女蘇青竹正忙著煎藥。\n"
             "若要細檢患者臟腑異律晶化反應並示範冷敷隔離，可為病患診脈（diagnose patient）。\n"
             "向東穿出矮石門返回【灰燼石堡】。\n");

    set_exits(([
        "east" : "/d/realm/edge/ash_watch_post.c",
    ]));
    set("is_outdoor", 0);

    set_touch("default", MAG "病患未晶化的右手脈門冰冷遲滯，鎖骨下方卻硬如打磨過的冷玉石板。" NOR);
    set_smell("default", GRN "濃苦的野苦苔汁氣、礦灰粉味與一絲極淡的晶塵鐵腥氣。" NOR);
    set_listen("default", WHT "病榻傳來宛如兩塊碎瓷摩擦般的沉重呼吸聲，夾著瓦罐微沸的細響。" NOR);

    spawn_npc("/clone/npc/stone_clinic_healer_su.c");
}

void init() {
    ::init();
    add_action("do_diagnose", "diagnose");
}

int do_diagnose(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "patient" && arg != "病患" && arg != "salt_worker") {
        notify_fail("你要替誰診症？試試：diagnose patient\n");
        return 0;
    }

    tell_object(me, CYN "你叫停溫補藥湯，取細礦灰粉與苦苔冷敷替病患隔絕幾何晶塵，仔細對照三百年病例簿。\n" NOR);
    say(me->query_name() + " 取細礦灰粉與苦苔替榻上鹽夫冷敷隔塵，並細閱病例簿。\n");
    tell_object(me, HIG
        "【律令排異症病理初斷】\n"
        "你證實凡間溫補湯反會助長『異律晶化』，唯有藉冷苦苔與礦灰降溫隔塵方能暫緩惡化，\n"
        "但徹底石化的骨骼已無力回天，須待集齊三極樣本再行配製緩衝針方。\n" NOR);

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([ "verb": "diagnose", "target": "patient" ]));
    }
    return 1;
}
