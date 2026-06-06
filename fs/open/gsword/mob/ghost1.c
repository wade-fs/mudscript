inherit NPC;
#include <ansi.h>
void create()
{
	set_name("綠毛小鬼", ({ "Green ghost" , "ghost" }) );
	set("race", "野獸");
	set("age", 7);
	set("long", "一隻長滿綠毛的小鬼,正張牙舞爪地尋找他的獵物.\n");                                                                                                                                                                                                          
	set("str", 35);
	set("cor", 35);
        set("limbs", ({ "頭部", "身體", "雙腳", "雙手" }) );
        set("verbs", ({ "bite", "claw", "dunt" }));
	set("combat_exp", 1500);
	set("attitude","aggressive");
	set("chat_chance_combat", 15);
	set("chat_msg_combat", ({  
          HIB + " 小鬼憤怒地叫:    吱～ 吱～\n" + NOR      }) );
	set_skill("dodge",35);
	setup();               
}
void die()
{
  object me;
  me= this_object()->query_temp("last_damage_from");
  if( me&& userp(me) ) {
      me->add("bounds",10);
    tell_room(environment(),sprintf("%s 從小鬼身上除下10根綠毛放進口袋\n",me->name()));
       }
      ::die() ;
   }
