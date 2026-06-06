inherit COMBINED_ITEM;
void create()
{
        set_name("絕世丹藥", ({"world pill","pill"}) );
set("long",
"此丹藥將可以提升使用者，使用絕世匕首的威力，並且強化殺意魔氣的威力\n"+
"看來這就是任盈盈所說的丹藥，應該可以吃(eat pill).\n");
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

   if( !arg )                      return 0;
   arg=lower_case(arg);
   if( !ob = present(arg,me) )     return 0;
   if( ob != this_object() )       return 0;
   if (me->query("class") != "killer")
   {
	me->set("kee",10);
	tell_object(me,"你吃下之後感到一陣不適  難道是中毒了!!!\n");
	ob->add_amount(-1);
	return 0;
   }
   if (me->query_temp("getpill") == 1)
   {
	   message_vision("$N吃下絕世丹藥後，感到體內彷彿有一道虛幻的真力流走著.\n", me);
                  me->set("quest/worldpill",1);
	   ob->add_amount(-1);
	   return 1;
   }
    else
    {
       message_vision("$N吃下絕世丹藥後，心知此藥不是自己所得.心裡有鬼﹐連大便都拉出來\n",me);
       me->set("kee",10);
      me->set("gin",10);
      me->set("sen",10);
       ob->add_amount(-1);
       return 1;
    }
}
