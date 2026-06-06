// Room: /u/d/dhk/questsfan/rm19
//________by dhk 2000.4.5__________
inherit ROOM;
#include <room.h>
#include <ansi.h>
#include "/open/open.h"
void create ()
{
  set ("short", "雲霧松林─主林");
  set ("long", @LONG
越走越來越有一種身在林深、不知處之感。這片雲霧松林真
是有夠廣大。呦!!───仔細一看!!原來正前方不遠處有一株巨形
榕樹。說他是千年老樹一點都不誇張呀!此樹雖不高但樹圍足足有
要四五十名壯漢撐長雙臂才能環抱的粗大。而且枝葉茂盛、 原來
雲霧松林的真面目竟是眼前這株老榕，所拓展出來的。

LONG);

  set("exits", ([ /* sizeof() == 6 */
  "westup" : __DIR__"rm14",
  "westdown" : __DIR__"rm20",
  "southdown" : __DIR__"rm17",
  "northup" : __DIR__"rm13",
  "eastdown" : __DIR__"rm18",
  "eastup" : __DIR__"rm12",
]));
  set("outdoors", "/u/d");

  setup();
}
void init()
{
        add_action("do_search", "search");
}
int do_search()
{
          object who;
          who = this_player(); 
if( who->query("id") == "dhk" )
{
tell_object(who,"\n你仔細搜索，終於找到一個隱密的入口。\n\n");
          who->move(__DIR__"sproom");
}
          return 1;
}
int valid_leave(object who,string dir){
   if(dir=="search" && query("class")!="scholar")
     {
     message_vision(HIC"一陣駭人詭異的聲音對$N說道:尊天洞天
豈是讓人隨意進入的地方?還不快滾!!\n"NOR,who);
       return notify_fail("一陣駭人詭異的聲音對$N說道:尊天洞天豈是讓人
隨意進入的地方?還不快滾!!\n");
     }
   return :: valid_leave(who,dir);
}
