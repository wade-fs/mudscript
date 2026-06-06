inherit ROOM;
void create() {
	set( "short", "飛龍居" );
	set( "owner", "imissyou" );
	set( "object", ([
		"amount7"  : 1,
		"file2"    : "/obj/stone/jiao",
		"file6"    : "/open/killer/obj/kill_yar_head",
		"file10"   : "/open/magic-manor/obj/master_snake_head",
		"file9"    : "/open/mogi/castle/obj/ninepill",
		"amount10" : 1,
		"amount5"  : 72,
		"amount8"  : 1,
		"file5"    : "/obj/stone/suipian",
		"file1"    : "/obj/stone/powder",
		"file8"    : "/open/magic-manor/obj/master_snake_head",
		"amount2"  : 18,
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"amount3"  : 88,
		"amount6"  : 1,
		"amount4"  : 1,
		"file3"    : "/open/fire-hole/obj/g-pill",
		"file4"    : "/open/magic-manor/obj/master_snake_head",
		"amount1"  : 896,
		"amount9"  : 40,
	]) );
	set( "light_up", 1 );
	set( "build", 10072 );
	set( "exits", ([
		"south"     : "/open/clan/sky-wu-chi/room/room440",
		"east"      : "/open/clan/sky-wu-chi/room/room435.c",
		"chome"     : "/open/clan/sky-wu-chi/room/hall",
		"north"     : "/open/clan/sky-wu-chi/room/room439.c",
		"west"      : "/open/clan/sky-wu-chi/room/room436.c",
	]) );
	set( "long", @LONG
詩人的情,詩人的意,全部灌溉在這片園地裡.....
由扶風小樹灌溉出來的空間......對 這 杯的詩
 ~非真 心空 ~非真 炎殘雨 ~慾惘過客炎殘雨碎
痛心寒 ~慾惘過客炎殘雨 英雄一戰-儒門雙嘆 ~
白羽長風客 痴劍只為真 ~...  

怒 顏 寒 髮 凍 千 山
雨 細 飄 渺 驚 萬 浪
飛 簷 走 璧 行 天 地
龍 非 凡 物 任 翱 翔

LONG);
	setup();
	replace_program(ROOM);
}
