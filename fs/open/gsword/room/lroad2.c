#include <room.h>

 inherit ROOM;

void create ()
{
	set("short", "仙劍派前山");
	set("long", "          
你的眼前盡是垂直的峭壁，光滑的連一根草也無法在上面著根，維獨在峭壁(cliff)的
左側，顏色較趨暗色，好奇心使你想看的清楚些，不過那高度實在太高你再怎麼努
力，也無法瞧個仔細。        

");

  set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"lroad3",
  "east" : __DIR__"lroad1",
]) );

  set("outdoors", "/open/gsword/room" );

  setup();
}

void init()
{
    add_action("do_enter","pass");
    add_action("do_search","search");
}

int do_enter(string str)
{
   object me = this_player();
if(me->query("quests/yan")==4)
{
      tell_object(me,"你看了看峽谷.鐵了心..咻的一聲就衝進峽谷中\n");
       tell_object(me,"修的一聲..你運起頂級輕功\..輕輕的落在崖下\n");
          me->move("/open/gsword/room2/sha1.c");
}
else if( me->query("family/family_name")=="仙劍派" && me->query("get_sha_sp",1) &&me->query("quests/sunfire")!=1 && me->query("quests/yan")>=2)
   {
   if (me->query("combat_exp")<1000000)
     tell_object(me,"你看了看峽谷..看了看自己..還是覺得不要進去好了\n");
   else 
    {
       tell_object(me,"你看了看峽谷.鐵了心..咻的一聲就衝進峽谷中\n");
       tell_object(me,"你剛走進峽谷..腳步一個不穩..不小心就滑下懸崖\n");       
      this_player()->unconcious();
          me->move("/open/gsword/room2/sha1.c");
    }
   }
   return 1;
}

int do_search(string str)
{
   object me = this_player();
if( me->query("family/family_name")=="仙劍派" && me->query("get_sha_sp",1) &&me->query("quests/yan")>=1)
   {    
   tell_object(me,"找著找著..你似乎找到了一個可以穿越(pass)的步道\n");
   if (me->query("quests/yan")==1 ) me->set("quests/yan",2);
    }
 return 1;
}
