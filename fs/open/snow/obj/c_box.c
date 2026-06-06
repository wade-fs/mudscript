inherit ITEM;
#include <ansi.h>
#include "../../open.h"
int call_guard(int i);
void create()
{
	set_name(MAG "紫玉霞盒" NOR,({"mag box","box"}));
	set("long","這是一個特殊的盒子﹐外殼發出閃閃的紫光﹐且附著兩條封條﹐而裡頭所裝的是獨孤愁生前的衣物。\n");
     set("unit","俱");
     set_weight(1000000);
     set("value",10000);
}
void init()
{
	add_action("do_search","search");
	add_action("do_tear","tear");
	add_action("do_open","open");
}
int do_search(string str)
{
	if(str!="box"&&str!="mag box")
		return notify_fail("你在找什麼 ?\n");
	if(this_object()->query_temp("tear_paper")!=1)
	tell_object(this_player(),"你發現在這個盒子上有兩道封條(fon papers)。\n");
	if(this_object()->query_temp("tear_paper")==1)
		return notify_fail("你發現盒子上有兩道被撕掉的封條。\n");
	return 1;
}
int do_tear(string str)
{
	int i;
	if(this_object()->query_temp("tear_paper")==1)
		return notify_fail("盒子上的封條已經被撕開。\n");
	seteuid(getuid());
	if(str!="fon papers")
		return 0;
	tell_object(this_player(),"你用手撕開了盒子上的封條。\n");
	message_vision(
	"雪蒼武者走了過來﹐發現你撕掉了封條。\n雪蒼武者大暍﹕小賊 !! 你想偷什麼 !!\n" NOR,this_player());
	for(i=0;i<10;i++) call_guard(i);
	this_object()->set_temp("tear_paper",1);
	return 1;
}
int call_guard(int i)
{
	object guard;
	string place;
	if(i<2) place="ducu_room_in2";
	else if(i<5) place="ducu_room_in1";
	else if(i<7) place="ducu_room_in";
	else place="ducu_room";
	seteuid(getuid());
	guard=new(SNOW_NPC"snow_guard");
	guard->move(SNOW_ROOM+place);
	guard->kill_ob(this_player());
	guard->set_leader(this_player());
	guard->set_leader(this_player());
}
int do_open( string arg )
{
	object ob;
	if( !arg || arg != "box" )
			return 0;
	if( !this_object()->query_temp("tear_paper") ) return 0;
	if( query("opened") ) 
		return notify_fail("箱內空無一物。\n");
	message_vision( "$N從"+this_object()->name()+"搜出一本詩集。\n",
		this_player() );
	this_object()->set("opened",1);
	ob = new( "/open/snow/obj/poet_book" );
	ob->move(this_player());
	return 1;
}
