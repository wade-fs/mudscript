// Room: /open/gblade/port/room/port.c
//by wugi
inherit ROOM;

void create()
{  
   
   set("short","楓林港港口");
   set ("long", @LONG
這裡是楓林港港口 , 你看到大大小小的商船 , 渡船進進
出出 , 非常的繁忙 , 港邊立了個告示牌(board) , 說明楓林港
目前通航的地區及時刻 , 價錢等訊息 .

LONG);
   set("light_up", 1);
	set_heart_beat(1);
	set("outdoors", "/open/port");
  set("exits", ([ /* sizeof() == 1 */
	"north" : "/open/port/room/r5-1.c",
]));
  	
	set("item_desc",
	(["board":
"公告:
本港開幕大喜 , 所有乘客一律免費 

現在通航的地點有 :
鏡月島 : 一個時辰一班次 , 勿搭乘(board)
冥魔島 : 三刻鐘一班次 , 未完工 , 勿搭乘
東瀛島 : 趕工中

"]));

 setup();
}
 init()
{
	add_action("board_ship","board");
	do_start_ship();
	
}
 
//下面這個動作是用來將被記憶體清掉的船再呼叫出來
void do_start_ship()
{
	object ob1,ob2;
	if(!find_object("ship leader"))
	{
	ob1=new("/open/gblade/port/npc/ship_leader");
	 ob1->move("/open/gblade/port/room/ship");
	destruct(ob1);
	}
	if(!find_object("vessel leader"))
	{
	ob2=new("/open/gblade/port/npc/vessel_leader");
	ob2->move("/open/gblade/port/room/vessel");
	destruct(ob2);
	}
}
int board_ship(string str)
{
	object ob;
 	if(!str)
	return notify_fail("你要搭什麼?\n");	
	if(!objectp(ob=present(str,environment(this_player()))))
        return notify_fail("看清楚點 , 有那種船嗎 ?\n");
//下面這段 , 我的寫法有個大麻煩之處
//每隻船都要不同 id 才能處理 , 看那位能幫忙矯正矯正 
//hmm , 不過船應該也不多吧 , 英文的船名應該也不少了 , 呵
        if(str=="ship") 
	{
	message_vision("$N走到岸邊 , 搭上了渡船 !\n",this_player());
	this_player()->move("/open/gblade/port/room/ship");
	return 1;
	}
	if(str=="vessel")
	{
	message_vision("$N走到岸邊 , 搭上了幽冥魔船 !\n",this_player());
	this_player()->move("/open/gblade/port/room/vessel");
	return 1;
	}
	
return 0;
}	
