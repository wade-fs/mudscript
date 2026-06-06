inherit ROOM;
void create() {
	set( "short", "陽台" );
	set( "owner", "djlh" );
	set( "object", ([
		"amount2"  : 1,
		"amount3"  : 1,
		"file7"    : "/open/ghost-hole/obj/eq/ghost-pants",
		"file10"   : "/open/killer/obj/s_pill",
		"amount6"  : 1,
		"amount10" : 98,
		"file9"    : "/open/magic-manor/obj/master_snake_head",
		"file6"    : "/open/killer/headkill/obj/world_dag",
		"file4"    : "/open/killer/obj/hate_knife",
		"file2"    : "/open/killer/obj/dagger",
		"amount7"  : 1,
		"file3"    : "/open/killer/obj/dagger",
		"amount9"  : 1,
		"amount4"  : 9014,
	]) );
	set( "build", 11051 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room666.c",
		"south"     : "/open/clan/13_luck/room/room664",
	]) );
	set( "long", @LONG

   ╬◇◆◇◆◇╬◆◇◆◇◆◇╬◆◇◆◇◆◇╬◆◇◆◇◆◇╬◆◇◆◇◆╬         
   ◆看窗外的風景  看天空藍的多麼熟悉  看日曆一頁一頁撕去  看自己老去◆         
   ◇聽風輕輕吹襲  聽陽光笑的多麼美麗   聽耳邊傳來句句旋律 是自己聲音◇         
   ◆如果可以 讓 現在 停止不走 就不會 害怕 失去 這秒的 感動 如果可以◆         
   ◇ 重新選擇個  夢  那夢會是什麼顏色  我的 存在 也會 不同 時間快轉 ◇         
   ◆它 不停 的快轉  旋轉 我跟著旋轉 失去方向 我沒有方向 迷失方向  我◆         
   ◇模糊了 焦點 想不通太多事情呀  就把它 遺忘 時間快轉 它 不停的快轉◇         
   ◆旋轉 我跟著旋轉  失去方向 我沒有方向 迷失方向 我 模糊了 焦點  想◆         
   ◇不通太多道理呀 就選擇遺忘  就選擇  遺忘...    ◎Penny˙時間快轉 ◇         
   ╬◇◆◇◆◇╬◆◇◆◇◆◇╬◆◇◆◇◆◇╬◆◇◆◇◆◇╬◆◇◆◇◆╬        
  
  
LONG);
	setup();
	replace_program(ROOM);
}
