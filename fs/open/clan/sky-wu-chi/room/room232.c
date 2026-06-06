inherit ROOM;
void create() {
	set( "short", "國王的寢宮" );
	set( "owner", "panhermes" );
	set( "object", ([
		"file5"    : "/open/magic-manor/obj/evil-kill-claw",
		"amount1"  : 1,
		"file3"    : "/open/magic-manor/obj/maun-shadow-blade",
		"file1"    : "/open/magic-manor/obj/fon-sky-sword",
		"file4"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount9"  : 1,
		"file8"    : "/open/magic-manor/obj/lin-cloud-fan",
		"amount4"  : 1,
		"file6"    : "/open/magic-manor/obj/fire-color-ribbon",
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/obj/dark-soul-dagger",
		"amount7"  : 1,
		"amount6"  : 1,
		"file9"    : "/open/magic-manor/obj/hwa-je-icer",
		"amount5"  : 1,
		"amount3"  : 1,
	]) );
	set( "build", 10030 );
	set( "light_up", 1 );
	set( "exits", ([
		"out"       : "/open/clan/sky-wu-chi/room/room313",
	]) );
	set( "long", @LONG
你正站在國王的臥室裡，簡單的傢具令你大吃一驚，一張巨大的床佔了整個房間
的一半，用黃金織成的棉被整齊疊在上頭，床頭掛著新婚時的畫像；化粧台則在
房間的另一角，放滿了五顏六色的化粧瓶，一件透明的蕾絲睡衣被隨意丟在化粧
台的椅子上。往外你可以回到走廊。
LONG);
	setup();
	replace_program(ROOM);
}
