// Room: /open/capital/room/r64.c

inherit ROOM;

void create ()
{
  set ("short", "雲洋大街");
  set ("long", @LONG
來到這裡，因為鄰近皇城與達官貴人的住所附近, 很少有閒雜人來
此閒蕩，也許不是我們該來的地方吧。正因為如此, 你發現街上一個人
影也沒有, 除了偶而走過的禁衛軍外, 可以說是完全靜悄悄的。

LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/capital/room/r63",
  "east" : "/open/capital/room/r50",
]));

  set("outdoors", "/open/capital");

  setup();
}
