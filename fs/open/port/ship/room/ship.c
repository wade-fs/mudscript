// Room: /open/gblade/port/room/port.c
// made by wugi
//因在下功力淺薄 , 做條航線需寫 6 個 file , 修改一個 file
//因為航線不多 , 因此沒必要寫來 inherit
//想增加航線的人就拿去修改吧 , 很快的 
inherit ROOM;

int time=0;
void create()
{
   set("short","渡船內");
   set ("long", @LONG
一騪小渡船 , 已經非常破舊了 , 你不禁擔心 , 如果遇上
暴風雨的話會如何。

LONG);
   set("light_up", 1);
	set("objects",([
	"/open/gblade/port/npc/ship_leader":1,
//這隻 npc 有個好處 , 可以增加些 chat_msg , 比較不會太死寂
//還有我拿 npc 來當做呼叫 ship 的參考物
	]));
   set("no_clean_up",1);
  setup();
	set_heart_beat(1);
}

   void arrive_port()
{
	tell_room(this_object(),"楓林港到囉 , 請趕快下(out)船!\n");
	set("exits/out","/open/gblade/port/room/port.c");
	new("/open/gblade/port/npc/ship1")->move("/open/gblade/port/room/port"); 
// 由於無法將 room 搬到 room 內 , 因此我做了兩隻船的 npc , 分別丟到兩岸
	
}	
  void leave_port()
{
	tell_room(this_object(),"出發啦 , 目的地是鏡月島 !\n");
	delete("exits/out");

	
}
   void arrive_island()
{
	tell_room(this_object(),"鏡月島到囉 , 請趕快下(out)船!\n");
	set("exits/out","/open/gblade/port/room/island.c");
        new("/open/gblade/port/npc/ship2")->move("/open/gblade/port/room/island");
}	
  void leave_island()
{
	tell_room(this_object(),"出發啦 , 目的地是楓林港 !\n");
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
	arrive_island();
	if(time==41)
	leave_island();
}

	

