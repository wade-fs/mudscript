//written by acelan...../u/a/acelan/room/wood5.c

inherit ROOM;

void create()
{
        set("short", "森林的小徑");
        set("long", @LONG
這裡是森林的西側, 有一條由樹葉構成的小徑向前延伸, 似乎可
以帶你走出這片恐怖的森林。兩旁樹木高聳, 排列有致, 強風迎面吹
來, 不禁令你打了個冷顫。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : "/open/killer/mon/room/wood12.c",
       "east"  : "/open/killer/mon/room/wood6.c",
   ]));
   set("objects", ([ /* sizeof() == 1 */
       "/open/killer/mon/npc/grnnpc3.c":2,
       "/open/killer/mon/npc/spy5.c":1,
   ]));
        setup();
}
