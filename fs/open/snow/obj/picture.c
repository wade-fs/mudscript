/*********************************************************************************
修改 By Kalin (2003-06-17)
a.如果為scholar且要解god-plan,之前的過程正確,就會導引到dguger_door
*********************************************************************************/

inherit ITEM;
#include <ansi.h>
void create()
{
	set_name(HIG "路觀圖" NOR,({"snow picture","picture"}));
	set("unit","張");
	set("value",10);
        setup();
}
void init()
{
	add_action("do_read","read");
}
int do_read( string arg )
{
	object env = environment( this_player() );
	if( !arg || arg != "picture" ) return 0;
	if( base_name( env ) != "/open/snow/room/room3" ) {
		tell_object( this_player() ,@LONG
		/\
	      /    \
	   /         \
-----------        *   \
LONG);
		return 1;
	}
	if(this_player()->query("family/family_name") != "儒門")
	{
		tell_object( this_player() , "你在這裡發現了路觀圖所指示的路口。\n" );
		this_player()->move("/open/snow/room/dguger_room");
	}
	else
	{
		if(!this_player()->query_temp("scholar_godplan_gi_dguger_letter"))
		{
			tell_object( this_player() , "你在這裡發現了路觀圖所指示的路口。\n" );
			this_player()->move("/open/snow/room/dguger_room");
		}
		else
		{
			tell_object( this_player() , "你在這裡發現了路觀圖所指示的路口。\n" );
			this_player()->move("/open/snow/room/dguger_door");
		}
	}
	return 1;
}
