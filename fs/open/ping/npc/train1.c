#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("段家初級練習生",({"trainee"}) );
    set("gender", "男性");
    set("age",18);
    set("attitude", "peaceful");
    set("long", "陪段家弟子練習的學生 \n");
    set("kee",600);
    set("max_kee",600);
    set("combat_exp",800);
    setup();
}
