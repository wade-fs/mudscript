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
		set("must_heart_beat",1);
        setup();
}
void check()
{
    foreach(object obj in all_inventory(environment(this_object())))
	{
		if(!userp(obj)) continue;
		if(obj->query_temp("hide")) continue;
		CHANNEL_D->do_channel(this_object(),"mud",HIC + "從蒙古草原附近的大軍裡傳來一陣騷動。\n" + NOR);
		tell_object(obj,HIR+name()+"大叫：這裡有奸細！！！\n" + NOR);
		tell_object(obj,HIR + "突然之間，附近突然冒出大量的士兵往你的方向衝了過去。\n");
		tell_object(obj,HIR + "你慌慌忙忙的逃出這裡。\n");
		tell_object(obj,HIR + "慌忙之中，被士兵刺了幾刀。\n" + NOR);
		obj->move("/open/grassland/r01");
		obj->receive_wound("kee",obj->query("kee")/2);
		
	}
}
void init()
{
  set_heart_beat(1);
    if(!query("path"))
	{
		set("path",copy(environment(this_object())->query("path")));
	}
   check();
}

int return_home(object home)
{
  return 1;
}
static int patrol = -1;
void patrol()
{
	string *path;
	path = query("path");
	if(!sizeof(path)) return ;
	patrol++;
	patrol = patrol % sizeof(path);
	command(path[patrol]);
}
void heart_beat()
{
 if(!environment()) return ;
 if(random(3) ==0) patrol();
 ::heart_beat();
 if(sizeof(query("path"))) set_heart_beat(1);
}
