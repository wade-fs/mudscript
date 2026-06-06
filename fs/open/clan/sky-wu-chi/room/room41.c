// Room : /open/clan/sky-wu-chi/room/room41.c
 inherit ROOM;

void create()
{
        seteuid(getuid());
	set( "exits", ([ /* sizeof() == 1 */
		"east"      : "/open/clan/sky-wu-chi/room/room132",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"down"      : "/open/clan/sky-wu-chi/room/room128",
		"out"       : "/open/clan/sky-wu-chi/room/room21",
]) );
	set( "cmkroom", 1 );
	set( "long", @LONG
門口屏風畫著山水風光,你的目光越過屏風,雖然只見到房內一小部分,
但裏面的雅致已讓你覺得如沐春風,此時耳中傳來思量陣陣低吟{明朝散髮
弄扁舟},你更想一睹其人了. ^_^;
正當你提起腳步往房內走去時,
你感覺右側的假山似乎怪怪的,
在你仔細察探下發覺上面某塊青苔有被人移動過的跡象,
你撥開青苔發現一顆按紐,
在好奇心驅使下壓下按鈕,
轟的一聲,假山後多了一條向下的樓梯.....
LONG);
	set( "short", "$HIC$思量之家$HIW$大廳$NOR$" );
	set( "owner", "salicili" );
	set( "object", ([
		"file9"    : "/open/mon/obj/ghost-cloak",
		"file5"    : "/open/tendo/obj/chaosbelt",
		"amount9"  : 1,
		"amount4"  : 1,
		"file6"    : "/open/mogi/castle/obj/lochagem",
		"file4"    : "/open/mon/obj/ghost-helmet",
		"amount7"  : 1,
		"amount10" : 1,
		"amount1"  : 1,
		"file1"    : "/daemon/class/blademan/obj/shield",
		"file7"    : "/open/mon/obj/ghost-legging",
		"amount5"  : 1,
		"amount6"  : 1,
		"file8"    : "/open/sky/obj/lucky_grasslink",
		"file10"   : "/open/wu/npc/obj/armband",
		"amount8"  : 1,
	]) );
	set( "outdoors", "/open/clan/sky-wu-chi" );
	set( "light_up", 1 );
	set( "build", 10037 );
	set( "no_transmit", 1 );
	set( "no_clean_up", 0 );
	setup();

	}
