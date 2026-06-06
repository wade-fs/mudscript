inherit ROOM;
void create() {
	set( "short", "內山理名之間" );
	set( "owner", "borkiller" );
	set( "build", 10452 );
	set( "light_up", 1 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room240",
	]) );
	set( "long", @LONG
內山理名
生日 1981年11月7日
出生地 神奈川縣 
血型 O型 
星座 天蠍座 
身高 157cm 
三圍 B-79cm W-56cm H-79cm 
興趣 騎馬、做西點-尤其是香蕉蛋糕 
特殊技能 書道7段、游泳、單簧管 
自認迷人之處  眼睛 (嗯~真的很迷人) 
LONG);
	setup();
	replace_program(ROOM);
}
