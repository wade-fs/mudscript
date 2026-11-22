// clone/npc/folk/wang_washerwoman.c
// 王大嬸・碎石溪下游洗衣婦（黑石鋪家長里短與鄰里日常人物）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("王大嬸");
    set_short(CYN "溪畔洗衣" NOR " 王大嬸");
    set_long("一位挽著袖管、雙手泡得發白起皺卻依然手腳麻利的中年婦人。\n"
             "她拎著木槌與粗皂角整日在碎石溪下游替村戶搗洗衣物，村裡大小閒話十有八九從她這兒傳開。\n");
    set_id(({ "wang_washerwoman", "aunt wang", "wang dashen", "王大嬸", "洗衣婦" }));

    setup_archetype("J", 5);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info" }));
    set("no_combat", 1);

    add_response(({ "石板", "斷碑", "洗衣" }),
        "王大嬸啪啪敲著木槌笑道：「上游那塊黑石板冰得要命，只有你們這些小年輕跟張屠戶愛去那兒！我們女人家在下游淺灘避風處洗衣服，順手還能摸兩條小溪魚回去煮湯呢。」");
    add_response(({ "家長里短", "村子", "鄰居", "送糧" }),
        "王大嬸壓低聲音：「唉，東頭老李家的媳婦快臨盆了，西頭孤寡張婆婆膝蓋一到陰天就疼……聽說陳記雜糧鋪的陳老漢最近找人代送糙米呢，真是有心人！」");
}
