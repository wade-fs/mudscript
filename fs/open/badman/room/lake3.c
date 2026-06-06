// Room: /open/badman/room/lake3.c
// written by powell 96.4.26@FS

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "湖底");
  set ("long", @LONG
這裏就是惡人湖的湖底，湖底鋪滿了一層白色的小石子，完全 
沒有污泥的存在，也難怪這湖水會這麼清澈。在你的正前方有塊大
石頭平躺在湖壁邊，此外還可看一棵棵的水草隨著水波搖來搖去，
煞是有趣。
                                                        
LONG);

  set("item_desc", ([ /* sizeof() == 1 */
  "rock" : "一顆巨大的石頭，不知你是否搬的動它。
",
]));
  set("exits", ([ /* sizeof() == 1 */
  "up" : __DIR__"lake2",
]));
  set("objects", ([ /* sizeof() == 1 */
  BAD_NPC"octopus.c" : 1,
]));

  setup();
}

void init()
{
	add_action("do_move","move");
}

int do_move(string arg)
{
	object who = this_player(), ob = this_object();
   	if ( arg == "rock" ) {
        if ( ob ->query_temp("way") != 1 ) {
	message_vision("$N用力將巨石一推，果然石後另有玄機，出現在你眼前的是個
			\r狹窄的通道。\n",who);
	add("exits/enter",__DIR__"lake4");
	ob->set_temp("way",1);
	}
	else {   
   	message_vision("$N用力將巨石一推，又將巨石推回原來的地方。\n",who);
 	delete("exits/enter");	
	ob->delete_temp("way");
	}
	return 1;
	}
	return notify_fail("你想要移動甚麼啊？\n");
	return 1;
}
