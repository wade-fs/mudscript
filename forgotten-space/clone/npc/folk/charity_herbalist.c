// clone/npc/folk/charity_herbalist.c
// 義診老藥工周伯・南關外施藥義棚（貧苦流民免費施藥與救傷日常）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("義診老藥工周伯");
    set_short(HIG "南關義棚" NOR " 周伯");
    set_long("一位穿洗得發白灰布袍、兩鬢霜白卻眼神溫和的老藥工。\n"
             "他年輕時曾在府城百草堂學徒，因買不起資格考牒只能退到南關外搭起草棚，專替付不起診金的流民熬廉價甘草金銀花湯、包紮外傷。\n");
    set_id(({ "charity_herbalist", "old zhou", "zhou bo", "義診老藥工周伯", "周伯", "老藥工" }));

    setup_archetype("G", 8);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "healer", "info" }));
    set("no_combat", 1);

    add_response(({ "義診", "施藥", "流民", "看病" }),
        "周伯拿木勺撇去藥鍋上的浮沫嘆道：「中心大醫館一貼方子動輒半吊錢，南關外這些逃荒苦力哪掏得起？棚裡免費備著苦參清熱湯，你受傷或乏了便自己照方子熬一碗（brew medicine）喝下！」");
    add_response(({ "資格", "醫館", "百草堂" }),
        "周伯淡淡一笑：「沒有宣道或丹鼎執業牒印，進了內城連藥櫃都不許碰。可人命等不得公文印章啊，在這城外熬點粗藥能救一個是一個。」");
}
