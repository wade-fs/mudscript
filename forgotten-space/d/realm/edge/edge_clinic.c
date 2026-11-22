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
             "初診可為病患把脈隔離（diagnose patient）；集齊三極樣本後可配製緩衝針藥（brew buffer）；\n"
             "校準夜可點燃三十座中和藥爐護民（light stoves），戰後亦須照護傷員（tend wounded）。\n"
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
    add_action("do_brew_buffer", "brew");
    add_action("do_light_stoves", "light");
    add_action("do_tend_wounded", "tend");
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

int do_brew_buffer(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "buffer" && arg != "針藥" && arg != "藥方") {
        notify_fail("你要配製什麼？試試：brew buffer\n");
        return 0;
    }
    tell_object(me, HIG "你對照太虛玉屑、萬物浸液與戰祖獸血三組極端樣本，配成【律令排異症三元緩衝針藥】！\n"
                    "成功保住三名早期鹽夫觸覺，亦向徹底石化老匠坦白不治邊界並反推出戰祖冒領暗倉尾碼。\n" NOR);
    say(me->query_name() + " 對照三極樣本配出第一版三元緩衝針藥組。\n");
    object t3 = load_object(TIER3_D);
    if (t3) {
        t3->grant_k_from_experiment(me, "medicine", "compare_three_pole_samples", ([
            "taixu_dust"  : 1,
            "wanwu_sludge": 1,
            "zhanzu_blood": 1
        ]));
        t3->unlock_u_via_path(me, "medicine", "clinic_three_pole_samples", ([
            "bitter_moss_ratio"     : 3,
            "bone_needle_insulation": 1
        ]));
    }
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "brew", "target": "buffer" ]));
    return 1;
}

int do_light_stoves(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "stoves" && arg != "藥爐" && arg != "stoves_fog") {
        notify_fail("你要點燃什麼？試試：light stoves\n");
        return 0;
    }
    tell_object(me, HIG "你與蘇青竹同時點燃三十座改良三元緩衝中和爐，淡青藥煙化作緩衝霧障護住千餘遺民肺腑！\n"
                    "隨身珍稀藥母徹底耗盡，雙掌掌心亦留下洗不掉的微晶灰白硬斑。\n" NOR);
    say(me->query_name() + " 點燃三十座緩衝藥爐，升起濃稠藥煙護霧攔截撲來的排異碎晶塵！\n");
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "light", "target": "stoves" ]));
    return 1;
}

int do_tend_wounded(string arg) {
    object me = this_player();
    if (!me) return 0;
    if (arg != "wounded" && arg != "傷員" && arg != "clinic") {
        notify_fail("你要照護誰？試試：tend wounded\n");
        return 0;
    }
    tell_object(me, CYN "你替校準夜後撤回的傷員重紮敷藥，並與蘇青竹核對三極百年停戰後的藥材貨殖清單。\n" NOR);
    say(me->query_name() + " 在醫棚細心照料校準夜撤返的傷員並核對停戰藥材清單。\n");
    object qe = load_object(QUEST_ENGINE_D);
    if (qe) qe->trigger_event(me, "action", ([ "verb": "tend", "target": "wounded" ]));
    return 1;
}
