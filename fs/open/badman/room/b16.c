// Room: /open/badman/room/b16
inherit ROOM;

void create ()
{
  set ("short", "惡人谷南街");
  set ("long", @LONG
這兒有幾個小販聚集在此地，不知道他們在賣些甚麼，也許你
有興趣問問看。此外，還有幾隻頑皮的小麻雀，在屋頂和地面間飛
來飛去，可愛的模樣讓你想好好親近它們，或許正是因為你厭倦了
在惡人谷的那股似有若無的肅殺氣息。

LONG);

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/sparrow" : 3,
  "/open/badman/npc/vendor" : 1,
]));
  set("outdoors", "/open/badman");
  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"b17",
  "east" : __DIR__"b15",
]));

	set("no_transmit",1);
  setup();
}
void init()
{
        object who=this_player();
        who->set_temp("can_feed",1);
}

int valid_leave(object who,string dir)
{
	who->delete_temp("can_feed");
        return ::valid_leave(who,dir);
}
