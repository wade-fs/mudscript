// Room: /open/start/room/s11.c

inherit ROOM;

void create ()
{
  set ("short", "凌雲村");
  set ("long", @LONG
平靜安詳的村莊，兩旁見到的都是平凡的民舍，
沒有什麼特殊的建築，遠向南方望去是一片綠油油的
稻田，有幾個農夫正在辛勤的耕作。
    北面是村長的房舍。

LONG);

  set("exits", ([ /* sizeof() == 3 */
  "west" : "/open/start/room/s10",
  "north" : "/open/start/room/s12",
  "east" : "/open/start/room/s14",
]));

  set("outdoors", "/open/start");

  setup();
}
