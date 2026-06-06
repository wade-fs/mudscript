// Room: /open/main/room/[3].c
inherit ROOM;
void create()
{
	set("short", "廢墟");
	set( "build", 36 );
	set("long",
"你來到了一處可帕的地方, 凌亂的雜草中, 聳立著幾面斷岩殘璧,
高大的老樹, 遮掩了天空, 竟連一絲陽光也透不下, 你可以想像這裡
曾是熱鬧的地方, 而今已久無人居矣, 你想你還是趕快離開為妙.
");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"r44",
  "south" : __DIR__"s29",
]) );
  set("objects", ([
      "/open/main/npc/shie-chiun" : 1,
      ]) );
  setup();
}

void init()
{
}
