// Room: /u/g/guetenr/beggar/room/beg2/clr14.c
#include <ansi.h>
inherit ROOM;

void create ()
{
  set ("short", "太君山頂");
  set ("long", @LONG
一上頂峰，映入眼簾的卻是一棟破舊的廟宇, 雖然有點破舊，
但是四周的環境卻很乾淨，屋簷下方掛著一個匾額，上頭刻了降龍
羅漢」四個大字，看來這裡應該丐幫總舵的所在地了。
LONG);

  set("outdoors", "/open/beggar");
  set("exits", ([ /* sizeof() == 2 */
  "north" : __DIR__"clr20.c",
  "northdown" : __DIR__"clr13.c",
]));

  setup();
}
