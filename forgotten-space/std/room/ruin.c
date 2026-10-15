// std/room/ruin.c
// 《遺忘的世界》遺跡機關房基底類別

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/room.c";

string relic_inscription; // 遺跡上的太古銘文內容
string relic_target;      // 可被研讀的物象標識 (例如: "stone", "slab", "wall")
int required_fate;        // 破除認知盲區所需之天命值
int required_int;         // 參悟其中星象奧秘所需之悟性值

void create() {
    ::create();
    required_fate = 1;
    required_int = 1;
    relic_target = "stone";
    relic_inscription = "一片模糊難辨的太古石痕，依稀記錄著逆行的古老星軌。";
}

void init() {
    ::init();
    add_action("do_study_ruin", "study");
    add_action("do_study_ruin", "參悟");
    add_action("do_tuoyin", "tuoyin");
    add_action("do_tuoyin", "拓印");
}

void set_relic_target(string target) {
    relic_target = target;
}

void set_inscription(string text) {
    relic_inscription = text;
}

void set_required_fate(int val) {
    required_fate = val;
}

void set_required_int(int val) {
    required_int = val;
}

int do_study_ruin(string arg) {
    object me = this_player();

    if (!arg || arg == "" || (arg != relic_target && arg != "stone" && arg != "stele" && arg != "石板" && arg != "斷碑" && arg != "ruin" && arg != "刻痕")) {
        return 0; // 交由後續指令處理
    }

    write(HIG "你凝視著眼前的古代殘痕，試圖沉澱雜念、細細推演...\n" NOR);

    // 1. 認知盲區檢定 (天命檢定)
    int my_fate = me->query(STAT_FATE);
    if (my_fate < required_fate) {
        write(CYN "你看著這些斑駁凹槽，只覺得線條凌亂無章，宛如前人隨手塗鴉的頑石，瞧不出個所以然來。\n" NOR);
        return 1;
    }

    // 2. 悟性與神識檢定
    int my_int = me->query(STAT_INT);
    int my_sen = me->query(VITAL_SEN);

    if (my_sen < 10) {
        write(HIR "你此刻心神渙散，神識不足，強行參悟只覺大腦隱隱刺痛。\n" NOR);
        return 1;
    }

    me->add(VITAL_SEN, -10);

    write(HIY "【宿命感應】你的眉心忽有一絲神經突觸猛烈跳動，破除了長久以來的認知盲區！\n" NOR);
    write(WHT "你發現這些看似凌亂的凹槽，其夾角與周天星象完全相反，隱隱對應著太古大清洗前的失落星軌！\n" NOR);
    write(HIC "銘文殘意：" + relic_inscription + "\n" NOR);

    // 鍛鍊悟性
    me->add(STAT_INT, 1);
    write(HIG "【你對天地星象的理解加深了，悟性微幅提升！】\n" NOR);
    return 1;
}

int do_tuoyin(string arg) {
    object me = this_player();

    if (!arg || arg == "" || (arg != relic_target && arg != "stone" && arg != "stele" && arg != "石板" && arg != "斷碑")) {
        write("你想拓印什麼？（例如：tuoyin " + relic_target + "）\n");
        return 1;
    }

    write("你取出粗紙與炭黑，小心翼翼地敷在石刻凹槽上，均勻拓印...\n");
    write(HIW "一柱香後，你成功將石面上的神秘星紋拓印了下來，獲得了一張【殘缺星圖拓片】！\n" NOR);

    object rubbing = clone_object("/clone/relic/stele_rubbing.c");
    if (rubbing) {
        rubbing->move(me);
    }
    return 1;
}
