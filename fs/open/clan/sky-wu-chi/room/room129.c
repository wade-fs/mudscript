inherit ROOM;
void create() {
	set( "short", "空瓶子武器室3" );
	set( "build", 10885 );
	set( "light_up", 1 );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room126",
	]) );
	set( "long", @LONG
你在這裡所看到的東西,絕對會讓你感到非常的驚訝..因為這些武器
都是非常有名的一些人所擁有的武器,也就是聚靈八傑及樹妖等等
有名的大頭目所在用的武器
如 凌微雲扇飄(lin-cloud-fan)化劫菱歸真(hwa-je-icer)
楓映天蓮劍(fon-sky-sword)閻匕影螫魂(dark-soul-dagger)
刀斬邪元歸(evil-gwe-blade)絕世匕首(world)

LONG);
	setup();
	replace_program(ROOM);
}
