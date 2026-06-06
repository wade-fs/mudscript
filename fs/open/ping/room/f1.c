// Room: /open/ping/room/f1.c ~night~(小戀)

inherit ROOM;

void create ()
{
  set ("short", "風行山寨外");
	set( "build", 96 );
  set ("long", @LONG

這裡就是風行山頂了,而風行山寨就建在這兒,山寨內好像有很多人在那走來走去的,如果你
想多活幾年,現在下山去還來的及喔. 門口有兩名守衛站著,看的出來,不是隨便什麼人都可
以進去的.


LONG);

   set("objects", ([ /* sizeof() == 2 */
   "/open/ping/npc/f-guard" : 2,
]));

  set("outdoors", "/open/ping");

  set("exits", ([ /* sizeof() == 3 */
  "east" : __DIR__"f2.c",
 "north" : __DIR__"f3.c",
  "down" : __DIR__"m19",
]));

  setup();
}
int valid_leave(object me,string dir)
{

        if(dir=="north"&&present("mount guard",environment(me)))
        {
        if(me->query_temp("weapon"))
        return notify_fail("山寨守衛怒氣沖沖的看著你說: 幹嘛 ? 來鬧事 ?\n");
        }
        return 1;
}
