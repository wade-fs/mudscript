// Room : /open/clan/ou-cloud-club/room/room38.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "short", "$HIW$惡魔城$HIR$入口$NOR$" );
	set( "owner", "bbsboss" );
	set( "object", ([
		"file8"    : "/open/mon/obj/ghost-claw",
		"amount6"  : 1,
		"file6"    : "/open/mon/obj/ghost-claw",
		"amount3"  : 1,
		"amount5"  : 1,
		"amount1"  : 1,
		"amount4"  : 1,
		"file1"    : "/open/mon/obj/ghost-claw",
		"file3"    : "/open/mon/obj/ghost-claw",
		"file7"    : "/open/mon/obj/ghost-claw",
		"amount7"  : 1,
		"amount10" : 1,
		"file9"    : "/open/mon/obj/ghost-claw",
		"amount9"  : 1,
		"file10"   : "/open/mon/obj/ghost-claw",
		"amount8"  : 1,
		"file4"    : "/open/mon/obj/ghost-claw",
		"amount2"  : 1,
		"file5"    : "/open/mon/obj/ghost-claw",
		"file2"    : "/open/mon/obj/ghost-claw",
	]) );
	set( "build", 10011 );
	set( "light_up", 1 );
	set( "no_clean_up", 0 );
	set( "cmkroom", 1 );
	set( "long", @LONG
兩旁牆上的古老燭臺中,昏暗不明的燭火隨著腐敗的空氣搖晃著,
你依稀可見到牆上零星的散佈著斑駁的血跡,幾乎使你當場作嘔,更令
人感到驚懼的,是面前有些許奇怪的人影漫無目的的走動著,以眼角餘
光偷偷觀察,才警覺到這些都是四肢五官殘破不全的食屍人,雖然空有
力量而無智慧靈魂的怪物不足為懼,但若是被纏上了,光他們恐怖的面
容就可以讓你連作三天惡夢了,還是儘速低調通過吧!!
LONG);
	set( "exits", ([ /* sizeof() == 2 */
  "east" : "/open/clan/ou-cloud-club/room/room39.c",
  "west" : "/open/clan/ou-cloud-club/room/room37",
]) );
	set( "no_transmit", 1 );
	set( "clan_room", "傲雲山莊" );
	setup();

	}
