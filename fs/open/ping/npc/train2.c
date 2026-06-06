#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("段家中級練習生",({"trainee"}) );
    set("gender", "男性");
    set("age",18);
    set("attitude", "peaceful");
    set("long", "陪段家弟子練習的學生 \n");
    set("kee",800);
    set("max_kee",800);
    set("combat_exp",4000);
    setup();
}
