#include <ansi.h>
#include <room.h>
inherit ROOM;
                
void create ()
{
  set ("short", "𮧫");
  set ("long", @LONG
oO̱SV᪺𮧪a  
bo঳@p(water),GIżAO٬OiHܪ,
LڷQ٬OnܤnAӬ~FˬOĳC
iHťaUǨӤ@}}FFn,QOaUҵoX


LONG);
  set("light_up", 1);
  set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"r0.c",
  "west" : __DIR__"restrm.c",
]));
  set("item_desc", ([ /* sizeof() == 1 */
  "water" : "MIC,OA٬OiHboܤ(drink) 
",
   ]));
  set("resource", ([ /* sizeof() == 1 */
  "water" : 1,
]));

  setup();
}

void init()
{
   add_action("do_drink", ({"drink"}) );
   add_action("do_enter",({"enter"}));
   add_action("do_wash",({"wash"}));
}
int do_drink(string arg)
{
  object me;

  if (!arg || arg=="" )
  {
    me = this_player();
    if ( (int)me->query("water") >= (int)me->max_water_capacity() )
    {
     tell_object(me,"Awg@f]ܤUF.......\n");
     return 1;
    }
    tell_object(me,"AqFXfܡAo{GǨ......\n");
    me->add("water",40);
    return 1;  
  }
    return 1;
}
int do_enter(string arg)
{
   object who;
   who=this_player();
   if(who->query("class")!="killer")
   return notify_fail("oOMαKD,@HLkiJ!\n");
   if((arg="water") || (arg=="water")) {
   message_vision(GRN + "$NiJFp\n" + NOR,who);
   tell_object(who,"\nAuťMա
    Mա\n\n");
   tell_object(who,HIW + "u@}jjժﭱӨӡ \n" + NOR);
   tell_object(who,"AbLkϧܤUQyaLB \n");
tell_object(who,HIC + "\nAPıմz,HKç줧U,@jY \n\n" + NOR);
who->move(__DIR__"stonerm.c");
   return 1;
   }
      return 0;
}

int do_wash(string arg)
{
   object who;

   who=this_player();

   if(present("herb",who))
   {
     tell_object(who,"\nANIhsJoөC⪺A
      Mզa~F_ӡ\n\n");
     tell_object(who,HIW + "u@}_ǪCܤơ \n" + NOR);
     tell_object(who,"oXF_~AӥiHFaCCC \n");
   }
   if(who->query_temp("herb_1")==1)
   {
     tell_object(who,HIW + "OѩAA@~ \n" + NOR);
     tell_object(who,"ϱooXF⪺~AשiHFI \n");
     who->set_temp("herb_1",2);
   }
   who->set_temp("herb_1",1);
   return 1;
}  
