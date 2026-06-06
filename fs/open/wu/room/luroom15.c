// Room: /open/wu/room/luroom15.c
// 瀧山武館的花園
inherit ROOM;
void create()
{
        set("short", "花園");
        set("long", @LONG
這裏是瀧山武館的花園,由於瀧山武館的地理位置位在南方所以四季如
春,花繁景緻,草木碧綠,一陣陣和煦的風吹來,一趟森林浴下來讓人精神
氣爽,的辛苦,消除了在平時練武,四週蝴蝶飛舞,更是談請說愛的好地方。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
        "south" : __DIR__"luroom16",
        "west" : __DIR__"luroom12",
]));
        setup();
}
