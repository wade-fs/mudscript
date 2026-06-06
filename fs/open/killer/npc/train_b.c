#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("一級練習生",({"trainee"}) );
    set("title", "黑牙聯成員");
    set("gender", "男性");
    set("age",20);
    set("attitude", "killer");
    set("long", "他是用來給殺手練習的NPC \n");
    set("force",200);
    set("max_force",200);
    set("kee",1000);
    set("max_kee",1000);
    set("combat_exp",10000);
    setup();
}
