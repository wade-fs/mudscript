//written by acelan...../u/a/acelan/room/wood22.c

inherit ROOM;

void create()
{
        set("short", "樹林上的密道");
        set("long", @LONG
你走上了樓梯, 很訝異的發現樹林上竟然有一條精心設計的密道
, 如果沒有相當程度的輕功, 是無法繼續前進。你小心翼翼的踏著樹
枝, 緩緩前進。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : "/open/killer/mon/room/wood29.c",
       "west" : "/open/killer/mon/ghost/room/ghost1.c",
       "down" : "/open/killer/mon/room/wood15.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc2.c":2,
   ]));

   set("no_clean_up", 0);

   setup();
}
