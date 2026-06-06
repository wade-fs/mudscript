inherit ROOM;
#include <ansi.h>
void create ()
{
  set ("short", "沙灘");
  set ("long", @LONG
遍地的白沙, 除了一棵枯樹與一塊大岩之外, 並沒有其他事物. 你雖覺得枯
樹與岩石的感覺十分怪異, 但是經過仔細的尋找並沒有找到什麼奇怪的地方. 此
地除了東邊是海之外, 其他方向放眼望去都是白藹藹的沙灘, 在西北方能見到一
座高聳的岩壁.
LONG);

  set("outdoors", "/u/u");
  set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"is13.c",
  "west" : __DIR__"is7.c",
  "south" : __DIR__"is5",
]));

  setup();
}
void init()
{
add_action("do_search", "search");
add_action("do_look", "look");
add_action("do_get", "get");
add_action("do_put", "put");
}
int do_search()
{
object me=this_player();
if (me->query_temp("can_search")==1)
{
tell_object(me,HIC + "你赫然發現岩石的樹旁可以看到因退潮而呈現的沙岸上有一塊扁平的大岩石(stone).\n" + NOR);
tell_object(me,HIY + "原來黎明時是這座島退潮的時間 .\n" + NOR);
new("/u/u/unfinished/room/obj/stone.c")->move(environment(me));
me->delete_temp("can_search");
me->set_temp("can_back",1);
return 1;
}
else
{
return 0;
}
}
int do_look(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(arg!="box")
       return 0;
   if(me->query_temp("openbox")!=1)
       return 0;
else
{
tell_object(me,"testtest");
return 1;
}
}
int do_get(string arg)
{
object me,ob;
me=this_player();
   if( !arg )
       return 0;
   if(arg!="all from box")
       return 0;
   if(me->query_temp("care")==1)
{
tell_object(me,"you are care 2 !!");
me->set_temp("care",2);
return 1;
}
else
{
tell_object(me,"don't get anything !!");
me->set_temp("care",1);
return 1;
}
}
