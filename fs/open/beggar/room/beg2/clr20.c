// Room: /u/g/guetenr/beggar/room/beg2/clr20.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "丐幫總舵");
  set ("long", @LONG
橋樑北端蹲著兩個大石獅子，皆張牙舞爪氣勢不凡；大門上懸匾書『丐
滿天下』四個大字，兩側門柱上復有一聯曰：『高山流水遇知音，揖風臥雲
支天下』；栗色厚重木門終日洞開供遊人玩賞莊園，更有那白色牆垣向東西
綿延不絕，垣頂用灰瓦覆蓋，相襯得十分素雅；牆上每隔三五步鑲有漏窗，
於陽光逆照中透射迷人光影，又使牆裡牆外隱約可見。
LONG);

  set("outdoors", "/open/beggar");
  set("exits", ([ /* sizeof() == 2 */
  "enter" : __DIR__"clr21.c",
  "south" : __DIR__"clr14.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/beggar/room/beg1/npc/lv7beg.c" : 2,
]));

  setup();
}
