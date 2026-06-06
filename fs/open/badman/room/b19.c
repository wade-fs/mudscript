// Room: /open/badman/room/b19
inherit ROOM;

void create ()
{
	set("short", "惡人谷南街");
	set( "build", 1 );
	set("long", "惡人谷的南街。人來人往的景像，很難讓人聯想這是個與世隔
絕之地；而雖人多，人人的臉上卻都是副冷漠的表情；彷彿任何事
都是不干己身的模樣，讓人瞧了不禁心冷。

");

  set("objects", ([ /* sizeof() == 2 */
  "/open/badman/npc/dog.c" : 1,
  "/open/badman/npc/boy.c" : 1,
]) );

  set("outdoors", "/open/badman" );

  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"b18",
  "north" : __DIR__"b7",
]) );


  setup();
}
