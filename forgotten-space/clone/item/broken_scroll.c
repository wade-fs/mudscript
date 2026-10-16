// clone/item/broken_scroll.c
// 殘破引氣訣 - 破落道童的隨身殘卷

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/item.c";

void create() {
    ::create();
    set_name("殘卷", ({ "broken scroll", "scroll", "canjuan", "殘卷", "殘破引氣訣" }));
    set_short("殘破引氣訣");
    set_long("半卷受潮發黃的道家吐納抄本，邊角已被鼠齧殘缺。\n"
             "上面以墨筆勾畫著幾副粗淺的靜坐調息行氣圖，字跡斑駁。\n"
             "（可使用 read scroll / 研讀 參悟其中的『止心大法(初級)』）\n");
    set_weight(60);
    set("is_scroll", 1);
    set_value(10);
}

void init() {
    ::init();
    add_action("do_read", "read");
    add_action("do_read", "研讀");
}

int do_read(string arg) {
    if (!arg || (arg != "scroll" && arg != "broken scroll" && arg != "canjuan" && arg != "殘卷" && arg != "殘破引氣訣")) {
        return 0;
    }
    object me = this_player();
    if (me->query("background") != "daoist") {
        write(YEL "你翻開泛黃殘卷，只見上面滿是古怪的道門隱語與缺字，看得頭昏腦脹，難以領會。\n" NOR);
        return 1;
    }
    object skill_d = load_object("/secure/skill_d.c");
    if (me->query_skill("still_heart") <= 0) {
        write(HIC "你捧起自幼伴隨的《殘破引氣訣》，結合盲眼老道枯木平日的告誡，豁然看懂了墨筆行氣圖中「止念存神、不引外邪」的真意！\n" NOR);
        skill_d->grant_starter_force(me, "still_heart");
        return 1;
    }
    write(CYN "你反覆摩挲著《殘破引氣訣》上的斑駁字跡，對『止心大法(初級)』的理解更加圓融（可使用 調息/打坐/吐納 運功修習）。\n" NOR);
    return 1;
}
