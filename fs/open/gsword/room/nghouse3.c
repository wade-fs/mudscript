// Room: /open/gsword/room/nghouse2.c
inherit ROOM;

void create ()
{
  set ("short", "廣場");
  set ("long", @LONG
這廣場是仙劍門徒練劍的場所，只見廣場中間一個頗大的太極圖，
在太極圖上依照著八卦的方位滿佈木樁。在廣場的所邊的一塊大石頭上
有著幾行字(words)。
LONG);

  set("light_up", 1);
  set("outdoors", "/open/gsword");

  set("exits", ([ /* sizeof() == 1 */
  "east" : "/open/gsword/room/nghouse2",
]));

  setup();
}
