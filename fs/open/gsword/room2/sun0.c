#include <ansi.h>
inherit ROOM;
void create()
{
   set("short", HIW"仙劍試煉峽谷"NOR);
   set("long", @LONG
一個雜草叢生的峽谷.四周山壁聳立..看起來似乎無法離開此處...
就在你仔細找尋出口時..你發現山壁上盡是屬不盡的劍痕.。
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
  int edir=random(5);
  int wdir=random(5);
  int sdir=random(5);
  room->set("exits/west","/open/gsword/room2/sun"+wdir);
  room->set("exits/east","/open/gsword/room2/sun"+edir);
  room->set("exits/north","/open/gsword/room2/sun5");
  room->set("exits/south","/open/gsword/room2/sun"+sdir);
    message_vision(HIR"\n$N進入仙劍試煉場後後..瞬間衝出數道劍芒.\n",who);
    message_vision(HIR"劍芒消失後，數到人影$N衝來！！！\n"NOR,who);
    seteuid(getuid());
    i=random(3)+1;
    while(i--)
   {
      mob=new("/open/gsword/npc2/t_man");
      mob->move(room);
      mob->callset(who);
      mob->kill_ob(who);
    }
  return 1;
}
int valid_leave(object me, string dir)
{
if((dir=="south" || dir=="east" || dir=="west")&& present("man",environment(me)))
    if(!me->query_temp("allow_read",1))
   return notify_fail("你以為你能活得過去嗎??"+RANK_D->query_respect(me)+"你去死吧!\n");
return ::valid_leave(me,dir);
}
