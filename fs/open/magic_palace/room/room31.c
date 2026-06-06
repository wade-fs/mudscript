inherit ROOM;
#include <ansi.h>
void create ()
{
set ("short","青光之扉");
set("long",@LONG
此地在青蛇護符的祝福之下，令人感到五體舒暢，之前的陰鬱妖氣
受到相當的抑制，你趁機喘了口氣，然而隨即感到北方傳來一股雖細微
卻異常犀利的魔氣，逼得你不得不立刻全副武裝起來。

LONG);
        set("no_auc", 1);
        set("no_transmit", 1);
        set("light_up",-1);
        set("exits", ([ /* sizeof() == 1 */
        "north"   : __DIR__"room35",
      ]));
        setup();
}
