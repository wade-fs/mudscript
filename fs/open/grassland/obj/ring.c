inherit ITEM;
#include <ansi.h>
object ob=this_object(),me=this_player();
void create()
{
	set_name("牧羊鈴",({"Sheep Ring","sheep ring"}));
	set("long","這是牧羊人呼喚羊群集合進食的鈴鐺，據說如果搖搖看
(rock ring)，羊群聽到便會靠過來。\n");
	set("unit","副");
	set("value",100);
	set("no_get",1);
	set("no_sac",1);
	set("no_auc",1);
	set_weight(500000);
        setup();
}

void init()
{
	add_action("do_rock","rock");
}

int do_rock(string str)
{
	object me,ob,sheep;
	int x,per;
	me=this_player();
    ob=this_object();
    per = me->query_per();
	per = per/7;
	if(per>3) per=3;
	per = 2+random(per);
	
	switch(str)
	{
	case "ring":
	if(ob->query("find")!=1)
	{
      message_vision("$N拿起鈴鐺搖了幾下，羊兒聽到鈴聲，立刻朝著大草原狂奔而出。\n"NOR,me);
	  for(x=0;x<per;x++)
	  {
	    //sheep = new("/u/a/alucard/area/grassland/npc/sheep");
		sheep = new("/open/grassland/npc/sheep");
		sheep->move(environment(me));
		sheep->random_move();
		sheep->random_move();
		sheep->random_move();
		sheep->random_move();
	  }
	  ob->set("find",1);
	  call_out("des",1,ob);
	}else{
	  tell_object(me,"你已經搖過囉!!\n");
	}
	break;

	default:
	tell_object(me,"你想搖什麼呀!!\n");
	break;
	}
	return 1;
}

int des(object ob)
{
	destruct(ob);
}
