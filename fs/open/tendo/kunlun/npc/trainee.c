#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("三級練習生",({"trainee"}) );
    set("title", "黑牙聯成員");
    set("gender", "男性");
    set("age",18);
    set("attitude", "killer");
    set("long", "他是用來給殺手練習的NPC \n");
    set("kee",500);
    set("max_kee",500);
    set("combat_exp",1000);
    setup();
}
