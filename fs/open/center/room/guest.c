// Room: /u/l/lotus/girl/guest.c

#include "/open/open.h"
inherit ROOM;

void create ()
{
  set ("short", "香樓大廳");
  set ("long", @LONG
張燈結綵, 一片喜氣洋洋, 桌上盛放著的牡丹, 使大廳更添嫵媚
色彩. 香樓來往的客人還真不少, 有一擲千金的富商巨賈, 也有風流
倜儻的才子, 牆上掛著的畫, 便是出自性情才子之手.

姑娘們正笑盈盈地迎接客人.
LONG);

  set("exits", ([ /* sizeof() == 3 */
  "north" : CENTER_ROOM"guest3.c",
  "west" : CENTER_ROOM"guest2.c",
  "east" : CENTER_ROOM"tree.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  CENTER_NPC"powyi.c" : 1,
]));
  set("light_up", 1);
  set("file_name", CENTER_ROOM"guest.c");

  setup();
}
