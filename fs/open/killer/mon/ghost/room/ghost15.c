//written by acelan...../u/a/acelan/ghost/room/ghost15.c

inherit ROOM;

void create()
{
        set("short", "墓穴");
        set("long", @LONG
墓穴內光線昏暗, 陰氣森森, 但見四周空空曠曠, 一無所有, 不
過近處卻不時有嘎嘎聲響傳出, 偏偏你又什麼東西都看不見, 頓時覺
得毛骨悚然, 全身不寒而慄。
LONG
        );
   set("exits", ([ /* sizeof() == 1 */
       "north" : __DIR__"ghost22.c",
       "east"  : __DIR__"ghost16.c",
   ]));
   set("no_clean_up", 0);

   setup();
}
