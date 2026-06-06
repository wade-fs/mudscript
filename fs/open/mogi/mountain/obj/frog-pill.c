// made by roger
//300萬
inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name(HIC"冰蟾丹元"NOR, ({"ice-frog pill","pill"}) );
	set("long",
	"本是千年冰蟾額上的丹元，發出淡淡冰冷的氣息。\n");
        set("no_sell",1);
        set("no_auc",1);
        set("no_drop",1); 
        set("no_put",1);
	set("unit", "顆");
	set("base_unit", "粒");
        set("value", 500000);
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
        int force,fireforce;
        object ob,me=this_player();
        force=me->query_skill("force",1);
        fireforce=me->query_skill("fireforce",1);
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
  	if( ob != this_object() )       return 0;
    if(me->query("quests/ice-frog")==1){
 tell_object(me,"冰蟾丹元一生只能服用一次，否則恐有內勁失控之慮。\n");
    return 0;
                                        }

message_vision(
"$N一口吞下了"HIC"冰蟾丹元"NOR"，只覺丹元冰冷的氣息暫時壓抑了練內功\時
所帶來的心浮氣躁，不知不覺中$N的基本內功\已增益了不少。\n", me);
  me->set_skill("force",force+25);
  me->clear_condition();
  me->set("quests/ice-frog",1);
  add_amount(-1);
  return 1;	
}

