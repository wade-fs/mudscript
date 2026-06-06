inherit ITEM;
void create()
{
      set_name("衙門令牌",({"yamen mark","mark"}) );
      set_weight(8000);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","個");
           set("long","這是衙門總理頒佈的的令牌, 見此令有如總理親至, "+
           "你可以將此令牌顯示(show)給別人看。");
           set("value",1);
           }
      setup();
}

void init()
{
	add_action("do_show","show");
}

int do_show(string str)
{
	object me=this_player();
	object target;
        if( !present(this_object(),me))
	  return 0;
	if( !str || !present(str, environment(me)) )
	  return notify_fail("你要向誰顯示令牌?\n");
	target=present(str, environment(me));
	if( !target->is_character() || target==me)
	  return notify_fail("你要向誰顯示令牌?\n");
	message_vision("$N很臭屁的掏出一面「衙門令牌」向$n炫耀。\n",me,target);
	if(me->query_temp("thief") >= 2)
	{
	  message_vision("結果$N很惶恐的說: 是是.."+RANK_D->query_respect(me)+"有何建教。\n",target,me);
	  target->set_temp("show_mark",getuid(me));
	}  
	else
	  message_vision("結果$N以懷疑的眼光對$n說: 這個東西是你的嗎。\n",target,me);
	return 1;
}
