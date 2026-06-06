#include <ansi.h>
inherit ROOM;
void create()
{
        set("short", "門口");
        set("long", @LONG

          ╭═╮  ╭══╮     ╭═╮     ╮    ╭══╮╭══╮
        ╭╯  ╰╮║╭═╣   ╭╯  ╰╮   ║    ╠══║╠══║
        ║═╦═║║╰╯║   ║═╦═║ ═╬═  ╠══╯╰══╣
        ║═╬═║╠══╯   ║═╬═║   ║    ║            ║
        ╯╮║╭╰║═╮╯   ╯╮║╭╰   ║    ║            ║
        ═╩╩╩═╰═╰═   ═╩╩╩═   ║    ╰            ╯

LONG
        );
        set("light_up", 1);
        set("outdoors", 1);
        set("exits", ([ /* sizeof() == 2 */

      "south" : __DIR__"d2",
      "north" : __DIR__"2-door",
]));
        set("no_clean_up", 0);

        setup();
        }


