// Room: dancer's rest room //by purple
inherit ROOM;
void create ()
{
	set("short","舞者談心室");
  set ("long", @LONG
這裡是舞者專用的聊天，談心，交換心得的地方。加入舞者的美
少女們可以在此相互研討。前輩們也可以將多餘的裝備放置於此，以
照顧新手們。幽雅的環境，點綴著幾朵淡粉紅的玫瑰，及淡雅的花香
，令人不禁忘記了疲憊……
在這裡(dancing)看看，會有意想不到的結果喔～～

LONG);

  set("light_up", 1); 
  set("exits", ([ /* sizeof() == 2 */
        "east" : __DIR__"start",
]));
	set("objects",([
	]));
  set("no_magic", 1);
  set("no_fight", 1);

  setup();
}
void init()
{
  add_action("do_dancing","dancing");
}
int do_dancing()
{
  object me;
  me = this_player();
  me->move("/open/ping/room/road3");
  return 1;
}
