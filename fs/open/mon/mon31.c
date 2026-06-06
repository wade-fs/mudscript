inherit ROOM;

#include <ansi.h>

void create ()
{
        set ("short", "天外福地");
	set( "build", 19 );
        set ("long", @LONG
洞天之中，還有這樣一塊令人感覺清靜的地方，一股幽香的味道
隱隱的從一處花叢中傳來，卻不知有什麼樣的東西藏在裏面，而在這
福地之中，透出一股令人清爽的氣味，讓你想要找一找是什麼樣的東
西傳出這樣的氣味，令你忘懷一切不愉快的源頭。

遠遠的那頭你可以瞧見一個朽壞的樹頭(torch)!!

LONG);
        set("outdoors", "");
        set("exits", ([ /* sizeof() == 1 */
        "west"     : __DIR__"mon30",

]));
        set("item_desc",(["torch":
	"好奇的你走上前一看，朽壞的樹頭上似乎有一個特別的東西藏在裏面，\n"+
	"你似乎要好好的搜尋一下了!! (tosearch here)\n",
]));
        setup();
        set_heart_beat(1); 

}

void init()
{
	add_action("search_here", "tosearch");
	add_action("pull_it","pull");
	set("no_reset",1);
}

int search_here(string arg)
{
	object me=this_player();
	object room = environment(me);
	if( !arg)
	return 0;
	if( arg == "here" )
	{
	  if( me->query_temp("mon-search") )
	  return notify_fail("一棵千年靈芝耶!!你還在想什麼，快點動手拔呀!!\n");

	  if( room->query("have-pull") )
	  return notify_fail("你找到的只是一個被拔過的痕跡!!\n");

	  if( (this_player()->query("combat_exp") > 1000000) )
	  {
	  tell_object(me,"你輕輕撥開奇異的花叢，終於在花叢中發現了一棵千年靈芝。\n"+
          "此時你正在尋思要如何拔起它(pull it)。\n");
	  me->set_temp("mon-search",1); 
	  }else{
	  tell_object(me,"也許\是你的江湖歷練不足，你什麼也沒發現...\n");
	  }
	  return 1;
	}
	return 0;
}

int pull_it(string arg)
{
	object me,ob,room;
	me = this_player();
	room = environment(me);

	if( !arg )
	return 0;

	if( arg == "it" )
	{
	  if( room->query("have-pull") )
	  return notify_fail("千年靈芝已經被拔走了，只剩下一點痕跡在拔過的地方。\n");

	  if( (me->query("combat_exp") > 3000000 )  && me->query_temp("mon-search") == 1 )
	  {
	  ob=new("/open/mon/npc/beast.c");
	  ob->move("/open/mon/mon31");
	  me->delete_temp("mon-search");
	  room->set("have-pull",1);
	  message_vision("正當$N靠近靈芝時，只見靈芝幻化成一隻仙獸向你衝了過來！！\n", me);
	  ob->kill_ob(me);
	  call_out("re_pull",1800,room);
  	  return 1;
	  }
	}
	return 0;
}   

int re_pull(object room)
{
	object me = this_player();
	room->delete("have-pull");
	return 1;
}
