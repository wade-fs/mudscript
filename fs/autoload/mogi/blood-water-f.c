// made by roger

inherit COMBINED_ITEM;
#include <ansi.h>
void create()
{
        set_name("千墳之水", ({"blood water","water"}) );
	set("long",
	"一顆藏黑的心臟仍在不斷的跳動著, 青黑色的血液被凍化而封在心臟裡, 
看起來似乎可以吸乾(suck)裡面的血\n");
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
		add_action("suck_water", "suck");
}
int suck_water(string arg)
{
        object ob,me=this_player();

        if( !arg )                      return 0;
        arg=lower_case(arg);
        if( !ob = present(arg,me) )     return 0;
  	if( ob != this_object() )       return 0;

        if (me->query_condition("mogi") > 30){
        message_vision(
"$N割開心臟吸乾了其中黑色的血水之後, 發出了一聲淒厲的慘嚎, 身子慢慢倒了下去...\n", me);
        me->die();
 log_file("mogi/poison", sprintf("%s(%s) 二次誤食千墳之水葛屁 on %s\n"
,me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
                                       }

       else if (me->query_condition("mogi") > 0){
        message_vision(
"$N割開心臟吸乾了其中黑色的血水, 突然覺得腦中一陣劇痛, 隨即七竅噴出黑血, 入滅之毒猛然發作！\n", me);
        me->apply_condition("mogi",35);
 log_file("mogi/poison", sprintf("%s(%s) 誤食假千墳之水 on %s\n"
,me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
                                       }
       else {
        message_vision(
"$N割開心臟吸乾了其中黑色的血水, 忽然頭痛欲裂, 臉上霎時全無血色！\n", me);
        me->add("force",-1000);
        me->receive_wound("kee",90);
        me->apply_condition("mogi",5);
 log_file("mogi/poison", sprintf("%s(%s) 中入滅之毒(誤食) on %s\n"
,me->query("name"),me->query("id"), ctime(time()) ));
	add_amount(-1);
	return 1;
        }    	
}

int query_autoload()
{
 return 1;
}
