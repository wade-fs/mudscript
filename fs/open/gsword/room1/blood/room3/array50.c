#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW + "開天三才陣" + NOR);
        set("long", @LONG
這是傳說中由仙劍祖師逍遙子所設計的封印血魔的陣法..陣中遙遙望去發現陣眼有三個發亮的寶珠..眼見三晶珠閃閃發亮..你心中魔氣頓時受到壓抑...。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
]));
        set("light_up",1);
        set("no_transmit", 1);
        setup();
}

void init()
{
  object ob;
  if( interactive( ob= this_player()))
   {
      remove_call_out("greeting");
        call_out("greeting", 0, ob);
   }
}
int greeting (object who)
{
  object room = this_object();
  object mob;
  int i;
  int edir=random(50);
  int wdir=random(50);
  int ndir=random(50);
  int sdir=random(50);
  room->set("exits/west","/open/gsword/room1/blood/room3/array"+wdir);
  room->set("exits/east","/open/gsword/room1/blood/room3/array"+edir);
  room->set("exits/north","/open/gsword/room1/blood/room3/array"+ndir);
  room->set("exits/south","/open/gsword/room1/blood/room3/array"+sdir);
  if(who->query("bellicosity") > 20+random(10)) {
    message_vision(HIR + "\n$N進入開天三才陣後..瞬間陣中的破魔七星發出耀眼光芒.\n",who);
    message_vision(HIR + "光芒消失後，數條駭人之巨龍向$N衝來！！！\n" + NOR,who);
    seteuid(getuid());
    i=random(4)+1;
    while(i--)
   {
      mob=new("/open/gsword/npc2/t_dragon");
      mob->move(room);
      mob->callset(who);
      mob->kill_ob(who);
    }
  }
  return 1;
}
int valid_leave(object me, string dir)
{
if((dir=="north" || dir=="south" || dir=="east" || dir=="west")&& present("dragon",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以為你能活得過去嗎??"+RANK_D->query_respect(me)+"你去死吧!\n");

return ::valid_leave(me,dir);
}

