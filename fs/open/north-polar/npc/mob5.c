#include <ansi.h>
inherit NPC;
inherit SSERVER;

void create()
{

	set_name("企鵝", ({"penguin"}));
	set("age",24);
	set("long","看到牠屁股搖著在冰上晃來晃去的可愛模樣，任何人都無法狠心對他下手，\n");
	set("race", "野獸");
	set("family/family_name","北極圈");
	set("str",30);
	set("con",30);
        set("no_fight", 1);
set("class","blademan");
set("no_kill",1);
	set("bellicosity",3000);
	set("attitude", "friendly");
	set("max_kee",60000);
	set("kee",60000);
	set("max_gin",60000);
	set("gin",60000);
	set("max_sen",60000);
	set("sen",60000);
	set("combat_exp",14000000);
	set("max_force",20000);
	set("force",30000);
	set("force_factor",15);
	set("random_move",200);
        set("limbs", ({ "頭部", "身體", "前爪", "後爪", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
	set_skill("dodge",120);
	set_skill("move",200);
	set_skill("force",100);
	set_skill("snow-kee",100);
	set_skill("winter-steps",100);
	set_skill("unarmed",120);
	set_skill("iceforce",100);
	set("chat_chance",100);
        set("chat_msg",({
       (: random_move :),
        }));
	map_skill("dodge","winter-steps");
	map_skill("parry","snow-kee");
	map_skill("force","iceforce");
	set("polar_mob",1);
        set_temp("apply/armor", 150);
        set_temp("apply/defense", 150);
        set_temp("apply/damage", 150);
        set_temp("apply/attack", 150);
	setup();
}

void heart_beat()
{
        object *enemy,*all,me,room;
        int i,j;
        me = this_object();
        room = environment(me);
        enemy = me->query_enemy(room);
        j = sizeof(enemy);
        if(!me) return ;   
   if(!query_temp("unconcious"))
     {            
     	if(me->is_busy() && random(4) == 1)
	  {
	   message_vision(HIW + "$N「呱」的一聲，搖著屁股一擺\一擺\的掙脫了身上束縛。\n" + NOR,me);
	   me->delete_busy();
	  }
     if(me->query("kee") <= 0)    me->die();
      }
        set_heart_beat(1);
        :: heart_beat();
}

/*
void unconcious()
{
        object me = this_object();
        if(random(3)==1)
        {
        message_vision(HIM + "$N見情況不對，「噗」的一聲跳下海裡逃走了。\n" + NOR,me);
        destruct(me);
        }
}
*/
