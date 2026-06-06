inherit COMBINED_ITEM;
void create()
{
        set_name("瞬移丹", ({"move pill","pill"}) );
set("long",
"此物乃天才機關手諸岡渡自富士山密洞採來之密藥.\n"+
"只交給藍鳳組使用，一般殺手並拿不到，吃下(eat pill)後.
  會有一種飄然神迷的感覺，據說可以穿越空間。\n");
        set("unit", "盒");
        set("base_unit", "粒");
        set("no_sell",1);
        set("value",0);
        set("base_weight", 10);
set_amount(1);
setup();
}

void init()
{
  if( this_player()==environment() )
  {
    add_action("eat_pill", "eat");
  }
}

int eat_pill(string arg)
{      

   object ob,me=this_player();
   int max_atman,atman;

   if( !arg )                      return 0;
   arg=lower_case(arg);
   if( !ob = present(arg,me) )     return 0;
   if( ob != this_object() )       return 0;
   if (me->query("class") != "killer")
   {
     atman=me->query("kee");
     atman= atman/2;
     me->add("kee",-atman);
	tell_object(me,"你吃下之後感到一陣不適  難道是中毒了!!!\n");
     ob->add_amount(-1);
     return 0;
   }
   message_vision("$N吃下瞬移丹.\n", me);
   me->move("/open/killer/headkill/oldroom/r2.c");
   ob->add_amount(-1);
   return 1;
}
