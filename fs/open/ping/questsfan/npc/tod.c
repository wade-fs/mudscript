inherit NPC;
#include "/open/open.h"
#include <ansi.h>
string do_key();
void create()
{
    set_name("小道士",({"find tod","tod"}) );
    set("gender", "男性");
    set("age",45);
    set("attitude", "peaceful");
    set("long","一心追求﹝道﹞的真義，四處旅行的小道士\n");
    set("kee",20000);
    set("max_kee",20000);
    set("combat_exp",3200);
  set("chat_chance",10);
    set("chat_msg", ({
"小道士傷心的說道：唉!!!如果我能一步步，按部就班的，或許\我就可以結仙緣了。\n"
    }));
    setup();
  carry_object("/open/center/obj/torch");
  add_money("silver",20);
}
