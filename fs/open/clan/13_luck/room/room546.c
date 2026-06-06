inherit ROOM;
void create() {
	set( "short", "細細品味喔(1)" );
	set( "object", ([
		"amount5"  : 1,
		"file1"    : "/obj/gift/shenliwan",
		"file3"    : "/obj/gift/hobowdan",
		"amount1"  : 1,
		"file5"    : "/open/mogi/dragon/obj/scale",
		"file2"    : "/obj/gift/hobowdan",
		"amount3"  : 1,
		"amount2"  : 1,
		"file4"    : "/obj/gift/shenliwan",
		"amount4"  : 1,
	]) );
	set( "owner", "dfyw" );
	set( "build", 10035 );
	set( "light_up", 1 );
	set( "exits", ([
		"east"      : "/open/clan/13_luck/room/room547",
	]) );
	set( "long", @LONG
喝酒的時候，六分醉的微醺感總是最舒服的。  
　　喝到五六分醉的時候，身上的每一塊肌肉都可以得到鬆弛，腦中
的每一個細胞都可以變得很柔軟，眼中看到的一切都是很可愛的，而
耳朵聽到的一切也都會是非常扣人心弦的，甚至，或許是因為喉嚨開
了的緣故，連歌也可以唱的特別的好。  
　　但是，如果已經到了五六分醉還繼續喝，或者以上情形還是
可以持續保有，但是因為每個人的體質不同，或者酒的種類不同，就
會有許多隨之而來的後遺症，如：腸胃無法負荷的嘔吐、酒精過量帶
來的暈眩感、隔天醒來頭疼欲裂，全身不舒服的宿醉感覺....等等，完
全喪失了飲酒的樂趣。 
LONG);
	setup();
	replace_program(ROOM);
}
