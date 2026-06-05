// c_goto.c by ACKY 03/22/00

inherit F_CLEAN_UP;
#include <ansi.h>

int main(object me, string arg)
{
	object obj, room;
	if( me->query("clan/rank") > 3 )
		return notify_fail("您無權使用此指令。\n");
	if( !CLAN_D->is_clan_room(me) )
		return notify_fail("此處並非貴幫之地盤。\n");
	if( me->is_fighting() )
		return notify_fail("您正忙於戰鬥。\n");
	if( CLAN_D->clan_query(me->query("clan/id"),"gold") < 100000 )
		return notify_fail("幫派存款至少要有拾萬兩黃金。\n");
	if( !arg )
		return notify_fail("使用方式：c_goto <幫眾ID>\n");
	sscanf(arg, "%s", arg);
	obj = find_player(arg);
         if(obj && wizardp(obj))
        return notify_fail("這位幫眾目前不在線上喔。\n");


//	if(!obj) obj = find_living(arg);
//	if (!obj) obj=LOGIN_D->find_body(arg);
	if(!obj)
		return notify_fail("這位幫眾目前不在線上喔。\n");
	if( CLAN_D->what_clan_area(obj)!=me->query("clan/id") )
		return notify_fail("幫眾所在之處並非貴幫之地盤。\n");
	room = environment(me);
	tell_room(room,HIC + "只見一陣煙霧過後，"+me->query("name")+"的身影已經不見了。\n" + NOR, me);
	if( obj && wizardp(obj))	{
		write("轟～～"+obj->query("name")+"用神力將你反彈回來。");
		return 0;
	}
	me->move(environment(obj));
	room = environment(me);
	tell_room(room,HIC + ""+me->query("name")+"的身影突然出現在一陣煙霧之中。\n" + NOR, me);
	return 1;
}

int help( object me )
{
	write("
   c_goto         ：立刻移動到幫眾身邊。

                                                         by ACKY 2000/03/22
");
	return 1;
}
