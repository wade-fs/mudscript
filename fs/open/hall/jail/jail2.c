// Room: /open/hall/jail/jail2.c

inherit ROOM;

#include <ansi.h>

void create()

{

        set("short", "牢房走道");
        set("long", @LONG
走道兩旁燃著兩隻火把，整個牢房的燈光就來自此地..潮濕的地板
..偶而還夾點斑斑的血跡....陣陣的寒意登時湧上你的心頭......你感
到一股強烈的不愉快感!!你最好盡快離開這裡為上!!
LONG);

        set("exits", ([ /* sizeof() == 1 */
  "south" :__DIR__"jail",
  "north" :__DIR__"jail3",

  ]));

        setup();

}

