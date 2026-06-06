//written by acelan...../u/a/acelan/ghost/room/ghost23.c

inherit ROOM;

void create()
{
        set("short", "石棺");
        set("long", @LONG
眼前出現了一座石棺, 寒氣森森, 更駭人的是, 石棺上竟然還有
一灘血跡, 旋即你又發現四周散落著女生的小衣小褲, 和一些衣服碎
片, 忽然又聽見一女子哀嚎聲, 令人不寒而慄, 毛骨悚然。
LONG);
   set("exits", ([ /* sizeof() == 1 */
       "south" : __DIR__"ghost16.c",
       "east"  : __DIR__"ghost24.c",
       "west"  : __DIR__"ghost22.c",
   ]));
set("objects", ([ /* sizeof() == 1 */
  "/open/killer/mon/ghost/npc/bghost.c" : 1,
]));
   setup();
}
