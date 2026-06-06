inherit ROOM;
void create() {
	set( "short", "『洞內洞』" );
	set( "owner", "ywarter" );
	set( "object", ([
		"amount10" : 1,
		"amount1"  : 1,
		"file8"    : "/open/magic-manor/obj/maun-shadow-blade",
		"amount2"  : 1,
		"file2"    : "/obj/example/besttea",
		"file5"    : "/open/sky/obj/lucky_grasslink",
		"file1"    : "/open/magic-manor/obj/hwa-je-icer",
		"file4"    : "/obj/gift/unknowdan",
		"amount7"  : 1,
		"amount8"  : 1,
		"file7"    : "/open/magic-manor/obj/evil-gwe-blade",
		"file10"   : "/open/magic-manor/obj/fon-sky-sword",
		"file6"    : "/obj/gift/unknowdan",
		"file3"    : "/open/common/obj/liz_meat",
		"amount4"  : 1,
		"file9"    : "/open/sky/obj/lucky_grasslink",
		"amount3"  : 1,
		"amount9"  : 1,
		"amount5"  : 1,
		"amount6"  : 1,
	]) );
	set( "exits", ([
		"west"      : "/open/clan/sky-wu-chi/room/room206",
	]) );
	set( "build", 10026 );
	set( "long", @LONG

    當火球上升在綻藍之中                ------------------------------------
    ------------------------------------              十個矮人的舞蹈終告落幕
    被取而代之的燈火                    ------------------------------------
    ------------------------------------                    沉寂黑暗中的螢光
    苦澀的救助劃入腹中                  ------------------------------------
    ------------------------------------                  冰冷的刺痛洗去苦澀
    灼燙的紅色在眼前揮舞                ------------------------------------
    ------------------------------------                  灰色的模糊漸漸隱藏
    虛假的生命之扉將被關閉              ------------------------------------
    ------------------------------------                不死者將進入墓地安息

LONG);
	setup();
	replace_program(ROOM);
}
