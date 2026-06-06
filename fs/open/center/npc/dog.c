// dog.c by babe

#include <ansi.h>
#include "/open/open.h"

inherit NPC;
int black = 0;
void create()
{
        seteuid(getuid());
        set_name( "野狗", ({ "dog" }) );
        set("race", "野獸" );
        set("age", 3 );
        if(random(4) == 0) {
          set("long", "一隻渾身髒兮兮的野狗。\n");
        } else {
          black = 1;
          set("long", "一隻渾身髒兮兮的野狗，其毛色是黑色的。\n");
        }
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set_temp( "apply/attack", 3 );
        set_temp( "armor", 50 );
        set( "combat_exp", 240 );
        carry_object(CENTER_OBJ"bonze");
        setup();
}
void die()
{
  object me;
  me = query_temp("last_damage_from");
  if(me && me->query_temp("control") && black)
  {
    object blood = new("/open/zombie_hole/obj/blood.c");
    blood->move(this_object());
      me->set_temp("control_dog",1);
  }
  ::die();
}



