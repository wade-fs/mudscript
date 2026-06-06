#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIW"天地破魔陣"NOR);
        set("long", @LONG
渾渾噩噩之間..你來到的破魔陣的陣眼,耀眼的七彩光芒..閃爍不定.尋尋覓覓中
你發現在你正上方..七顆無比耀眼的奇異礦石.依一個你不知道圖形排列..礦石外
被幾個半透明的光圈包圍...另你不知其作用為何。
LONG
        );
        set("exits", ([ /* sizeof() == 3 */
 "north":"/open/gsword/room2/tesinroad.c",

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
  if(who->query("bellicosity") > 500+random(100)) {
    message_vision(HIR"\n$N進入天地破魔陣後..瞬間陣眼中的破魔七星發出耀眼光芒.\n",who);
    message_vision(HIR"光芒消失後，數條駭人之巨龍向$N衝來！！！\n"NOR,who);
    seteuid(getuid());
    i=random(5)+1;
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

