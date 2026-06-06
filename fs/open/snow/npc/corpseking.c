#include <ansi.h>

inherit NPC;

void create()
{
         set_name("殭屍王", ({ "corpse king", "corpse", "king"}) );
        set("long",
             "當你看到它的時候,你不禁想到自己如果在這裡死掉會不會變成它那副醜陋的模樣。\n");
        set("attitude", "heroism");
	set("combat_exp", 2540);

        set_skill("unarmed",50);
	set_temp("apply/damage",50);
	set_skill("dodge",2);
        set("chat_chance",6);
	set("random_move",2);
       set("chat_msg",({
          (:this_object(),"random_move":),
}));
        setup();
}
