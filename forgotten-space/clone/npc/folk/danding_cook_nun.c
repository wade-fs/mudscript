// clone/npc/folk/danding_cook_nun.c
// 丹鼎門・火頭道姑（宗門底層膳堂與藥膳日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("火頭道姑");
    set_short(HIG "百味灶前" NOR " 火頭道姑");
    set_long("一位系著深藍粗布圍裙、頭髮挽著木簪的中年女冠。\n"
             "丹鼎門內門長老終日守著真火丹爐，她卻守著兩口熬藥渣粥的大鐵鍋，養活上下百十名雜役與貧寒外門弟子。\n");
    set_id(({ "danding_cook_nun", "cook_nun", "nun", "火頭道姑", "道姑", "廚娘" }));

    setup_archetype("H", 15);
    set("class", "immortal");
    set("faction", "danding");
    set("roles", ({ "inn", "info" }));
    set("no_combat", 1);

    add_response(({ "用膳", "吃飯", "藥膳", "粥" }),
        "火頭道姑拿大木勺攪著冒熱氣的鐵鍋笑道：「內門師兄吃三轉金丹，咱們外門弟子與山下散修喝這鍋去火陳皮蓮子米粥 (eat)，一樣能養脾胃、穩心火！」");
    add_response(({ "領粥", "抄經", "太清門", "relief" }),
        "火頭道姑盛起滿滿一大木碗溫熱滑糯的蓮子糙米粥遞給你，低聲笑道：「又是太清門那邊抄經抄得眼花手抖才摸過來的吧？快趁熱喝完！別餓壞了底氣！」");
    add_response(({ "誤採", "錯草", "藥草", "山藥", "差事" }),
        "火頭道姑指著牆角幾筐帶泥草藥苦笑：「新來的兩個小雜役把苦參和斷腸草根混成一筐了！你若得空，幫我去【外門洗藥晾曬坡】把藥根分揀洗淨（wash_herb），再拿回來交給我下鍋！」");
}
