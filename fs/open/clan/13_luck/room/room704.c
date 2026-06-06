inherit ROOM;
void create() {
	set( "short", "二樓northeast" );
	set( "object", ([
		"file6"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount9"  : 1,
		"file7"    : "/open/capital/obj/4-3",
		"amount8"  : 1,
		"amount5"  : 1,
		"file1"    : "/open/capital/obj/blade2",
		"file2"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount10" : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount7"  : 1,
		"amount4"  : 1,
		"file4"    : "/open/magic-manor/obj/fire-color-ribbon",
		"file8"    : "/open/capital/obj/4-3",
		"file5"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount2"  : 1,
		"file10"   : "/open/capital/obj/blade2",
		"amount1"  : 1,
		"file9"    : "/open/capital/obj/4-2",
		"amount3"  : 1,
		"amount6"  : 1,
	]) );
	set( "owner", "djlh" );
	set( "build", 10005 );
	set( "exits", ([
		"south"     : "/open/clan/13_luck/room/room698",
		"west"      : "/open/clan/13_luck/room/room701",
	]) );
	set( "long", @LONG

※ ● 這裡的空氣很新鮮　這裡的小吃很特別                ※※※※─────┼┼  
※ ◣     這裡的Latte不像水　這裡的夜景很有感覺  ●β       ╴╴  ※※※─┼┼  
※※/ 在一萬英呎的天邊　在有港口View的房間      ﹀◥＝    （    ）        ││  
※※    在討價還價的商店　在凌晨喧鬧的三四點              ︱¯¯｜        ││  
│※可是親愛的　你怎麼不在我身邊  我們有多少時間能浪費    ︱﹋﹌｜        ││  
││  電話再甜美　傳真再安慰　也不足以應付不能擁抱你的遙遠╰——╯        ※│  
││我的親愛的　你怎麼不在我身邊　一個人過一天像過一年       ∥ ＃＃＃    ※※  
││    海的那一邊　烏雲一整片  我很想為了你快樂一點   ＃＃＃∥           ※※  
┼┼───※※※    可是親愛的　你怎麼   不在身邊          ╭╩╮           ※  
┼┼────────※※※※ 親愛的˙你怎麼不在身邊  江美琪 ¯¯  ＃＃＃    ※  

LONG);
	setup();
	replace_program(ROOM);
}
