// clone/npc/folk/sun_old_carter.c
// 孫老車夫・金石南關外流民賃居矮巷（底層苦力與家書日常線） (Ch.39-82)

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("孫老車夫");
    set_short(WHT "南關苦力" NOR " 孫老車夫");
    set_long("一位右腿微跛、穿著打滿補丁的灰褐短褂的老車夫。\n"
             "他年輕時拉過南嶺重車，如今年老力衰，在金石南關外這條潮濕矮巷租了半間土坯房躲避城防驅逐。\n");
    set_id(({ "sun_old_carter", "old sun", "sun carter", "孫老車夫", "孫伯", "老車夫" }));

    setup_archetype("B", 7);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "info" }));
    set("no_combat", 1);

    add_response(({ "矮巷", "流民", "通牒", "戶口" }),
        "孫伯縮在門檻邊抽著旱煙低聲道：「城裡哪有那麼多『路引』與『保書』？外縣逃難來的十個有九個只能擠在這南關外土坯棚裡，天沒亮就扛大包，半夜聽見巡防靴聲連大氣都不敢出。」");
    add_response(({ "家書", "寫信", "兒子", "報平安", "letter" }),
        "孫伯紅著眼眶搓手道：「老漢大字不識一個，小子在盤木林場拉木排半年沒見面了……若是有識字的好心人肯去城中槐蔭茶肆尋個書生幫我代寫一紙報平安家書，可千萬別提老漢這腿又腫了啊！」");
}
