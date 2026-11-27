// clone/book/dao_basic_manual.c
// 《周虛微茫引氣訣》- 宣道司入門法典

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("周虛微茫引氣訣", ({ "dao basic manual", "manual", "book", "周虛微茫引氣訣", "引氣訣", "道藏" }));
    set_short(HIC "《周虛微茫引氣訣》" NOR);
    set_long("宣道司頒發給清虛外門記名弟子的真法入門道藏手抄本。\n"
             "扉頁蓋有宣道司玄機真人硃砂法印，記載著借天地微茫靈機、感應周虛星軌\n"
             "與以意念引導天光法印的口訣心法。研讀 (study manual) 可修習宣道司初階法門。\n");
    set_weight(500);
    set_value(1200);
    set("is_book", 1);
}

void init() {
    ::init();
    add_action("do_study", "study");
    add_action("do_study", "研讀");
}

int do_study(string arg) {
    object me = this_player();
    if (!arg || (arg != "manual" && arg != "book" && arg != "引氣訣" && arg != "周虛微茫引氣訣")) {
        write("你想研讀什麼？(study manual)\n");
        return 1;
    }

    if (me->query("sen") < 15) {
        write("你精神恍惚，神識池耗竭，無法靜心領會玄奧道法。\n");
        return 1;
    }

    me->add("sen", -10);
    write(CYN "你展卷凝神，默誦《周虛微茫引氣訣》，感應天地微弱游離靈機...\n" NOR);
    write(HIW "靈台之中泛起微光，你對宣道司借法真言有了更深的領悟！\n" NOR);
    
    object sk_d = load_object("/secure/skill_d.c");
    if (sk_d) {
        sk_d->check_upgrade(me, "dao_tuna");
    }
    return 1;
}
