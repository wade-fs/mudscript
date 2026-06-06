#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("段家上級級練習生",({"trainee"}) );
    set("gender", "男性");
    set("age",18);
    set("attitude", "peaceful");
    set("long", "陪段家弟子練習的學生 \n");
    set("kee",1200);
    set("max_kee",1200);
    set("combat_exp",15000);
    setup();
}
