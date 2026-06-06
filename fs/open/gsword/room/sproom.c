// Room: /open/gsword/room/wghouse.c
inherit ROOM;

void create ()
{
  set ("short", "後堂");
  set ("long", @LONG
這裡是仙劍的後堂 ,往西是仙劍的藏劍室 ,東南邊是仙劍的中心位置 , 一般掌門
是不許弟子來此的 ,為了避免麻煩 ,還是儘早離開為妙 
LONG);

  set("exits", ([ /* sizeof() == 2 */
  "west" : "/open/gsword/room/g5-5.c",
  "southeast" : "/open/gsword/room/g5-4.c",
]));
  set("objects", ([ /* sizeof() == 1 */
  "/open/gsword/npc/swordman" :1,
]));

  set("light_up", 1);

  setup();
}
int valid_leave(object me, string dir)
{
if( dir=="west" && present("han toung",environment(me)))
   return notify_fail(" 邢濤說道 :這裡是仙劍重地 ,你還是快離開吧!!!\n");
return ::valid_leave(me,dir);
}
