// Room: /open/main/room/d10.c

inherit ROOM;

void create ()
{
  set ("short", "沙漠");
	set( "build", 12 );
  set ("long", @LONG
這兒是一望無際的撒哈拉沙漠，西北邊有一棟建築依勢而建，
從這兒看過去, 卻看不到入口, 不知它的門是在哪一邊?
南邊則現出稀稀疏疏的草皮, 想來那邊應該有水吧?
LONG);

  set("exits", ([ /* sizeof() == 4 */
  "east" : __DIR__"d11",
  "west" : __DIR__"r1",
  "south" : __DIR__"s10",
  "north" : __DIR__"d3.c",
]));
  set("outdoors", "/open/main");

  setup();
}
int valid_leave(object me, string dir)
{
if(dir == "up")
if(me->query("combat_exp") < 2400000)
return notify_fail("你的武學經驗太低了。\n");
     return :: valid_leave(me, dir);
}
