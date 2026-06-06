// Room: /open/gblade/port/room/port.c
inherit ROOM;

void create()
{  
   
   set("short","鏡月島");
   set ("long", @LONG
哈哈哈 , 鏡月島還沒做好啦 !!


LONG);
   set("light_up", 1);
	set_heart_beat(1);
  set("outdoors", "/open/gblade");
  	

 setup();
}
 init()
{
	add_action("board_ship","board");
	
}
 
int board_ship(string str)
{
object ob;
 	if(!str)
	return notify_fail("你要搭什麼?\n");	
	if(!objectp(ob=present(str,environment(this_player()))))
        return notify_fail("看清楚點 , 有那種船嗎 ?\n");
        if(str=="ship") 
	{
	message_vision("$N走到岸邊 , 搭上了渡船 !\n",this_player());
	this_player()->move("/open/gblade/port/room/ship");
	return 1;
	}
	
return 0;
}	
