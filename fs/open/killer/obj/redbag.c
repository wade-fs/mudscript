inherit ITEM;
#include <ansi.h>
void create()
{
set_name(HIR + "紅包" + NOR,({"red bag","bag","red"}));
set("long","過年發給小朋友的紅包, 可以打開(open)看看裡面有什麼。\n");
     set("unit","包");
     set_weight(1);
     set("value",1);
}
void init()
{
add_action("do_open","open");
}


int do_open( string arg )
{
  object ob,me,bag;
  bag=this_object();
  me=this_player();

  if( query("opened") ) return notify_fail("紅包裡面已經空無一物。\n");
  message_vision( "$N從"+this_object()->name()+"拿出一些東西。\n",me );
  this_object()->set("opened",1);
  ob = new( "/obj/stone/stone" ); //stone一個
  ob->move(me);
  ob = new( "/obj/money/diamond" ); //鑽石
  ob->add_amount(random(10)+5);
  ob->move(me);
  ob = new( "/open/mon/obj/mon-pill" );  //千年靈芝仙丹
  ob->add_amount(random(5));
  ob->move(me);  
  ob = new( "/open/mogi/castle/obj/ninepill" );  //九轉熊蛇丸
  ob->add_amount(random(5)+10);
  ob->move(me);  
  ob = new( "/autoload/mogi/sspill" );    //生生造化丹
  ob->add_amount(random(5));
  ob->move(me);
  ob = new( "/open/fire-hole/obj/b-pill.c" );  //藍龍精元
  ob->add_amount(random(5));
  ob->move(me);
  ob = new( "/open/fire-hole/obj/r-pill.c" );  //紅龍精元
  ob->add_amount(random(5));
  ob->move(me);  
  ob = new( "/open/fire-hole/obj/k-pill.c" );  //龍王精元
  ob->add_amount(random(5));
  ob->move(me); 
  ob = new( "/open/fire-hole/obj/p-pill.c" );  //毒龍精元
  ob->add_amount(random(5));
  ob->move(me);
  ob = new( "/open/fire-hole/obj/w-pill.c" );  //白龍精元
  ob->add_amount(random(5));
  ob->move(me);  
  ob = new( "/open/fire-hole/obj/g-pill.c" );  //綠龍精元
  ob->add_amount(random(5));
  ob->move(me);  
  ob = new( "/open/fire-hole/obj/y-pill.c" );  //黃龍精元
  ob->add_amount(random(5));
  ob->move(me);
  destruct(bag);
  return 1;
}
