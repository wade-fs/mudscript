inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name(HIY"神龍真元"NOR, ({"dragon vigor","vigor"}) );
        set("long",
        "這是黃金甲龍的真元，可以大大提升能力，是習武者夢寐以求的珍品。
可以拿來吞服(swallow)\n");
        set("no_sell",1);
        set("no_give", 1);
        set("no_auc",1);
        set("no_drop",1); 
        set("no_put",1);
        set("unit", "顆");
        set("base_unit", "顆");
        set("value", 500000);
        set("base_weight", 50);
        set_amount(1);
        setup();
}
void init()
{
        if( this_player()==environment() )
                add_action("eat_pill", "swallow");
}
int eat_pill(string arg)
{
        int force;
        object ob,me=this_player();
        force=me->query_skill("force",1);
       
        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
        if( ob != this_object() )       return 0;
			if(me->query_condition("giftout"))
			{
			tell_object(me,"運著強化型技能，再服用龍元，會暴血而亡。\n");
			return 0;
			}
    if(me->query("quests/dragonvigor")==1){
 tell_object(me,"龍元只能服用一次，否則會被龍的狂性所制，精神失常。\n");
 
    return 0;
                                        }

message_vision(
"$N服下了"HIY"龍元"NOR"，一股熱流從喉頭進入腹中，$N氣力大增。\n", me);
if (me->query_str()>=30)
{
me->set("str",35);
}
else
{
me->add("str",5);
}
  
// me->add("cor",5);
if((force+10)<=400)
{
 me->set_skill("force",force+10);
}
else if(force<400)
 {
 me->set_skill("force",400);
 }
  me->clear_condition();
  me->set("quests/dragonvigor",1);
  add_amount(-1);
  return 1;
}





