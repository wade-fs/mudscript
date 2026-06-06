inherit ROOM;
void create() {
	set( "short", "『墨教大廳』" );
	set( "owner", "poll" );
	set( "object", ([
		"amount6"  : 1,
		"amount10" : 1,
		"file5"    : "/open/killer/headkill/obj/f_dag",
		"amount8"  : 1,
		"file4"    : "/open/killer/headkill/obj/f_dag",
		"file8"    : "/open/killer/headkill/obj/f_dag",
		"file6"    : "/open/killer/headkill/obj/f_dag",
		"amount5"  : 1,
		"file9"    : "/open/killer/headkill/obj/f_dag",
		"amount9"  : 1,
		"file10"   : "/open/killer/headkill/obj/f_dag",
		"amount7"  : 1,
		"file2"    : "/open/killer/headkill/obj/f_dag",
		"amount4"  : 1,
		"file7"    : "/open/killer/headkill/obj/f_dag",
		"file1"    : "/open/killer/headkill/obj/f_dag",
		"amount1"  : 1,
		"amount2"  : 1,
	]) );
	set( "build", 11477 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/13_luck/room/room450",
		"north"     : "/open/clan/13_luck/room/room453",
		"south"     : "/open/clan/13_luck/room/room451.c",
	]) );
	set( "long", @LONG
  
     這裡是墨教的總部，墨教創立於春秋戰國時代，是由墨子一手創建，墨
 教主張兼愛，非攻，博愛，發揚天下之大愛，而且墨眾都是良好的工匠，他
 們自己種菜，煉鐵，萬事都由自己來，他們出門都穿著樸素的衣服和赤腳，
 只有鉅子可以穿著鞋子，墨教非常重視門規，絕不允許有叛徒的存在，否則
 執法堂絕不輕饒，近年來墨教在江湖上創出名聲，依靠著墨子傳下來的劍法
 這裡燈火通明，墨教鉅子正坐在地上講道，旁邊有著很多墨家行者，這裡你
 可以感覺得出來那股嚴肅莊嚴的氣氛。還有墨教最不可以忍受對偶像的崇拜
 ，凡是練就法術或者咒術的人，會把視為斜魔歪道，而加以處罰，不過聽說
 有一個墨眾練就了移體的神通，只是不知道他現在人在那裡。

LONG);
	setup();
	replace_program(ROOM);
}
