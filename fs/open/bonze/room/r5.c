// Room: /open/soulin/room/r5.c

inherit ROOM;

void create ()
{
	set("short", "林間小徑");
	set( "build", 12 );
	set("long",@LONG
	少林寺乃是個佛門清修之地，一進山門便是一條
	小徑，兩旁種植了許多不知名的樹木，高聳參天
	，間而鳥語，更顯示出此地的清靜。


LONG );

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"r2",
  "out" : "/open/main/room/M15",
]) );

  set("outdoors", "/open/soulin" );


  setup();
}
