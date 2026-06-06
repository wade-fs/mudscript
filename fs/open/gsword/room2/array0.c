#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"天地破魔陣"NOR);
        set("long", @LONG
這是傳說中由破魔師-於蘭天武所設計的破魔奇陣..陣中遙遙望去發現陣眼安置了
傳說中的破魔七星..據說此七星乃是女媧補天所用九天玄晶所製成..乃破魔至極之物
眼見破魔七星閃閃發亮..你心中魔氣頓時受到壓抑...。
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
  int edir=random(20);
  int wdir=random(20);
  int ndir=random(20);
  int sdir=random(20);
this_player()->delete_temp("find_tesin1");
this_player()->delete_temp("find_tesin2");
this_player()->delete_temp("find_tesin3");
this_player()->delete_temp("find_tesin4");
this_player()->delete_temp("find_tesin5");
this_player()->delete_temp("find_tesin6");
  room->set("exits/west","/open/gsword/room2/array"+wdir);
  room->set("exits/east","/open/gsword/room2/array"+edir);
  room->set("exits/north","/open/gsword/room2/array"+ndir);
  room->set("exits/south","/open/gsword/room2/array"+sdir);
  if(who->query("bellicosity") > 500+random(100)) {
    message_vision(HIR"\n$N進入天地破魔陣後..瞬間陣眼中的破魔七星發出耀眼光芒.\n",who);
    message_vision(HIR"光芒消失後，數條駭人之巨龍向$N衝來！！！\n"NOR,who);
    seteuid(getuid());
    i=random(3)+1;
    while(i--) {
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
