inherit ROOM;
void create() {
	set( "short", "$HIC$$BWHT$阿嚕米的裝備室$NOR$" );
	set( "owner", "cong" );
	set( "object", ([
		"amount10" : 1,
		"file9"    : "/open/mogi/dragon/obj/scale",
		"file10"   : "/open/mogi/dragon/obj/scale",
		"amount9"  : 1,
	]) );
	set( "build", 33701 );
	set( "exits", ([
		"east"      : "/open/clan/sky-wu-chi/room/room110",
	]) );
	set( "long", @LONG
這一間是$HIR$阿嚕米$NOR$的$HIB$裝備室$NOR$之一，裡面放了各式各樣的武器與
防具。這都是$HIR$阿嚕米$NOR$常年在外去與人比武或是出任務時，所
帶回來的勝利品，裝備都是放在$HIY$櫃子$NOR$裡，由$HIR$阿嚕米$NOR$本人親自
整理，這些裝備經過$HIR$阿嚕米$NOR$灌輸深厚的內力後，只能適合他
本人使用了，外人想要穿上這些裝備是難上加難。
LONG);
	setup();
	replace_program(ROOM);
}
