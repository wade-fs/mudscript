// Room: /u/t/tide/room/tide1.c

inherit ROOM;

void create()
{
        set("short", "小巷道");
        set("long", @LONG
幽暗僻靜的小巷道中，迎面襲來的是股刺鼻薰人的霉臭味；而　　
地上所佈滿的坑坑洞洞，則是積滿了無處可流的死水。垃圾遍佈的
此地，偶而幾隻老鼠穿梭其中；除此之外，大概也沒啥生物了。
        正南方傳來幾聲的聲響，好像有人在那兒。

LONG
        );
        set("exits", ([ /* sizeof() == 1 */
                "south" : __DIR__"tide2",
        ]) );

        set("outdoors",1);
        setup();
}
