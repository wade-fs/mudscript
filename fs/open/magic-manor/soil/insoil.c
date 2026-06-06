inherit ROOM;
#include <ansi.h>

void create()
{
        set("short","土靈塔七樓");
	set( "build", 1 );
        set("long","土靈塔的鎮塔之王，正坐鎮於此，四周的空間完全的密閉看來你
已經沒有地方可以逃了，拿出你的本事和土靈塔王拼了吧!!\n");

    set("exits", ([
    ]));
	set("objects", ([
	"/open/magic-manor/soil/npc/soil-king": 1,
	])); 

        set("light", 1);
	set("no_auc", 1);
	set("no_transmit",1);
        setup();

}

init()
{
	add_action("do_break","break");
}

int do_break(string arg)
{
	object me=this_player();
	if( present("soilen king",environment(me)) )
	{
	return 0;
	}else{
	  if( me->query_temp("magic-manor/soilmagic") && !me->query_temp("magic-manor/breaksoil") )
	  {
	  message_vision(YEL"\n$N運足十成的勁力並夾帶著土靈之力打在斑斑的裂痕上!!\n"NOR,me);
	  me->set_temp("magic-manor/breaksoil",1);
      call_out("out_way",3,me);
	  return 1;
	  }else{
        if( me->query_temp("magic-manor/soilmagic") && me->query_temp("magic-manor/breaksoil") )
		{
	    message_vision(GRN"$N才剛運完十成的勁力，正虛脫無力中!!\n"NOR,me);
	    return 1;
		}
	  }
	}
}

int out_way()
{
    object me;
    me=this_player();

    message_vision(HIY"\n忽然間受力的塔身應身而碎，在$N的眼前，開啟了一道出塔的路!!\n"NOR,me);
	set("exits",([
    "out"   :"/open/magic-manor/manor65",
    ]));

    call_out("close",60,me);
	return 1;
}

int close()
{
    object room,me;
    room=this_object();
    me=this_player();

    room->delete("exits/out");
    if( me->query_temp("magic-manor/breaksoil") )
    {
	me->delete_temp("magic-manor/breaksoil");
	}
    tell_room(room,GRN"\n塔身因靈氣再次聚滿消濔了裂痕，而將出口封住了。\n"NOR);
    return 1;
}

int valid_leave(object me, string dir)
{
	me=this_player();

    if( dir=="out" && me->query_temp("magic-manor/breaksoil") )
    me->delete_temp("magic-manor/breaksoil");
    return ::valid_leave(me,dir);
}
