//open/prayer/room/2elder6

#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "執法長老房");
  set ("long", @LONG

	    你己來到了執法長老的大廳了，往南走正
	是長老的辦公室，而北邊及西邊都有傳來陣陣
	的武鬥聲，看來聖火教的弟子們的功夫都應該
	不錯．

LONG);

  set("exits", ([ /* sizeof() ==  4*/
	"out" : "/open/prayer/room/train1-9",		//`走廊
	"north" : "/open/prayer/room/2elder5",		//`長老房
	"south" : "/open/prayer/room/2elder7",		//`長老房
	"west" : "/open/prayer/room/2elder3",		//`長老房
]));
  set("light_up", 1);

  setup();
}

// 干擾 tin by ACKY
void init()
{
	object me;
	me = this_player();
	remove_call_out("check");
	if( me->query_temp("elder2") > 3 ) {
		tell_room( this_object(), "聖火教弟子急忙將" + me->query("name") + "拉了過去。\n", me );
		if( random(2) ) me->move("/open/prayer/room/2elder7");
		else            me->move("/open/prayer/room/2elder5");
		me->delete_temp("elder2");
		me->start_busy(2);
		message_vision( HIY"弟子說道: 別慌慌張張地亂闖, 這裡可是執法長老執法的地方唷。\n"NOR, me );
	}
	else {
		me->add_temp( "elder2", 1 );
		call_out( "check", 300, me );
	}
}

int check( object me )
{
    if(me)
	me->delete_temp("elder2");
	return 1;
}
