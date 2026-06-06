// Room: /open/soulin/room/big.c

inherit ROOM;

void create ()
{
  set ("short", "$HIY$少林大雄寶殿$NOR$");
  set ("long", @LONG

一個非常寬廣的大殿，殿內有一尊十分龐大的如來佛像，
大概有六﹑七人高，令人嘆為觀止。寺內除了僧人們低沈
的誦經聲外，聽不到其他的聲音，彷彿如針般細微的東西
落地也能夠聽見。


LONG);

  
  set("no_magic", "1");
  set("build", 12);
  set("light_up", "1");
  set("valid_startroom", 1);
  set("objects", ([ /* sizeof() == 1 */
  "/daemon/class/bonze/master.c" : 1,
]));
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"s07.c",
  "up" : __DIR__"s20.c",
]));

  setup();
  call_other("/obj/board/bonze_b","???");
}
  int valid_leave(object me, string dir)
{
if( dir=="up" )
   if( me->query("family/family_name")!="少林派")
                return notify_fail("只有少林弟子才可以進入。\n");
return ::valid_leave(me,dir);
 }

