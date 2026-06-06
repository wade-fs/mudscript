//written by acelan...../u/a/acelan/ghost/room/ghost5.c

inherit ROOM;

void create()
{
        set("short", "墓園");
        set("long", @LONG
這裡是十三公墓的一角, 由於地處偏遠, 再加上風水並不是很理
想, 所以這裡並沒有埋有墳墓。四周野草及腰, 且兼光線昏暗, 連落
腳處都看不清, 所以還是不要久留的好。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"ghost2.c",
       "east"  : __DIR__"ghost6.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
