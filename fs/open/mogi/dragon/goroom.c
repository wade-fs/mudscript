// Room: /u/p/poloer/dragon/goroom
inherit ROOM;

#include <ansi.h>
void create ()
{
  set ("short", "柳家寶庫");
	set( "build", 56 );
  set ("long", @LONG
一間建築在谷旁隱密的地方，四周都沒有東西，只有一個破爛的靈位
上面隱約看到"柳..."似乎可以膜拜(pray)看看。

LONG);

  set("objects", ([ /* sizeof() == 1 */
  __DIR__"obj/status.c" : 1,
]));

  setup();
}
void init()

{
    add_action("do_pray","pray");
    add_action("search_here", "search");
    add_action("do_enter","enter");
    add_action("do_see","see");
}

int do_pray(string str){
   object me,obj;
   object key;
   string bluekey;
   me = this_player();
if(!str || str !="liu"){
                return notify_fail("你向誰膜拜？\n");
                           return 1;
                                 }
else{
message_vision(HIW"柳淳風說:哈!哈!我終於報仇了。謝謝了。\n"NOR,this_player());
message_vision(HIW"柳淳風說:為了報答你就送你三件禮物吧。\n"NOR,this_player());
message_vision(HIW"柳淳風說:老夫送你一程吧。\n"NOR,this_player());
  if( !me->query("mogi-pray-liu") ) {
   me->set("mogi-pray-liu",1);
        new(__DIR__"obj/sunblade")->move(this_player());
        new(__DIR__"obj/dragonar")->move(this_player());
        new(__DIR__"obj/hounghe")->move(this_player());
}
this_player()->move(__DIR__"enterroo");
        if (!key) key = present("bluekey", me);
        if (!key) key = present("bluekey", environment(me));
        if (!key) key = find_object( resolve_path(me->query("cwd"), bluekey) );
             if(key)
                  destruct(key);
     return 1;
}

           }

int search_here(string arg)

{
   if (this_player()->query_temp("find_tesin7")>=1)
tell_room(this_object(),"你找啊找的,發現牆有留字，可以探索(see). \n");
  else if(this_player()->query_temp("find_tesin8")>=1)
    {
    tell_room(this_object(),"找著找著...你忽然發現到一個密道..看樣子你可以鑽的進去(enter).\n");
    }
return 1;
}

int do_see(string str)
{
  if(!this_player()->query_temp("find_tesin7")) tell_room(this_object(),"你找了半天，可是看不出有任何特殊之處。\n");
  else 
  {
   tell_room(this_object(),"牆上寫著..'劍師龍鐵心到此一遊'.\n");
   if (this_player()->query_temp("find_tesin7")==1)
   {
   this_player()->set_temp("find_tesin8",1);
   this_player()->delete_temp("find_tesin7");
   }
   else if (this_player()->query_temp("find_tesin7")==2)
   {
   this_player()->set_temp("find_tesin8",2);
this_player()->delete_temp("find_tesin7");
   }
   else if (this_player()->query_temp("find_tesin7")==3)
   {
   this_player()->set_temp("find_tesin8",3);
this_player()->delete_temp("find_tesin7");
   }
  }
}
int do_enter(string str)
{
if (!this_player()->query_temp("find_tesin8"))
   tell_room(this_player(),"你想去哪???\n");
else
{ 
   tell_room(this_player(),"你順這密道..滑向未知的地方...\n");
   tell_room(this_player(),"你漸漸地看到眼前有光線出現...\n");
   this_player()->move("/open/gsword/room2/road1.c");
  this_player()->unconcious();
}
}

