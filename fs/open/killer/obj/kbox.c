inherit ITEM;
#include <ansi.h>

int call_guard(int i);

void create()
{
set_name(MAG "裝備箱" NOR,({"hate box","box"}));
set("long","這是一個平凡的盒子﹐且附著封條。\n");
     set("unit","俱");
     set_weight(1000000);
     set("value",10000);
}
void init()
{
add_action("do_search","search");
add_action("do_tear","tear");
add_action("do_open","open");
}

int do_search(string str)
{
if(str!="box"&&str!="eq box")
return notify_fail("你在找什麼 ?\n");
if(this_object()->query_temp("tear_paper")!=1)
tell_object(this_player(),"你發現在這個箱上有封條(fon papers)。\n");
if(this_object()->query_temp("tear_paper")==1)
return notify_fail("你發現箱上有道被撕掉的封條。\n");
return 1;
}

int do_tear(string str)
{
  int i;
  if(this_object()->query_temp("tear_paper")==1)
    return notify_fail("封條已經被撕開。\n");
  seteuid(getuid());
  if(str!="fon papers")
    return 0;
  tell_object(this_player(),"你用手撕開了箱上的封條。\n");
  this_object()->set_temp("tear_paper",1);
    return 1;
}

int do_open( string arg )
{
  object ob,me;
  me=this_player();
  if( !arg || arg != "box" ) 
    return 0;
  if( !this_object()->query_temp("tear_paper") ) return 0;
  if( query("opened") ) 
    return notify_fail("箱內空無一物。\n");
  message_vision( "$N從"+this_object()->name()+"拿出一些裝備。\n",me );
  this_object()->set("opened",1);
  ob = new( "/open/killer/obj/bellstar.c" );
  ob->add_amount(39);
  ob->move(me);
  ob = new( "/open/killer/obj/s_pill.c" );
  ob->add_amount(2);
  ob->move(me);
  ob = new( "/open/killer/obj/k_ring.c" );
  ob->move(me);
  return 1;
}
