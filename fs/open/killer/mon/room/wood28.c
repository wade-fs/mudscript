//written by acelan...../u/a/acelan/room/wood28.c

inherit ROOM;

void create()
{
        set("short", "樹林上的密道");
        set("long", @LONG
在前方不遠處, 你發現有一朵靈芝, 在靈芝的四周雜草不生, 似
乎是難得一見的千年靈芝, 不過頗為奇怪的是這棵靈芝身上五彩斑斕
, 或許它身懷劇毒, 還是不吃為妙。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "east" : "/open/killer/mon/room/wood29.c",
       "west" : "/open/killer/mon/room/wood27.c",
   ]));

        set("no_clean_up", 0);

        setup();
}
