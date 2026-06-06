// 增加north 06/13/93 by Firedancer
// Room: /open/start/room/s1.c

inherit ROOM;

void create ()
{
  set ("short", "凌雲村");
	set( "build", 442 );
  set ("long", @LONG
平靜安詳的村莊，兩旁見到的都是平凡的民舍，
沒有什麼特殊的建築，遠向南方望去是一片綠油油的
稻田，有幾個農夫正在辛勤的耕作。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/start/room/startroom",
  "east" : "/open/start/room/s2",
  "north":"/open/area/house/h01",
]));

  set("outdoors", "/open/start");

  setup();
}

