//written by acelan...../u/a/acelan/ghost/room/ghost39.c

inherit ROOM;

void create()
{
        set("short", "黑風組組長衛博戰的閨房");
        set("long", @LONG
這裡是黑風組組長衛博戰的閨房, 房內擺設簡單, 除了一張床及
圓桌外, 就只有牆上供俸著的神明了, 香火尚未燃盡, 看來黑風組組
長衛博戰似乎做過了不少的虧心事, 以至現在必須常常燒香拜佛。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"ghost37.c",
   ]));
   set("no_clean_up", 0);
 set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/chen.c" : 1,
]));

   setup();
}
