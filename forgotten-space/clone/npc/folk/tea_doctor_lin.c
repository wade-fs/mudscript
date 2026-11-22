// clone/npc/folk/tea_doctor_lin.c
// 茶博士老林・金石城中槐蔭茶肆（市井傳聞交匯與代書線）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("茶博士老林");
    set_short(CYN "槐蔭茶肆" NOR " 茶博士老林");
    set_long("一位提著長嘴銅茶壺、腕力極穩的茶館老夥計。\n"
             "銅壺上下翻飛，茶湯入碗卻不濺出一滴。茶肆裡坐滿了候差捕快、落第書生與跑商腳夫。\n");
    set_id(({ "tea_doctor_lin", "lin", "tea master", "茶博士老林", "茶博士", "老林" }));

    setup_archetype("J", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "inn", "info" }));
    set("no_combat", 1);

    add_response(({ "喝茶", "茶水", "歇腳" }),
        "老林手腕一抖，一道滾燙茶線精準注入粗瓷大碗笑道：「十文一碗茉莉花茶渣，管夠續水！在茶肆坐著，能聽全城三分之二的真假消息。」");
    add_response(({ "家書", "代寫", "書生", "letter" }),
        "老林朝靠窗那位磨墨的老秀才努努嘴：「替南關外孫老車夫寫平安信？沒問題！那邊寫好家書的紙墨都晾乾了，小哥順路帶回去交給孫伯吧（ask lin about 代寫完畢）！」");
    add_response(({ "代寫完畢", "拿信", "信紙" }),
        "老林小心翼翼將折成方勝的油紙家書遞給你點頭道：「這封報平安信寫得工整明白，連裡頭藏著的兩錢碎銀我也幫他縫進襯裡啦！快給南關外矮巷的孫老車夫送去吧！」");
}
