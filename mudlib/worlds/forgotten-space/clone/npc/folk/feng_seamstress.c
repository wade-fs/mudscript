// clone/npc/folk/feng_seamstress.c
// 馮嫂・鎮風縣戍卒家眷窄巷（邊塞縫製羊皮冬襖與軍屬日常） (Ch.61-62)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("馮嫂");
    set_short(CYN "邊塞軍屬" NOR " 馮嫂");
    set_long("一位手指關節因長年穿粗牛筋針而微微變形的三十餘歲婦人。\n"
             "她的丈夫在鎮風北塞烽燧當值，她便和十幾戶軍屬擠在這條背風矮巷裡，靠給戍卒和行商縫補雙層狼羊皮冬襖糊口。\n");
    set_id(({ "feng_seamstress", "feng sao", "seamstress", "馮嫂", "軍屬婦人" }));

    setup_archetype("H", 7);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "craft", "info" }));
    set("no_combat", 1);

    add_response(({ "冬襖", "皮襖", "縫補", "手藝", "差事" }),
        "馮嫂咬斷嘴邊的粗麻線嘆道：「今年北風比往年冷得早，烽燧上那批老卒的羊皮襖全開了線！你若願意照著架子幫忙補齊兩件（stitch coat），再替我跑一趟北塞烽燧把衣裳交給守卒（county_bailiff），我分你一百二十文針線錢！」");
    add_response(({ "烽燧", "丈夫", "邊塞", "世道" }),
        "馮嫂低頭搓了搓凍得發紅的手指：「當兵吃糧聽起來體面，實則軍餉常拖欠兩三個月。要是沒有我們這些婦人在巷裡縫皮賣肉乾，哪撐得過臘月朔風？」");
}
