inherit ITEM;
#include <ansi.h>
object ob=this_object(),me=this_player();
void create()
{
	set_name("兔子的便便",({"bembem"}));
	set("long","這附近似乎有兔子出沒，所以地上遺留了兔子的便便，也許\你小
心找找(search rabbit)，應該會發現免兔的蹤影的！\n");
	set("unit","沱");
	set("value",100);
	set("no_get",1);
	set("no_sac",1);
	set("no_auc",1);
	set_weight(500000);
        setup();
}

void init()
{
	add_action("do_search","search");
}

int do_search(string str)
{
	object me,ob;
	me=this_player();
        ob=this_object();

	switch(str)
	{
	case "rabbit":
	if(ob->query("find")!=1)
	{
          message_vision("找來找去，$N終於在草叢中找到了幾隻兔子!!\n"NOR,me);
	  new("/open/mon/npc/rabbit")->move(environment(me));
	  ob->set("find",1);
	  call_out("des",1,ob);
	}else{
	  tell_object(me,"你已經找過囉!!\n");
	}
	break;

	default:
	tell_object(me,"你想找什麼呀!!\n");
	break;
	}
	return 1;
}

int des(object ob)
{
	destruct(ob);
}
