// Room: /open/ping/room/road1.c
inherit ROOM;

void create ()
{
	set("short", "石板大道");
	set("long", "走進了平南城,仍是一片歌舞平昇,半點也見不到戰爭的氣息
,路上的行人嘻嘻嚷嚷,偶爾有幾位軍人通過, 才有一點張緊張的
味道,西方就是平南鬧區,也\\許\你可以過去看看.
");

  set("exits", ([ /* sizeof() == 4 */
  "north" : "/open/poison/room/pingroom.c",
//"south" : __DIR__"war_room",
  "west" : __DIR__"road2.c",
  "east" : __DIR__"edoor",
]) );

  set("outdoors", "/open/ping" );


  setup();
}
