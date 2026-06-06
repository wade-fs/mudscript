//written by acelan...../u/a/acelan/ghost/room/ghost35.c

inherit ROOM;

void create()
{
        set("short", "黑風組總部");
        set("long", @LONG
這裡是黑風組的總部, 黑風組員一個個神色木然, 看起來頗不易
與, 四周空盪盪的, 除了牆上釘了幾把千古恨外, 便再無其他東西了
, 看來黑風組並不富裕。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "west"  : __DIR__"ghost34.c",
   ]));
   set("no_clean_up", 0);

   setup();
}

