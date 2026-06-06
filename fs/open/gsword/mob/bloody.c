#include <ansi.h>

inherit NPC;
int tt=0;
void create()
{
	set_name("血妖", ({ "Bloody","bloody" }) );
	set("race", "野獸");
	set("age", 30);
	set("long", "全身流動著紅色液體的怪物,忽而膨脹,忽而縮小,宛如要將你吞下去.\n");
	set("str", 40);
	set("cor", 40);
        set("limbs", ({ "頭部", "身體", }) );
        set("verbs", ({ "poke"}));
	set("combat_exp", 4000);
	set_temp("apply/armor", 30);
        set_temp("apply/attack", 20);
	set("attitude","aggressive");
	set("random_move",2);
	set("chat_chance_combat",10);
	set("chat_msg_combat", ({
	    (: this_object(),"add_att" :), 
	   "      ～血妖發出陣陣邪惡的氣息～   \n",      
	         }) );
	set_skill("dodge",35);
	setup();               
	 add_money("silver",10);

}
 
int add_att() 
{  int att ;
   att=random(3);
   if (tt <1) { 
     this_object()->add_temp("apply/attack",att);
     message_vision ("不知道是不是錯覺 , "
	"你發現血妖的身軀突然變得粗壯許\多\n"NOR,this_object());
   }
   tt++;
   return 1;
}

void die()
{
 
  object me;
  me=this_object()->query_temp("last_damage_from");
  if( me&& userp(me) )  {
   me->add("bounds",20);
     tell_room(environment(),sprintf("%s從血妖身上除下20根綠毛放進口袋\n",me->name()));
    }
 :: die();
 } 
      
