// Room: /open/badman/room/t7
inherit ROOM;

void create ()
{
  set ("short", "地道");
  set ("long", @LONG
空氣中傳來一絲血腥味，看來應該快到盡頭了。前頭仍舊是一
片漆黑，聲音靜的出奇，但是你確定黑暗中有某個東西正在看著自
己。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "south" : "/open/badman/room/tigerhole",
  "west" : "/open/badman/room/t3",
]));

  setup();
}
