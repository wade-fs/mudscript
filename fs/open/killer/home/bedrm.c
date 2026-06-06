#include "/open/open.h"
#include <ansi.h>
inherit ROOM;

void create ()
{
set("short", "q׫");
set("long", @LONG
   BDqMݪ׫ǡA@ɭԥiOHKiHiӪC
   жAèSSO˹~AuLX֪Pre]word)C
   ~Aj]u@Ǫd㲴@I}FC

LONG 
);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"masterm.c",
]) );
  set("item_desc", ([ /* sizeof() == 2 */
  "word":"@iZreALˬOOA`N@Ǫ]֡^\n",
  "sign":"ӥF@Uo{iH(turn),AO_ӦҼ{(think)AHK~Ĳ\n",
]));
  set("search_desc", ([ /* sizeof() == 1 */
  "" : "nSSOAoHL]sign)C\n",
  "mark" : "AլdtAAtAMw]turn)F\n",
]));
  set("objects",([
  "/open/killer/npc/spy3.c":1,]));
  setup();
}
void init()
{
	add_action("do_think","think");
	add_action("do_turn","turn");
}

int do_think(string str)
{
  object me;
  
  me=this_player();
  message_vision("ھڸgAMwA٬OJ[@UAGMo{`Bt]mark)\n",me);
  me->set_temp("diray",2);
  return 1;
}

int do_turn(string str)
{
	object me=this_player();
        
  if( str != "" )
    return notify_fail("रHݭntܡHH\n");
  if(me->query_temp("diray") != 2)
  {
    message_vision("pĲʾA@wg$NC\n",me);
    me->add("kee",-30);
    return 0;
   }
  if(me->query_temp("diray") == 2)
  {
    message_vision(HIG + "H۪֪ʡAreF_ӡAK}C\n",me);
    message_vision("X{F@qOAn½Y@\n",me);
    message_vision("eyCCCuOpߡA~M]N]٩XӦh\n",me);
    message_vision("ۤAϦ]bKDפΪaFˡC\n",me);
    message_vision("icA⥦ʦLb]MΧLǡ^nFAƱ~cnXh\n",me);
    message_vision("LLǪ_͡AnWb@ӤFA䤣CCC\n",me);
    message_vision("AQbݤUhɡAo{~GHӤFAO榣hFXh\n\n" + NOR,me);
    me->set_temp("diray",1);
    me->move(__DIR__"masterm.c");
    return 1;
  }
}
