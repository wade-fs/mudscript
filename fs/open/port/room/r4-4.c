// Room: /open/gblade/port/room/p1-6.c
inherit ROOM;

void create()
{
  set ("short", "武器店");
	set( "build", 142 );
  set ("long", @LONG
這是一家武器店 , 販賣著各式各樣的刀 , 為全國刀器最
為齊全之地 , 你看到很多刀客在此選購適合自己的兵器 , 所
謂工欲善其事 , 必先利其器 , 看來 ,你也該為自己選把像樣
的武器 , 好闖蕩江湖 .你可以看看(list)老闆在賣些什麼 ?

LONG);

  set("light_up", 1);
	set("objects",([
	"/open/port/npc/wang":1,
	"/open/port/npc/trainee2":1,
	]));
  set("exits", ([ /* sizeof() == 1 */
	"south" : "/open/port/room/r4-2",
]));
  setup();
}
