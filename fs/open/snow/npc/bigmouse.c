#include <ansi.h>

inherit NPC;

void create()
{
        set_name("大老鼠", ({ "big mouse", "big", "mouse" }) );
        set("long",
             "它是一隻肥胖的老鼠,其大無比,可別小覷它喔,它可是非常靈敏的。\n");
        set("attitude", "heroism");
	set("combat_exp", 1164);
	set_temp("apply/damage",40);
	set_skill("unarmed",2);
	set_skill("dodge",2);
        setup();
}
