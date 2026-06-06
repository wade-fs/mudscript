#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "森林");
  set ("long", @LONG
這裡一望無際的森林，東邊黑壓壓的一片密林，看來是人煙稀少
的地方，這裡有一株相當高大的榕樹，看起來似乎年代已經相當久遠
了，應該是顆年餘百歲的老樹了，這裡的土地似乎相當的鬆軟，應該
蠻好挖(dig)的...
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "west" : __DIR__"f3",
  "south" : __DIR__"f6",
  "north" : __DIR__"f2",
  "east" : __DIR__"F4",
]));

  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/mob/squirt" : 1,
]));

  setup();
}
void init()
{
    add_action("do_dig","dig");
}
int do_dig(string arg)
{
    object me=this_player();
    object ob=new("/open/doctor/obj/root");

    if(me->query_temp("sos_tor")==1 && !me->query_temp("get_root") && arg == "土地")
{
	write("你把這鬆軟的泥土給挖開，並摘取了幾條榕樹根...\n"NOR);
	ob->move(me);
	me->set_temp("get_root",1);
	return 1;
}
    else
{
	write("你挖ㄚ挖的，老半天也沒挖到啥東西！\n"NOR);
	return 1;
  }
}
