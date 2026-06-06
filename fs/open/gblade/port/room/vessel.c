// Room: /open/gblade/port/room/port.c
inherit ROOM;

int time=0;
void create()
{
	set("short","幽冥魔船內");
   set ("long", @LONG
一收陰氣森森的魔船 , 坐在上面 , 你感到一股寒氣侵體 ,
船首一個人在駛著船 , 從背後看起來 , 到像具骷顱 .

LONG);
   set("light_up", 1);
	set("objects",([
	"/open/gblade/port/npc/vessel_leader":1,
	]));
   set("no_clean_up",1);
  setup();
	set_heart_beat(1);
}

   void arrive_port()
{
	tell_room(this_object(),"楓林港到囉 , 請趕快下(out)船!\n");
	set("exits/out","/open/gblade/port/room/port.c");
	new("/open/gblade/port/npc/vessel1")->move("/open/gblade/port/room/port");
	
}	
  void leave_port()
{
	tell_room(this_object(),"出發啦 , 目的地是冥魔島 !\n");
	delete("exits/out");

	
}
   void arrive_island()
{
	tell_room(this_object(),"冥魔島到囉 , 請趕快下(out)船!\n");
	set("exits/out","/open/gblade/port/room/island2.c");
	new("/open/gblade/port/npc/vessel2.c")->move("/open/gblade/port/room/island2");
}	
  void leave_island()
{
	tell_room(this_object(),"出發啦 , 目的地是楓林港 !\n");
	delete("exits/out");

}


  void heart_beat()
{
	
	time++;
	if(time>50)
	time=1;
	if(time==1)
	arrive_port();
	if(time==11)
	leave_port();
	if(time==26)
	arrive_island();
	if(time==36)
	leave_island();
}

	

