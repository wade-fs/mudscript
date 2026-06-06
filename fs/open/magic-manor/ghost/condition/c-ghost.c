#include <ansi.h>
inherit NPC;

void create()
{
        set_name("陰靈",({"ghost"}));
        set("long","是人死後之一種靈魂，帶有極重的怨氣。\n");
        set("race", "人類");
        set("gender", "男性");
        set("title",HIB"(鬼氣)"NOR);
        set("age",37);
        set("str",25);
        set("cor",25);
        set("max_gin",50000);
        set("max_kee",50000);
        set("max_sen",50000);
        set("max_force",2000);
        set("force",2000);
        set("force_factor",15);
        set("combat_exp",5000000);
        set_skill("unarmed",100);
        set_skill("dodge",100);
        set_skill("nine-steps",100);
        set_skill("move",100);
        set_skill("parry",100);
        set_skill("hell-evil", 100);
        map_skill("unarmed", "hell-evil");
        map_skill("dodge","nine-steps");
        map_skill("parry","hell-evil");
        map_skill("move","nine-steps");
        set("chat_chance",10);
        set("chat_msg",({
        "還我命來 ～ ～ ～\n",
        "我死的好慘啊 ！ ！ ！\n",
	"我要你的命........\n",
        }));
        setup();
 }

void init()
{
        object obj;
        ::init();
	set_heart_beat(1);
}

int heal_up()
{
        if (!is_fighting() )
	{
        message_vision (HIB"一陣強光捲來，$N消失於光中！\n"NOR, this_object ());
        destruct(this_object());
        return 1;
        }
        return ::heal_up() + 1;
}

void heart_beat()
{
	object *enemy,me=this_object();
	int i,j;

	enemy=me->query_enemy();
	i=random(sizeof(enemy));

	if(!enemy) return;

	if( me->is_fighting() )
	{
	  if( (random(100) > 50) )
	  {
	    if( (environment(me) == environment(enemy[i])) )
	    {
	    message_vision(HIB"$N"HIB"發出一道詭異的光茫，直接穿過$n"HIB"身體，$n"HIB"連閃避的機會都沒有。\n"NOR,me,enemy[j]);
	      switch( random(10) )
	      {
	      case 0:
	    	  enemy[j]->apply_condition("no_power",enemy[j]->query_condition("no_power")+5);
		  break;
	      case 1:
	    	  enemy[j]->apply_condition("blockade",enemy[j]->query_condition("blockade")+5);
		  break;
	      case 2:
	    	  enemy[j]->apply_condition("hellfire",enemy[j]->query_condition("hellfire")+5);
		  break;
	      case 3:
	    	  enemy[j]->apply_condition("tsunami",enemy[j]->query_condition("tsunami")+5);
		  break;
	      case 4:
	    	  enemy[j]->apply_condition("burn",enemy[j]->query_condition("burn")+5);
		  break;
	      case 5:
	    	  enemy[j]->apply_condition("ice",enemy[j]->query_condition("ice")+5);
		  break;
	      case 6:
	    	  enemy[j]->apply_condition("ff_poison",enemy[j]->query_condition("ff_poison")+5);
		  break;
	      case 7:
	    	  enemy[j]->apply_condition("blade",enemy[j]->query_condition("blade")+5);
		  break;
	      case 8:
	    	  enemy[j]->apply_condition("fire_poison",enemy[j]->query_condition("fire_poison")+5);
		  break;
	      case 9:
	    	  enemy[j]->apply_condition("five_poison",enemy[j]->query_condition("five_poison")+5);
		  break;
	      }
	    enemy[j]->receive_wound("kee",50);
	    enemy[j]->receive_wound("gin",30);
	    enemy[j]->receive_wound("sen",30);
	    COMBAT_D->report_status(enemy[j]);
	    }
	  }
	}
	set_heart_beat(1);
	::heart_beat();
}

void unconcious()
{
	message_vision (HIB"$N驚叫一聲，已經魂飛魄散，消失的無影無蹤!!\n"NOR, this_object ());
	destruct (this_object ());
}

void die()
{
	message_vision (HIB"$N驚叫一聲，已經魂飛魄散，消失的無影無蹤!!\n"NOR, this_object ());
	destruct (this_object ());
        ::die();
}
