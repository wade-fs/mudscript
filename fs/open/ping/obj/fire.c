inherit ITEM;
#define VOID		"/obj/void"
#define QUEST_ROOM	"/open/main/room/s16"
void create()

{
      set_name("炮仗",({"firecracker"}) );
      set_weight(8000);
      if( clonep() )
           set_default_object(__FILE__);
      else {
           set("unit","個");
           set("long","這是段家聯絡用的炮仗, 你可以燃放(fire)它。");
           set("value",0);
           }
      setup();
}

void init()
{
	add_action("do_fire","fire");
}

int do_fire(string str)
{
	object me=this_player();
	object place=environment(me);
	if( !place->query("outdoors") )
	  write("在屋子裡你想放火啊。\n");
	else
	{
	if( str != "firecracker" )
	  write("你要燒什麼東東啊? \n");
	else
	{
	  this_object()->move(VOID);
	  message_vision("$N從懷裡掏出一個炮仗, 然後帥氣的將它發射出去。\n",me);
	  if(me->query_temp("thief") >= 7)
	  {
	    tell_room(environment(me),"炮仗呈現優美的弧度在天空炸了開來...\n"+
"								  \n"+
"	   **	*		*  * 				  \n"+
"             *  ★   *           ★  	*		  **      \n"+
"                   *         ☆ *                        *   ★  \n"+
"                      *   *   ★         *        *    ☆ *      \n"+
"		*		*  *		    * 	    **    \n"+
"			**			**		  \n"+
"                            					  \n");
	    call_out("result",4);
	  }
	  else
	  { 
	    tell_room(environment(me),"可能是技術不好的關係, 炮仗歪歪斜斜的落了下來。\n");
	    destruct(this_object());
	  }  
	}
	}
	return 1;
}
void result()
{
	object me=this_player();
	if( environment(me)->query("capital_thief") == 0 )
	{  
	  write("可是四周圍都沒什麼動靜, 可能是因為這兒不是京城裡地勢最高的地方。\n"); 
	  destruct(this_object());
	}  
	else
	{
	  write("你似乎撇見角落有黑影一閃。\n機不可失, 你馬上追了過去。\n");
	  tell_room(environment(me),me->query("name")+"突然急急忙忙的離開了。\n",me);
	  call_out("follow1",3);
	  me->set_temp("block_msg/all", 1);
	  me->move(VOID);
	}
}
void follow1()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("(我追我追我追追追....)\n");
	call_out("follow2",3);
	me->set_temp("block_msg/all", 1);
}
void follow2()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("(披荊斬棘我追追追....)\n");
	call_out("follow3",3);
	me->set_temp("block_msg/all", 1);
}
void follow3()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("(翻山越嶺我追追追....)\n");
	call_out("follow4",3);
	me->set_temp("block_msg/all", 1);
}
void follow4()
{
	object me=this_player();
	me->set_temp("block_msg/all", 0);
	write("只見黑影在草叢(bush)間一竄, 似乎失去了蹤影\n");
	me->set_temp("thief",8);
	me->move(QUEST_ROOM);
	destruct(this_object());
}	
