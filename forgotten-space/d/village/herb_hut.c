// d/village/herb_hut.c
// 黑石鋪・南面懸崖峭壁・採藥草廬 (採藥孤兒出生地)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

void create() {
    ::create();
    set_short("懸崖峭壁・採藥草廬");
    set_long("這是一間半懸於水谷峭壁凹槽中的簡陋竹草茅廬。窗外長年瀰漫著清冷濕潤的\n"
             "水霧，幾根粗大的攀岩麻藤自柴門邊垂落，順著濕滑崖壁通往上方的溪灘。\n"
             "草廬內壁懸掛著數副竹木藥篩與半乾的草藥根莖，濃郁甘苦的草木氣息撲面\n"
             "而來。角落的木几上散亂堆放著碾藥石臼、泛黃的土偏方，以及你從小隨身\n"
             "背負的竹編藥簍。\n");

    set_exits(([
        "up": "/d/village/stream.c",
    ]));

    set("is_outdoor", 0);

    spawn_npc("/clone/npc/ge_doctor.c");
    spawn_item("/clone/item/steel_grinder.c");
}

void init() {
    ::init();
    add_action("do_herb_recover", "drink");
    add_action("do_herb_recover", "inhale");
    add_action("do_herb_recover", "聞藥");
    add_action("do_herb_recover", "飲湯");
    add_action("do_triage_miner", "triage");
    add_action("do_triage_miner", "分診");
    add_action("do_triage_miner", "施針");
}

int do_herb_recover(string arg) {
    object me = this_player();
    if (!me->consume_drink(30)) return 1;

    write("你湊近泥爐上咕嘟冒泡的粗陶藥罐，深深吸了一口濃郁甘苦的草木藥氣，並淺啜了半碗溫熱藥湯。\n");
    write(HIG "溫潤醇厚的草木靈氣順著經絡化開，淤積的暗傷與疲勞迅速消融，只覺神清氣爽！\n" NOR);
    me->add(VITAL_KEE, 30);
    me->add(VITAL_SEN, 20);
    me->add(VITAL_SP, 20);
    write(HIG "【藥氣浸潤，你的氣血 +30、神識 +20、精力 +20！】\n" NOR);

    if (me->query("background") == "herbalist" && me->query_skill("herb_breathe") <= 0) {
        write(CYN "\n瘋郎中葛半仙嘿嘿一笑，指點道：「記住這股草木藥氣入肺的韻律！人在草木間，一呼一吸皆是藥理！」\n" NOR);
        load_object("/secure/skill_d.c")->grant_starter_force(me, "herb_breathe");
    }
    return 1;
}

int do_triage_miner(string arg) {
    object me = this_player();
    if (arg && arg != "" && arg != "miner" && arg != "daniu" && arg != "傷患" && arg != "孫大牛" && arg != "寒針截脈") {
        write("你想對誰進行分診施針？提示：triage miner（對傷患進行戰時分診與寒針截脈止痛）\n");
        return 1;
    }

    write(CYN "你檢視草廬內哀嚎的傷患：僅剩的三包【麻沸止痛散】必須留給胸腹內傷與碎骨清創的柱子、老李頭與趙老四。\n" NOR);
    write("面對右小腿脛骨開放性斷裂、疼得滿頭冷汗的孫大牛，你取出三寸寒鐵長針，\n"
          "精準刺入他右膝後側【委中】與膝下【陽陵泉】、【足三里】三處大穴，施展局部「寒針截脈法」！\n");
    write(HIG "孫大牛右膝以下瞬間酸麻失覺，劇痛立止，既保住了傷腿清創的時機，也省下了救命的麻沸散！\n" NOR);

    object qe = load_object(QUEST_ENGINE_D);
    if (qe) {
        qe->trigger_event(me, "action", ([
            "verb": "triage",
            "target": "miner"
        ]));
    }
    return 1;
}


