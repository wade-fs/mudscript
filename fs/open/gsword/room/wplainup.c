// Room: /open/gsword/room/wplainup.c
inherit ROOM;

void create()
{
  set ("short", "松樹上");
  set ("long", @LONG
站在高高的樹上，遠眺四方，西北方是武林泰斗仙劍派，東南方則是蜀中城
再向遠望 ，盡是綿延無盡的山脈，裊裊雲煙環繞，似乎又是另外一個世界。

LONG);

  set("objects", ([ /* sizeof() == 1 */
 "/open/gsword/mob/eagle" : 2,
]) );

  set("outdoors", "/open/gsword/room" );

  set("exits", ([ /* sizeof() == 1 */
  "down" : __DIR__"wplain1",
]) );

  setup();
}
