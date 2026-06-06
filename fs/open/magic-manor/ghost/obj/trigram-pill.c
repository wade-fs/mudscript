inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name(HIC + "八卦"NOR+HIB"定" + HIC + "魂丹" + NOR, ({"trigram pill","pill"}) );
	set("long","相傳有定魂、鎮魂、趨魂、招魂的效果，如果是平常人誤食的話，會招來鬼氣纏身。\n");
	set("unit", "顆");
	set("no_steal",1);
	set("base_unit", "顆");
        set("value", 100000);
        set("base_weight", 50);
	set_amount(1);
	setup();
}
void init()
{
	if( this_player()==environment() )
	add_action("eat_pill", "eat");
}
int eat_pill(string arg)
{
        int maxkee,maxforce;
        object ob,me=this_player();
        maxkee=me->query("max_kee",1);
        maxforce=me->query("max_force",1);
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
  	if( ob != this_object() )       return 0;
        if (me->query_condition("ghost") > 0)
	{
        message_vision("$N服下了"+ob->query("name")+"之後，一股正氣油然而生，趨走了纏身的陰魂。\n", me);
        me->clear_condition("ghost");
//	log_file("mogi/poison", sprintf("%s(%s) 解除入滅之毒 on %s\n",me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
	}else{
        message_vision("$N服下了"+ob->query("name")+"之後，一股陰氣油然而生，招來了纏身的陰魂。\n", me);
        me->add("force",-1000);
        me->receive_wound("kee",90);
        me->apply_condition("ghost",30);
//	log_file("mogi/poison", sprintf("%s(%s) 中入滅之毒(誤食) on %s\n",me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
        }    	
}
/*
int query_autoload()
{
 return 1;
}
*/
