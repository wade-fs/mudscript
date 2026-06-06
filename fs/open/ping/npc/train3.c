#include "/open/open.h"
inherit NPC;
void create()
{
    set_name("段家高級練習生",({"trainee"}) );
    set("gender", "男性");
    set("age",18);
    set("attitude", "peaceful");
    set("long", "陪段家弟子練習的學生 \n");
    set("kee",1000);
    set("max_kee",1000);
    set("combat_exp",8000);
    setup();
}
