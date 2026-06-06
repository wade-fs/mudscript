//tesinroom
#include <ansi.h>
inherit ROOM;

void create()
{
        set("short", HIY + "鐵心居" + NOR);
        set("long", @LONG
進入屋內..一陣濃濃的沉香..另你心神一陣...屋內簡單的擺設..讓人有種
清新自然的感覺...大廳上..一個年近半百的前輩正閉目沉思..難道它就是傳說
中的大劍師--【龍鐵心】?
LONG );
        set("exits", ([ /* sizeof() == 3 */
      "out":"/open/gsword/room2/tesinroad2.c",
 ]));
        set("light_up",1);
        set("no_transmit", 1);
        set("objects",([
        "/open/gsword/npc2/tesin.c":1,
  ]));
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
if(!who->query("quests/findtesin"))
{
 who->set("quests/shasword",6);
 if (who->query_temp("find_tesin8")==1)
 {
 who->set("quests/findtesin",1);
 who->delete_temp("find_tesin8",);
  who->set("swordskill/fsword2",1);
 }
 else if (who->query_temp("find_tesin8")==2)
 {
 who->set("quests/findtesin",1);
 who->delete_temp("find_tesin8",);
  who->set("swordskill/fsword2",1);
 }
 else  if (who->query_temp("find_tesin8")==3)
 {
 who->set("quests/findtesin",1);
 who->set("swordskill/sword2",1);
 who->delete_temp("find_tesin8",);
 }
}
}
