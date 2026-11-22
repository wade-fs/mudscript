// clone/npc/folk/panmu_raftsman.c
// 放排老把式林四・盤木縣木排下水碼頭（林業木排生計與山貨商情）

#include "/include/ansi.h"
#include "/include/globals.h"

inherit "/std/npc.c";

void create() {
    ::create();
    set_name("放排老把式林四");
    set_short(GRN "盤木木客" NOR " 林四");
    set_long("一位腰間纏著雙股粗棕繩、小腿滿是水浸舊疤的精壯中年木客。\n"
             "他長年領著十幾名短工在倒影澗下水扎排，把鋸好的冷杉木與鐵木料順溪送出山外。\n");
    set_id(({ "panmu_raftsman", "lin si", "raftsman", "放排老把式林四", "林四", "木客" }));

    setup_archetype("B", 10);
    set("class", "mortal");
    set("faction", "folk");
    set("roles", ({ "worker", "info" }));
    set("no_combat", 1);

    add_response(({ "木排", "放排", "扎排", "冷杉", "差事" }),
        "林四甩緊手裡濕漉漉的麻繩喊道：「這批新鋸的冷杉木等著趁漲水出澗！幫我把碼頭邊那組冷杉木排捆扎妥當（lash raft），再去【聽松客棧】找夥計（innkeeper）通知押車人手備飯，回來我算你一份大工錢！」");
    add_response(({ "商會", "木材", "松脂" }),
        "林四往澗水裡啐了一口：「林場伐木越來越深，商會收料價卻壓得越來越狠。我們流汗賣命放一趟排，扣完山稅跟棧費，剩下的還不夠補一雙水靴。」");
}
