inherit ROOM;

void create ()
{
 set ("short", "聚賢亭");
	set( "build", 19 );
  set ("long", @LONG

據說金刀門的第一代門主是一個大將軍，當初為了號召義士曾經在這裡召
開英雄大會，後來又在這裡創立金刀門，為了紀念當初那次的英雄大會就
在這裡建了一座亭子，並名為聚賢亭。在這你不禁想像起當年的英雄大會
，許久才會過神來。

LONG);


  set("light_up", 1);
  set("outdoors", "/open/gblade");

  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"g1-3.c",
	"out" : "/open/gblade/room/g1-1",
]));

  setup();
}
int valid_leave(object me,string dir)
{
 if(dir=="out")
 me->delete_temp("lose_cup");
 return 1;
 }
