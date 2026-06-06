// Room: /open/ping/room/road7.c
inherit ROOM;

void create ()
{
  set ("short", "石板大道");
  set ("long", @LONG
這裡是一條林蔭大道, 兩旁的大樹伸展著其巨大的樹幹, 互相交叉
的纏在一起, 黑壓壓的把天空都蓋住了, 只能由樹葉的隙縫中勉強看到
藍天。往前轉出林蔭, 就看見前方正中的一座高樓, 迎著蒼穹, 很有種
獨步天下,主沈浮的氣勢, 相信這必定是段王府了。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/ping/room/road4",
  "north" : "/open/ping/room/pingking",
]));
  set("outdoors", "/open/ping");

  setup();
}
