// Room: /u/d/dhk/questsfan/rm28
inherit ROOM;
#include "/open/open.h"
#include <ansi.h>
void create ()
{
  set ("short", "藏仙谷");
  set ("long", @LONG
這裡是嵩山最有名的〝嵩山雙谷〞之一，有著『仙人故鄉』的雅
稱的藏仙谷。據一些江湖謠傳，若是修道之人在將近得道成仙之前能
前往此谷修行、居住一段時日便能立即得道成仙。不過你仔細向四周
打量一番，發覺此地只不過是一座普通的山谷，頂多是環境略為優雅
、清新一點罷了，實在看不出它的特別在何處，實在令人納悶呀！

LONG);

  set("outdoors", "/u/d");
  set("no_transmit", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"rm33",
  "west" : __DIR__"rm35",
]));

  setup();
}
int valid_leave(object who,string dir)
{
        if(dir=="west"&&present("mountain god",environment(who))||dir=="west"&&!present(environment(who)))
  {
        if(who->query_temp("meetgod_4")!=1)
        {
//       tell_object(who,"" + HIM + "谷中仙怒喝:凡夫俗子竟然亂闖藏仙谷，還不速速離去。" + NOR + "\n");
        return notify_fail("谷中仙怒喝:凡夫俗子竟然亂闖藏仙谷，還不速速離去。\n");
        }
        return :: valid_leave(who,dir);
  }
  return :: valid_leave(who,dir);
}
void init()
{
call_out("dhk",1,this_player()); 
}
void dhk(object who)
{
  object god=new(__DIR__"npc/god.c");
    if(who->query_temp("meetgod_4")!=1 && !present("mountain god",environment(who)))
    {
       god->move(__DIR__"rm34.c");
       remove_call_out("dhk");
    }
}
