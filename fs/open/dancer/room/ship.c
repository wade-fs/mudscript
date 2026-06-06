inherit ROOM;

int time=0;
void create()
{
  set("short","彎月舫");
  set( "build", 85 );
  set ("long", @LONG
雕飾著雲女玩月圖的彎月舫，船體是由千年神木所輮製而成，是
當今京城首富贈與雙月姊妹的禮物，只為能夠欣賞一次她們媲美天仙
的技藝。姊妹偶爾會乘著彎月舫遊湖賞景，但通常都是讓弟子們外出
購物用。

LONG);
  set("light_up", 1);
  set("objects",([
  "/open/dancer/npc/ship_girl":1,
  "/open/tensan/linjoy/npc/linlin":1,
  ]));
  set("no_clean_up",1);
  set("no_transmit", 1);
  setup();
  set_heart_beat(1);
}

   void arrive_port()
{
	tell_room(this_object(),"鏡月島到囉 , 請趕快下(out)船!\n");
	set("exits/out","/open/dancer/room/port.c");
	new("/open/dancer/npc/ship1")->move("/open/dancer/room/port"); 
	
}	
  void leave_port()
{
	tell_room(this_object(),"本船即將駛往楓林港 !\n");
	delete("exits/out");

	
}
   void arrive_fonport()
{
	tell_room(this_object(),"楓林港到了 , 要下(out)船的請快!\n");
	set("exits/out","/open/dancer/room/fonport.c");
        new("/open/dancer/npc/ship2")->move("/open/dancer/room/fonport");
}	
  void leave_fonport()
{
	tell_room(this_object(),"鏡月島之旅開始囉 !\n");
	delete("exits/out");

}


  void heart_beat()
{
	
	time++;
	if(time>60)
// 60 為週期 , 要更密集就調低一點 
	time=1;
	if(time==1)
	arrive_port();
	if(time==11)
	leave_port();
	if(time==31)
	arrive_fonport();
	if(time==41)
	leave_fonport();
}
