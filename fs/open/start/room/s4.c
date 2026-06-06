// Room: /open/start/room/s4.c

inherit ROOM;

void create ()
{
  set ("short", "凌雲村");
	set( "build", 2560 );
  set ("long", @LONG
平靜安詳的村莊，兩旁見到的都是平凡的民舍，
沒有什麼特殊的建築，遠向南方望去是一片綠油油的
稻田，有幾個農夫正在辛勤的耕作。
    南面的房舍是村人們飼養家畜的地方。
北邊則是驛站.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/start/room/s2",
  "south" : "/open/start/room/s6",
  "east" : "/open/start/room/s5",
  "north" : "/open/trans/room/room5.c",
]));

  set("outdoors", "/main/start");

  setup();
}
