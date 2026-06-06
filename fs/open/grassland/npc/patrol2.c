// /open/center/npc/vendor.c
#include <obj.h>
#include <ansi.h>
#include "/open/open.h"
inherit NPC;
void create()
{
      set_name("蒙古大軍巡邏隊", ({ "patrol guard", "guard" }) );
        set("attitude", "friendly");
        set("combat_exp",30000000);
        set_temp("apply/dodge",500);
        set_temp("apply/parry",500);
		set("no_kill",1);
		set("no_fight",1);
        setup();
}
